#pragma once
#include "Container.h"
class Transport
{
	//��������� �������� ����� ����������� ������ �� ������������� ����������
public:
	void generate_id();
	double check_free_obem();
	void print_information();
	void add_cont(Container Cont);
	vector<Container> Conte;
	int tip_tranporta;
			//1 - �������������
			//2 - ���������������
			//3 - ���������

protected:
	int id;	//���������� �����
	double free_obem;
};

