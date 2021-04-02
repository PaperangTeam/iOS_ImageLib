//
//  ImgTextForCutting.h
//  MMJ_alg_Demo
//
//  Created by hjx on 2019/10/31.
//  Copyright © 2019 hjx. All rights reserved.
//

#ifndef ImgTextForCutting_h
#define ImgTextForCutting_h


#ifdef __cplusplus
extern "C"
{
#endif
#include "ImgType.h"
    
    /*
     GetFitHeightForTextImg：获取图像合适切割高度
     pImgSrc：原始图像，最好是二值图像
     iNewH：切割的最大高度
     iImgNum：切割后的块数
     返回值：切割对应的高度数组
     */
    int *GetFitHeightForTextImg(ImgStruct *pImgSrc, int iNewH, int *iImgNum);
    
    /*
     GetFitHeightImgForTextImg：切割合适图像并旋转90度
     pImgSrc：原始图像，最好是二值图像
     iNewH：切割的最大高度，切割高度不足之处补充空白
     iImgNum：切割后的图像数量(增加了一张图像数量)
     返回值：切割对应的图像数组，共用数据内存（第一张图像为切割后拼接全图数据，其余的为单张切割图像数据）
     */
    ImgStruct *GetFitHeightImgForTextImg(ImgStruct *pImgSrc, int iNewH, int *iImgNum);
    
    
    /*
     GetFitWidthImgForTextImg：切割合适图像
     pImgSrc：原始图像，最好是二值图像
     iNewW：切割的最大宽度，切割宽度不足之处补充空白
     iImgNum：切割后的图像数量(增加了一张图像数量)
     返回值：切割对应的图像数组，共用数据内存（第一张图像为切割后拼接全图数据，其余的为单张切割图像数据）
     */
    ImgStruct *GetFitWidthImgForTextImg(ImgStruct *pImgSrc, int iNewW, int *iImgNum);
    
    /*
     GetWidthByFontSize:获取切割宽度,错题本铺满字号偏小切割用
     iScreenW:屏幕宽度
     iImgW:图像宽度
     iFontScale:字号比例
     返回值:合适的切割宽度
     */
    int GetWidthByFontSize(int iScreenW, int iImgW, int iFontScale);
    
    /*
     FreeTextImgs:释放图像数组，一定调用此函数释放，因为内存共用的关系，避免出现错误使用此函数。
     */
    void FreeTextImgs(ImgStruct **pImg);
    
#ifdef __cplusplus
}
#endif

#endif /* ImgTextForCutting_h */
