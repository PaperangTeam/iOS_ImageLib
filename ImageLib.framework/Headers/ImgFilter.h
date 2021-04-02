//
//  ImgFilter.h
//  MMJ_alg_Demo
//
//  Created by hjx on 2019/11/1.
//  Copyright © 2019 hjx. All rights reserved.
//

#ifndef ImgFilter_h
#define ImgFilter_h

#ifdef __cplusplus
extern "C"
{
#endif
    
#include "ImgType.h"

    typedef enum
    {
        TEXTFILTER = 0, //文本滤镜
        REVERSEDTEXTFILTER, //反相文本滤镜
        WHITEBACKGROUND,    //白底滤镜
        KATONG, //卡通滤镜
        LINEDRAFT, //线稿滤镜
        SHADOW,  //阴影滤镜
        BWPENCIL, //铅笔滤镜
        COLORPENCIL,  //彩铅滤镜
        BLACKWHITE, //黑白滤镜
        HARDIMAGE, // 硬像滤镜
        MEDIUMGRAY, //中灰滤镜
        QUIETLYELEGANT, //淡雅滤镜
        FINEGRAIN, //细粒滤镜
        ACUTANCE, //锐度滤镜
        GRANULE, // 颗粒滤镜
        ARRANGEMENT, //层次滤镜
    }GRAYFILTERTYPE;
    

    //动漫滤镜，用规律性线条点阵模拟图像
    ImgStruct *GetPicKaTong(ImgStruct *pImgSrc);
    
    //线稿图
     int GetPicLineDraft(ImgStruct *pImgSrcDst, int iRadius);
    
    //白底滤镜，将图片背景调整趋向白底。
    int GetPicWhiteBackground(ImgStruct *pImgSrcDst);
    
    //ps黑白滤镜算法
    int ImgBlackWhitePs(ImgStruct *pImgSrcDst, int iRed, int iYellow, int iGreen, int iCyan, int iBlue, int iMagenta);

    int ImgNoise(ImgStruct *pImgSrcDst, int iGrain);
    
#ifdef __cplusplus
}
#endif

#endif /* ImgFilter_h */
