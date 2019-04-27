#include "pch.h"
#include "VeryLong.h"
// verylong.cpp
// реализация обработки данных типа verylong
//---------------------------------------------------------
void VeryLong::putvl() const       //вывод на экран verylong
{
	char temp[SZ];
	strcpy_s(temp , vlen+1 , vlstr); //создать копию
	cout << _strrev(temp);         //перевернуть копию
}                                  //и вывести ее
//---------------------------------------------------------
void VeryLong::getvl()             //получить сверхбольшое число от
							       //пользователя
{
	cin >> vlstr;                  //получить строку от пользователя
	vlen = strlen(vlstr);          //найти ее длину
	_strrev(vlstr);                //перевернуть ее
}
//---------------------------------------------------------
VeryLong VeryLong::operator + (const VeryLong v)
//сложение
{
	char temp[SZ];
	int j;
	//найти самое длинное число
	int maxlen = (vlen > v.vlen) ? vlen : v.vlen;
	int carry = 0;                 //установить в 1, если сумма >= 10
	for (j = 0; j < maxlen; j++)   //и так для каждой позиции
	{
		int d1 = (j > vlen - 1) ? 0 : vlstr[j] - '0';    //получить
													     //разряд
		int d2 = (j > v.vlen - 1) ? 0 : v.vlstr[j] - '0'; //и еще
		int digitsum = d1 + d2 + carry;  //сложить разряды
		if (digitsum >= 10)              //если перенос, то
		{
			digitsum -= 10; carry = 1;
		}   //увеличить сумму на 10
		else                        //установить перенос в 1
			carry = 0;              //иначе перенос = 0
		temp[j] = digitsum + '0';   //вставить символ в строку
	}
	if (carry == 1)                 //если перенос в конце,
		temp[j++] = '1';            //последняя цифра = 1
	temp[j] = '\0';                 //поставить ограничитель строки
	return VeryLong(temp);          //вернуть временный verylong
}
//---------------------------------------------------------
VeryLong VeryLong::operator * (const VeryLong v)//умножение
{                                             //сверхбольших чисел
	VeryLong pprod;            //произведение одного разряда
	VeryLong tempsum;          //текущая сумма
	for (int j = 0; j < v.vlen; j++)//для каждого разряда аргумента
	{
		int digit = v.vlstr[j] - '0'; //получить разряд
		pprod = multdigit(digit);     //умножить текущий на него
		for (int k = 0; k < j; k++)   //умножить результат на
			pprod = mult10(pprod);    //  степень 10-ти
		tempsum = tempsum + pprod;    //прибавить произведение к
									  //текущей сумме
	}
	return tempsum;                  //вернуть полученную текущую сумму
}

VeryLong VeryLong::operator / (unsigned long n)
{
	VeryLong temp(0.0);
	strcpy_s(vlstr, vlen+1, _strrev(vlstr));
	int p1 = 0; int ost = 0; int t = 0; int c = vlen;
	int count = 0;
	while (true)
	{
		while (true)
		{
			p1 = p1 * 10 + (vlstr[count] - '0');
			if (p1 >= n) break;
			count++;
		}
		t = p1 / 8;
		temp = temp * 10.0 + t;
		ost = p1 - t * n;
		p1 = p1 * 10 + (vlstr[count++] - '0');
		if (count == vlen) break;
	}
	return temp;
}

bool VeryLong::operator==(const VeryLong vl)
{
	for (int i = 0; i < vlen; i++) {
		if (vlstr[i] != vl.vlstr[i]) return false;
	}
	return true;
}

bool VeryLong::operator<(const VeryLong n)
{
	for (int i = 0; i < vlen; i++) {
		if (vlstr[i] - '0' > n.vlstr[i] - '0') {
			if (i == vlen - 1 && vlstr[i] - '0' >= n.vlstr[i] - '0')
				return false;
			return false;
		}
	}
	return true;
}

unsigned long VeryLong::operator % (const unsigned n)
{
	return 1;
}
//---------------------------------------------------------
VeryLong VeryLong::mult10(const VeryLong v) const //умножение аргумента 
												  //на 10
{
	char temp[SZ];
	for (int j = v.vlen - 1; j >= 0; j--)//сдвинуться на один разряд
		temp[j + 1] = v.vlstr[j];        //выше
	temp[0] = '0';                       //обнулить самый младший разряд
	temp[v.vlen + 1] = '\0';             //поставить ограничитель строки
	return VeryLong(temp);               //вернуть результат
}
//---------------------------------------------------------
VeryLong VeryLong::multdigit(const int d2) const
{                          //умножение числа на
	char temp[SZ];         //аргумент (цифру)
	int j, carry = 0;
	for (j = 0; j < vlen; j++)    //для каждого разряда
	{              //  в этом сверхбольшом
		int d1 = vlstr[j] - '0';   //получить значение разряда
		int digitprod = d1 * d2;   //умножить на цифру
		digitprod += carry;        //добавить старый перенос
		if (digitprod >= 10)       //если возник новый перенос,
		{
			carry = digitprod / 10;  //переносу присвоить //значение старшего разряда
			digitprod -= carry * 10; //результату - младшего
		}
		else
			carry = 0;             //иначе перенос = 0
		temp[j] = digitprod + '0'; //вставить символ в строку
	}
	if (carry != 0)                //если на конце перенос,
		temp[j++] = carry + '0';   //это последний разряд
	temp[j] = '\0';                //поставить ограничитель
	return VeryLong(temp);         //вернуть сверхбольшое число
}


