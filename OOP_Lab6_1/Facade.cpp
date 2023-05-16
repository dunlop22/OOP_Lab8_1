#include "Facade.h"

void Facade::get_new_parcel(vector<Parcel> parcel_spisok, int num_parcel)
{
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
