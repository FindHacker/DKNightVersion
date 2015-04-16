//
//  DKNightVersionManager.h
//  DKNightVersionManager
//
//  Created by apple on 4/14/15.
//  Copyright (c) 2015 DeltaX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UIView+NightVersion.h"

typedef enum : NSUInteger {
    DKThemeVersionNormal,
    DKThemeVersionNight,
} DKThemeVersion;

@interface DKNightVersionManager : NSObject

/**
 Set themeVersion to swich to night or normal theme, default is DKThemeVersionNormal.
 */
@property (nonatomic, assign) DKThemeVersion themeVersion;

/**
 * Returns global DKNightVersionManager instance.
 *
 * @return DKNightVersionManager shared instance
 */
+ (DKNightVersionManager *)sharedNightVersionManager;

@end