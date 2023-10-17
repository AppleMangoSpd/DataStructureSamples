#pragma once
#include "Node.h"

//기초유닛
class BaseUnit : public Node
{
public:
	BaseUnit() : Node("Base Unit"){}
	BaseUnit(std::string name) : Node(name) {}
};

//투석
class Catapult : public BaseUnit
{
public:
	Catapult() : BaseUnit("투석") {}
};

//보병
class Swordman : public BaseUnit
{
public:
	Swordman() : BaseUnit("보병") {}
};

//궁병
class Archer : public BaseUnit
{
public:
	Archer() : BaseUnit("궁병") {}
};

//창병
class Spearman : public BaseUnit
{
public:
	Spearman() : BaseUnit("창병") {}
};

//전차
class Tank : public BaseUnit
{
public:
	Tank() : BaseUnit("전차") {}
};

//기마
class Cavalry : public BaseUnit
{
public:
	Cavalry() : BaseUnit("기마") {}
};