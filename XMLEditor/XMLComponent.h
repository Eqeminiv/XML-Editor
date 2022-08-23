#pragma once
#include "XMLTag.h"

class XMLComponent
{
private:
	XMLTag info;

protected:
	XMLComponent* parent = nullptr;
	
public:
	XMLComponent();
	virtual ~XMLComponent();
	void SetParent(XMLComponent* const parent);
	XMLComponent* GetParent() const;
	virtual void Add(XMLComponent* xmlComponent);
	virtual void Remove(XMLComponent* xmlComponent);
	virtual void ShowChildren() const;
	void Show(const int times) const;
	XMLTag GetInfo() const;
	virtual void ShowAll(int j) const;
	void SetXMLTag(const XMLTag xmlTag);
	const virtual bool IsComposite() const;
	
};

class XMLLeaf : public XMLComponent
{
	
};

class XMLComposite : public XMLComponent
{
protected:
	std::vector<XMLComponent*> children;

public:
	~XMLComposite();
	void Add(XMLComponent* xmlComponent) override;
	const bool IsComposite() const override;
	void findChildren(const std::vector<XMLTag>& nodeList, const int startPoint);
	void ShowChildren() const override;
	void ShowAll(int j) const override;

};