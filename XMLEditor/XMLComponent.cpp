#include "XMLComponent.h"
#include <iostream>

XMLComponent::XMLComponent()
{

}

XMLComponent::~XMLComponent()
{

}

void XMLComponent::SetParent(XMLComponent* parent)
{
	this->parent = parent;
}

XMLComponent* XMLComponent::GetParent()
{
	return this->parent;
}

void XMLComponent::Add(XMLComponent* xmlComponent)
{

}

void XMLComponent::Remove(XMLComponent* xmlComponent)
{

}

void XMLComponent::ShowChildren()
{

}

void XMLComponent::Show(int times)
{
	for (int i = 0; i < times; i++)
		std::cout << " \t ";
	info.showLine();
}

XMLTag XMLComponent::GetInfo()
{
	return info;
}

void XMLComponent::ShowAll(int j)
{

}

void XMLComponent::SetXMLTag(XMLTag xmlTag)
{
	info = xmlTag;
}



const bool XMLComponent::IsComposite()
{
	return false;
}

void XMLComposite::findChildren(const std::vector<XMLTag>& nodeList, const int startPoint)
{
	





}

void XMLComposite::ShowChildren()
{
	for (int i = 0; i < children.size(); i++)
	{
		std::cout << std::endl;
		children[i]->Show(0);
	}
}


void XMLComposite::Add(XMLComponent* xmlComponent)
{
	children.push_back(xmlComponent);
	xmlComponent->SetParent(this);
}

const bool XMLComposite::IsComposite()
{
	return true;
}

void XMLComposite::ShowAll(int j)
{
	int starter = j;
	for (int i = 0; i < children.size(); i++)
	{
		j = starter;
		if (!children[i]->IsComposite())
		{
			children[i]->Show(++j);
		}
		else
		{
			children[i]->Show(++j);
			children[i]->ShowAll(++j);
		}
	}
}
