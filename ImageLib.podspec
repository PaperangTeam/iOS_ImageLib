#
# Be sure to run `pod lib lint ImageLib.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ImageLib'
  s.version          = '0.1.4.2'
  s.summary          = 'MiaoBao SDK of ImageLib.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/PaperangTeam/iOS_ImageLib'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Theodore' => 'hoho.qiu@paperang.com' }
  s.source           = { :git => 'https://github.com/PaperangTeam/iOS_ImageLib.git', :tag => s.version.to_s }
  #s.source = { :http => 'https://mb-ios.paperang.com/framework/sdk.zip' }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '9.0'
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64', 'ENABLE_BITCODE' => 'NO' }
  s.source_files = 'ImageLib.framework/Headers/*'
  s.ios.vendored_frameworks = ['ImageLib.framework']
  #s.ios.vendored_frameworks = ['SDK/*.framework']
end
