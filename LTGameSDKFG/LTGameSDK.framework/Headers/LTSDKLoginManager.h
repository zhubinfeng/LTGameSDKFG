//
//  LTSDKLoginManager.h
//  LTGameSDK
//
//  Created by ZBF on 2019/1/3.
//  Copyright © 2019 gnetop. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "LTUser.h"

NS_ASSUME_NONNULL_BEGIN
typedef void (^loginUserBlock)(LTUser *loginUser);
typedef void(^userAgreeCallback)(void);
@interface LTSDKLoginManager : NSObject
+(LTSDKLoginManager *)sharedInstance;
/**
 LT应用注册

 @param appId 应用ID
 @param appkey 应用Key
 */
-(void)registLTPlatformAppID:(NSString *)appId withAppkey:(NSString *)appkey withUIViewController:(UIViewController *)uc;
/**
 google平台注册

 @param clientID Google平台生成的客户端ID
 @param uc 当前所在的UIViewController
 */
-(void)registGooglePlatform:(NSString *)clientID withUIViewController:(UIViewController *)uc;
/**
 google登录

 @param block 回调通知
 */
-(void)googleLoginGetLTID:(loginUserBlock)block;
/**
 Facebook登录

 @param block 回调通知
 */
-(void)facebookLogin:(loginUserBlock)block;
/**
 游客登录
 
 @param block 回调通知
 */
-(void)touristLogin:(loginUserBlock)block;
/**
 显示登录界面（需要使用SDK的登录界面UI时调用）

 @param uc 当前界面所在的UIViewController
 @param block 回调通知
 */
-(void)showLoginManagerUI:(UIViewController *)uc withBlock:(loginUserBlock)block isShowGuestButton:(BOOL)isShowGuestButton;
/**
 检查用户状态，判断是否可以自动登录

 @param block 回调通知
 */
-(void)getUserLoginState:(loginUserBlock)block;
/**
 退出登录(清空信息，不弹出登录框)
 */
-(void)userLogout;
/**
 退出登录（清空信息弹出登录框）
 */
-(void)userLogoutToLoginUI:(UIViewController *)uc withBlock:(loginUserBlock)block isShowGuestButton:(BOOL)isShowGuestButton;
/**
 设置用户协议和隐私条款连接

 @param userAgreement 用户协议网址
 @param privacy 隐私政策网址
 */
-(void)linkOfUserAgreement:(NSString *)userAgreement andPrivacyLine:(NSString *)privacy agreePrivacyCallback:(userAgreeCallback)callback;

/**
 用户是否同意了隐私政策和用户条款

 @return 是否
 */
-(BOOL)isUserAgreesTerms;
/**
 获取登录结果回调

 @param application 当前应用
 @param url 回调的url
 @param options 包含回调应用的BundleIdentifier（比如“com.facebook.app”）
 @return 内部使用
 */
- (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
            options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

//当前用户
@property (nonatomic, strong) LTUser *currentUser;
@end

NS_ASSUME_NONNULL_END
