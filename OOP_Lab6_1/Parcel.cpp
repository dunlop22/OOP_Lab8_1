#include "Parcel.h"

void Parcel::set_parcel(Parcel* parc)
{
}

bool Parcel::check_info()
{
	return false;
}

bool Parcel::send_parcel()
{
	return false;
}

int Parcel::get_id()
{
	return (this->id);
}
//����� ���������� � �������
void Parcel::print_information()
{
	cout << this->id << " : " << this->town_sender << "-->" << this->town_recipient;
	if (this->danger == 1)
	{
		cout << " (!_DANGER_!)";
	}
	else
	{
		cout << "             ";
	}
	cout << " (" << this->shirina << "x" << this->dlina << "x" << this->visota << ") " << this->weight << "��. " << this->obem << " (�^3)\n";
}

//��������� ���������� ������ ��� ������� (����������� �������� ������������)
void Parcel::generate_id()
{
	//��������� ���������� 8-�� �������� ������ id
	this->id = 10000000 + rand() % 90000000;
	//�������� ���������������� ������� ������ (���???)
}

//��������� ������ ����������
string Parcel::get_town()
{
	return (this->town_recipient);
}

void Parcel::set_information()
{
	//��������� ��������������� 8-�������� ������ ������� (ID)
	generate_id();

	do
	{
		system("cls");
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

	cout << "\n\n������� ������ (�.): ";
	cin >> this->shirina;
	//this->shirina = 8 + rand() % (54 - 8 + 1);		//��������� ���������� �������� ������ (��� �����)

	cout << "\n������� ������ (�.): ";
	cin >> this->visota;
	//this->visota = 8 + rand() % (54 - 8 + 1);		//��������� ���������� �������� ������ (��� �����)

	cout << "\n������� ����� (�.): ";
	cin >> this->dlina;
	//this->dlina = 8 + rand() % (54 - 8 + 1);		//��������� ���������� �������� ������ (��� �����)

	cout << "\n�������� ����� (�^3): ";
	this->obem = this->dlina * this->visota * this->shirina;
	cout << this->obem;
	//this->obem = 8 + rand() % (54 - 8 + 1);		//��������� ���������� �������� ������ (��� �����)

	cout << "\n\n������� ��� (��.): ";
	cin >> this->weight;
	//this->weight = 8 + rand() % (54 - 8 + 1);		//��������� ���������� �������� ������ (��� �����)
	do
	{
		cout << "\n\n������� �������? (1 - ��, 2 - ���): ";
		this->danger = _getch();
	} while (this->danger != 49 && this->danger != 50);
	this->danger = this->danger - 48;


	if (this->danger == 1)
	{
		cout << "��";
	}
	else
	{
		cout << "���";
	}

	cout << "\n\n����� ������� ��� �������������";
	cin.ignore();
	_getch();


}

void Parcel::get_ves_razmer(double ves_razmer[])
{
	ves_razmer[0] = this->dlina;
	ves_razmer[1] = this->shirina;
	ves_razmer[2] = this->visota;
	ves_razmer[3] = this->weight;
}
