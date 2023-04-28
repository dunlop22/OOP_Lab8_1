#include "Decorate_Parcel.h"

void Decorate_Parcel::print_information()
{
	Parce->print_information();
	cout << "Коробка: " << korobka_parcel;
}

void Decorate_Parcel::set_information()
{
	vector <double> razmer_item;
	razmer_item.push_back(Parce->dlina);
	razmer_item.push_back(Parce->shirina);
	razmer_item.push_back(Parce->visota);
	sort(razmer_item.begin(), razmer_item.end());	//сортировка по возрастанию посылки

	for (int i = 0; i < korobka.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (razmer_item[j] <= korobka[i][j])
			{
				if (j == 2)
				{

					korobka_parcel = std::to_string(korobka[i][0]) + "x" + std::to_string(korobka[i][1]) + "x" + std::to_string(korobka[i][2]);
					return;
				}
			}
			else
			{
				j = 4;
			}
			
		}
	}
	korobka_parcel = "Отсутствует";

}
