#include "Transport_Company.h"


Transport_Company* Transport_Company::instance = NULL;



Transport_Company* Transport_Company::Instance()
{
    if (instance == 0)
    {

        cout << "Транспортная компания ООО \"Везуха\" создана \n";
        instance = new Transport_Company();
    }
    else
    {
        cout << "Транспортная компания ООО \"Везуха\" уже осуществляет свою деятельность на территории РФ\n";
    }
    return instance;
}