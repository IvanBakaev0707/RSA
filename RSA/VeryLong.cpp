#include "pch.h"
#include "VeryLong.h"
// verylong.cpp
// ���������� ��������� ������ ���� verylong
//---------------------------------------------------------
void VeryLong::putvl() const       //����� �� ����� verylong
{
	char temp[SZ];
	strcpy_s(temp , vlen+1 , vlstr); //������� �����
	cout << _strrev(temp);         //����������� �����
}                                  //� ������� ��
//---------------------------------------------------------
void VeryLong::getvl()             //�������� ������������ ����� ��
							       //������������
{
	cin >> vlstr;                  //�������� ������ �� ������������
	vlen = strlen(vlstr);          //����� �� �����
	_strrev(vlstr);                //����������� ��
}
//---------------------------------------------------------
VeryLong VeryLong::operator + (const VeryLong v)
//��������
{
	char temp[SZ];
	int j;
	//����� ����� ������� �����
	int maxlen = (vlen > v.vlen) ? vlen : v.vlen;
	int carry = 0;                 //���������� � 1, ���� ����� >= 10
	for (j = 0; j < maxlen; j++)   //� ��� ��� ������ �������
	{
		int d1 = (j > vlen - 1) ? 0 : vlstr[j] - '0';    //��������
													     //������
		int d2 = (j > v.vlen - 1) ? 0 : v.vlstr[j] - '0'; //� ���
		int digitsum = d1 + d2 + carry;  //������� �������
		if (digitsum >= 10)              //���� �������, ��
		{
			digitsum -= 10; carry = 1;
		}   //��������� ����� �� 10
		else                        //���������� ������� � 1
			carry = 0;              //����� ������� = 0
		temp[j] = digitsum + '0';   //�������� ������ � ������
	}
	if (carry == 1)                 //���� ������� � �����,
		temp[j++] = '1';            //��������� ����� = 1
	temp[j] = '\0';                 //��������� ������������ ������
	return VeryLong(temp);          //������� ��������� verylong
}
//---------------------------------------------------------
VeryLong VeryLong::operator * (const VeryLong v)//���������
{                                             //������������ �����
	VeryLong pprod;            //������������ ������ �������
	VeryLong tempsum;          //������� �����
	for (int j = 0; j < v.vlen; j++)//��� ������� ������� ���������
	{
		int digit = v.vlstr[j] - '0'; //�������� ������
		pprod = multdigit(digit);     //�������� ������� �� ����
		for (int k = 0; k < j; k++)   //�������� ��������� ��
			pprod = mult10(pprod);    //  ������� 10-��
		tempsum = tempsum + pprod;    //��������� ������������ �
									  //������� �����
	}
	return tempsum;                  //������� ���������� ������� �����
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
VeryLong VeryLong::mult10(const VeryLong v) const //��������� ��������� 
												  //�� 10
{
	char temp[SZ];
	for (int j = v.vlen - 1; j >= 0; j--)//���������� �� ���� ������
		temp[j + 1] = v.vlstr[j];        //����
	temp[0] = '0';                       //�������� ����� ������� ������
	temp[v.vlen + 1] = '\0';             //��������� ������������ ������
	return VeryLong(temp);               //������� ���������
}
//---------------------------------------------------------
VeryLong VeryLong::multdigit(const int d2) const
{                          //��������� ����� ��
	char temp[SZ];         //�������� (�����)
	int j, carry = 0;
	for (j = 0; j < vlen; j++)    //��� ������� �������
	{              //  � ���� ������������
		int d1 = vlstr[j] - '0';   //�������� �������� �������
		int digitprod = d1 * d2;   //�������� �� �����
		digitprod += carry;        //�������� ������ �������
		if (digitprod >= 10)       //���� ������ ����� �������,
		{
			carry = digitprod / 10;  //�������� ��������� //�������� �������� �������
			digitprod -= carry * 10; //���������� - ��������
		}
		else
			carry = 0;             //����� ������� = 0
		temp[j] = digitprod + '0'; //�������� ������ � ������
	}
	if (carry != 0)                //���� �� ����� �������,
		temp[j++] = carry + '0';   //��� ��������� ������
	temp[j] = '\0';                //��������� ������������
	return VeryLong(temp);         //������� ������������ �����
}


