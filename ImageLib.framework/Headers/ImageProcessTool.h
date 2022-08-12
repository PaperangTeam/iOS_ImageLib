//
//  ImageProcessTool.h
//  ImglibTool
//
//  Created by 李育洋 on 2017/8/21.
//  Copyright © 2017年 walktewy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MMJ_ImgAlg.h"

NS_ASSUME_NONNULL_BEGIN
@interface ImageProcessTool : NSObject

#pragma mark - 滤镜
+ (UIImage *)image:(UIImage *)image addHWFilterType:(int)filter;
+ (UIImage *)image:(UIImage *)image addSpecialFilterType:(int)filter;
+ (UIImage *)image:(UIImage *)image addTextFilterType:(int)filter;
/**
 获得灰度图片

 @param image image description
 @return return value description
 */
+ (UIImage *)getGrayImageWithImage:(UIImage *)image;

//获得灰阶图片
+ (UIImage *)getGrayScaleImageWithImage:(UIImage *)image;

/// 获取纯文本处理后的图片
+ (UIImage *)getMonoWithImage:(UIImage *)image;

#pragma mark - 调整
/**
 设置颜色，对比度，亮度，二值阈值

 @param rgbImage 图片
 @param thresh 二值阈值
 @param delType 去除颜色类型，同上
 @return image
 */

+ (UIImage *)getImageWithRGBImage:(UIImage *)rgbImage
                           thresh:(int)thresh
                          delType:(int)delType;

/// bcs调整
/// @param image 原图
/// @param brightness 亮度 -100~100
/// @param contrast 对比度 -100~100
/// @param saturate 饱和度 -100~100
+ (UIImage *)getImageBCS:(UIImage *)image brightness:(int)brightness contrast:(int)contrast saturate:(int)saturate;

/**
 判断图片中的文字是否过小 参数参考MMJ_IsToPrintByFont
 @param image image description
 @return return value description
 */
+ (int)getFontSizeRatioEnableWithImage:(UIImage *)image dpi:(MMJ_PrinterDPI)dpi printW:(int)printW;

/**
 获得切割后的图片，用于搜题横向排版

 @param image image description
 @return return value description
 */
+ (UIImage*)getFitHeightImagesWithImage:(UIImage*)image
                              maxHeight:(CGFloat)maxHeight;

/// 获得固定高度的图片数组(不切掉文本)
/// @param iNewH 固定高度
/// @param originImages 原始图片数组
+ (NSArray<UIImage *> *)getFitImagesWithHeight:(NSInteger)iNewH
                                  originImages:(NSArray<UIImage *> *)originImages;

+ (UIImage *)imageAutoBinaryzation:(UIImage *)image withPoints:(NSArray * _Nullable)points;
+ (UIImage *)imageTextBinary:(UIImage *)image changeImgSize:(BOOL)change;
+ (UIImage *)imageWithPrinterImgBin:(UIImage *)image withPoints:(NSArray *)points;
+ (UIImage *)imageWithPrintImgBin:(UIImage *)image flag:(int *)flag;

#pragma mark - Scan

/**
 扫描王滤镜

 @param image 原图
 @param type 滤镜
 @return 结果
 */
+ (UIImage *)getScanFilterImg:(UIImage *)image type:(MMJ_ScanType)type;
+ (UIImage *)getScanAdjustImg:(UIImage *)rgbImage brightness:(int)brightness contrast:(int)contrast detail:(int)detail;

/**找边框**/
+ (NSArray <NSValue *>*)findNewEdge:(UIImage *)image;
+ (NSArray <NSValue *>*)revertPoint:(UIImage *)image oldPoint:(NSArray *)oldPoint angle:(int)angle fromServer:(BOOL)fromServer;

/**
 获取

 @param image 原图
 @param points 四个切割点
 @return 矫正后图形
 */
+ (UIImage *)getPerspectiveImg:(UIImage *)image points:(NSArray <NSValue *>*)points;

#pragma mark - private method

/**
 是否全白

 @param image image description
 @return return value description
 */
+ (BOOL)isAllWhite:(UIImage *)image;

/// 喵喵机图片改变尺寸
/// @param size 新的尺寸
/// @param oldImage 原图
+ (UIImage *)scaleSize:(CGSize)size oldImage:(UIImage *)oldImage;

+ (void)freeSth;

/// 获取打印数据（F1）
/// @param image 图片
/// @param packageSize 包大小
/// @param paperWidth 宽
/// @param iBinType 处理类型
/// @param needBinaryzation 是否要二值化
+ (NSData *)getA4PrintData:(UIImage *)image
               packageSize:(int)packageSize
                paperWidth:(CGFloat)paperWidth
                  iBinType:(NSInteger)iBinType
          needBinaryzation:(BOOL)needBinaryzation;

//        A4纸宽度为21.0cm，长度为29.7cm
//        限制上下左右留白为1.27cm，则画布宽18.46cm，长27.16cm
/// 获取A4打印图片
/// @param images 原图
/// @param addInsets 是否加边距
+ (NSArray<UIImage *>*)getA4Images:(NSArray<UIImage *>*)images
                         addInsets: (BOOL)addInsets
               isWidthPaddingPercent:(BOOL)isWidthPaddingPercent
            regularPaperContinuity: (BOOL)regularPaperContinuity;

+ (CGSize)getA4ContentImageSize: (CGSize)imageSize
                      addInsets: (BOOL)addInsets
          isWidthPaddingPercent:(BOOL)isWidthPaddingPercent
         regularPaperContinuity: (BOOL)regularPaperContinuity;

+ (UIImage *)getA4ImageFromData:(NSData *)data;
+ (UIImage *)getA4ImageFromUrl:(NSURL *)url;


//MMJ_BLACKWHITE,黑白滤镜
+ (NSArray <UIImage *>*)getFilterImagesWithImages:(NSArray *)images
                                           filter:(int)filter;

+ (NSArray <NSValue *>* _Nullable)findNewEdgePaperClip:(UIImage *)image;
+ (NSArray <NSArray <NSValue *> *> * _Nullable)findBookNewEdge:(UIImage *)image;
+ (NSArray <UIImage *>*)getAutoBinaryzationImagesWithImages:(NSArray *)images;

/// 误差扩散
/// @param image 图片
/// @param luminance 是否预处理
+ (UIImage *)errorDiffusionByShortWithImage:(UIImage *_Nullable)image
                                  luminance:(BOOL) luminance;
@end

NS_ASSUME_NONNULL_END
