#include "XMLComponent.h"
#include <iostream>

XMLComponent::XMLComponent()
{

}

XMLComponent::XMLComponent(std::shared_ptr<XMLComponent> pointer) : parent(pointer)
{

}

XMLComponent::~XMLComponent()
{

}

void XMLComponent::SetParent(std::shared_ptr<XMLComponent> parent)
{
	this->parent = parent;
	
}


std::shared_ptr<XMLComponent> XMLComponent::GetParent()
{
	return parent;
}



void XMLComponent::Add(std::shared_ptr<XMLComponent> xmlComponent)
{
}

void XMLComponent::Remove() //maybe argument not needed
{

}

void XMLComponent::ShowChildren() const
{

}

void XMLComponent::Show(const int times, int level) const
{
	
	if (times <= level)
	{
		for (int i = 0; i < times; i++)
			std::cout << "   ";

		std::cout << "<" << info.getName() << " " << info.getAllAttributeVectorXMLFormatted();

		if (info.getIsStart() && info.getIsEnd())
			std::cout << "/>" << std::endl;
		else
			std::cout << ">" << std::endl;
	}
	else
	{
		for (int i = 0; i < times; i++)
			std::cout << "   ";
		std::cout << "[...]" << std::endl;
	}
}

XMLTag XMLComponent::GetInfo() const
{
	return info;
}

void XMLComponent::ShowAll(int counter, int level) const
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

void XMLComponent::RemoveChild(XMLTag info)
{
}

std::shared_ptr<XMLComponent> XMLComponent::searchForNodeOnChildren(const std::string name)
{
	return std::shared_ptr<XMLComponent>();
}

std::shared_ptr<XMLComponent> XMLComposite::searchForNodeOnChildren(const std::string name)
{
	if (GetInfo().getName() == name)
		return shared_from_this();

	std::shared_ptr<XMLComponent> node = nullptr;
	for (auto& child : children)
	{
		node = child.get()->searchForNodeOnChildren(name);
		if (node != nullptr)
		{
			std::cout << "znaleziono: " << node.get()->GetInfo().getName();
			return node;
		}
	}

	return nullptr;
}

void XMLComposite::findChildren(const std::vector<XMLTag>& nodeList, const int startPoint)
{
	
}

void XMLComposite::ShowChildren() const
{
	for (auto& child : children)
	{
		std::cout << std::endl;
		child->Show(0, 0);
	}
}

void XMLComposite::Add(std::shared_ptr<XMLComponent> xmlComponent)
{
	children.emplace_back(xmlComponent);
	xmlComponent->SetParent(shared_from_this());
}

void XMLComposite::Remove()
{
	children.clear();
	parent = nullptr;
}

const bool XMLComposite::IsComposite() const
{
	return true;
}

void XMLComposite::ShowAll(const int maxLevel, const int currentLevel) const
{
	for (const auto& child : children)
	{
			if (!child->IsComposite())
			{
				child->Show(currentLevel + 1, maxLevel);
			}
			else
			{
				child->Show(currentLevel + 1, maxLevel);
				child->ShowAll(maxLevel, currentLevel + 1);
				std::string times((currentLevel + 1)*3, ' ');
				if (currentLevel < maxLevel)
				{
					std::cout << times << "<\/" << child->GetInfo().getName() << ">";
					std::cout << std::endl;
				}
			}
			
	}
}

void XMLComposite::RemoveChild(const XMLTag info)
{
	int i = 0;
	while (i >= 0 && i < children.size())
	{
		if (children[i].get()->GetInfo() == info)
		{
			children.erase(children.begin() + i);
			i = -1;
		}
		else
			i++;
	}
}

/*void XMLLeaf::Remove()
{
	std::shared_ptr<XMLComponent> tempParent = this->GetParent();
	tempParent.get()->RemoveChild(this->GetInfo());
}*/

void XMLLeaf::Remove()
{
	parent = nullptr;
}

std::shared_ptr<XMLComponent> XMLLeaf::searchForNodeOnChildren(const std::string name)
{
	if (GetInfo().getName() == name)
		return shared_from_this();
	return nullptr;
}
