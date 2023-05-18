#pragma once
#include <iostream>
#include <string>
using namespace std;
class Transport_Company
{
private:
	static Transport_Company* instance;
protected:
	Transport_Company() {}
public:
	static Transport_Company* Instance();
	
};

