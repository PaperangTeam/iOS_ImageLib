//
//  WM_DataEncode.h
//  MMJ_alg_Demo
//
//  Created by hjx on 2019/8/15.
//  Copyright © 2019 hjx. All rights reserved.
//

#ifndef WM_DataEncode_h
#define WM_DataEncode_h

#ifdef __cplusplus
extern "C"
{
#endif
    
    //威码标签机压缩算法
    // srclen = iw * ih.
    int WM_DataEncode(unsigned char *pDataSrcDst, int iW, int iH, int *iDstLen);
    
#ifdef __cplusplus
}
#endif

#endif /* WM_DataEncode_h */
