//
//  cpstool.h
//  Paperang
//
//  Created by hoho on 24/03/2018.
//  Copyright © 2018 Hoho. All rights reserved.
//

#ifndef cpstool_h
#define cpstool_h

//#include "minilzo.h"


#ifdef __cplusplus
extern "C" {

#endif
    
#define byte unsigned char
int mm_compress(void *src, unsigned src_len, void *dst);
int mm_decompress(void *src, unsigned src_len, void *dst);
#ifdef __cplusplus
}
#endif
#endif /* cpstool_h */
