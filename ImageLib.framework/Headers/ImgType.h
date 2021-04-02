//
//  ImgType.h
//  MMJ_alg_Demo
//
//  Created by hjx on 2019/10/29.
//  Copyright © 2019 hjx. All rights reserved.
//

#ifndef ImgType_h
#define ImgType_h

#ifdef __cplusplus
extern "C"
{
#endif

//图像类型
typedef enum
{
    CV_GRAY = 0,
    CV_BIN,
    CV_RGB,
    CV_ARGB,
    CV_RGBA,
    CV_ABGR,
    CV_BGRA,
    CV_RGB565,
    CV_CMY,
    CV_CMYK,
    CV_YUV,
}ImgType;

//图像数据结构
typedef struct IMGSTRUCT
{
    unsigned char *pData;
    int iWidth;
    int iHeight;
    int iChannels;
    ImgType eType;
}ImgStruct;

//点数据结构
typedef struct
{
    int x;
    int y;
}CPOINT;

//直线数据结构
typedef struct
{
    CPOINT cStartPt;
    CPOINT cEndPt;
}CLine;

//颜色数据结构，Gray_A为单通道灰度和四通道A通道共用
typedef struct
{
    unsigned char R;
    unsigned char G;
    unsigned char B;
    unsigned char Gray_A;
}CCOLOR;

//直线点集
typedef struct LISTPT
{
    CPOINT cPt;
    struct LISTPT *pNext;
}CPtList;


//矩形数据结构
typedef struct
{
    int iW;
    int iH;
    int iArea;
    int iMinX;
    int iMinY;
    int iMaxX;
    int iMaxY;
}CRect;

//矩形宽高数据结构
typedef struct
{
    int iWidth;
    int iHeight;
}CSIZE;

//最小外接矩阵数据结构
typedef struct
{
    CPOINT pt[4];
    int iArea;
    int iW;
    int iH;
}CRotatedRect;

//连通域的数据结构
typedef struct connected_component_struct
{
    int iPixelsCnt;
    int iMinX, iMaxX;
    int iMinY, iMaxY;
    int iWidth, iHeight;
    int iArea;
    CPOINT *pPixelsPoint;
    unsigned char ucRemovedFlag;
    unsigned char ucFlag;
}CONCOM;

//整个图像的连通域数据结构
typedef struct image_connected_components_struct
{
    int  iConComCnt;
    CONCOM *pConComs;
    CPOINT *pAllPixelsPoint;
}IMGCONCOMS;

//范围数据结构
typedef struct
{
    int iStart;
    int iEnd;
}CRange;

#ifdef __cplusplus
}
#endif

#endif /* ImgType_h */
