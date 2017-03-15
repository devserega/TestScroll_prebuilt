#include "StartScene\StartSceneReader.h"
#include "StartScene\StartScene.hpp"

USING_NS_CC;

using namespace cocos2d::ui;

StartScene* StartSceneReader::sm_pTmpNode = nullptr;
cocos2d::ccNodeLoadCallback StartSceneReader::sm_nodeLoadCallbackLambda = [](cocos2d::Ref * pRef) {
	if (StartSceneReader::sm_pTmpNode) {
		cocos2d::Node * pNode = dynamic_cast<cocos2d::Node *>(pRef);
		if (!pNode) {
			return;
		}

		if (pNode->getName().compare("MyListView")==0) {
			//StartSceneReader::sm_pTmpNode->m_pMyListView = dynamic_cast<ui::ListView*>(pNode);
		}

		//if (HelperFunctions::extractProperty(pNode, StartSceneReader::sm_pTmpNode, StartScene::sm_properties)) {
		//}
	}
};

void StartSceneReader::sm_nodeLoadCallback(cocos2d::Ref * pRef) {
	if (StartSceneReader::sm_pTmpNode) {
		cocos2d::Node * pNode = dynamic_cast<cocos2d::Node *>(pRef);
		if (!pNode) {
			return;
		}

		if (pNode->getName().compare("MyListView") == 0) {
			StartSceneReader::sm_pTmpNode->m_pMyListView = dynamic_cast<ui::ListView*>(pNode);
		}

		//if (HelperFunctions::extractProperty(pNode, StartSceneReader::sm_pTmpNode, StartScene::sm_properties)) {
		//}
	}
}

static StartSceneReader* _instanceStartSceneReader = nullptr;
StartSceneReader* StartSceneReader::getInstance()
{
	if (!_instanceStartSceneReader)
	{
		_instanceStartSceneReader = new StartSceneReader();
	}
	return _instanceStartSceneReader;
}

void StartSceneReader::purge()
{
	CC_SAFE_DELETE(_instanceStartSceneReader);
}

Node* StartSceneReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeStartScene)
{
	StartScene* node = StartScene::create();
	sm_pTmpNode = node;
	setPropsWithFlatBuffers(node, nodeStartScene);

	
	sm_pTmpNode->m_pMyListView;
	//sm_pTmpNode->test = 5;

	return node;
}

