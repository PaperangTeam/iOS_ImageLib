//
//  ImgProc.h
//  MMJ_alg_Demo
//
//  Created by hjx on 2019/10/29.
//  Copyright © 2019 hjx. All rights reserved.
//

#ifndef ImgProc_h
#define ImgProc_h

#ifdef __cplusplus
extern "C"
{
#endif
    
#include "ImgType.h"

//二值化

//误差扩散，矩阵7,3,5,1
int ErrorDiffusion(ImgStruct *pImgSrcDst);
//误差扩散，矩阵8,4,2,4,8,4,2,1,2,4,2,1
int ErrorDiffusionByShort(ImgStruct *pImgSrcDst);


//二值化类型，二值化，反二值化，自动二值化
typedef enum ThresholdType
{
    THRESH_BINARY = 1,
    THRESH_BINARY_INV = 2,
    THRESH_OTSU = 4,
}THRESHOLDTYPE;
/*
 pImgSrcDst:灰度图像
 iThreshV:二值化阈值, [0,255]
 iMaxV:二值化最大值，最小值0，一般设为255，或1
 iType:二值化方法类型，使用计算阈值方法，iThreshV值无效
 */
int Threshold(ImgStruct *pImgSrcDst, int iThreshV, int iMaxV, int iType);

//灰度化，彩色图像转成灰度图像
int RGB2Gray(ImgStruct *pImgSrcDst);


//基础色彩处理函数
/*
 ImgNormalizeMaxMin:图像拉伸归一化，区间拉伸映射到[0, 255]
 pImgSrcDst:原始图像，结果覆盖
 iMinV:拉伸区间最小值
 iMaxV:拉伸区间最大值
 return:0-错误，1-正确
 */
int ImgNormalizeMaxMin(ImgStruct *pImgSrcDst, int iMinV, int iMaxV);

/*
 ImgBrightnessContrastOld:PS亮度对比度调整旧算法
 pImgSrcDst:原始图像，结果覆盖
 iB:亮度调整，区间【-100,100】 0表示不处理
 iC:对比度调整，区间【-100，100】 0表示不处理
 return:0-错误，1-正确
 */
int ImgBrightnessContrastOld(ImgStruct *pImgSrcDst, int iB, int iC);

/*
 ImgBrightnessContrastNew:PS亮度对比度调整新算法
 pImgSrcDst:原始图像，结果覆盖
 iB:亮度调整，区间【-150,150】 0表示不处理
 iC:对比度调整，区间【-50，100】 0表示不处理
 return:0-错误，1-正确
 */
int ImgBrightnessContrastNew(ImgStruct *pImgSrcDst, int iB, int iC);


/*
 ImgColorGradation:ps的色阶功能
 pImgSrcDst:原始图像，结果覆盖
 iMinIn:最小输入阈值，【0，255】
 iMinIn:中间输入阈值，【1，999】
 iMaxIn:最大输入阈值，【0，255】
 iMinOut:最小输出阈值，【0，255】
 iMaxOut:最大输出阈值，【0，255】
 return:0-错误，1-正确
 */
int ImgColorGradation(ImgStruct *pImgSrcDst, int iMinIn, int iMidIn, int iMaxIn, int iMinOut, int iMaxOut);

//饱和度设置[-100, 100]
int SetImgSaturation(ImgStruct *pImgSrcDst, int iValue);

/*
 ImgCLAHE:图像CLAHE算法，限制对比度自适应直方图均衡
 pImgSrcDst:原始图像，结果覆盖
 cTileGridSize:直方图均衡的网格大小
 fClipLimit:对比度限制的剪辑限制阈值
 return:0-错误， 1-成功
 */
int ImgCLAHE(ImgStruct *pImgSrcDst, CSIZE cTileGridSize, float fClipLimit);


//模糊锐化

/*
ImgBlur:均值平滑
pImgSrc:原始图像
iRadius:半径
return:0-错误， 1-成功
*/
int ImgBlur(ImgStruct *pImgSrcDst, int iRadius);

/*
 ImgGaussianBlur:高斯模糊
pImgSrc:原始图像
iRadius:半径
return:0-错误， 1-成功
*/
int ImgGaussianBlur(ImgStruct *pImgSrcDst, int iRadius);


/*
 ImgDivide:图像除法，dst = src1 * iscale / src2
 pImgSrc1:原始图像，除数
 pImgSrc2:原始图像，被除数
 iScale:乘数因子，【0，255】
 return:结果图像，商
 */
ImgStruct *ImgDivide(ImgStruct *pImgSrc1, ImgStruct *pImgSrc2, int iScale);

/*
 ImgDilate:图像膨胀，同ps滤镜其他最大值
 pImgSrc:原始图像
 iRadius:半径
 return:膨胀后图像
 */
ImgStruct *ImgDilate(ImgStruct *pImgSrc, int iRadius);

/*
 ImgErode:图像腐蚀，同ps滤镜其他最小值
 pImgSrc:原始图像
 iRadius:半径
 return:腐蚀后图像
 */
ImgStruct *ImgErode(ImgStruct *pImgSrc, int iRadius);

/*
 ImgMin:两张图像合并像素取小, 图像大小尺寸一致
 pImgSrc1:原始图像1
 pImgSrc2:原始图像2
 return:图像取小合并图
 */
ImgStruct *ImgMin(ImgStruct *pImgSrc1, ImgStruct *pImgSrc2);

/*
 ImgMin:两张图像合并像素取大
 pImgSrc1:原始图像1
 pImgSrc2:原始图像2
 return:图像取大合并图
 */
ImgStruct *ImgMax(ImgStruct *pImgSrc1, ImgStruct *pImgSrc2);

//连通类型，四连通，八连通
typedef enum
{
    connect_4 = 0,
    connect_8
}CONNECTTYPE;
/*
 FindImgConComs:查找图像的连通域，传入二值图像
 pImgData:二值图像数据
 iWidth:图像宽度
 iHeight:图像高度
 type:连通域类型
 return:返回值，图像的连通域
 */
IMGCONCOMS *FindImgConComs(unsigned char *pImgData, int iWidth, int iHeight, int type);

/*
 FreeImgConComs:释放图像连通域内存
 pImgConComs:待释放的连通域
 */
void FreeImgConComs(IMGCONCOMS **pImgConComs);

/*
 RemoveConComFromImg:移除某个连通域数据
 pConCom:待移除的连通域
 pImgData:原始图像数据
 iWidth:图像宽度
 */
void RemoveConComFromImg(CONCOM *pConCom, unsigned char *pImgData, int iWidth);


#ifdef __cplusplus
}
#endif

#endif /* ImgProc_h */
