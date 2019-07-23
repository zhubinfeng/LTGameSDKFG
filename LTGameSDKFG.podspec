
Pod::Spec.new do |s|

  s.name         = "LTGameSDKFG"
  s.version      = "0.1.3"
  s.summary      = "Like this you can get LTGameSDKFG."
  s.description  = "This is a SDK for Third Login easy to user"
  s.homepage     = "https://github.com/zhubinfeng/LTGameSDKFG"
  s.license      = "MIT"
  s.author             = { "zhubinfeng" => "zhubin_feng@163.com" }
  s.platform     = :ios
  s.source       = { :git => "https://github.com/zhubinfeng/LTGameSDKFG.git", :tag => "#{s.version}" }
  s.source_files  = "LTGameSDKFG/LTGameSDK.framework/Headers/*.{h}"
  s.vendored_frameworks = 'LTGameSDKFG/LTGameSDK.framework'
  s.resource  = "LTGameSDKFG/IconResource.bundle"
  s.framework  = "Foundation", "UIKit"

end
