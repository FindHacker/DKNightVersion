![](./images/Banner.png)

# DKNightVersion

DKNightVersion is a light weight framework. It's mainly built through `objc/runtime` library and reflection, providing a neat approach  adding night mode to your iOS app. A great many codes of this framework is automatically generated by Ruby script.

The most delightful feature of DKNightVersion is that it appends one more property `nightColor` to frequently-used UIKit components and provides you a default night mode theme. It is easily-used and well-designed. Hope you have a great joy to use DKNightVersion to integrate night mode in your Apps.

![Version](https://img.shields.io/badge/Pod-%20v0.7.0%20-or.svg)
[![Build Status](https://travis-ci.org/Draveness/DKNightVersion.png)](https://travis-ci.org/Draveness/DKNightVersion)
![MIT License](https://img.shields.io/github/license/mashape/apistatus.svg)
![Platform](https://img.shields.io/badge/platform-%20iOS%20-lightgrey.svg)

# Demo

![](./images/DKNightVersion.gif)

# Installation with CocoaPods

[CocoaPods](https://cocoapods.org/) is a dependency manager for Objective-C, which automates and simplifies the process of using 3rd-party libraries like DKNightVersion in your projects. See the [Get Started section](https://cocoapods.org/#get_started) for more details.

## Podfile

```
pod "DKNightVersion", "~> 0.7.0"
```

## Usage

Just add one line of code in your precompiled header, or import it where you need.

```
#import "DKNightVersion.h"
```

----

# How to use

## Using night color

DKNightVersion is based on property `nightColor`, such as `nightBackgroundColor` `nightTextColor` and etc.

Assign the night mode color you want to the `UIKit` component like this:

```
self.view.nightBackgroundColor = [UIColor blackColor];
self.label.nightTextColor = [UIColor whiteColor];
```

## Using DKNightVersionManager change theme

Use `DKNightVersionManager` sets the theme.

```
[DKNightVersionManager nightFalling];
```

If you'd like to switch back to normal mode:

```
[DKNightVersionManager dawnComing];
```

It's pretty easy to swich theme between night and normal mode.

## Make your own customize

### Notification

`nightFalling` method will post `DKNightVersionNightFallingNotification` when it is called. Similarly, `dawnComing` will post `DKNightVersionDawnComingNotification`. You can observe these notification in proper place, and make your own customize easily.

## RespondClasses

If you want your own class changing color while switch theme.

You are supposed to add it to `respondClasseses` set. In the new version, in order to prevent subclass inheritance superclass's night color, I add `respondClasseses` set.

Use `addClassToSet:` or `removeClassToSet:` method to deal with it.

```
[DKNightVersionManager addClassToSet:self.class];
[DKNightVersionManager removeClassToSet:self.class];
```

If you don't add your own classes to this set, `DKNightVersionManager` will prevent it from changing color when switch theme.

Use `respondClasseses` to get all respond classes which will change color when `nightFalling` or `dawnComing`.

```
NSSet *set = [DKNightVersionManager respondClasseses];
```

### JSON

There is a json file in `Generator` folder named `property.json`, you can change the color in it, which will cuz the default color changing to the color you want.

```
{
    "UIView":
    {
        "backgroundColor": "0x343434",
        "tintColor": "0xffffff"
    },
    "UILabel":
    {
        "textColor": "0x5d5d5d"
    },
    "UINavigationBar":
    {
        "barTintColor": "0x444444"
    },
    "UIButton":
    {
        "titleColor": "0x5F80AC"
    },
    "UIScrollView":
    {
        "backgroundColor": "0x343434"
    },
    "UITableView":
    {
        "backgroundColor": "0x343434",
        "separatorColor": "0x313131"
    },
    "UITableViewCell":
    {
        "backgroundColor": "0x343434"
    }
}
```

And run `rake` in terminal under folder `Pods/DKNightVersion`.

> This ruby script is based on the Cocoapods components [`Xcodeproj`](https://github.com/CocoaPods/Xcodeproj). If there is a  NoMethodError, you should install it first or run `bundle install` in `DKNightVersion` folder.

This command will automatically do everything for you.

## Using default night version

If you set `useDefaultNightColor` property for singleton manager to `YES`, which is the default value. DKNightVersion will provide you a default night mode.

And you can also customize the color through assign color value to `nightColor` property. And we will first pick color you specified instead of default behavior.

Optionally, turn off the default night mode and set it on your own is also supported.

```
[DKNightVersionManager setUseDefaultNightColor:NO];
```

## Picking Color

DKNightVersionManager will pick the proper color following these two rules.

1. `useDefaultNightColor == YES` (The default behavior)

		nightColor > defaultNightColor > normalColor

2. `useDefaultNightColor == NO`

		nightColor > normalColor

# Contribute

Feel free to open an issue or pull request, if you need help or there is a bug.

# Contact

- Powered by [Draveness](http://github.com/draveness)
- Personal website [DeltaX](http://deltax.me)

# License

DKNightVersion is available under the MIT license. See the LICENSE file for more info.

# Todo

- Documentation
