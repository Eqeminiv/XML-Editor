#include "XMLComponent.h"
#include <iostream>

XMLComponent::XMLComponent()
{

}

XMLComponent::~XMLComponent()
{

}

void XMLComponent::SetParent(XMLComponent* const parent)
{
	this->parent = parent;
}

XMLComponent* XMLComponent::GetParent() const
{
	return this->parent;
}

void XMLComponent::Add(XMLComponent* xmlComponent)
{

}

void XMLComponent::Remove(XMLComponent* xmlComponent)
{

}

void XMLComponent::ShowChildren() const
{

}

void XMLComponent::Show(const int times) const
{
	for (int i = 0; i < times; i++)
		std::cout << " \t ";
	info.showLine();
}

XMLTag XMLComponent::GetInfo() const
{
	return info;
}

void XMLComponent::ShowAll(int j) const
{

}

void XMLComponent::SetXMLTag(const XMLTag xmlTag)
{
	info = xmlTag;
}



const bool XMLComponent::IsComposite() const
{
	return false;
}

void XMLComposite::findChildren(const std::vector<XMLTag>& nodeList, const int startPoint)
{
	
}

void XMLComposite::ShowChildren() const
{
	for (auto child : children)
	{
		std::cout << std::endl;
		child->Show(0);
	}
}


XMLComposite::~XMLComposite()
{
	for (auto child : children)
	{
		if (child != nullptr)
			delete child;
	}
	
}

void XMLComposite::Add(XMLComponent* xmlComponent)
{
	children.push_back(xmlComponent);
	xmlComponent->SetParent(this);
}

const bool XMLComposite::IsComposite() const
{
	return true;
}

void XMLComposite::ShowAll(int j) const
{
	int starter = j;
	for (auto child : children)
	{
		j = starter;
		if (!child->IsComposite())
		{
			child->Show(++j);
		}
		else
		{
			child->Show(++j);
			child->ShowAll(++j);
		}
	}
}

/*XMLLeaf::~XMLLeaf()
{
	delete this;
}*/
