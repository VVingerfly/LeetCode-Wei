#include <iostream>
using namespace std;


class AlgGCD
{
public:
	int gcd(int a, int b) 
	{
		int r;
		while (b!= 0)
		{
			r = a % b;
			a = b;
			b = r;
		}
		return a;
	}

	int gcd_recursive(int a, int b)
	{
		if (b == 0)
			return a;
		else
			return gcd_recursive(b, a%b);
	}
};


int main()
{
	int a = 24;
	int b = 6;
	AlgGCD res;
	cout << res.gcd(a, b) << endl;
	cout << res.gcd_recursive(a, b) << endl;
	return 0;
}
