#include "ProxyParcel.h"



bool ProxyParcel::check_info()
{
    //cout << this->obem;
    //_getch();
    if (this->Parce->danger == 1 && this->Parce->obem > 50)
    {
        cout << "\n\n�������������� ���� ������� � ����������� ������.\n������� ����� ������� ��� ���������� ����� ���������� � �������!\n";
        _getch();
        return false;
    }
    else
    {
        if (this->Parce->obem > 200)       //����� ������� ������, ��� ����� ����������
        {

            cout << "\n\n����� ������� ��������� ��������� ��������.\n������� ����� ������� ��� ���������� ����� ���������� � �������!\n";
            _getch();
            return false;
        }
        else
        {

            return true;
        }
    }

}

bool ProxyParcel::send_parcel()
{
    {
        int num = 10 + rand() % (256 - 10 + 1);
        if (num % 2 == 0)
        {
            return true;
        }
        else
        {
            cout << "\n\n���������� ��������� ������� � ������ ����� ����������.\n������� ����� ������� ��� ���������� ����� ���������� � �������!\n";
            _getch();
            return false;
        }
    }
}


