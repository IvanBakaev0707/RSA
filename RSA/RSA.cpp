#include "pch.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <random>
#include <time.h>
#include <algorithm>
#include "VeryLong.h"

using namespace std;

int NOD(int a, int b)
{
	while (a > 0 && b > 0)
		if (a > b)
			a %= b;
		else
			b %= a;
	return a + b;
}

bool IsPrime(int n)
{
	const int n2 = n / 2;
	if (n < 2) return false;
	for (int i = 2; i <= n2; ++i)
		if (n % i == 0)
			return false;
	return true;
}

int MIN(int a, int b)
{
	return (a < b) ? a : b;
}

VeryLong power(const int num, const unsigned long p) {
	VeryLong _NUM = num;
	for (int i = 0; i < p-1; ++i) {
		_NUM = _NUM * num;
	}
	return _NUM;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	const int INDEX = 168;
	int JustNum[INDEX];
	long int count = 0;

	int e;
	long int n;
	int p , q;
	int d;

	for (long int i = 0; i < 1000; i++) {
			if (IsPrime(i))
				JustNum[count++] = i;
		}
	while(true)
	{
		while(true)
		{
			p = JustNum[rand() % INDEX - 1]; // первый
			q = JustNum[rand() % INDEX - 1]; // второй
			if (p > 2 && q > 2) break;
			cout << "Ошибка!\n";
		}

		cout << "P = " << p << endl << "Q = " << q << endl;

		n = p * q;

		bool flag;
		d = (p + q) / 2;

		for (;;)
		{
			if (NOD(d, ((p - 1)*(q - 1))) == 1)
				break;
			else
			{
				d++;
				if (d > JustNum[INDEX - 1])
				{
					cout << "ERROR!\n";
					_exit(-1);
				}
			}
		}
		for (int i = 0;; i++)
		{
			if ((i*d) % ((p - 1) * (q - 1)) == 1) {
				e = i;
				break;
			}
		}
		cout << "D = " << d << endl << "E = " << e << endl;
		if (e < 40000) break;
	}
//////////////////////////////////////////////////////////////////////////////
	VeryLong vl;
	cout << endl;
	for (int i = 2; i < 11; i++) {
		vl = power(i, e);
		cout << i;
		cout << "^";
		cout << e;
		cout << " = ";
		vl.putvl();
		cout << endl << endl;
	}

	return 0;
}
