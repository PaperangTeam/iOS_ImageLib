//
//  ImgScanner.h
//  MMJ_alg_Demo
//
//  Created by hjx on 2019/10/31.
//  Copyright © 2019 hjx. All rights reserved.
//

#ifndef ImgScanner_h
#define ImgScanner_h

#ifdef __cplusplus
extern "C"
{
#endif
#include "ImgType.h"
    
    typedef enum
    {
        BRIGHTENUP = 0,       //增亮
        ENHANCESHARPEN,       //增强并锐化
        BLACKWHITEMODE,     //黑白
        GRAYMODEL,          //灰度
        SAVEINK,           //省墨
    }SCANFILTERTYPE;
    
    /*
     GetScanFilterImg:扫描王滤镜处理
     pImgSrcDst:源图像,结果图像覆盖
     filterType:滤镜类型
     返回：1-ok,0-error
     */
    int GetScanFilterImg(ImgStruct *pImgSrcDst, int filterType);
    
    /*
     SetScanImgAdjust:扫描王图像调整
     pImgSrcDst:处理源图像处理结果图像
     iB:亮度调整，【0，50，100】
     iC:对比度调整，【0，50，100】
     iD:细节调整，【0，100，100】
     返回值:1-正确，0-错误
     */
    int SetScanImgAdjust(ImgStruct *pImgSrcDst, int iB, int iC, int iD);
    
    
#ifdef __cplusplus
}
#endif

#endif /* ImgScanner_h */
