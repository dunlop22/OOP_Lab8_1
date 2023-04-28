#include "Transport.h"

void Transport::generate_id()
{
	this->id = 10000 + rand() % 90000;
}

double Transport::check_free_obem()
{
	return this->free_obem;
}

//����� ���������� � ����������� �����������
void Transport::print_information()
{
	cout << "����� ����������: " << this->id << " (";
	if (this->tip_tranporta == 1)
	{
		cout << "�������������";
	}
	else if (this->tip_tranporta == 2)
	{
		cout << "���������������";
	}
	else if (this->tip_tranporta == 3)
	{
		cout << "���������";
	}
	cout << ")\n\n������ �����������:\n";		//����� ��������������� ������
	for (int i = 0;i < Conte.size();i++)		//����� ���������� � ��������� ����������� � ��������
	{
		Conte[i].print_information_c(0);
	}
	cout << "\n\n";
}

void Transport::add_cont(Container Cont)
{
	this->Conte.push_back(Cont);		//��������� ���������� � ���������
	this->free_obem = free_obem - Cont.space_obem();		//��������� ������� ����� � ����������
}
