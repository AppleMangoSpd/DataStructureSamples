#include"Troops.h"
#include "Units.h"
#include "Items.h"
int main()
{
#pragma region �δ뿡 ���� �߰� ���� �ڵ�
	Troops* troops = new Troops();

	troops->addUnit(new Catapult());
	troops->addUnit(new Swordman());
#pragma endregion



#pragma region 1�� �׷� 3�� ���� ���� ���� ���� �ڵ�
	troops->groupInfo();

	troops->addUnit(new Tank());
	troops->addUnit(new Cavalry());
	troops->addUnit(new Archer());
	troops->groupInfo();
#pragma endregion



#pragma region ������ �߰� �����ڵ�
	//������ ��� ������ �߰�
	troops->addUnitItem(new CatapultFlag());

	//�ú����� Ȱ�� ȭ�� �߰�
	troops->addUnitItem(new Arrow());
	troops->addUnitItem(new Bow());

	//������ �� ������ �߰�
	TankHorse* tank_horse = new TankHorse();
	troops->addUnitItem(tank_horse);

	//������ ��� ������ �߰�
	troops->addUnitItem(new TankHorseController());

	//���� ������ �߰� �õ�
	//���������� ���� �߰����� �ʾƼ� ����
	troops->addUnitItem(new Saddle());

	//â ������ �߰� �õ�
	//â���� ��� ����
	troops->addUnitItem(new Spear());


	troops->groupInfo();
#pragma endregion

	
	return 0;
}