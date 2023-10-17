#pragma once
class NTree;
class Node;
class BaseItem;
class BaseUnit;

class Troops
{
public:
	Troops();
	//���� �߰�
	void addUnit(Node* added);
	//��ü ��ȸ
	void groupInfo() const;
	//������ �߰�
	void addUnitItem(BaseItem* added) const;
private:
	NTree* _nTree;
	//�δ뺰 �ִ� ���� ��
	const int _maxUnitVolume;
	//���� �δ� ��
	int _troopSize;

	//�δ� ��ȸ
	void showByTroop() const;
	//���� ��ȸ
	void showWeapon(Node* target) const;
	//���� �߰��� ���� ����ִ� �δ� ã��
	Node* findEmptyTroop();
};