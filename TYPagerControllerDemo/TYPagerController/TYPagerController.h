//
//  TYPagerController.h
//  TYPagerControllerDemo
//
//  Created by tanyang on 16/4/13.
//  Copyright © 2016年 tanyang. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TYPagerController;
@protocol TYPagerControllerDataSource <NSObject>

- (NSInteger)numberOfControllersInPagerController;

- (UIViewController *)pagerController:(TYPagerController *)pagerController controllerForIndex:(NSInteger)index;

@optional

- (NSString *)pagerController:(TYPagerController *)pagerController titleForIndex:(NSInteger)index;

@end

@protocol TYPagerControllerDelegate <NSObject>

@optional

- (void)pagerController:(TYPagerController *)pagerController transitionFromIndex:(NSInteger)formIndex toIndex:(NSInteger)toIndex animated:(BOOL)animated;

- (void)pagerController:(TYPagerController *)pagerController transitionFromIndex:(NSInteger)formIndex toIndex:(NSInteger)toIndex progress:(CGFloat)progress;

@end

@interface TYPagerController : UIViewController

@property (nonatomic, weak, readonly) UIScrollView *contentView; // don‘t change the frame

@property (nonatomic, weak) id<TYPagerControllerDataSource> dataSource;
@property (nonatomic, weak) id<TYPagerControllerDelegate>   delegate;

@property (nonatomic, strong, readonly) NSCache *memoryCache;

@property (nonatomic, assign, readonly) NSInteger curIndex;

@property (nonatomic, assign, readonly) NSRange visibleRange;

@property (nonatomic, assign) CGFloat contentTopEdging; // contentView top edge

@property (nonatomic, assign) CGFloat changeIndexWhenScrollProgress; // default 1.0

- (void)reloadData;

// override must call super
- (void)updateContentView;

- (void)moveToControllerAtIndex:(NSInteger)index animated:(BOOL)animated;

- (NSArray *)visibleViewControllers;

- (BOOL)isProgressScrollEnabel;

@end

@interface TYPagerController (TransitionOverride)

// override

- (void)transitionFromIndex:(NSInteger)fromIndex toIndex:(NSInteger)toIndex animated:(BOOL)animated;

- (void)transitionFromIndex:(NSInteger)fromIndex toIndex:(NSInteger)toIndex progress:(CGFloat)progress;

@end
