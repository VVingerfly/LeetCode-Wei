
#include "../global.h"
#include <iostream>
using namespace std;
/**
 * @brief ��Ҫ��д�̳����ķ��麯����
 *
 * @note ��Ϊpb������Base*��pd������Derived*������**��ͨ����func�ĵ����Ǿ�̬�󶨵ģ��ڱ����ڱ�����˵��õ�ַƫ������**��
 * ���ǻ����ָ�����Ͷ����е��Ǹ���������`pb->func()`���õ���`Base::func`��`pd->func()`���õ���`Derived::func`��\n
 * \code{.cpp}
 * class Base{
   public:
       void func(){}
   };
   class Derived: public Base{
   public:
       void func(){}   // �����˸��������func����Item 33
   };
   Derived d;
   Base* pb = &d;
   Derived* pd = &d;
   // ��д��override�����麯��func��������������ý����һ��
   pb->func();
   pd->func();
 * \endcode
 * **��Ȼ�麯��������������⣬����һ�ֶ�̬�󶨵Ļ��ơ�**\n
 * ����������д����ķ��麯�����������ì�ܵģ�
 * - һ���棬���ඨ������ͨ����func����ζ������ӳ�˸���Ĳ���ʽ��������д����Ĳ���ʽ���ٳ������������͸��಻���ǡ�is a���Ĺ�ϵ��
 * - ��һ���棬���funcӦ�����������ṩ��ͬ��ʵ�֣���ô���Ͳ��ٷ�ӳ����Ĳ���ʽ������Ӧ������Ϊvirtual������
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