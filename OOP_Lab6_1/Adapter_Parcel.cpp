#include "Adapter_Parcel.h"
Adapter_Parcel::Adapter_Parcel(Buketik* buke)
{
	bukt = buke;
	
	this->dlina = buke->d;
	this->shirina = buke->w;
	this->visota = buke->l;

	this->weight = buke->ves;
}

void Adapter_Parcel::set_information()
{
	//bukt->set_inf();

	this->generate_id();
	//���������� �����������
	do
	{
		cout << "���� ���������� � ����� �������\n\n���������� ����� ������� (id): " << this->id;
		cout << "\n\n������� ����� �����������: ";
		getline(cin, this->town_sender);
	} while (this->town_sender == "");

	vector<string> town = { "�������", "������", "�����������", "�����������", "������ ��������" };
	int num_town;
	do
	{
		cout << "\n\n1) �������\n2) ������\n3) �����������\n4) �����������\n5) ������ ��������";
		cout << "\n\n�������� ����� ����������: ";
		num_town = _getch();
	} while (num_town < 49 || num_town >(town.size() + 48));
	this->town_recipient = town[num_town - 49];
	cout << "(" << this->town_recipient << ")";

	this->obem = this->visota * this->shirina * this->dlina;
	
	this->danger = 0;	//��������� ��������� �������
}
