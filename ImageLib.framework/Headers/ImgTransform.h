//
//  ImgTransform.h
//  MMJ_alg_Demo
//
//  Created by hjx on 2019/10/31.
//  Copyright © 2019 hjx. All rights reserved.
//

#ifndef ImgTransform_h
#define ImgTransform_h

#ifdef __cplusplus
extern "C"
{
#endif
#include "ImgType.h"
    
    /*
     GetPerspectiveImg:获取透视变换后的图像
     pImgSrc:图像原图
     ptSrc[4]:确定透视变换范围的四个点
     return:返回透视变换后的图像
     */
    ImgStruct *GetPerspectiveImg(ImgStruct *pImgSrc, CPOINT ptSrc[4]);
    
    /*
     ImgRotateFull:图像旋转
     pImgSrc:待旋转的图像原图
     iAngle:旋转角度，0-360
     iRotateType: 0-返回原图大小， 1-返回图像保持原图所有内容，多余部分填充
     return:旋转后的图像
     */
//需要添加565
    ImgStruct *ImgRotateFull(ImgStruct *pImgSrc, int iAngle, int iRotateType);
    
    /*
     ImgRotate:图像旋转，90度，180度，270度
     pImgSrc:待旋转的图像原图
     iAngle:旋转角度，传入【0, 90，180， 270】
     return:旋转后的图像
     */
//需要添加565
    ImgStruct *ImgRotate(ImgStruct *pImgSrc, int iAngle);
    
    /*
     ImgResize:图像缩放
     pImgSrc:原始图像
     iNewWidth:缩放后图像的宽度
     iNewHeight:缩放后图像的高度
     return:缩放后的图像
     */
    ImgStruct *ImgResize(ImgStruct *pImgSrc, int iNewWidth, int iNewHeight);
    
    /*
     ImgFlip:图像翻转
     pImgSrc:待翻转的原始图像
     iHVFlipType:翻转类型，0-水平翻转，1-竖直翻转
     return:翻转后的图像
     */
//需要添加565
    ImgStruct *ImgFlip(ImgStruct *pImgSrc, int iHVFlipType);
    
    
    /*
     PointRotate:点旋转
     pt:点坐标
     iAngle:旋转角度【0，90，180，270】
     */
    void PointRotate(CPOINT pt[4], int iAngle, int iw, int ih);
    
#ifdef __cplusplus
}
#endif

#endif /* ImgTransform_h */
