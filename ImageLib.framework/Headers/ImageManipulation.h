//
//  ImageManipulation.h
//  QXDrawBoard
//
//  Created by hoho on 15/10/28.
//  Copyright © 2015年 Chiu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, EFilterType) {
    EFilterNull,//默认效果
    EFilterSketch,//素描效果
    EFilterEdge,//描边效果
    EFilterNeon,//反色效果
    EFilterThreshold,//喷墨效果
    EFilterTypeAll
};


@interface ImageManipulation : NSObject

@property (strong, nonatomic) UIImage *lastImage;

/// 图片转灰度
+ (UIImage *)manipulationWithImage:(UIImage *)originalImage;
+ (UIImage *)manipulationWithImage:(UIImage *)originalImage width:(NSInteger)width;
+ (UIImage *)manipulationWithImage:(UIImage *)originalImage
                             width:(NSInteger)width
                        withPoints:(NSArray *)points;
+ (UIImage *)getGrayScaleImageWithImage:(UIImage *)image width:(NSInteger)width;
+ (UIImage *)manipulationWithImage:(UIImage *)originalImage andFilter:(NSInteger)type;
+ (UIImage *)dealWithImageForText:(UIImage *)originalImage;

+ (NSData *)printImage:(UIImage *)image;

/// 图片转NSData
+ (NSData *)dataWithManipulatedImage:(UIImage *)image;

/// 纯文本打印处理
+ (NSData *)generateMonoData:(UIImage *)sourceBitmap compressMode:(int)compressMode;
+ (NSData *)generateGrayScaleData:(UIImage *)image;

- (UIImage *)createBmpImg:(UInt32 *)ditherData with:(int)width and:(int)height;

@end
