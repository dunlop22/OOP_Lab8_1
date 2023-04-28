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
//вывод информации о посылке
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
	cout << " (" << this->shirina << "x" << this->dlina << "x" << this->visota << ") " << this->weight << "кг. " << this->obem << " (м^3)\n";
}

//генерация случайного номера для посылки (реализовать проверку уникальности)
void Parcel::generate_id()
{
	//генерация случайного 8-ми значного номера id
	this->id = 10000000 + rand() % 90000000;
	//проверка индивидуальности данного номера (как???)
}

//получение города получателя
string Parcel::get_town()
{
	return (this->town_recipient);
}

void Parcel::set_information()
{
	//генерация индивидуального 8-значного номера посылки (ID)
	generate_id();

	do
	{
		system("cls");
		cout << "Ввод информации о новой посылке\n\nУникальный номер посылки (id): " << this->id;
		cout << "\n\nВведите город отправителя: ";
		getline(cin, this->town_sender);
	} while (this->town_sender == "");

	vector<string> town = { "Барнаул", "Москва", "Новосибирск", "Владивосток", "Нижний Новгород" };
	int num_town;
	do
	{
		cout << "\n\n1) Барнаул\n2) Москва\n3) Новосибирск\n4) Владивосток\n5) Нижний Новгород";
		cout << "\n\nВыберите город получателя: ";
		num_town = _getch();
	} while (num_town < 49 || num_town >(town.size() + 48));
	this->town_recipient = town[num_town - 49];
	cout << "(" << this->town_recipient << ")";

	cout << "\n\nВведите ширину (м.): ";
	cin >> this->shirina;
	//this->shirina = 8 + rand() % (54 - 8 + 1);		//генерация случайного значения объема (для теста)

	cout << "\nВведите высоту (м.): ";
	cin >> this->visota;
	//this->visota = 8 + rand() % (54 - 8 + 1);		//генерация случайного значения объема (для теста)

	cout << "\nВведите длину (м.): ";
	cin >> this->dlina;
	//this->dlina = 8 + rand() % (54 - 8 + 1);		//генерация случайного значения объема (для теста)

	cout << "\nИтоговый объем (м^3): ";
	this->obem = this->dlina * this->visota * this->shirina;
	cout << this->obem;
	//this->obem = 8 + rand() % (54 - 8 + 1);		//генерация случайного значения объема (для теста)

	cout << "\n\nВведите вес (кг.): ";
	cin >> this->weight;
	//this->weight = 8 + rand() % (54 - 8 + 1);		//генерация случайного значения объема (для теста)
	do
	{
		cout << "\n\nПосылка опасная? (1 - ДА, 2 - НЕТ): ";
		this->danger = _getch();
	} while (this->danger != 49 && this->danger != 50);
	this->danger = this->danger - 48;


	if (this->danger == 1)
	{
		cout << "Да";
	}
	else
	{
		cout << "Нет";
	}

	cout << "\n\nЛюбая клавиша для подтверждения";
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
