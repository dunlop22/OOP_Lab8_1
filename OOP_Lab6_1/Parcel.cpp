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

void Parcel::set_information(Language* lang)
{
	//генерация индивидуального 8-значного номера посылки (ID)
	generate_id();

	do
	{
		system("cls");
		lang->print_info();
			cout << this->id;		//вывод уникального номера посылки
		lang->print_town_1();
		getline(cin, this->town_sender);
	} while (this->town_sender == "");

	vector<string> town = { "Барнаул", "Москва", "Новосибирск", "Владивосток", "Нижний Новгород" };
	int num_town;
	do
	{
		lang->print_spisok_town();
		lang->print_town_2();
		num_town = _getch();
	} while (num_town < 49 || num_town >(town.size() + 48));
	this->town_recipient = town[num_town - 49];
	cout << "(" << this->town_recipient << ")";
	
	lang->print_gabarit_1();
	cin >> this->shirina;
	//this->shirina = 8 + rand() % (54 - 8 + 1);		//генерация случайного значения объема (для теста)
	
	lang->print_gabarit_2();
	cin >> this->visota;
	//this->visota = 8 + rand() % (54 - 8 + 1);		//генерация случайного значения объема (для теста)
	
	lang->print_gabarit_3();
	cin >> this->dlina;
	//this->dlina = 8 + rand() % (54 - 8 + 1);		//генерация случайного значения объема (для теста)
	
	lang->print_size();
	this->obem = this->dlina * this->visota * this->shirina;
	cout << this->obem;
	//this->obem = 8 + rand() % (54 - 8 + 1);		//генерация случайного значения объема (для теста)
	
	lang->print_weight();
	cin >> this->weight;
	//this->weight = 8 + rand() % (54 - 8 + 1);		//генерация случайного значения объема (для теста)
	do
	{
		lang->print_danger();
		this->danger = _getch();
	} while (this->danger != 49 && this->danger != 50);
	this->danger = this->danger - 48;


	if (this->danger == 1)
	{
		lang->print_yes();
	}
	else
	{
		lang->print_no();
	}
	lang->any_key_to_cont();
	cin.ignore();
	_getch();


}

vector <double> Parcel::get_dimensions()
{
	vector <double> dimensions;
	dimensions.push_back(this->dlina);
	dimensions.push_back(this->shirina);
	dimensions.push_back(this->visota);
	dimensions.push_back(this->danger);
	dimensions.push_back(this->weight);
	
	return dimensions;
}
