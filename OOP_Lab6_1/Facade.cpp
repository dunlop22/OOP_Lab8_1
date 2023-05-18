#include "Facade.h"

void Facade::get_new_parcel(vector<Parcel> parcel_spisok, int num_parcel)
{
    int lang;   //флажок для выбора языка интерфейса
    do
    {
        system("cls");
        cout << "Выберите язык интерфейса / Select the interface language\n\n1) Русский язык\n2) English Language\n\n";
        lang = _getch();
    } while (lang != 49 && lang != 50);

    if (lang == 49) //переключение на русский язык интерфейса
    {

    }
    else if (lang == 50)    //переключение на английский язык интерфейса
    {

    }


    int new_parcel; ///количество новых посылок
    do
    {
        system("cls");
        cout << "Введите количество новых посылок: ";
        cin >> new_parcel;
    } while (new_parcel < 0);
    cin.get();

    for (int i = 0; i < new_parcel; i++)
    {
        Parcel parce_temp;
        Parcel* Prox;
        do
        {
            parce_temp.set_information();
            Prox = new ProxyParcel(&parce_temp);
            //} while (!(Prox->check_info()) || !(Prox->send_parcel()));        //минимальная  проверка. Опасный груз не может быть больше 50усл.ед.
        } while (!(Prox->check_info()));        //минимальная  проверка. Опасный груз не может быть больше 50усл.ед.

        parcel_spisok.push_back(parce_temp);
    }
    num_parcel = num_parcel + new_parcel;       //общее количество посылок (вместе с только что добавленными)

}
