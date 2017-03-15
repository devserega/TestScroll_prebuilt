#ifndef _MyUtils_h_
#define _MyUtils_h_

//#include <stdio.h>
//#include <set>
//#include <unordered_map>
//#include <functional>
#include "cocos2d.h"

template<class T>
T* findChildNode(cocos2d::Node* pParentNode, const char * pName)
{
	if (pParentNode == nullptr || pName == nullptr || pName[0] == '\0')
		return nullptr;

	std::hash<std::string> hashFunc;
	size_t nameHash = hashFunc(pName);
	cocos2d::Node* pResult = nullptr;

	auto childNodeFunc = [&hashFunc, &nameHash, pName, &pResult](cocos2d::Node * pNode)
	{
		if (!pNode)
			return false;

		size_t hash = hashFunc(pNode->getName());
		if (nameHash == hash && pNode->getName().compare(pName) == 0)
		{
			pResult = pNode;
			return true;
		}
		else
			return false;
	};

	pParentNode->enumerateChildren(std::string("//") + pName, childNodeFunc);
	return dynamic_cast<T*>(pResult);
}

#endif /* _MyUtils_h_ */