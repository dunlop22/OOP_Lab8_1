#include "Composite_Cont.h"

//�������� ������� ����� � ����������
bool check_space(Transport trans, Container* Cont)
{
	if (trans.check_free_obem() >= Cont->space_obem())
	{
		return true;
	}
	return false;
}

//�������� ������������ ���� ����������
bool check_vid(Transport trans, int tip)
{
	if (trans.tip_tranporta == tip)
	{
		return true;
	}
	return false;
}

void Composite_Cont::accumulation_parcel(Container* Cont)
{
	int rez;
	if (children.size() != 0)		//�������� �� ������� �����-���� �����������
	{
		for (auto iter = children.begin(); iter != children.end(); iter++)		//������� ���� ����� ����������
		{
			rez = 0;
			if (check_vid((*iter), Cont->vid_transporta))		//�������� ���������� ����� ����������
			{
				rez++;
				if (check_space((*iter), Cont))    //�������� ���������� ����� � ����������
				{
					rez++;
					//��������� ����� ����, ��� ���������� ���������
					//���������� ���������� � ���������


				}
			}
			if (rez == 2)
			{
				//���������� ���������� � ���������
				(*iter).add_cont(*Cont);

				return;
			}
		}
	}
	      //�������� ������ ���� ����������

	Transport* temp_tranport = new Automobile_Trans();
	delete temp_tranport;
	if (Cont->vid_transporta == 1)
	{
		temp_tranport = new Automobile_Trans();
		temp_tranport->tip_tranporta = 1;
	}
	else if (Cont->vid_transporta == 2)
	{
		temp_tranport = new Railway_Trans();
		temp_tranport->tip_tranporta = 2;
	}
	else if (Cont->vid_transporta == 3)
	{
		temp_tranport = new Fly_Trans();
		temp_tranport->tip_tranporta = 3;
	}
	temp_tranport->add_cont(*Cont);//���������� ���������� � ���������
	children.push_back(*temp_tranport);		//���������� ������ ���������� � ������
}

void Composite_Cont::print_info()
{
	if (children.size() != 0)		//�������� �� ������� ������-���� ����������
	{
		for (auto iter = children.begin(); iter != children.end(); iter++)		//������� ���� ����� ����������
		{
			(*iter).print_information();	//����� ���������� � ���������� �����������
		}
		cout << "\n\n����� ����������: " << children.size();
	}
}
