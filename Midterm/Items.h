#pragma once
#include "Node.h"

class BaseItem : public Node
{
public:
	BaseItem() : Node("Base Item") {}
	BaseItem(std::string name) : Node(name), _owner("none"), _requiredItem("none"){}
	BaseItem(std::string name, std::string owner) : Node(name), _owner(owner), _requiredItem("none") {}
	BaseItem(std::string name, std::string owner, std::string required) : Node(name), _owner(owner), _requiredItem(required) {}
	const std::string _owner;
	const std::string _requiredItem;
};

//깃발
class CatapultFlag : public BaseItem
{
public:
	CatapultFlag() : BaseItem("깃발", "투석") {}
};

//검
class Sword : public BaseItem
{
public:
	Sword() : BaseItem("검", "보병") {}
};

//활
class Bow : public BaseItem
{
public:
	Bow() : BaseItem("활", "궁병") {}
};

//화살
class Arrow : public BaseItem
{
public:
	Arrow() : BaseItem("화살", "궁병") {}
};

//창
class Spear : public BaseItem
{
public:
	Spear() : BaseItem("창", "창병") {}
};

//전차용 말
class TankHorse : public BaseItem
{
public:
	TankHorse() : BaseItem("전차용_말", "전차") {}
};

//기수
class TankHorseController :public BaseItem
{
public:
	TankHorseController() : BaseItem("기수", "전차", "전차용_말") {}
};

//기마용 말
class CavalryHorse : public BaseItem
{
public:
	CavalryHorse() : BaseItem("기마용_말", "기마") {}
};

//안장
class Saddle : public BaseItem
{
public:
	Saddle() : BaseItem("안장", "기마", "기마용_말") {}
};