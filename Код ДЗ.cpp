#include <iostream>

#include <vector>
#include <string>

#include <iomanip>

using namespace std;
string showVector(vector<long long int> vec)
{
	string num;
	const char a[27] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] < 0)
		{
			if (i == 0)
			{
				vec[i] = -vec[i];

				num.append("-");
			}
			else
			{
				cout << "Wrong number";
			}
		}
		if (vec[i] < 10)
		{

			num.append(to_string(vec[i]));
		}
		else if (vec[i] - 10 < 26)
		{

			num.push_back(a[vec[i] - 10]);
		}
		else
		{
			cout << "The numbers are too big :(";
			break;
		}
	}

	return num;
}
long long int fromAnyto10(string stra, int n)
{
	vector <long long int> a;
	bool* signflag = new bool(false);
	for (int j = 0; j < stra.size(); j++)
	{
		int* ascii = new int(stra[j]);
		if ((*ascii == 45) && !(*signflag))
		{
			*signflag = true;
		}
		if ((47 < *ascii) && (*ascii < 58))
		{
			a.push_back(*ascii - 48);
		}
		else if ((64 < *ascii) && (*ascii < 91))
		{
			a.push_back(*ascii - 55);
		}
		delete ascii;
	}
	long long int* c = new  long long int(0);
	if (n > 0)
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] < n)
			{
				*c += a[i] * pow(n, a.size() - 1 - i);
			}
			else
			{
				cout << "Wrong number: " << endl;
				showVector(a);
				break;
			}
		}
		if (*signflag)
		{
			*c = -*c;
		}
		return *c;
	}
	else
	{
		cout << "Wrong number: " << n;
	}
	delete c;
	delete signflag;
}
string from10toAny(long long int a, int n)
{
	vector<long long int> c;
	bool* signflag = new bool(false);

	if (n > 0)
	{
		if (a == 0)
		{
			c.insert(c.begin(), 0);
		}
		if (a < 0)
		{
			a = -a;
			*signflag = true;
		}
		while (a > 0)
		{
			c.insert(c.begin(), a % n);
			a = a / n;
		}
		if (*signflag)
		{
			c[0] = -c[0];
		}

		return showVector(c);
	}
	else
	{
		cout << "Wrong sign: " << n << endl;
	}
	delete signflag;
}


