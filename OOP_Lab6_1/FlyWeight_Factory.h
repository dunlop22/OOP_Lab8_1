#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>
#include <stdlib.h> 
#include <time.h> 
#include "FlyWeight.h"

using namespace std;

class FlyWeight_Factory
{
	vector <string> town_send = {"������", "�����������", "�������", "���������", "������"};
	vector <FlyWeight	> FlyWeights;
	
	/*
	typedef std::map<int, FlyWeight* > FlyWeights;
	FlyWeights mFlyWeights;
	FlyWeight* oneFlyWeight;     // �������� ��� ���������
					  // �������, ����������  
					  */
private:
	
	int random_num(int max);
public:
	FlyWeight_Factory();
	FlyWeight& get_pismo();
};

