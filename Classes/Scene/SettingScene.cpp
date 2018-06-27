#include "SimpleAudioEngine.h"
#include "SettingScene.h"
#include"ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;
using namespace CocosDenshion;
#define SOUND_KEY "sound_key"
#define MUSIC_KEY "music_key"
Scene* Setting::createScene()
{
	auto scene = Scene::create();
	auto layer = Setting::create();
	scene->addChild(layer);

	return scene;
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelpScene.cpp\n");
}

bool Setting::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite *bg = Sprite::create("setting.png");
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	this->addChild(bg);

	auto music_text = Text::create("BackgroundMusic", "Arial", 20);
	music_text->setPosition(Vec2(visibleSize.width*0.25, visibleSize.height*0.7));
	this->addChild(music_text);




/*	auto music_slider = Slider::create();
	music_slider->loadBarTexture("sliderTrack.png");
	music_slider->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png", "");
	music_slider->loadProgressBarTexture("sliderProgress.png");
	float musicPercent = CocosDenshion::SimpleAudioEngine::getInstance()->getBackgroundMusicVolume() * 100;
	if (musicPercent == 0.0f) {
		musicPercent = 100.0f;
	}
	music_slider->setPercent(musicPercent);
	music_slider->setPosition(Vec2(visibleSize.width*0.6, visibleSize.height*0.7));
	music_slider->addEventListener([=](Ref* pSender, Slider::EventType type) {
		if (type == Slider::EventType::ON_PERCENTAGE_CHANGED)
		{
			int percent = music_slider->getPercent();
			SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(float(percent) / 100);
			// 存储设置的背景音乐值
			UserDefault::getInstance()->setFloatForKey("musicPercent", float(percent) / 100);
		}
	});
	this->addChild(music_slider);*/

	/***********************音效音量标签和滑动条设计**************************/
	// 创建“音效音量”文本并添加为当前层的子节点
	auto sound_text = Text::create("EffectMusic", "Arial", 20);
	sound_text->setPosition(Vec2(visibleSize.width*0.25, visibleSize.height*0.5));
	this->addChild(sound_text);

	/*auto effects_slider = Slider::create();
	effects_slider->loadBarTexture("sliderTrack.png");
	effects_slider->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png", "");
	effects_slider->loadProgressBarTexture("sliderProgress.png");
	float effectPercent = UserDefault::getInstance()->getFloatForKey("effectPercent") * 100;
	// 如果是第一次进入设置场景，设置音效滑动条默认初始值为100
	if (effectPercent == 0.0f) {
		effectPercent = 100.0f;
	}
	effects_slider->setPercent(effectPercent);
	effects_slider->setPosition(Vec2(visibleSize.width*0.6, visibleSize.height*0.5));
	effects_slider->addEventListener([=](Ref* pSender, Slider::EventType type) {
		if (type == Slider::EventType::ON_PERCENTAGE_CHANGED)
		{
			int percent = effects_slider->getPercent();
			SimpleAudioEngine::getInstance()->setEffectsVolume(float(percent) / 100);
			UserDefault::getInstance()->setFloatForKey("effectPercent", float(percent) / 100);
		}
	});
	this->addChild(effects_slider);*/
	
// 创建“返回“按钮
	auto return_button = Button::create("back.png");
	return_button->setPosition(Vec2(visibleSize.width *0.85, visibleSize.height*0.18));
	return_button->addTouchEventListener([](Ref* pSender, Widget::TouchEventType type) {
		if (type == Widget::TouchEventType::ENDED) {
			// 切换到MenuScene场景
			//auto transition = TransitionShrinkGrow::create(2.0, OpenScene::createScene());
			Director::getInstance()->popScene();
		}
	});
	this->addChild(return_button);

   UserDefault *defaults = UserDefault::getInstance();

	/*if (defaults->getBoolForKey(MUSIC_KEY)) {
		
			musicToggleMenuItem->setSelectedIndex(0);                                
	}
	else {
		musicToggleMenuItem->setSelectedIndex(1);                                
	}


	if (defaults->getBoolForKey(SOUND_KEY)) {
		
			soundToggleMenuItem->setSelectedIndex(0);                                
	}
	else {
		soundToggleMenuItem->setSelectedIndex(1);                                
	}*/
	
	return true;
}



void Setting::menuSoundToggleCallback(Ref* pSender)
{
	auto soundToggleMenuItem = (MenuItemToggle*)pSender;
	log("soundToggleMenuItem %d", soundToggleMenuItem->getSelectedIndex());


	UserDefault *defaults = UserDefault::getInstance();
	if (defaults->getBoolForKey(SOUND_KEY)) {
		
			defaults->setBoolForKey(SOUND_KEY, false);                               
	}
	else {
		defaults->setBoolForKey(SOUND_KEY, true);                                
			SimpleAudioEngine::getInstance()->playEffect("2.mp3");                  
	}


}


void Setting::menuMusicToggleCallback(Ref* pSender)
{
	auto musicToggleMenuItem = (MenuItemToggle*)pSender;
	log("musicToggleMenuItem %d", musicToggleMenuItem->getSelectedIndex());


	UserDefault *defaults = UserDefault::getInstance();
	if (defaults->getBoolForKey(MUSIC_KEY)) {
		
			defaults->setBoolForKey(MUSIC_KEY, false);
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	}
	else {
		defaults->setBoolForKey(MUSIC_KEY, true);
		SimpleAudioEngine::getInstance()->playBackgroundMusic("1.mp3");
	}                                                                           
}


void Setting::onEnter()
{
	Layer::onEnter();
	log("Setting onEnter");
}


void Setting::menuSettingIsOkCallback(Ref* pSender)                                  
{
	Director::getInstance()->popScene();


	if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY)) {
		
			SimpleAudioEngine::getInstance()->playEffect("2.mp3");
	}
}


void Setting::onEnterTransitionDidFinish()                                      
{
	Layer::onEnterTransitionDidFinish();
	log("Setting onEnterTransitionDidFinish");


	if (UserDefault::getInstance()->getBoolForKey(MUSIC_KEY)) {
	
			//播放  
			SimpleAudioEngine::getInstance()->playBackgroundMusic("1.mp3", true);
	}


}


void Setting::onExit()
{
	Layer::onExit();
	log("Setting onExit");
}


void Setting::onExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
	log("Setting onExitTransitionDidStart");
}


void Setting::cleanup()
{
	Layer::cleanup();
	log("Setting cleanup");
	//停止  
	SimpleAudioEngine::getInstance()->stopBackgroundMusic("1.mp3");
}