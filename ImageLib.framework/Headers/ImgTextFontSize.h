//
//  ImgTextFontSize.h
//  MMJ_alg_Demo
//
//  Created by hjx on 2019/10/31.
//  Copyright © 2019 hjx. All rights reserved.
//

#ifndef ImgTextFontSize_h
#define ImgTextFontSize_h

#ifdef __cplusplus
extern "C"
{
#endif
    
#include "ImgType.h"
    
    /*
     GetFontSize:获取图片中文字字号大小
     pImgSrc:原图,rgb,rgba,gray,bin，当前版本针对服务器的二值图
     返回：0-失败，n-字体像素大小
     */
    int GetFontSize(ImgStruct *pImgSrc);
    
    typedef enum
    {
        DPI_200 = 0,
        DPI_300,
    }PRINTERDPI;
    
    /*
     IsToPrintByFont:当前字体大小是否适合打印
     pImgSrc:文档识别二值图像
     DPI:打印机分辨率，DPI_200,DPI_300
     printW:打印机像素宽，p1输入384，p2输入576,c4输入1248
     返回：<0-字号偏小不适合打印，1-字号适合打印，>1,屏幕宽：显示图像宽 * 1000,=0,无法判断字号大小
     >1时，返回值为scale，计算显示图像大小时，显示宽 = 屏幕宽*1000/scale，高度同理，scale区间【1000，正无穷】
     <0时，返回值为scale的相反数，如果要切割，限定最大切割宽度=屏幕宽*1000/scale。
     */
    int IsToPrintByFont(ImgStruct *pImgSrc, int DPI, int printW);
   
#ifdef __cplusplus
}
#endif

#endif /* ImgTextFontSize_h */
