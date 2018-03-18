#ifndef __OTHER_SCENE_H__
#define __OTHER_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class OtherScene : public cocos2d::Layer
{
public:
    OtherScene(); //コンストラクタ
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(OtherScene);
    
    void onBgmOnOff(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    void onSeOnOff(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    
    CC_SYNTHESIZE(cocos2d::ui::Button*, m_seOn,   seOn  );
    CC_SYNTHESIZE(cocos2d::ui::Button*, m_seOff,  seOff );
    CC_SYNTHESIZE(cocos2d::ui::Button*, m_bgmOn,  bgmOn );
    CC_SYNTHESIZE(cocos2d::ui::Button*, m_bgmOff, bgmOff);
};

#endif // __OTHER_SCENE_H__
