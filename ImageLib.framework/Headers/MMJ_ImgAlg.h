//
//  MMJ_ImgAlg.h
//  MMJ_alg_Demo
//
//  Created by hjx on 2019/9/29.
//  Copyright © 2019 hjx. All rights reserved.
//

#ifndef MMJ_ImgAlg_h
#define MMJ_ImgAlg_h

#ifdef __cplusplus
extern "C"
{
#endif

//返回值错误代码
typedef enum MMJ_ERROR_CODE
{
    MMJ_SUCCESS = 0,
    MMJ_ERROR = 1,
    MMJ_MEMORY_APPLY = 2,
    MMJ_PARAMETER = 3,
}MMJ_Error_Code;

//传输的图像数据类型，对应通道数，对应安卓和ios两端数据类型
typedef enum MMJ_IMAGE_TYPE
{
    Alpha8 = 1,
    RGB565 = 2,
    RGB888 = 3,
    ABGR8888 = 4,
    RGBA8888 = 5,
}MMJ_ImgType;

//传输的图像数据结构
typedef struct MMJ_IMAGE
{
    void *pData;
    int iW;
    int iH;
    int iType;
}MMJ_Img;

//坐标点数据结构
typedef struct MMJ_POINT
{
    int x;
    int y;
}MMJ_Pt;

/*
 MMJ_GetSuctionSidePointByLsd:吸边算法，根据lsd查找直线组合成不规则四边形
 pImgSrc:原始图像
 pt[4]:四边形四个顶点，顶点顺序：pt[0]-左上，pt[1]-右上，pt[2]-左下，pt[3]-右下
 return:0-表示错误，1表示成功找到，2表示太近提示拿远，3表示太远提示靠近
 */
int MMJ_GetSuctionSidePointByLsd(MMJ_Img *pImgSrc, MMJ_Pt pt[4]);

///*
// MMJ_GetPerspectiveImg:获取透视变换后的图像
// pImgSrcDst:图像原图，结果图
// ptSrc[4]:确定透视变换范围的四个点
// return:0-正确，其余为错误代码
// */
//int MMJ_GetPerspectiveImg(MMJ_Img *pImgSrcDst, MMJ_Pt ptSrc[4]);

/*
GetPerspectiveImgN:获取透视变换后的图像
pImgSrcDst:图像原图，结果图
ptSrc[4]:确定透视变换范围的四个点
return:新的透视变换图像
*/
MMJ_Img *MMJ_GetPerspectiveImg(MMJ_Img *pImgSrc, MMJ_Pt ptSrc[4]);

/*
 FreeMMJImg：图像内存释放
 */
void FreeMMJImg(MMJ_Img **pImgSrc);

//扫描王滤镜类型
typedef enum MMJ_SCAN_FILTER_TYPE
{
    MMJ_BRIGHTENUP = 0,         //增亮
    MMJ_ENHANCESHARPEN = 1,     //增强并锐化
    MMJ_BLACKWHITEMODE = 2,     //黑白
    MMJ_GRAYMODEL = 3,          //灰度
    MMJ_SAVEINK = 4,            //省墨
}MMJ_ScanType;

/*
 MMJ_GetScanFilterImg:扫描王滤镜处理
 pImgSrc:源图像
 ScanType:滤镜类型
return:0-正确，其余为错误代码
 */
int MMJ_GetScanFilterImg(MMJ_Img *pImgSrcDst, int ScanType);

/*
 MMJ_SetScanImgAdjust:扫描王图像调整
 pImgSrcDst:处理源图像处理结果图像
 iB:亮度调整，【0，50，100】-->对应最小数值，初始数值，最大数值
 iC:对比度调整，【0，50，100】
 iD:细节调整，【0，100，100】
 返回值:0-正确，其余为错误代码
 */
int MMJ_SetScanImgAdjust(MMJ_Img *pImgSrcDst, int iB, int iC, int iD);

//喵喵机打印分辨率
typedef enum MMJ_PRINTER_DPI
{
    MMJ_DPI200 = 200,
    MMJ_DPI300 = 300,
}MMJ_PrinterDPI;

/*
 IsToPrintByFont:当前字体大小是否适合打印
 pImgSrc:文档识别二值图像
 DPI:打印机分辨率，DPI_200,DPI_300
 printW:打印机像素宽，p1输入384，p2输入576,c1输入1248
 iScale:大于0时，计算显示图像大小时，显示宽屏幕宽*1000/scale，高度同理，scale区间【1000，正无穷】；
        小于0时，返回值为scale的相反数，如果要切割，限定最大切割宽度=屏幕宽*1000/scale；
        等于0时，字号适合打印或无法判断字号大小。
 返回：0-正确，其余为错误代码
 */
int MMJ_IsToPrintByFont(MMJ_Img *pImgSrc, int DPI, int printW, int *iScale);


/*
 MMJ_GetfitHeightForTextImg：获取图像合适切割高度
 pImgSrc：原始图像，最好是二值图像
 iNewH：切割的最大高度
 iImgNum：切割后的块数
 return:切割对应的高度数组
 */
int *MMJ_GetfitHeightForTextImg(MMJ_Img *pImgSrc, int iNewH, int *iImgNum);
/*
 MMJ_GetFitHeightForTextImgArray：根据图像数组获取图像合适切割高度
 pImgSrcArray：原始图像数组，最好是二值图像
 iArrayNum:图像数组数量
 iNewH：切割的最大高度
 iImgNum：返回后图像数组数量
 return:分页后返回分页后图像数组
 */
MMJ_Img *MMJ_GetFitHeightForTextImgArray(MMJ_Img *pImgSrcArray, int iArrayNum, int iNewH, int *iImgNum);


/*
 MMJ_GetFitHeightImgForTextImg：切割合适图像并旋转90度
 pImgSrc：原始图像，最好是二值图像
 iNewH：切割的最大高度，切割高度不足之处补充空白
 iImgNum：切割后的图像数量(增加了一张图像数量)
 return:0-正确，其余为错误代码
 */
//int MMJ_GetFitHeightImgForTextImg(MMJ_Img *pImgSrcDst, int iNewH);
MMJ_Img *MMJ_GetFitHeightImgForTextImg(MMJ_Img *pImgSrcDst, int iNewH);

/*
 MMJ_GetFitWidthImgForTextImg：切割合适图像
 pImgSrc：原始图像，最好是二值图像
 iNewW：切割的最大宽度，切割宽度不足之处补充空白
 iImgNum：切割后的图像数量(增加了一张图像数量)
 return:0-正确，其余为错误代码
 */
//int MMJ_GetFitWidthImgForTextImg(MMJ_Img *pImgSrcDst, int iNewW);
MMJ_Img *MMJ_GetFitWidthImgForTextImg(MMJ_Img *pImgSrcDst, int iNewW);


typedef enum MMJ_DEL_TYPE
{
    MMJ_DELRED = 1,
    MMJ_DELBLUE = 2,
    MMJ_DELCOL = 4,
}MMJ_DelType;
/*
 MMJ_TextAdjust:页面功能整合
 pImgSrcDst：图像原图，rgb
 iThresh:文档二值化阈值，参考TextBinary
 iDelType：去红去蓝类型参数, 0-表示不去色，【1，4】对应去色
 return:0-正确，其余为错误代码
 */
int MMJ_TextAdjust(MMJ_Img *pImgSrcDst, int iThresh, int iDelType);

/*
 MMJ_TextBinary:文档二值化
 pImgSrcDst:传入图像，结果覆盖
 iThresh:【0，64】，0-自动计算阈值，其余为阈值
 return:0-正确，其余为错误代码
 */
int MMJ_TextBinary(MMJ_Img *pImgSrcDst, int iThresh);

//误差扩散，矩阵8,4,2,4,8,4,2,1,2,4,2,1
/*
 MMJ_ErrorDiffusionByInt：误差扩散
 pImgSrcDst:图像原图，结果覆盖
 return：0-正确，其余为错误代码
 */
int MMJ_ErrorDiffusionByShort(MMJ_Img *pImgSrcDst);

//误差扩散，矩阵8,4,2,4,8,4,2,1,2,4,2,1
/*
 MMJ_GrayScalePrinterByErrorDiffusion：基于误差扩散的灰阶打印算法
 pImgSrcDst:图像原图，结果覆盖
 iScale:灰阶阶数
 return：0-正确，其余为错误代码
 */
int MMJ_GrayScalePrinterByErrorDiffusion(MMJ_Img *pImgSrcDst, int iScale);
/*
 MMJ_PrinterImgBin：打印机图像二值化
 pImgSrcDst:传入图像，结果覆盖
 pPt:截图中图像的区域坐标，矩形区域四个坐标
 iPtNum:坐标个数，4的倍数
 iAlg:打印算法切换，0-当前算法v1，1-新算法v2
 返回值：0-正确，其余为错误代码
 */
int MMJ_PrinterImgBin(MMJ_Img *pImgSrcDst, MMJ_Pt *pPt, int iPtNum, int iAlg);

/*
MMJ_PrinterImgBinData：打印机图像二值化数据
pImgSrcDst:传入图像，结果覆盖
pPt:截图中图像的区域坐标，矩形区域四个坐标
iPtNum:坐标个数，4的倍数
iAlg:打印算法切换，0-当前算法v1，1-新算法v2，2-安卓特供rgb565特殊情况
iPrinterW:打印机宽度
iDataLen:打印机数据长度
 返回值：打印机数据
*/
unsigned char *MMJ_PrinterImgBinData(MMJ_Img *pImgSrcDst, MMJ_Pt *pPt, int iPtNum, int iAlg, int iPrinterW, int *iDataLen);

/*
MMJ_PrinterImgBinData：二值图像转打印机数据
pImgSrc:传入图像
iPrinterW:打印机宽度
iDataLen:打印机数据长度
 返回值：打印机数据
*/
unsigned char *MMJ_BinaryImgToPrinterData(MMJ_Img *pImgSrc, int iPrinterW, int *iDataLen);

//二值化类型
typedef enum MMJ_THRESHOLD_TYPE
{
    MMJ_THRESH_BINARY = 1,
    MMJ_THRESH_BINARY_INV = 2,
    MMJ_THRESH_OTSU = 4,
}MMJ_ThreshType;

/*
 MMJ_Threshold:二值化算法
 pImgSrcDst:灰度图像
 iThreshV:二值化阈值, [0,255]
 iMaxV:二值化最大值，最小值0，一般设为255，或1
 iThreshType:二值化方法类型，使用自动计算阈值方法，iThreshV值无效
 return:0-正确，其余为错误代码
 */
int MMJ_Threshold(MMJ_Img *pImgSrcDst, int iThreshV, int iMaxV, int iThreshType);

/*
 MMJ_WM_DataEncode:威码标签机压缩算法
 pImgSrcDst:二值化图像，数据覆盖
 iImgDataLenDst:压缩后返回的压缩数据长度
 return:0-正确，其余为错误代码
 */
int MMJ_WM_DataEncode(MMJ_Img *pImgSrcDst, int *iImgDataLenDst);

//喵喵机灰度滤镜
typedef enum MMJ_GRAY_FILTER
{
    MMJ_BLACKWHITE = 0, //黑白滤镜
    MMJ_HARDIMAGE = 1, // 硬像滤镜
    MMJ_MEDIUMGRAY = 2, //中灰滤镜
    MMJ_QUIETLYELEGANT = 3, //淡雅滤镜
    MMJ_FINEGRAIN = 4, //细粒滤镜
    MMJ_ACUTANCE = 5, //锐度滤镜
    MMJ_GRANULE = 6, // 颗粒滤镜
    MMJ_ARRANGEMENT = 7, //层次滤镜
}MMJ_GrayFilter;

/*
MMJ_ImgGrayFilter:图像灰度滤镜，HW8款手机滤镜
pImgSrcDst:彩色图像
iGrayFilterType:滤镜类型
return:0-正确，其余为错误代码
*/
int MMJ_ImgGrayFilter(MMJ_Img *pImgSrcDst, int iGrayFilterType);

//喵喵机特效滤镜
typedef enum MMJ_SPECIAL_EFFECTS_FILTER
{
    MMJ_WHITEBACKGROUND = 30,    //白底滤镜
    MMJ_KATONG = 31, //卡通滤镜
    MMJ_LINEDRAFT = 32, //线稿滤镜
}MMJ_SE_Filter;

/*
 MMJ_ImgSpecialEffectsFilter:图像特效滤镜
 pImgSrcDst:灰度图像
 iSEfilterType:滤镜类型
 return:0-正确， 其余为错误代码
 */
int MMJ_ImgSpecialEffectsFilter(MMJ_Img *pImgSrcDst, int iSEfilterType);

typedef enum MMJ_TEXT_FILTER
{
    MMJ_TEXTFILTER = 50, //文本滤镜
    MMJ_REVERSEDTEXTFILTER = 51, //反相文本滤镜
}MMJ_TextFilter;

/*
MMJ_ImgTextFilter:图像文本滤镜
pImgSrcDst:灰度图像
iTextFilterType:滤镜类型
return:0-正确， 其余为错误代码
*/
int MMJ_ImgTextFilter(MMJ_Img *pImgSrcDst, int iTextFilterType);

/*
MMJ_ImgResize:图像缩放
pImgSrc:原始图像
iNW:新宽度
iNH:新高度
return:新图像
*/
MMJ_Img *MMJ_ImgResize(MMJ_Img *pImgSrc, int iNW, int iNH);

/*
 MMJ_SetImgBCS:设置图像亮度对比度饱和度
 pImgSrcDst:图像数据
 iB:亮度[-100,100]
 iC:对比度[-100,100]
 iS:饱和度[-100,100]
 返回:0-正确，其余错误
 */
int MMJ_SetImgBCS(MMJ_Img *pImgSrcDst, int iB, int iC, int iS);

/*
 MMJ_ImgStitching:图像拼接
 pImgList:图像数组
 iImgNum:数组图像个数
 返回：拼接后图像
 */
MMJ_Img *MMJ_ImgStitching(MMJ_Img *pImgList, int iImgNum);

/*
MMJ_PointRotate:点旋转
pt:点坐标
iAngle:旋转角度【0，90，180，270】
*/
void MMJ_PointRotate(MMJ_Pt pt[4], int iAngle, int iw, int ih);

/*
MMJ_Color2Gray:图像灰度化，灰度化后的图像还是原来的数据类型
pImgSrcDst:原始图像，结果图像覆盖
 返回：0-正确，其余错误
*/
int MMJ_Color2Gray(MMJ_Img *pImgSrcDst);

#ifdef __cplusplus
}
#endif

#endif /* MMJ_ImgAlg_h */
