#include "FlyWeight.h"
FlyWeight::FlyWeight()
{
	this->town1 = "�������";		//����� �������� ��������
	this->contain = "�������� ��������\n \
					 ������ �������� ������� � �������������� ������";

}
void FlyWeight::set_info(string town)
{
	this->town2 = town;
}

string FlyWeight::get_info()
{
	return this->town2;
}
