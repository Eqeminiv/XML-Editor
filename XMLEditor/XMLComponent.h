#pragma once
#include "XMLTag.h"

class XMLComponent
{
	XMLTag info;

protected:
	XMLComponent* parent;
	
public:
	XMLComponent();
	virtual ~XMLComponent();
	void SetParent(XMLComponent* parent);
	XMLComponent* GetParent();
	virtual void Add(XMLComponent* xmlComponent);
	virtual void Remove(XMLComponent* xmlComponent);
	virtual void ShowChildren();
	void Show(int times);
	XMLTag GetInfo();
	virtual void ShowAll(int j);
	void SetXMLTag(XMLTag xmlTag);
	const virtual bool IsComposite();
	
};

class XMLLeaf : public XMLComponent
{

};

class XMLComposite : public XMLComponent
{
protected:
	std::vector<XMLComponent*> children;

public:
	void Add(XMLComponent* xmlComponent) override;
	const bool IsComposite() override;
	void findChildren(const std::vector<XMLTag>& nodeList, const int startPoint);
	void ShowChildren() override;
	void ShowAll(int j) override;

};