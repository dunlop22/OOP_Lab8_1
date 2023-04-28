#pragma once 
#include <string>
#include "Parcel.h"	
#include <vector>

using namespace std;

class Container
{
	//���������
	//�������
	//��� ������� ������

	int id;	//���������� �����
	string town;	//����������� ����������
	vector<Parcel> parce;
	int kol_vo_parcel = 0;		//����� ���������� ������� � ����������
	
public:
	int vid_transporta;
	int danger = 0;
			//1 - �������������
			//2 - ���������������
			//3 - ���������

protected:
	double free_obem;			//���������� ���������� ����� � ����������
	double space;

public:
	virtual double space_obem();
	virtual int gen_vid_transporta();	//��������� �������� ��������
	virtual bool check_danger();
	virtual void generate_id();
	virtual void get_parcel(Parcel parc);
	virtual bool check_free_obem(double obem);
	virtual string get_town();
	virtual int get_id();
	virtual void print_information_c(int tip);
	virtual vector<Parcel> get_inf_parcel();
};

//��������� ������� ������������ ��������

//��� �������� ���������� �� ��������������� ��� �� ����������� ��������, �� ������� �� ����� �������������