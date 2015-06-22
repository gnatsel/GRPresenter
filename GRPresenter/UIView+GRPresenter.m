//
//  UITableViewCell+Presenter.m
//  SampleGRCoreDataUtils
//
//  Created by Gnatsel Reivilo on 04/06/2015.
//  Copyright (c) 2015 Gnatsel Reivilo. All rights reserved.
//

#import "UIView+GRPresenter.h"
#import "GRPresenter.h"
#import <objc/runtime.h>

static char UIPresenter;

@implementation UIView (Presenter)
- (void)setPresenter:(GRPresenter *)presenter{
    [self willChangeValueForKey:@"GRPresenter"];
    objc_setAssociatedObject(self, &UIPresenter,
                             presenter,
                             UIPresenter);
    [self didChangeValueForKey:@"GRPresenter"];
}

- (GRPresenter *)presenter {
    return objc_getAssociatedObject(self, &UIPresenter);
}
@end
