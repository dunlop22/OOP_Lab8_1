#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <locale.h>   
#include <windows.h>
#include "Container.h"          //контейнер
#include "Transport.h"          //транспорт
#include "Parcel.h"             //посылка
#include "Solver.h"             //решатель распределения посылок
#include <vector>
#include "ProxyParcel.h"        //прокси для посылки
#include "Decorate_Parcel.h"    //декоратор
#include "Composite_Cont.h"     //композит
#include "Buketik.h"            //класс для адаптера
#include "Adapter_Parcel.h"     //адаптер
#include "Iterator_My.h"
#include "Agregat_My.h"
#include "Element_My.h"
#include <cstdlib>;
#include "FlyWeight_Factory.h"

using namespace std;

int main()
{
    std::vector<Parcel> parcel_spisok;
    std::vector<Container> container_spisok;

    srand(time(NULL));  //для генерации случайных id
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    int num_parcel = 0;     //общее количество неотправленных посылок
    int func;   //флаг для выбора пункта меню
    do
    {
        do           //главное меню
        {
            system("cls");
            cout << "\
1) Добавить несколько новых посылок\n\
2) Отправить посылки\n\
3) Просмотр информации об имеющихся посылках\n\
4) Поместить посылки в коробки\n\
5) Создание массовой рассылки (легковес)\n\
ESC) Выход\n\nОбщее количество посылок на данный момент: " << parcel_spisok.size() << "\nОбщее количество контейнеров на данный момент: " << container_spisok.size() << "\n";
            func = _getch();
        } while (func < 49 || func > 53 && func != 27);

        if (func == 49)
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
                //ProxyParcel Prox;

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

        else if (func == 50)        //перемещение посылок
        {
            if (parcel_spisok.size() > 0)         //имеются посылки для отправления
            {
                system("cls");
                //распределение посылок по контейнерам
                Solver solv;
                solv.parcel_to_container(container_spisok, parcel_spisok, num_parcel);

                //удаление списка посылок
                for (int i = 0; i < parcel_spisok.size(); i++)
                {
                    parcel_spisok.clear();
                    parcel_spisok.shrink_to_fit();
                }

                //вывод контейнеров и их посылок
                for (int i = 0;i < container_spisok.size();i++)
                {
                    cout << "Контейнер №: " << i + 1 << "\n";
                    container_spisok[i].print_information_c(1);
                    container_spisok[i].get_cost_cont();        //подсчет стоимости перевозок посылок, содержащихся в контейнере
                    cout << "\nСтоимость посылок в контейнере: " << container_spisok[i].cost << "\n\n";
                }


                cout << "\n\n***   ***   ***   ***   ***   ***\nОбщее количество контейнеров: " << container_spisok.size();
                cout << "\n\nНажмите любую клавишу для продолжения (перемещение контейнеров в транспорт)";
                _getch();
                
                system("cls");
                
                
                /*
                string town[5] = { "Барнаул", "Москва", "Новосибирск", "Владивосток", "Нижний Новгород" };
                cout << "\n\n\nПеремещение посылок в города...\n";

                for (int i = 0; i < 5; i++)
                {
                    for (int k = 0; k < container_spisok.size(); k++)
                    {
                        if (container_spisok[k].get_town() == town[i])
                        {
                            cout << "\n__" << town[i] << "__" << "\n";
                            cout << "Контейнер (ID): " << container_spisok[k].get_id();
                            cout << "\nПосылки:\n\n";
                            for (int n = 0; n < (container_spisok[k].get_inf_parcel()).size(); n++)
                            {
                                (container_spisok[k].get_inf_parcel())[n].print_information();
                                cout << "\n";
                            }
                            for (int j = 0; j < 5; j++)
                            {
                                Sleep(500);
                                cout << "....";
                            }
                            cout << "-->" << container_spisok[k].get_town() << "\nКонтейнер доставлен!\n";
                        }
                    }
                }

                
                */

                //перемещение контейнеров(посылок) в транспорт
                Composite_Cont *Compos = new Composite_Cont();
                for (int m = 0;m < container_spisok.size();m++)
                {
                    Compos->accumulation_parcel(&(container_spisok[m]));    //проверка распределения контейнера с дальнейшим определением в транспорт
                }

                //удаление списка контейнеров
                container_spisok.clear();
                container_spisok.shrink_to_fit();
                num_parcel = 0;

                Compos->print_info();

                cout << "\n\nНажмите любую клавишу для выхода в главное меню";
                _getch();

            }
            else        //посылок для отправления нет
            {
                system("cls");
                cout << "Нет посылок для отправления!\n\nДля продолжения нажмите любую клавишу";
                _getch();
            }
        }
        else if (func == 51)        //просмотр информации о существующих посылках
        {
            system("cls");  //очистка экрана консоли

            if (parcel_spisok.size() > 0)
            {

                //вывод информации о посылках 


                //стандартный способ
                /*
                for (int i = 0; i < parcel_spisok.size(); i++)
                {
                    parcel_spisok[i].print_information();
                }
                */

                //итератор
                cout << "Просмотр списка посылок с использованием итератора\n\n";
                typedef Agregat_My<Parcel*> MyCont_Parcel;
                MyCont_Parcel contain;
                
                //добавление посылок в контейнер
                for (int i = 0;i < parcel_spisok.size(); i++)
                {
                    contain.push(&(parcel_spisok[i]));
                }

                for (MyCont_Parcel::myIter it = contain.begin(); it != contain.end(); ++it) {
                    (*(it.next()))->print_information();
                }

                cout << "\n\nНажмите любую клавишу для вывода информации информационного эксперта";
                _getch();
                system("cls");  //очистка экрана консоли    
                //работа информационного эксперта

                cout << "Стоимость перевозки посылок для потребителя (внешняя стоимость)\n\n";
                for (int i = 0;i < parcel_spisok.size(); i++)
                {
                    cout << i + 1 << ": " << parcel_spisok[i].get_cost() << "руб\n";        //установка значений
                }
            }
            else
            {
                cout << "Нет посылок для просмотра информации!";
            }
            cout << "\n\nДля продолжения нажмите любую клавишу\n";
            _getch();
        }
        else if (func == 52)    //помещение посылок в коробки
        {
            system("cls");      //очистка экрана консоли
            if (parcel_spisok.size() > 0)
            {
                for (int i = 0;i < parcel_spisok.size(); i++)
                {
                    Decorate_Parcel dec_parc(&parcel_spisok[i]);
                    dec_parc.set_information();
                    dec_parc.print_information();
                }
                    
            }
            else
            {
                cout << "Нет посылок для просмотра информации!";
            }
            cout << "\n\nДля продолжения нажмите любую клавишу\n";
            _getch();
        }
        
        //else if (func == 53)    //Адаптер Букет -> Посылка
        else if (func == 53)        //легковес
        {
            system("cls");      //очистка экрана консоли
            FlyWeight_Factory *factory = new FlyWeight_Factory();
            int nFlyWeight;
            do
            {
                cout << "Введите необходимое количество легковесов: ";
                cin >> nFlyWeight;
            } while (nFlyWeight <= 0);

            for (int i = 0;i < nFlyWeight;i++)
            {
                FlyWeight Fly = factory->get_pismo();
            }
            cout << "\n\nДля продолжения нажмите любую клавишу\n";
            _getch();

        /*
            system("cls");
            Buketik *buk = new Buketik();//создание объекта
            buk->set_inf();  //установка значений
            buk->printol(); //вывод информации о букетике


            Parcel* par_adap = new Adapter_Parcel(buk);
            par_adap->set_information();
            cout << "\n\nИнформация о посылке:\n";
            par_adap->print_information();
            cout << "Нажмите любую клавишу для продолжения";
            _getch();
            */
        }
        

    } while (func != 27);

    //drive...-> меню перемещения -> конечный пункт


}
