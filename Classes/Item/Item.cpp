//
//  Item.cpp
//  TestScroll
//
//  Created by roko on 1/16/17.
//
//

#include "Item\Item.hpp"
#include "Item\ItemReader.h"

USING_NS_CC;

using namespace cocos2d::ui;

Item::~Item()
{
    CCLOG("%d, %s", __LINE__, __FUNCTION__);
}

Item::Item()
{
    CCLOG("%d, %s", __LINE__, __FUNCTION__);
}

Item * Item::createDefault()
{
    static cocos2d::Data data;
    if (0 == data.getSize()) {
        data = FileUtils::getInstance()->getDataFromFile("Item.csb");
    }
    auto rootNode = static_cast<Item*>(CSLoader::createNode(data, ItemReader::sm_nodeLoadCallback));
	//auto rootNode = static_cast<Item*>(CSLoader::createNode(data));
    
    ui::Helper::doLayout(rootNode);
    
    rootNode->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    
    return (Item*)rootNode;
}

bool Item::init()
{
    if (Layout::init()) {
        return true;
    }
    return false;
}

#pragma mark WidgetCallBackHandlerProtocol methods
cocos2d::ui::Widget::ccWidgetTouchCallback Item::onLocateTouchCallback(const std::string &callBackName)
{
    if (callBackName == "onSuperButton")
    {
        return CC_CALLBACK_2(Item::onSuperButton, this);
    }
    return nullptr;
}

cocos2d::ui::Widget::ccWidgetClickCallback Item::onLocateClickCallback(const std::string &callBackName)
{
	if (callBackName == "onClick")
	{
		return CC_CALLBACK_1(Item::onClick, this);
	}
	return nullptr;
}

#pragma mark Button callbacks
void Item::onSuperButton(cocos2d::Ref * sender, cocos2d::ui::Widget::TouchEventType type)
{
    //CCLOG("%d, %s", __LINE__, __FUNCTION__);
    switch (type) {
        case Widget::TouchEventType::BEGAN:
        {
            CCLOG("onSuperButton::BEGAN");
            break;
        }
        case Widget::TouchEventType::MOVED:
        {
            break;
        }
        case Widget::TouchEventType::ENDED:
        {
            CCLOG("onSuperButton::ENDED");
            break;
        }
        case Widget::TouchEventType::CANCELED:
        {
            CCLOG("onSuperButton::CANCELED");
            break;
        }
            
        default:
            break;
    }
}

void Item::onClick(cocos2d::Ref * sender)
{
	CCLOG("Item::onClick");
}