//
//  GRPresenter.h
//  SampleGRPresenter
//
//  Created by Gnatsel Reivilo on 22/06/2015.
//  Copyright (c) Gnatsel Reivilo. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface GRPresenter : UIView
/**
 * Configure the presenter's view with the given entity
 *
 * @param entity The entity to use to configure the view
 * 
 */
-(void)configureWithEntity:(id)entity;

/**
 * @return an NSMutableDictionary representing the data of an entity;
 */
-(NSMutableDictionary *)dictionaryEntity;

/**
 * Should be called when you want to stop the loading of some UI elements (e.g : UIImage while 
 * scrolling in UITableView)
 */
-(void)stopLoadingUI;
@end
