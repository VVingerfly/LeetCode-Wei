
#include "../global.h"
#include <iostream>
#include <vector>
using namespace std;
/**
* @brief 如果在派生类中没有对虚函数重新定义，则它继承其基类的虚函数。
*
* @note 

* @see http://www.cnblogs.com/fly1988happy/archive/2012/09/25/2701237.html
*/
class CNote5
{
public:
	class CNote5_base
	{
	public:
		CNote5_base()          { cout << "  CNote5_base ctor" << endl; }
		virtual ~CNote5_base() { cout << "  CNote5_base dtor" << endl; }
		virtual void func()    { cout << "  CNote5_base::func" << endl; }
		virtual void test()    { cout << "  CNote5_base::test" << endl; func(); }
	};

	class CNote5_derived : public CNote5_base
	{
	public:
		CNote5_derived()    { cout << "  CNote5_derived ctor" << endl; }
		~CNote5_derived()   { cout << "  CNote5_derived dtor" << endl; }
		virtual void func() { cout << "  CNote5_derived::func()" << endl; }
		//virtual void test() { cout << "  CNote5_derived::test" << endl; func(); }
	};
	
	void runTest()
	{
		CNote5_base *pb = new CNote5_derived;
		pb->test();
		delete pb;
	}
};


#ifdef RUN_CNOTE5
int main()
{

	CNote5 cn5;
	cn5.runTest();

	return 0;
}
#endif