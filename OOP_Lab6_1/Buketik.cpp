#include "Buketik.h"
#include <stdlib.h>

void Buketik::set_inf()
{
	w = 0.1 + rand() % (2);
	l = 0.2 + rand() % (2);
	d = 0.3 + rand() % (2);
	ves = 0.5 + rand() % (3);
}

void Buketik::printol()
{
	cout << "������: " << this->w;
	cout << "\n�����: " << this->d;
	cout << "\n������: " << this->l;
	cout << "\n���: " << this->ves << "\n\n";
}
