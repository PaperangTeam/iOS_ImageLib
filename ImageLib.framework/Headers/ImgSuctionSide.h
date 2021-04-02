//
//  ImgSucitionSide.h
//  MMJ_alg_Demo
//
//  Created by hjx on 2019/10/31.
//  Copyright © 2019 hjx. All rights reserved.
//

#ifndef ImgSucitionSide_h
#define ImgSucitionSide_h

#ifdef __cplusplus
extern "C"
{
#endif
#include "ImgType.h"

    /*
     GetSuctionSidePointByLsd:吸边算法，根据lsd查找直线组合成不规则四边形
     pImgSrc:原始图像
     pt[4]:四边形四个顶点，顶点顺序：pt[0]-左上，pt[1]-右上，pt[2]-左下，pt[3]-右下
     return:0-找角点失败， 1-找到合适角点 提示保持稳定，2-无完整边缘线，提示离远点， 3-矩形框太小，提示靠近一点
     */
    int GetSuctionSidePointByLsd(ImgStruct *pImgSrc, CPOINT pt[4]);
#ifdef __cplusplus
}
#endif

#endif /* ImgSucitionSide_h */
