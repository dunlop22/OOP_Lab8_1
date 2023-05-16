#pragma once
#include "Parcel.h"
#include "ProxyParcel.h"
#include <iostream>
#include <conio.h>
#include <locale.h>   
#include <windows.h>
#include <vector>
class Facade		//процесс приемки новой посылки
{
public:
	void get_new_parcel(vector<Parcel> parcel_spisok, int num_parcel);
};

