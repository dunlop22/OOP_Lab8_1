#pragma once
#define _CRT_SECURE_NO_WARNINGS
//#include "Container.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
class Parcel
{
public:
	int danger;
	double obem;
	int id;
	string town_sender;
	string town_recipient;
	double shirina;
	double visota;
	double dlina;
	double weight;

public:
	virtual void set_parcel(Parcel* parc);  //��������� �������� �������
	virtual bool check_info();  //�������� �������� ���������
	virtual bool send_parcel();   //��������� ���������� �������. ����� ���������� ������� ��� ���     � ������������ 1/3
	
	int get_id();	//����������� id

	//����� ���������� � �������
	void print_information();

	//��������� ���������� ������ ��� ������� (����������� �������� ������������)
	void generate_id();

	//��������� ������ ����������
	string get_town();

	//�������� ���������� � �������
	virtual void set_information();

	double get_cost();
};

