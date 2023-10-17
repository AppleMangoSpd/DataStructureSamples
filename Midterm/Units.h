#pragma once
#include "Node.h"

//��������
class BaseUnit : public Node
{
public:
	BaseUnit() : Node("Base Unit"){}
	BaseUnit(std::string name) : Node(name) {}
};

//����
class Catapult : public BaseUnit
{
public:
	Catapult() : BaseUnit("����") {}
};

//����
class Swordman : public BaseUnit
{
public:
	Swordman() : BaseUnit("����") {}
};

//�ú�
class Archer : public BaseUnit
{
public:
	Archer() : BaseUnit("�ú�") {}
};

//â��
class Spearman : public BaseUnit
{
public:
	Spearman() : BaseUnit("â��") {}
};

//����
class Tank : public BaseUnit
{
public:
	Tank() : BaseUnit("����") {}
};

//�⸶
class Cavalry : public BaseUnit
{
public:
	Cavalry() : BaseUnit("�⸶") {}
};