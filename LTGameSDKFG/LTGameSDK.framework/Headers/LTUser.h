//
//  LTUser.h
//  thirdSDKTest
//
//  Created by ZBF on 2019/1/11.
//  Copyright © 2019 gnetop. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM(NSInteger,LTStateCode)
{
    LTCodeTypeSuccess = 0,
    LTCodeTypeCancel,
    LTCodeTypeFailed,
};
typedef NS_ENUM(NSInteger,LTUserType)
{
    LTUserTypeUnLogin = 0,
    LTUserTypeFacebook,
    LTUserTypeGoogle,
    LTUserTypeWeChat,
    LTUserTypeQQ,
    LTUserTypePhone,
    LTUserTypeTourist,
    LTUserTypeOther,
};
NS_ASSUME_NONNULL_BEGIN

@interface LTUser : NSObject
//乐推用户ID
@property (nonatomic,copy) NSString *LT_UID;
//乐推lt_uid_token
@property (nonatomic,copy) NSString *LTUidToken;
//用户登录操作返回结果（成功、失败、取消）
@property (nonatomic,assign) LTStateCode stateCode;
//用户类型
@property (nonatomic,assign) LTUserType userType;
//附带的一些消息
@property (nonatomic,copy) NSString *message;
//验证码（手机号注册时会用到）
@property (nonatomic,copy) NSString *authCode;
@end

NS_ASSUME_NONNULL_END
