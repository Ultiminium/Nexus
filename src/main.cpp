#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
using namespace geode::prelude;

bool g_noclip = false;

class NexusPopup : public Popup<> {
protected:
    bool setup() override {
        this->setTitle("Nexus");
        auto toggler = CCMenuItemToggler::create(
            CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png"),
            CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png"),
            this,
            menu_selector(NexusPopup::onNoclip)
        );
        toggler->toggle(g_noclip);
        toggler->setPosition({-50, 0});
        auto label = CCLabelBMFont::create("Noclip", "bigFont.fnt");
        label->setScale(0.6f);
        label->setPosition({-50, 25});
        m_buttonMenu->addChild(toggler);
        m_buttonMenu->addChild(label);
        return true;
    }
    void onNoclip(CCObject*) {
        g_noclip = !g_noclip;
        if(g_noclip) Notification::create("Noclip Enabled", NotificationIcon::Success)->show();
        else Notification::create("Noclip Disabled", NotificationIcon::Error)->show();
    }
public:
    static NexusPopup* create() {
        auto ret = new NexusPopup();
        if (ret && ret->initAnchored(240.f, 160.f)) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
};

class $modify(PlayLayer) {
    bool init(LevelSettingsObject* settings) {
        if (!PlayLayer::init(settings)) return false;
        auto sprite = CCSprite::createWithSpriteFrameName("controllerBtn_001.png");
        sprite->setScale(0.6f);
        sprite->setOpacity(100);
        auto btn = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(PlayLayer::onOpenNexus));
        auto winSize = CCDirector::get()->getWinSize();
        auto menu = CCMenu::create();
        menu->addChild(btn);
        menu->setPosition({winSize.width - 25, winSize.height - 25});
        this->addChild(menu);
        menu->setZOrder(100);
        return true;
    }
    void onOpenNexus(CCObject*) { NexusPopup::create()->show(); }
    void destroyPlayer(PlayerObject* player, GameObject* object) {
        if (g_noclip) return;
        PlayLayer::destroyPlayer(player, object);
    }
};
