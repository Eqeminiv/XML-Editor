#include "XMLNode.h"
#include <string>
#include <iostream>

XMLNode::XMLNode(const XMLTag &xmlNode)
{
	info = XMLTag(xmlNode);

}

XMLNode::~XMLNode()
{
	//todo
}

XMLTag XMLNode::getXMLTag()
{
	return info;
}

void XMLNode::findChildren(const std::vector<XMLTag>& nodeList, const int startPoint)
{
	if (info.getIsEnd()) //leaf or ending
	{
		return;
	}
	else //pack or leaf
	{
		for (int i = startPoint + 1; info.getName() != nodeList[i].getName(); i++)
		{
			if (nodeList[i].getIsStart() && nodeList[i].getIsEnd()) //leaf
			{
				
			}
			else if (nodeList[i].getIsStart() && !nodeList[i].getIsEnd()) //pack
			{
				
			}
		}
		std::cout << info.getName() << std::endl;
		for (int i = 0; i < children.size(); i++)
		{
			
		}

	}
}