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

//���
class CatapultFlag : public BaseItem
{
public:
	CatapultFlag() : BaseItem("���", "����") {}
};

//��
class Sword : public BaseItem
{
public:
	Sword() : BaseItem("��", "����") {}
};

//Ȱ
class Bow : public BaseItem
{
public:
	Bow() : BaseItem("Ȱ", "�ú�") {}
};

//ȭ��
class Arrow : public BaseItem
{
public:
	Arrow() : BaseItem("ȭ��", "�ú�") {}
};

//â
class Spear : public BaseItem
{
public:
	Spear() : BaseItem("â", "â��") {}
};

//������ ��
class TankHorse : public BaseItem
{
public:
	TankHorse() : BaseItem("������_��", "����") {}
};

//���
class TankHorseController :public BaseItem
{
public:
	TankHorseController() : BaseItem("���", "����", "������_��") {}
};

//�⸶�� ��
class CavalryHorse : public BaseItem
{
public:
	CavalryHorse() : BaseItem("�⸶��_��", "�⸶") {}
};

//����
class Saddle : public BaseItem
{
public:
	Saddle() : BaseItem("����", "�⸶", "�⸶��_��") {}
};