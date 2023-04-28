#include "Info_Expert.h"

void Info_Expert::set_cost(Parcel parc)
{
	double temp_ves_razmer[4];
	parc.get_ves_razmer(temp_ves_razmer);		//заполнение данными
	ves.push_back(temp_ves_razmer);
}

void Info_Expert::cost_parcel()
{


	for (int i = 0;i < ves.size();i++)
	{
		ves[i]->
	}


	//узнать количество посылок
	//узнать вес посылки
	//каждый 1кг посылки для перевозчика имеет стоимость перевозки 250р
	//узнать общую стоимость перевозки

	//каждый 1кг посылки для потребителя имеет стоимость перевозки 




	
}
