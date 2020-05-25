#include "SerialId.h"
#include<ctime>
#include <stdlib.h>
#include <cstring>

void SerialId::generate(string& serialId)
{
	int number;
	serialId.clear();
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		do
		{
			number =(rand() % 43 + 48);

		} while (number >= 58 && number <= 64);

		serialId += (char)number;
	}
}