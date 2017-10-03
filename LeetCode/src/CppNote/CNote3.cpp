
#include "../global.h"
#include <iostream>
using namespace std;
/**
 * @brief 不要重写继承来的非虚函数。
 *
 * @note 因为pb类型是Base*，pd类型是Derived*，对于**普通函数func的调用是静态绑定的（在编译期便决定了调用地址偏移量）**。
 * 总是会调用指针类型定义中的那个方法。即`pb->func()`调用的是`Base::func`，`pd->func()`调用的是`Derived::func`。\n
 * \code{.cpp}
 * class Base{
   public:
       void func(){}
   };
   class Derived: public Base{
   public:
       void func(){}   // 隐藏了父类的名称func，见Item 33
   };
   Derived d;
   Base* pb = &d;
   Derived* pd = &d;
   // 重写（override）非虚函数func将会造成下述调用结果不一致
   pb->func();
   pd->func();
 * \endcode
 * **当然虚函数不存在这个问题，它是一种动态绑定的机制。**\n
 * 在子类中重写父类的非虚函数在设计上是矛盾的：
 * - 一方面，父类定义了普通函数func，意味着它反映了父类的不变式。子类重写后父类的不变式不再成立，因而子类和父类不再是”is a”的关系。
 * - 另一方面，如果func应当在子类中提供不同的实现，那么它就不再反映父类的不变式。它就应该声明为virtual函数。
 * @see http://harttle.com/2015/09/03/effective-cpp-36.html
*/
class CNote3
{
public:
	class CNote3_base
	{
	public:
		CNote3_base() { cout << "  CNote3_base ctor" << endl; }
		virtual ~CNote3_base() { cout << "  CNote3_base dtor: delete CNote3_base" << endl; }
		virtual void func_virtual() { cout << " CNote3_base::func_virtual()" << endl; }
		void func() { cout << " CNote3_base::func()" << endl; }
	};

	class CNote3_derived : public CNote3_base
	{
	public:
		CNote3_derived() { cout << "  CNote3_derived ctor" << endl; }
		~CNote3_derived() { cout << "  CNote3_derived dtor: delete CNote3_derived" << endl; }
		void func_virtual() { cout << " CNote3_derived::func_virtual()" << endl; }
		void func() { cout << " CNote3_derived::func()" << endl; }
	};

	void test()
	{
		cout << "\n-------------virtual deconstructor-------------\n" << endl;

		cout << "==CNote3_base that points to CNote3_base" << endl;
		CNote3_base *p1 = new CNote3_base;
		p1->func();
		p1->func_virtual();
		delete p1;	cout << endl;

		cout << "==CNote3_base that points to CNote3_derived" << endl;
		CNote3_base *p2 = new CNote3_derived;
		p2->func();
		p2->func_virtual();
		delete p2;	cout << endl;

		cout << "==CNote3_derived that points to CNote3_derived" << endl;
		CNote3_derived *p3 = new CNote3_derived;
		p3->func();
		p3->func_virtual();
		delete p3;	cout << endl;
	}
};


#ifdef RUN_CNOTE3
int main()
{

	CNote3 cn3;
	cn3.test();

	return 0;
}
#endif