//
//  HFMcoding.h
//  MMJ_alg_Demo
//
//  Created by hjx on 2019/1/23.
//  Copyright © 2019 hjx. All rights reserved.
//

#ifndef HFMcoding_h
#define HFMcoding_h

#ifdef __cplusplus
extern "C"
{
#endif

    //哈夫曼树数据结构，
    typedef struct HGMRNCODENODE
    {
        int iweight;                        //权重
        int lchild, rchild, parent;         //左分支，右分支，父节点
        int icodecnt;                       //编码长度
        unsigned short cname;               //节点名，极限范围【0-512】
        unsigned char code[256];            //哈夫曼树编码
    }HFM_Encode_Node;
    
    /*
     GetHfmTree : 图像数据生成哈夫曼树
     pDataSrc : 传入数据
     iLenSrc : 数据长度
     iLenTree : 生成的哈夫曼树节点数
     iLossNum : 传入0表示无损压缩，传入1表示有损压缩，传入2表示自动判断无损压缩率超过60%的话进行有损压缩
     isRowCheck:是否进行行校验，0表示第一个字节不是行校验，每行156个字节，1表示每行第一个字节是行校验，每行157个字节
     返回值 : 哈夫曼树
     */
    HFM_Encode_Node *GetHfmTree(unsigned char *pDataSrc, int iLenSrc, int *iLenTree, int iLossNum, int isRowCheck);
    
    /*
     HFMencoding : 哈夫曼编码，整个数据包编码
     hfmTree : 哈夫曼树
     iLenTree : 哈夫曼树节点数
     pDataSrc : 原始数据
     iLenSrc : 数据长度
     iLenDst : 编码进行字节压缩的数据长度
     返回值 : 对数据重新压缩编码并进行字节压缩后的数据
     */
    unsigned char *HFMencoding(HFM_Encode_Node *hfmTree, int iLenTree, unsigned char *pDataSrc, int iLenSrc, int *iLenDst);
    
    //发送的数据包数据结构
    typedef struct DATABAG
    {
        unsigned char *pData;   //数据
        int iLen;               //数据长度
    }DataBag;
    
    /*
     HFMDGencoding : 根据数据包发送量限制，自动进行哈夫曼编码数据分包
     hfmTree : 哈夫曼树
     iLenTree : 哈夫曼树节点数
     pDataSrc : 原始数据
     iw : 数据宽度, (图像宽度/8+1)，新协议多一个行校验码
     ih : 数据高度, (iw * ih = 传入数据长度）
     iMinLen : 最小允许发送的数据包字节数，单纯数据，不包括协议间的数据格式之类的数据
     iLenDst : 返回的数据包数量
     返回值 : 分包后的，数据重新压缩编码并进行字节压缩后的数据包
     */
    DataBag *HFMDGencoding(HFM_Encode_Node *hfmTree, int iLenTree, unsigned char *pDataSrc, int iw, int ih, int iMinLen, int *iLenDst);
    /*
     释放数据包，因为内部实现涉及数据内存共用，释放必须使用此函数，避免内存泄露。
     */
    void FreeSendDataBag(DataBag *pSrc);
    
    /*
     GetTreePreorder : 获取哈夫曼树的前序遍历数据
     hfmTree : 哈夫曼树
     iLenTree : 哈夫曼树节点数
     返回值 : 前序排列节点名数据，数据长度为节点数
     */
    unsigned short *GetTreePreorder(HFM_Encode_Node *hfmTree, int iLenTree);
    /*
     GetTreePreorder : 获取哈夫曼树的中序遍历数据
     hfmTree : 哈夫曼树
     iLenTree : 哈夫曼树节点数
     返回值 : 中序排列节点名数据，数据长度为节点数
     */
    unsigned short *GetTreeMiddleorder(HFM_Encode_Node *hfmTree, int iLenTree);
    
    //哈夫曼解码数据结构
    typedef struct HFMDECODENODE
    {
        int lchild, rchild;     //左树，右树
        unsigned short cname;   //节点名
    }HFM_Decode_Node;
    
    /*
     MakeHfmTree : 根据二叉树的前序排列和中序排列生成哈夫曼树
     pPreorder : 前序排列节点数据
     ipreLen : 前序排列节点数据长度
     pMiddleorder : 中序排列节点数据
     imidLen : 中序排列数据长度
     返回值 : 哈夫曼解码二叉树
     */
    HFM_Decode_Node *MakeHfmTree(unsigned short *pPreorder, int ipreLen, unsigned short *pMiddleorder, int imidLen);
//    int MakeHfmTree(HFM_Decode_Node *pHfmTree, unsigned char *pPreMiddleData, int iDataLen);
    
    /*
     HFMdecoding : 哈夫曼解码
     hfmTree : 哈夫曼解码树
     pDataSrc : 待解码的数据
     iLenSrc : 待解码数据长度
     iLenDst : 解码后的数据长度
     返回值 : 哈夫曼树解码数据
     */
    unsigned char *HFMdecoding(HFM_Decode_Node *hfmTree, unsigned char *pDataSrc, int iLenSrc, int *iLenDst);
//    int HFMdecoding(HFM_Decode_Node *hfmTree, unsigned char *pDataDst, unsigned char *pDataSrc, int iLenSrc);
    
#ifdef __cplusplus
}
#endif


#endif /* HFMcoding_h */
