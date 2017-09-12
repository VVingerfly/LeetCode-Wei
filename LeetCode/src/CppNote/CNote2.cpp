
#pragma once
#include "../global.h"

#ifdef CNOTE2

#pragma once
#include <iostream>
/**
* @brief 如果要删除的是一个指向派生类对象的基类指针，则需要虚析构函数。
*
* @note 当我们<tt>delete</tt>动态分配的对象的指针时将执行析构函数。如果该指针指向继承体系中的某个类型，
* 则有可能出现指针的静态类型与被删除对象的动态类型不符的情况。例如，如果我们\c delete一个<tt>Base*</tt>类型的指针，
* 则该指针有可能实际指向了一个<tt>Derived</tt>类型的对象。如果这样的话，编译器就必须清楚它要执行的是<tt>Derived</tt>的析构函数，
* 和其他函数一样，我们通过将基类中将析构函数定义为虚函数以确保执行正确的析构函数版本：
* \code{.cpp}
  class Base
  {
  public:
	// 如果我们删除的是一个指向派生类对象的基类指针，则需要虚析构函数
	virtual ~Base() = default; //动态绑定析构函数
  };
  \endcode
* @see C++ Primer Chapter 15.7.1 虚析构函数
*/
class CNote2
{
public:
	class CNote2_base1
	{
	public:
		virtual ~CNote2_base1() { std::cout << "  CNote2_base1 dtor: delete CNote2_base1" << std::endl; }
	};

	class CNote2_derived1 : public CNote2_base1
	{
	public:
		~CNote2_derived1() { std::cout << "  CNote2_derived1 dtor: delete CNote2_derived1" << std::endl; }
	};


	class CNote2_base2
	{
	public:
		~CNote2_base2() { std::cout << "  CNote2_base2 dtor: delete CNote2_base2" << std::endl; }
	};

	class CNote2_derived2 : public CNote2_base2
	{
	public:
		~CNote2_derived2() { std::cout << "  CNote2_derived2 dtor: delete CNote2_derived2" << std::endl; }
	};

	void test()
	{
		CNote2_base1 *p1 = new CNote2_base1;
		std::cout << "delete CNote2_base1 that points to CNote2_base1" << std::endl;
		delete p1;
		std::cout << std::endl;

		p1 = new CNote2_derived1;
		std::cout << "delete CNote2_base1 that points to CNote2_derived1" << std::endl;
		delete p1;
		std::cout << std::endl;


		CNote2_base2 *p2 = new CNote2_base2;
		std::cout << "delete CNote2_base2 that points to CNote2_base2" << std::endl;
		delete p2;
		std::cout << std::endl;

		p2 = new CNote2_derived2;
		std::cout << "delete CNote2_derived2 that points to CNote2_derived2" << std::endl;
		delete p2;
		std::cout << std::endl;
	}
};



int main()
{
	
	CNote2 cn2;
	cn2.test();

	return 0;
}

#endif