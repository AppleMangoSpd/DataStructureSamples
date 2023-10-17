#pragma once
class NTree;
class Node;
class BaseItem;
class BaseUnit;

class Troops
{
public:
	Troops();
	//유닛 추가
	void addUnit(Node* added);
	//전체 조회
	void groupInfo() const;
	//아이템 추가
	void addUnitItem(BaseItem* added) const;
private:
	NTree* _nTree;
	//부대별 최대 유닛 수
	const int _maxUnitVolume;
	//현재 부대 수
	int _troopSize;

	//부대 조회
	void showByTroop() const;
	//무기 조회
	void showWeapon(Node* target) const;
	//유닛 추가를 위한 비어있는 부대 찾기
	Node* findEmptyTroop();
};