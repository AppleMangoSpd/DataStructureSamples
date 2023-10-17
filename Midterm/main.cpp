#include"Troops.h"
#include "Units.h"
#include "Items.h"
int main()
{
#pragma region 부대에 유닛 추가 예시 코드
	Troops* troops = new Troops();

	troops->addUnit(new Catapult());
	troops->addUnit(new Swordman());
#pragma endregion



#pragma region 1개 그룹 3개 유닛 구성 제한 예시 코드
	troops->groupInfo();

	troops->addUnit(new Tank());
	troops->addUnit(new Cavalry());
	troops->addUnit(new Archer());
	troops->groupInfo();
#pragma endregion



#pragma region 아이템 추가 예시코드
	//투석기 깃발 아이템 추가
	troops->addUnitItem(new CatapultFlag());

	//궁병에게 활과 화살 추가
	troops->addUnitItem(new Arrow());
	troops->addUnitItem(new Bow());

	//전차병 말 아이템 추가
	TankHorse* tank_horse = new TankHorse();
	troops->addUnitItem(tank_horse);

	//전차병 기수 아이템 추가
	troops->addUnitItem(new TankHorseController());

	//안장 아이템 추가 시도
	//선행조건인 말을 추가하지 않아서 실패
	troops->addUnitItem(new Saddle());

	//창 아이템 추가 시도
	//창병이 없어서 실패
	troops->addUnitItem(new Spear());


	troops->groupInfo();
#pragma endregion

	
	return 0;
}