//
//  ImgOCRProc.h
//  MMJ_alg_Demo
//
//  Created by hjx on 2019/10/31.
//  Copyright © 2019 hjx. All rights reserved.
//

#ifndef ImgOCRProc_h
#define ImgOCRProc_h


#ifdef __cplusplus
extern "C"
{
#endif

#include "ImgType.h"
    typedef enum
    {
        DELRED = 1,
        DELBLUE= 2,
        DELCOL = 4,
    }DELTYPE;
    
    /*
     去红去蓝功能v1
     pImgText:文档二值化图像,结果覆盖
     pImgColor:rgb图像
     type:去红去蓝选项
     返回：1-ok,0-error
     */

    int TextDelRedBlue(ImgStruct *pImgText, ImgStruct *pImgColor, int type);

    /*
     页面功能整合
     pImgSrc：图像原图，rgb
     iBrightness:亮度
     iContrast:对比度
     iThresh:文档二值化阈值，参考TextBinary1
     iDelType：去红去蓝类型参数
     */
    ImgStruct *TextAdjust(ImgStruct *pImgSrc, int iBrightness, int iContrast, int iThresh, int iDelType);
    
    
    /*
     TextBinary:文档二值化
     pImgSrcDst:传入图像，结果覆盖
     return:0-错误，1-正确
     */
    int TextBinary(ImgStruct *pImgSrcDst, int iThresh);


#ifdef __cplusplus
}
#endif

#endif /* ImgOCRProc_h */
