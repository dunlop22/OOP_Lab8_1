#include "Facade.h"

Facade::Facade(Language* lang)
{
    languag = lang; //��������� ���������� ����� (�� ���������: �������)
}

void Facade::get_new_parcel(vector<Parcel> *parcel_spisok, int *num_parcel)
{
    int new_parcel; ///���������� ����� �������
    do
    {
        system("cls");
        languag->print_num_parc();
        cin >> new_parcel;
    } while (new_parcel < 0);
    cin.get();

    for (int i = 0; i < new_parcel; i++)
    {
        Parcel parce_temp;
        Parcel* Prox;
        do
        {
            parce_temp.set_information(languag);
            Prox = new ProxyParcel(&parce_temp);
            //} while (!(Prox->check_info()) || !(Prox->send_parcel()));        //�����������  ��������. ������� ���� �� ����� ���� ������ 50���.��.
        } while (!(Prox->check_info()));        //�����������  ��������. ������� ���� �� ����� ���� ������ 50���.��.

       (*parcel_spisok).push_back(parce_temp);
    }
    *num_parcel = *num_parcel + new_parcel;       //����� ���������� ������� (������ � ������ ��� ������������)

}

void Facade::set_language(Language* lang)   //����� ����� (Rus -> Eng)
{
    languag = lang;
}
