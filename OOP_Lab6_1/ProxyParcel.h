#pragma once
#include "Parcel.h"
#include "Big_Cont.h"

class ProxyParcel :
    public Parcel
{
private:
    Parcel* Parce;

public:
    ProxyParcel(Parcel* parc) :Parcel()
    {
        Parce = parc;
        /*cout << "this" << this->Parce->obem << "\n";
        cout << "parc" << parc->obem;
        _getch();
        */
    };

    bool check_info();  //�������� �������� ���������
    bool send_parcel();   //��������� ���������� �������. ����� ���������� ������� ��� ���     � ������������ 1/3


};

