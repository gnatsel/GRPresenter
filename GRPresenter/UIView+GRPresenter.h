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
/**
 * The presenter that will configure the layout of an entity
 */
@property (nonatomic, weak) IBOutlet GRPresenter *presenter;

@end
