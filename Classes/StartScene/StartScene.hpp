//
//  StartScene.hpp
//  MultiRes
//
//  Created by roko on 8/27/16.
//
//

#ifndef StartScene_hpp
#define StartScene_hpp

#include "cocos2d.h"
#include "editor-support/cocostudio/CocoStudio.h"
#include "editor-support/cocostudio/WidgetCallBackHandlerProtocol.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;
using namespace cocos2d::ui;

//typedef std::pair<short, short> HexAxialCoord;   // TODO - make a class (??)
//typedef std::unordered_map<HexAxialCoord, int> PathHexInfoMap;

//PathHexInfoMap mPathInfo;

typedef std::unordered_map<size_t, std::string> Traders;

///////////////////////////////////////////////////////////////////////////////////////////////////////
typedef std::tuple<std::string, int, char> key_t;

struct key_hash : public std::unary_function<key_t, std::size_t>
{
	std::size_t operator()(const key_t& k) const
	{
		return std::get<0>(k)[0] ^ std::get<1>(k) ^ std::get<2>(k);
	}
};

struct key_equal : public std::binary_function<key_t, key_t, bool>
{
	bool operator()(const key_t& v0, const key_t& v1) const
	{
		return (
			std::get<0>(v0) == std::get<0>(v1) &&
			std::get<1>(v0) == std::get<1>(v1) &&
			std::get<2>(v0) == std::get<2>(v1)
			);
	}
};

struct data
{
	std::string x;
};

typedef std::unordered_map<const key_t, data, key_hash, key_equal> map_t;
///////////////////////////////////////////////////////////////////////////////////////////////////////

class StartScene 
	: public cocos2d::ui::Layout
	, public cocostudio::WidgetCallBackHandlerProtocol 
{
		friend class StartSceneReader;
    
	private:
		//CC_DISALLOW_COPY_AND_ASSIGN(StartScene);
    
	protected:
		StartScene();
		virtual bool init() override;
    
	private:
		void test();
		//int test;
		cocos2d::ui::ListView* m_pMyListView;
		
	public:
		virtual ~StartScene();
    
		CREATE_FUNC(StartScene)
    
		// WidgetCallBackHandlerProtocol methods
		cocos2d::ui::Widget::ccWidgetTouchCallback onLocateTouchCallback(const std::string &callBackName) override;
		cocos2d::ui::Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName) override;
    
		static StartScene * createDefault(void);
    
		virtual void onEnter() override;
		virtual void onExit() override;
    
		#pragma mark Button callbacks
		void onPlay(cocos2d::Ref * sender);
};

#endif /* StartScene_hpp */
