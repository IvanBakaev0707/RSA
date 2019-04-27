#pragma once

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
//#pragma warning(disable : 4996)
using namespace std;

const int SZ = 40000; //85000

class VeryLong
{
	char vlstr[SZ];
	int vlen;
	VeryLong multdigit(const int) const;
	VeryLong mult10(const VeryLong) const;
public:
	VeryLong() : vlen(0)
	{
		vlstr[0] = '\0';
	}
	VeryLong(const char* c)
	{
		int l = strlen(c);
		strcpy_s(vlstr, l+1, c);
		vlen = l;
	}
	VeryLong(const unsigned long n)
	{
		_ltoa_s(n, vlstr, 10);
		_strrev(vlstr);
		vlen = strlen(vlstr);
	}
	void putvl() const;
	void getvl();
	VeryLong operator + (const VeryLong);
	VeryLong operator * (const VeryLong);
	VeryLong operator / (unsigned long n);
	bool operator == (const VeryLong);
	bool operator < (const VeryLong);
	unsigned long operator % (const unsigned n);
};

