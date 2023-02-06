#pragma once
#include "XMLTag.h"
#include <memory>
#include <string>

class XMLComponent : public std::enable_shared_from_this<XMLComponent>
{
private:
	XMLTag info;

protected:
	std::shared_ptr<XMLComponent> parent = nullptr;
	
public:
	XMLComponent();
	XMLComponent(std::shared_ptr<XMLComponent> pointer);
	virtual ~XMLComponent();
	void SetParent(std::shared_ptr<XMLComponent> parent);
	std::shared_ptr<XMLComponent> GetParent();
	
	virtual void Add(std::shared_ptr<XMLComponent> xmlComponent);
	virtual void Remove();
	virtual void ShowChildren() const;
	void Show(const int times, int level) const;
	XMLTag GetInfo() const;
	virtual void ShowAll(int level, int counter = 0) const;
	void SetXMLTag(const XMLTag xmlTag);
	const virtual bool IsComposite() const;
	virtual void RemoveChild(XMLTag info);
	virtual std::shared_ptr<XMLComponent> searchForNodeOnChildren(const std::string& name);
	std::shared_ptr<XMLComponent> GetParent() const;
	void Move(std::shared_ptr<XMLComponent> target);
};

class XMLLeaf : public XMLComponent
{
	void Remove() override;
	std::shared_ptr<XMLComponent> searchForNodeOnChildren(const std::string& name) override;
};

class XMLComposite : public XMLComponent
{
protected:
	std::vector<std::shared_ptr<XMLComponent>> children;

public:
	void Add(std::shared_ptr<XMLComponent> xmlComponent) override;
	void Remove() override;
	const bool IsComposite() const override;
	void findChildren(const std::vector<XMLTag>& nodeList, const int startPoint);
	void ShowChildren() const override;
	void ShowAll(const int level, const int counter = 0) const override;
	void RemoveChild(const XMLTag info);
	std::vector<std::shared_ptr<XMLComponent>> GetChildren();
	std::shared_ptr<XMLComponent> searchForNodeOnChildren(const std::string& name) override;
};