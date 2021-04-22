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

+ (UIImage *)imageAutoBinaryzation:(UIImage *)image withPoints:(NSArray *)points;
+ (UIImage *)imageTextBinary:(UIImage *)image changeImgSize:(BOOL)change;
+ (UIImage *)imageWithPrinterImgBin:(UIImage *)image withPoints:(NSArray *)points;

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

@end
