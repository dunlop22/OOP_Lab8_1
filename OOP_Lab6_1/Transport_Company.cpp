#include "Transport_Company.h"


Transport_Company* Transport_Company::instance = NULL;



Transport_Company* Transport_Company::Instance()
{
    if (instance == 0)
    {

        cout << "������������ �������� ��� \"������\" ������� \n";
        instance = new Transport_Company();
    }
    else
    {
        cout << "������������ �������� ��� \"������\" ��� ������������ ���� ������������ �� ���������� ��\n";
    }
    return instance;
}