//
//  ImgLineLSD.h
//  MMJ_alg_Demo
//
//  Created by hjx on 2019/10/31.
//  Copyright © 2019 hjx. All rights reserved.
//

#ifndef ImgLineLSD_h
#define ImgLineLSD_h

#ifdef __cplusplus
extern "C"
{
#endif
#include "ImgType.h"
    
    /*
     GetLines:直线检测
     imgSrc:灰度图像，最好先压缩到小图，可以提高速度
     pLines:检测的直线，限制数量1000，必须先申请好内存
     iLinesNum:直线实际数量
     return:0-错误，1-正确
     */
    int GetLines(ImgStruct *pImgSrc, CLine *pLines, int *iLinesNum);
    
#ifdef __cplusplus
}
#endif

#endif /* ImgLineLSD_h */
