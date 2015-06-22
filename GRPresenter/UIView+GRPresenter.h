//
//  UITableViewCell+Presenter.h
//  SampleGRCoreDataUtils
//
//  Created by Gnatsel Reivilo on 04/06/2015.
//  Copyright (c) 2015 Gnatsel Reivilo. All rights reserved.
//

#import <UIKit/UIKit.h>
@class GRPresenter;
@interface UIView (GRPresenter)
@property (nonatomic, weak) IBOutlet GRPresenter *presenter;

@end
