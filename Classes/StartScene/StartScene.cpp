//
//  StartScene.cpp
//  MultiRes
//
//  Created by roko on 8/27/16.
//
//

#include "StartScene/StartScene.hpp"
#include "StartSceneReader.h"
#include "Item/Item.hpp"
#include "Utils.h"

USING_NS_CC;

StartScene::~StartScene()
{
	CCLOG("%d, %s", __LINE__, __FUNCTION__);
}

StartScene::StartScene()
{
	map_t m;
	data d;
	d.x = "test data";
	m[std::make_tuple("abc", 1, 'X')] = d;
	auto itr = m.find(std::make_tuple(std::string("abc"), 1, 'X'));
	if (m.end() != itr)
	{
		CCLOG("x: %s", itr->second.x.c_str());
		//std::cout << "x: " << itr->second.x;
	}
}

StartScene * StartScene::createDefault(void)
{
	static cocos2d::Data data;
	if (0 == data.getSize()) {
		data = FileUtils::getInstance()->getDataFromFile("StartScene.csb");
	}

	// v1
	//auto rootNode = static_cast<StartScene*>(CSLoader::createNode(data, StartSceneReader::sm_nodeLoadCallback));
	
	// v2 (find element)
	//auto rootNode = static_cast<StartScene*>(CSLoader::createNode(data));
	//rootNode->m_pMyListView = findChildNode<ui::ListView>(rootNode, "MyListView");

	// v3
	auto rootNode = static_cast<StartScene*>(CSLoader::createNode(data, StartSceneReader::sm_nodeLoadCallback));

	rootNode->setContentSize(Director::getInstance()->getWinSize());
	ui::Helper::doLayout(rootNode);

	rootNode->m_pMyListView->setScrollBarEnabled(false);
	for (int i = 0; i < 10; ++i) {
		auto myItem = Item::createDefault();
		auto scaleFactor = rootNode->m_pMyListView->getContentSize().width / myItem->getContentSize().width;
		myItem->setContentSize(myItem->getContentSize()*scaleFactor);
	
		// test
		//Layout* default_item = Layout::create();
		//default_item->setContentSize(myItem->getContentSize());
		//default_item->addChild(myItem);
		//rootNode->m_pMyListView->pushBackCustomItem(default_item);
		rootNode->m_pMyListView->pushBackCustomItem(myItem);
	}

	return (StartScene*)rootNode;
}

// WidgetCallBackHandlerProtocol methods
Widget::ccWidgetTouchCallback StartScene::onLocateTouchCallback(const std::string &callBackName)
{
	//    if (callBackName == "onPlay")
	//    {
	//        return CC_CALLBACK_2(StartScene::onPlay, this);
	//    }

	return nullptr;
}

cocos2d::ui::Widget::ccWidgetClickCallback StartScene::onLocateClickCallback(const std::string &callBackName)
{
	if (callBackName == "onPlay")
	{
		return CC_CALLBACK_1(StartScene::onPlay, this);
	}
	return nullptr;
}

bool StartScene::init()
{
	if (Layout::init()) {
		return true;
	}
	return false;
}

void StartScene::onEnter()
{
	Layout::onEnter();
}

void StartScene::onExit()
{
	Layout::onExit();
}

#pragma mark Button callbacks

void StartScene::onPlay(cocos2d::Ref * sender)
{
	CCLOG("StartScene::onPlay");
}

void StartScene::test() {
}