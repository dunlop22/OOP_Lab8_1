#pragma once
#include "Parcel.h"
#include <algorithm>  //������� ���������� (sort)
class Decorate_Parcel :
    public Parcel
{
public:
    Parcel *Parce;
    vector <vector <double>> korobka = { {0.3, 0.4, 0.8}, {2, 2, 3}, {5, 7, 8}, {2, 8, 10} };
    string korobka_parcel;
    Decorate_Parcel(Parcel* Parc) :Parcel()
    {
        Parce = Parc;
        sort(korobka.begin(), korobka.end());       //���������� ������������ �������
    };
    virtual void print_information();
    virtual void set_information();
};

