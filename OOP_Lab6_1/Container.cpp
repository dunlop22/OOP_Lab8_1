#include "Container.h"


double Container::space_obem()
{
	return this->space;
}

int Container::gen_vid_transporta()
{
	return (1 + rand() % (3));
}

bool Container::check_danger()
{
	return false;
}

void Container::generate_id()
{
	this->id = 10000 + rand() % 90000;
}

int Container::get_id()
{
	return this->id;
}


void Container::get_parcel(Parcel parc)
{
	this->town = parc.get_town();
	this->parce.push_back(parc);	//��������� ������� � ������
	this->free_obem = this->free_obem - parc.obem;
	this->kol_vo_parcel = kol_vo_parcel + 1;
}

//�������� ���������� ������ � ����������
bool Container::check_free_obem(double obem)
{
	if (this->free_obem >= obem)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string Container::get_town()
{
	return (this->town);
}

void Container::print_information_c(int tip)
{
	cout << "ID: " << this->id << "\n";
	for (int i = 0;i < parce.size();i++)
	{
		cout << "     --";
		this->parce[i].print_information();
	}
	if (tip == 1)
	{
		cout << "��������� ����� � ����������: " << this->free_obem << "�^3\n\n";
		cout << "��� ����������: ";
		if (this->vid_transporta == 1)		//������������� ���������
		{
			cout << "�������������\n\n";
		}
		else if (this->vid_transporta == 2)		//��������������� ���������
		{
			cout << "���������������";
		}
		else if (this->vid_transporta == 3)		//��������� ���������
		{
			cout << "���������";
		}
	}
	
}

vector<Parcel> Container::get_inf_parcel()
{
	return this->parce;
}
