//
//  ImgSuctionSideBook.h
//  MMJ_alg_Demo
//
//  Created by paperang on 2021/12/7.
//  Copyright © 2021 hjx. All rights reserved.
//

#ifndef ImgSuctionSideBook_h
#define ImgSuctionSideBook_h

#ifdef __cplusplus
extern "C"
{
#endif
#include "ImgType.h"


/*
 GetSuctionSidePointByLsdForBook：书本拍摄ab面吸边
 pImgSrc：书籍图片
 ptOut：ab面四个角点
 return：0-失败，1-成功
 */
int GetSuctionSidePointByLsdForBook(ImgStruct *pImgSrc, CPOINT ptOut[8]);

#ifdef __cplusplus
}
#endif
#endif /* ImgSuctionSideBook_h */
