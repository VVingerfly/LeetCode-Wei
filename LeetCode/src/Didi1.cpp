///*
//����������R��n�����R��n�η�
//����0.0<R<99.999,0<n<=25
//
//�����������
//����ÿ��Ϊһ��������R��һ������n
//���R��n�η�
//*/
//
//
//#include <iostream>
//using namespace std;
//int main()
//{
//	char r[6] = { '0' };  //���� 
//	int n = 1;            //ָ�� 
//	while (cin >> r >> n)
//	{
//		int m[250] = { 0 };
//		int b[6] = { 0 };
//		int i, j, m_i;
//		int m_number = 0, m_data = 0;//С���������ÿ����˵����� 
//		for (i = 0;i < 6;i++)//�ҵ�С�����λ�� 
//		{
//			if (r[i] == '.')
//			{
//				m_i = i;
//				break;
//			}
//		}
//		if (i == 6)//˵��û��С����
//		{
//			j = 0;
//			while (r[j] == '0')
//			{
//				r[j] = 'a';
//				j++;
//			}
//			m_number = 0;
//		}
//		else//˵����С���� 
//		{
//			i = 0;
//			while (i < m_i&&r[i] == '0')//С����֮ǰǰ��0����Ϊ-1
//			{
//				r[i] = 'a';
//				i++;
//			}
//			i = 5;
//			while (i > m_i && (!r[i] || r[i] == '0'))//С����֮��ĺ�׺�㴦�� 
//			{
//				r[i] = 'a'; //��ֵΪa 
//				i--;
//			}
//			for (i = 5;i >= 0;--i)
//			{
//				if (!r[i] || r[i] == 'a')continue;
//				if (r[i] == '.')break;
//				m_number++; //�ж��ж���С�� 
//			}
//		}
//		for (i = 0, j = 0;i < 6;++i)
//		{
//			if (r[i] == 'a')
//				continue;
//			if (r[i] == '.')
//				continue;
//			if (!r[i])
//				continue;
//			b[j] = (int)(r[i] - '0'); //ת��int��b 
//			j++;
//		}
//		while (j < 6)
//		{
//			b[j] = -1;
//			j++;
//		}//b����Ū��ʵ������
//		for (i = 0;i < 6;++i)
//		{
//			if (b[i] == -1)continue;
//			m_data = m_data * 10 + b[i]; //��˵Ĵ��� 
//		}
//		for (j = 5, i = 250 - 1;j >= 0 && i >= 0;--j)
//		{
//			if (b[j] == -1)
//				continue;
//			else
//			{
//				m[i] = b[j]; //��ֵ��m 
//				i--;
//			}
//		}
//		m_number = m_number*n;
//		n--;
//		while (n--&&i != 249)//����������붼��0 
//		{
//			for (j = i + 1;j < 250;j++)//����ô��λ 
//			{
//				int tem = m[j] * m_data;//ÿһλ������� 
//				m[j] = 0;
//				if (tem == 0)
//					m[j] = 0;
//				else
//				{
//					int t = j;
//					while (tem / 10 != 0 || tem % 10 != 0)
//					{
//						m[t] = m[t] + tem % 10;//��ÿһλ�������������ڲ�ͬ�ĵ�Ԫ 
//						int tt1 = t;
//						while (m[tt1] > 9)//�Գ���9�Ĵ��� 
//						{
//							int tem2 = m[tt1];
//							m[tt1] = tem2 % 10;//�õ���λ������ 
//							tt1--;
//							m[tt1] = m[tt1] + tem2 / 10;//��ǰ�ӽ���λ�� 
//						}
//						t--;
//						tem = tem / 10;
//					}
//				}
//			}
//			i = 0;
//			while (m[i] == 0)
//				i++;//�ҵ�m�е�һ�������λ�� 
//			i--;
//		}
//		i = 0;
//		while (i < 250 && m[i] == 0)
//			i++;
//		if (m_number == 0)//��û��С����Ĵ��� 
//		{
//			if (i == 250)cout << 0 << endl;
//			else
//			{
//				for (;i < 250;++i)cout << m[i];
//				cout << endl;
//			}
//		}
//		else//��С����Ĵ��� 
//		{
//			if (m_number > 250 - i)//250-i��ʾ��i֮ǰ��i���㣬��250-i������ 
//			{//С���㳬����˵õ���ʵ�������� 
//				cout << ".";
//				while (m_number-->250 - i)
//					cout << 0;
//				for (;i < 250;i++)
//					cout << m[i];
//				cout << endl;
//			}
//			else
//			{
//				for (;i < 250;++i)
//				{
//					if (m_number == 250 - i)
//						cout << ".";  //����������� 
//					cout << m[i];
//				}
//				cout << endl;
//			}
//		}
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//////
//////#include <iostream>
//////#include <cmath>
//////using namespace std;
//////
//////double fun(double x, int n)
//////{
//////	if (n == 0)
//////		return 1;
//////	double half;
//////	if (n & 1)
//////	{
//////		half = fun(x, n / 2);
//////		return x*half*half;
//////	}
//////	else
//////	{
//////		double  half = fun(x, n / 2);
//////		return half * half;
//////	}
//////}
//////
//////double mypow1(double x, int n) 
//////{
//////	double result = fun(x, n);
//////	if (n < 0)
//////		result = 1 / result;
//////	return result;
//////}
//////
//////double mypow2(double x, int n)
//////{
//////	if (n == 0)
//////		return 1;
//////	if (n < 0) 
//////	{
//////		n = -n;
//////		x = 1 / x;
//////	}
//////	return (n % 2 == 0) ? mypow2(x*x, n / 2) : x*mypow2(x*x, n / 2);
//////}
//////
//////double mypow3(double x, int n) 
//////{
//////	double ans = 1;
//////	unsigned long long p;
//////	if (n < 0)
//////	{
//////		p = -n;
//////		x = 1 / x;
//////	}
//////	else 
//////	{
//////		p = n;
//////	}
//////	while (p) 
//////	{
//////		if (p & 1)
//////			ans *= x;
//////		x *= x;
//////		p >>= 1;
//////	}
//////	return ans;
//////}
//////
//////void test()
//////{
//////	double x = 89;
//////	int n = 10;
//////	cout << mypow1(x, n) << endl;
//////	cout << mypow2(x, n) << endl;
//////	cout << mypow3(x, n) << endl;
//////	cout << pow(x, n) << endl;
//////}
//////
//////int main()
//////{
//////	test(); return 0;
//////
//////
//////	double x;
//////	int n;
//////	//cin >> x >> n;
//////	while (cin >> x >> n) //ע��while������case
//////		cout << mypow2(x, n) << endl;
//////
//////
//////	return 0;
//////}


// http://www.cnblogs.com/leewiki/archive/2011/12/11/2283911.html