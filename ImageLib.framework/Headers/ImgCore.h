//
//  ImgCore.h
//  MMJ_alg_Demo
//
//  Created by hjx on 2019/10/29.
//  Copyright © 2019 hjx. All rights reserved.
//

#ifndef ImgCore_h
#define ImgCore_h


#ifdef __cplusplus
extern "C"
{
#endif
    
#include "ImgType.h"

//复制图像
ImgStruct *ImgStructClone(ImgStruct *pImgSrc);

//创建图像
ImgStruct *CreateImg(int iW, int iH, int iChannels, int type, unsigned char data);

//图像反相
int ImgReverse(ImgStruct *pImgSrcDst);

//图像是否大小类型一致
int IsImgEqual(ImgStruct *pImgSrc1, ImgStruct *pImgSrc2);


//获取最大最小值
void GetImgMinMax(ImgStruct *pImgSrc, unsigned char *minV, unsigned char *maxV);

//图像交换
void ImgSwop(ImgStruct *pimgSrc1, ImgStruct *pimgSrc2);

//释放图像内存
void FreeImg(ImgStruct **pImgSrcDst);

//基础算法，最大最小
#define MMAX(a, b) (((a) > (b))?(a):(b))
#define MMIN(a, b) (((a) < (b))?(a):(b))
#define ClampToByte(a) MMIN(255, MMAX(0, (a)))


#define type3

#ifdef type1//丢失低位
#define RGB565TORGB_R(a) (((a) >> 8) & 0xf8)
#define RGB565TORGB_G(a) (((a) >> 3) & 0xfc)
#define RGB565TORGB_B(a) (((a) << 3) & 0xf8)
#endif

#ifdef type2//低位填充
#define RGB565TORGB_R(a) ( (( (a) >> 8) & 0xf8) | (((a) >> 11) & 0x7) )
#define RGB565TORGB_G(a) ( (( (a) >> 3) & 0xfc) | (((a) >> 5) & 0x3) )
#define RGB565TORGB_B(a) ( (( (a) << 3) & 0xf8) | ((a) & 0x7) )
#endif

#ifdef type3//拉伸映射
#define RGB565TORGB_R(a) ((((a) >> 8) & 0xf8) * 0xff / 0xf8)
#define RGB565TORGB_G(a) ((((a) >> 3) & 0xfc) * 0xff / 0xfc)
#define RGB565TORGB_B(a) ((((a) << 3) & 0xf8) * 0xff / 0xf8)
#endif

#define RGBTORGB565(r, g, b) ( ((r << 8) & 0xf800) | ((g << 3) & 0x07e0) | ((b >> 3) & 0x001f) )


#ifdef __cplusplus
}
#endif

#endif /* ImgCore_h */
