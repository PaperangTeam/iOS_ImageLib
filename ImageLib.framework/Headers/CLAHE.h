//
//  CLAHE.h
//  MMJ_alg_Demo
//
//  Created by hjx on 2019/10/29.
//  Copyright © 2019 hjx. All rights reserved.
//

#ifndef CLAHE_h
#define CLAHE_h

#ifdef __cplusplus
extern "C"
{
#endif

#define BYTE_IMAGE
    
#ifdef BYTE_IMAGE
    typedef unsigned char DATA_TYPE;
#define uiNR_OF_GREY (256)
#else
    typedef unsigned short DATA_TYPE;
# define uiNR_OF_GREY (65536)//(4096)
#endif
    //65536

int CLAHE_Data(DATA_TYPE* pImage, unsigned int uiXRes, unsigned int uiYRes, DATA_TYPE Min,
          DATA_TYPE Max, unsigned int uiNrX, unsigned int uiNrY,
          unsigned int uiNrBins, float fCliplimit);

    
#ifdef __cplusplus
}
#endif

#endif /* CLAHE_h */
