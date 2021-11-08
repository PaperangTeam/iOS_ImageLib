//
//  mbPrintProtocol.h
//  RenderEngine
//
//  Created by paperang on 2021/11/2.
//  Copyright © 2021 hjx. All rights reserved.
//

#ifndef mbPrintProtocol_h
#define mbPrintProtocol_h

#ifdef __cplusplus
extern "C"
{
#endif

int mbSetPrintStart(unsigned char *pDataSrcDst);
int mbSetPrintEnd(unsigned char *pDataSrcDst);
int mbSetPrintHfmTree(unsigned char *pDataDst, unsigned char *pHfmTreePre, unsigned char *pHfmTreeMid, int iTreeLen);
int mbSetPrintData(unsigned char *pDataDst, unsigned char *pDataSrc, int iDataLen, int iPrintW, int iIsHfm);

int mbGetPrintStart(unsigned char *pDataSrc, int iDataLen);
int mbGetPrintEnd(unsigned char *pDataSrc, int iDataLen);
int mbGetPrintHfmTree(unsigned char *pDataSrc, int iDataLen, unsigned char *pHfmTreePre, unsigned char *pHfmTreeMid, int *iTreeLen);
int mbGetPrintData(unsigned char *pDataSrc, int iDataLen, unsigned char *pDataDst, int *iDstLen, int *iPrintW);
#ifdef __cplusplus
}
#endif

#endif /* mbPrintProtocol_h */