int main()
{

	setlocale(LC_ALL, "RU");

	string mantiss = "11001011010101101101";
	string order = "10000";

	long double* man = new long double(0);
	long double* ord = new long double(0);
	long double* ans = new long double(0);

	*man = fromAnyto10(mantiss, 2);
	*ord = fromAnyto10(order, 2);

	*ans = (*man / *ord);

	cout << "������� 1: ������� � ���� ������� ���������" << endl << "����(��������, �������� ������� �����): " << endl << mantiss << ", " << order << endl;
	cout << "�����: " << endl;
	cout << setprecision(20) << *ans << endl;
	cout << "������� ���������: ��������, �������� ������� ����� " << endl;
	cout << "2: " << from10toAny(*man, 2) << ", " << from10toAny(*ord, 2) << endl;
	cout << "8: " << from10toAny(*man, 8) << ", " << from10toAny(*ord, 8) << endl;
	cout << "10: " << *man << " " << *ord << endl;
	cout << "16: " << from10toAny(*man, 16) << ", " << from10toAny(*ord, 16) << endl << endl;


	mantiss = "A1B3C";
	order = "100";

	*man = fromAnyto10(mantiss, 16);
	*ord = fromAnyto10(order, 16);

	*ans = (*man / *ord);

	cout << "������� 2: ������� � ���� ������� ���������" << endl << "����(��������, �������� ������� �����): " << endl << mantiss << ", " << order << endl;
	cout << "�����: " << endl;
	cout << setprecision(20) << *ans << endl;
	cout << "������� ���������: ��������, �������� ������� ����� " << endl;
	cout << "2: " << from10toAny(*man, 2) << ", " << from10toAny(*ord, 2) << endl;
	cout << "8: " << from10toAny(*man, 8) << ", " << from10toAny(*ord, 8) << endl;
	cout << "10: " << *man << ", " << *ord << endl;
	cout << "16: " << from10toAny(*man, 16) << ", " << from10toAny(*ord, 16) << endl << endl;

	long double* man1 = new long double(0);
	long double* ord1 = new long double(0);

	mantiss = "101111010101";
	order = "1000";

	string mantiss1 = "1110101011";
	string order1 = "1000";

	*man = fromAnyto10(mantiss, 2);
	*ord = fromAnyto10(order, 2);
	*man1 = fromAnyto10(mantiss1, 2);
	*ord1 = fromAnyto10(order1, 2);

	*ans = (*man / *ord) + (*man1 / *ord1);

	cout << "������� 3: ����� ����� � ������� � ���� ������� ��������� " << endl << "����(��������, �������� ������� �����): " << endl << mantiss << ", " << order << endl << mantiss1 << ", " << order1 << endl;
	cout << "�����: " << endl;
	cout << setprecision(20) << *ans << endl;
	cout << "������� ���������: ����� " << endl;
	cout << "2: " << from10toAny(*ans, 2) << endl;
	cout << "8: " << from10toAny(*ans, 8) << endl;
	cout << "10: " << *ans << endl;
	cout << "16: " << from10toAny(*ans, 16) << endl << endl;


	mantiss = "5E8A";
	order = "1";

	mantiss1 = "124552";
	order1 = "100";

	*man = fromAnyto10(mantiss, 16);
	*ord = fromAnyto10(order, 16);
	*man1 = fromAnyto10(mantiss1, 8);
	*ord1 = fromAnyto10(order1, 8);

	*ans = (*man / *ord) * (*man1 / *ord1);

	cout << "������� 4: ������������ ����� � ������� � ���� ������� ��������� " << endl << "����(��������, �������� ������� �����): " << endl << mantiss << ", " << order << endl << mantiss1 << ", " << order1 << endl;
	cout << "�����: " << endl;

	cout << setprecision(15) << *ans << endl;

	*ord = 10000;
	*man = (*ans) * (*ord);

	cout << "������� ���������: ��������, �������� ������� ����� " << endl;
	cout << "2: " << from10toAny(*man, 2) << ", " << from10toAny(*ord, 2) << endl;
	cout << "8: " << from10toAny(*man, 8) << ", " << from10toAny(*ord, 8) << endl;
	cout << "10: " << *man << ", " << *ord << endl;
	cout << "16: " << from10toAny(*man, 16) << ", " << from10toAny(*ord, 16) << endl << endl;


	delete man1;
	delete ord1;

	*ans = ((fromAnyto10("2FA4A", 16) / fromAnyto10("100", 16) + fromAnyto10("33324", 8) / fromAnyto10("100", 8)) * fromAnyto10("101001111", 2) / fromAnyto10("1000", 2)) / (fromAnyto10("9E2", 16) / fromAnyto10("1", 16) - fromAnyto10("101011001", 2) / fromAnyto10("100", 2));
	cout << "������� 5: ����� �������� ��������� ((n16 + n8) * n2)/(n16 - n2)" << endl << "����(��������, �������� ������� �����): " << endl << "2FA4A, 100" << endl << "33324 100" << endl << "101001111, 1000" << endl << "9E2, 1" << endl << "101011001, 100" << endl;
	cout << "�����: " << endl;

	cout << setprecision(15) << *ans << endl;


	cout << "������� ���������: ����� " << endl;
	cout << "2: " << from10toAny(*ans, 2) << endl;
	cout << "8: " << from10toAny(*ans, 8) << endl;
	cout << "10: " << *ans << endl;
	cout << "16: " << from10toAny(*ans, 16) << endl << endl;


	*ans = ((fromAnyto10("100110111", 2) / fromAnyto10("100", 2) - fromAnyto10("11101", 2) / fromAnyto10("10", 2)) * (fromAnyto10("C52", 16) / fromAnyto10("1", 16) + fromAnyto10("645", 8) / fromAnyto10("100", 8))) / (fromAnyto10("7A9", 16) / fromAnyto10("1", 16) + fromAnyto10("101011011", 2) / fromAnyto10("1000", 2));
	cout << "������� 6: ����� �������� ��������� ((n2 - n2)*(n16 + n8))/(n16 + n2)" << endl << "����(��������, �������� ������� �����): " << endl << "100110111, 100" << endl << "11101, 10" << endl << "C52, 1" << endl << "645, 100" << endl << "7A9, 1" << endl << "101011011, 1000" << endl;
	cout << "�����: " << endl;

	cout << setprecision(15) << *ans << endl;

	*ord = 1;
	*man = (*ans) * (*ord);

	cout << "������� ���������: ����� " << endl;
	cout << "2: " << from10toAny(*ans, 2) << endl;
	cout << "8: " << from10toAny(*ans, 8) << endl;
	cout << "10: " << *ans << endl;
	cout << "16: " << from10toAny(*ans, 16) << endl << endl;
	delete ord;
	delete man;
	delete ans;

	cout << "������� 7: " << endl << "������������� 4 � 1, ����� 1, ���� d2 ��� d3 �������.\n������� q = (a1 * !a0 * d2) + (a1 * a0 * d3)" << endl;
	cout << "������� ����������: " << endl;
	cout << "a1 a0 d2 d3 q" << endl;

	for (int a1 = 0; a1 < 2; a1++)
	{
		for (int a0 = 0; a0 < 2; a0++)
		{
			for (int d2 = 0; d2 < 2; d2++)
			{
				for (int d3 = 0; d3 < 2; d3++)
				{
					if ((a1 && !a0 && d2) || (a1 && a0 && d3))
					{
						cout << a1 << "  " << a0 << "  " << d2 << "  " << d3 << "  1" << endl;
					}
					else
					{
						cout << a1 << "  " << a0 << "  " << d2 << "  " << d3 << "  0" << endl;
					}
				}
			}
		}
	}
	cout << endl;

	cout << "������� 8: " << endl << "������������� 8 � 1, ����� 1, ���� d3 ��� d6 ��� d7 �������.\n������� q = (!a2 * a1 * a0 * d3) + (a2 * a1 * !a0 * d6) + (a2 * a1 * a0 * d7)" << endl;
	cout << "������� ����������: " << endl;
	cout << "a2 a1 a0 d3 d6 d7 q" << endl;
	for (int a2 = 0; a2 < 2; a2++)
	{
		for (int a1 = 0; a1 < 2; a1++)
		{
			for (int a0 = 0; a0 < 2; a0++)
			{
				for (int d3 = 0; d3 < 2; d3++)
				{
					for (int d6 = 0; d6 < 2; d6++)
					{
						for (int d7 = 0; d7 < 2; d7++)
						{
							if ((!a2 && a1 && a0 && d3) || (a2 && a1 && !a0 && d6) || (a2 && a1 && a0 && d7))
							{
								cout << a2 << "  " << a1 << "  " << a0 << "  " << d3 << "  " << d6 << "  " << d7 << " 1" << endl;
							}
							else
							{
								cout << a2 << "  " << a1 << "  " << a0 << "  " << d3 << "  " << d6 << "  " << d7 << " 0" << endl;
							}
						}
					}
				}
			}
		}
	}

	return 0;

}