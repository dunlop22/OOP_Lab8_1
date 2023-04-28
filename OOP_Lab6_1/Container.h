#pragma once 
#include <string>
#include "Parcel.h"	
#include <vector>

using namespace std;

class Container
{
	//маленький
	//большой
	//для опасных грузов

	int id;	//уникальный номер
	string town;	//направление контейнера
	vector<Parcel> parce;
	int kol_vo_parcel = 0;		//Общее количество посылок в контейнере
	
public:
	int vid_transporta;
	int danger = 0;
			//1 - автомобильный
			//2 - железнодорожный
			//3 - воздушный

protected:
	double free_obem;			//Количество свободного места в контейнере
	double space;

public:
	virtual double space_obem();
	virtual int gen_vid_transporta();	//генерация варианта отправки
	virtual bool check_danger();
	virtual void generate_id();
	virtual void get_parcel(Parcel parc);
	virtual bool check_free_obem(double obem);
	virtual string get_town();
	virtual int get_id();
	virtual void print_information_c(int tip);
	virtual vector<Parcel> get_inf_parcel();
};

//контейнер делегат транспортное средство

//при создании контейнера он конфигурируется под то транпортное средство, на котором он будет передвигаться