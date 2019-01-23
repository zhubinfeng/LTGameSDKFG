//
//  LTPayManager.h
//  LTSDKGame
//
//  Created by rp.wang on 2018/12/29.
//  Copyright © 2018 gnetop. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GoodsModel.h"

//=====================================
// 暴露给外部的接口，调起支付界面 by rp.wang
// Payment class
//=====================================

NS_ASSUME_NONNULL_BEGIN

// pay success block
typedef void(^paySuccessBlocks)(int code,NSDictionary *successInfoData,NSString *secuessInfoMessage);
// pay failure block
typedef void(^payFailureBlocks)(int error, NSString *errorInfoMessage);
// pay now status
typedef void(^payNowStatusBlocks)(int code, NSString *nowInfoMessage);

// !!!: - ================================= pay delegate
@class TLPayManager;
@protocol delegatePay <NSObject>
//=========================================
// If using a delegate, Must be realized,
// If using Blocks,Don't realized
// 如果使用了代理，必须实现下面的回调，
// 如果使用了Block可以不用实现
//=========================================
@required
// pay Success delegate
-(void)paySuccessDelegate:(int)code secuessInfoData:(NSDictionary *)secuessInfoData secuessInfoMessage:(NSString *)secuessInfoMessage;
// pay failure delegate
-(void)payFailureDelegate:(int)error errorInfoMessage:(NSString *)errorInfoMessage;
//
@optional

// pay now status
-(void)payNowStatusDelegate:(int)code nowInfoMessage:(NSString *)nowInfoMessage;

@end


// !!!: - =================================
@interface LTPayManager : NSObject
///
-(instancetype)initPayWithViewModel:(GoodsModel *)goodsModel SuccessBlocks:(paySuccessBlocks)successBlocks failureBlocks:(payFailureBlocks)failureBlocks;


/// Product information 订单信息
@property (strong, nonatomic, nonnull) GoodsModel *goodsModel;

/// 当前支付状态 Blocks
@property (copy, nonatomic) payNowStatusBlocks nowStatusBlocks;

@property (weak, nonatomic) id <delegatePay> delegatePay;

@end

NS_ASSUME_NONNULL_END
