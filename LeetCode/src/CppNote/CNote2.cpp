
#pragma once
#include "../global.h"

#ifdef CNOTE2

#pragma once
#include <iostream>
/**
* @brief ���Ҫɾ������һ��ָ�����������Ļ���ָ�룬����Ҫ������������
*
* @note ������<tt>delete</tt>��̬����Ķ����ָ��ʱ��ִ�����������������ָ��ָ��̳���ϵ�е�ĳ�����ͣ�
* ���п��ܳ���ָ��ľ�̬�����뱻ɾ������Ķ�̬���Ͳ�������������磬�������\c deleteһ��<tt>Base*</tt>���͵�ָ�룬
* ���ָ���п���ʵ��ָ����һ��<tt>Derived</tt>���͵Ķ�����������Ļ����������ͱ��������Ҫִ�е���<tt>Derived</tt>������������
* ����������һ��������ͨ���������н�������������Ϊ�麯����ȷ��ִ����ȷ�����������汾��
* \code{.cpp}
  class Base
  {
  public:
	// �������ɾ������һ��ָ�����������Ļ���ָ�룬����Ҫ����������
	virtual ~Base() = default; //��̬����������
  };
  \endcode
* @see C++ Primer Chapter 15.7.1 ����������
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