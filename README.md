GRPresenter
===============
Implementation of MVCP design pattern inspired from [Model View Controller Presenter](https://medium.com/ios-apprentice/model-view-controller-presenter-8bb4149fa5ef)

Presentation
----------
The goal of this library is to drastically reduce view configuration code redundancy.
GRPresenter is a subclass of UIView to allow it to be draggable in Storyboards.

You need to import two files in your UIViewController subclasses : GRPresenter.h and UIView+GRPresenter.h


How to use
----------

## Subclassing GRPresenter 

```objective-c
// FeedItem.h (entity that will be used by the subclass of GRPresenter)

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@interface FeedItem : NSManagedObject

@property (nonatomic, retain) NSString * author;
@property (nonatomic, retain) NSString * authorId;
@property (nonatomic, retain) NSNumber * dateTaken;
@property (nonatomic, retain) NSString * detailedDescription;
@property (nonatomic, retain) NSNumber * isBookmarked;
@property (nonatomic, retain) NSNumber * isRead;
@property (nonatomic, retain) NSString * link;
@property (nonatomic, retain) NSString * media;
@property (nonatomic, retain) NSNumber * published;
@property (nonatomic, retain) NSString * tags;
@property (nonatomic, retain) NSString * title;

@end

...

// FeedItemPresenter.h
#import "GRPresenter.h"

@class FeedItem;
typedef NS_ENUM(NSInteger, FeedItemPresenterStyle) {
    FeedItemPresenterStyleDefault = 0,
    FeedItemPresenterStyleDetail = 1
};


IB_DESIGNABLE
@interface FeedItemPresenter : GRPresenter<UIWebViewDelegate>
@property (nonatomic,assign) IBInspectable NSInteger presenterStyle;

@property (nonatomic,weak) IBOutlet UIImageView *mediaImageView;
@property (nonatomic,weak) IBOutlet UILabel *titleFeedLabel;
@property (nonatomic,weak) IBOutlet UILabel *publicationInfoLabel;

@property (nonatomic,weak) IBOutlet UIWebView *detailedDescriptionWebView;
@property (nonatomic,weak) IBOutlet UIWebView *linkWebView;
@property (nonatomic,weak) IBOutlet UIBarButtonItem *bookmarkBarButtonItem;


-(void)configureBookmarkBarButtonItemWithFeedItem:(FeedItem *)feedItem;

@end
```
## Using GRPresenter to configure UITableViewCell

```objective-c

// FeedTableViewController.h

...
// FeedTableViewController.m
#import "Presenter.h"
#import "UIView+Presenter.h"
@interface FeedTableViewController ()
@property (strong, nonatomic) NSArray *feedItemsArray;

@end

#pragma mark - UITableViewDataSource
-(NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return 1;
}
-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return _feedItemsArray.count;
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    NSString *cellIdentifier = NSStringFromClass([FeedItemTableViewCell class]);
    FeedItemTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier forIndexPath:indexPath];
    [cell.presenter configureWithObject:[_feedItemsArray objectAtIndex:indexPath.row]];
    
    return cell;
}


#pragma mark - UITableViewDelegate
-(void)tableView:(UITableView *)tableView didEndDisplayingCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath{
    [cell.presenter stopLoadingUI];
}

```


Sample codes
------------
See [GRSampleGRCoreDataUtils](https://github.com/gnatsel/GRCoreDataUtils) or [GRSampleWebServiceManager](https://github.com/gnatsel/GRWebServiceManager) for sample codes.


## License
The MIT License (MIT)

Copyright (c) 2015 gnatsel

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.