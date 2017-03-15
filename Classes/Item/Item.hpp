//
//  Item.hpp
//  TestScroll
//
//  Created by roko on 1/16/17.
//
//

#ifndef Item_hpp
#define Item_hpp

#include "cocos2d.h"
#include "editor-support/cocostudio/CocoStudio.h"
#include "editor-support/cocostudio/WidgetCallBackHandlerProtocol.h"
#include "ui/CocosGUI.h"

class Item
	: public cocos2d::ui::Layout
	, public cocostudio::WidgetCallBackHandlerProtocol
{
    friend class ItemReader;
    
	//private:
	 //  CC_DISALLOW_COPY_AND_ASSIGN(Item);
    
	protected:
		Item();
		bool init() override;

	private:
		CC_SYNTHESIZE(cocos2d::ui::Button*, m_pSuperButton, SuperButton)
		CC_SYNTHESIZE(cocos2d::ui::Layout*, m_pContentPanel, ContentPanel)
    
	public:
		virtual ~Item();
    
		CREATE_FUNC(Item)
    
		static Item * createDefault();
    
		#pragma mark WidgetCallBackHandlerProtocol methods
		cocos2d::ui::Widget::ccWidgetTouchCallback onLocateTouchCallback(const std::string &callBackName) override;
		cocos2d::ui::Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName) override;
    
		#pragma mark Button callbacks
		void onSuperButton(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);

		void onClick(cocos2d::Ref * sender);
};

#endif /* Item_hpp */
