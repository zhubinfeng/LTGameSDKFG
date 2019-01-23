//
//  LTPayErrorCode.h
//  LTSDKGame
//
//  Created by rp.wang on 2019/1/14.
//  Copyright © 2019 gnetop. All rights reserved.
//

#ifndef LTPayErrorCode_h
#define LTPayErrorCode_h

//==================================
// 支付模块返回的错误码
//==================================

///探索相关状态
typedef NS_ENUM (int, payTypeCode)
{
    /// 购买成功
    TypePaySuccess = 1000,
    /// 请求订单时失败
    TypeGetOrderFailure = 1001,
    /// 没有商品 Product list is null
    TypeProductListIsNull = 10002,
    /// 商品ID和苹果给的不匹配Product ID and apple server do not match
    TypeProductIDNotMatch = 1003,
    /// 正在购买 buying
    TypeBuyingfromAppleServer = 1004,
    /// 已经收到Apple的购买成功通知 正在和服务器验证
    TypeMineServerVerifying = 1005,
    /// 购买失败
    TypePayFailureCode = 1006,
    /// 已经购买， Apple正在处理
    TypePaymentTransactionStateRestored = 1007,
    /// 正在购买中，最终状态还没确定
    TypePaymentTransactionStateDeferred = 1008,
    /// 服务器验证支付失败
    TypeServerPaymentVerificationFailed = 1009,

};



#endif /* LTPayErrorCode_h */
