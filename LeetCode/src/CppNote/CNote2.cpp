
#include "../global.h"
#include <iostream>

/**
* @brief ���Ҫɾ������һ��ָ�����������Ļ���ָ�룬����Ҫ������������ȷ����������������������á�
*
* @note ������`delete`��̬����Ķ����ָ��ʱ��ִ�����������������ָ��ָ��̳���ϵ�е�ĳ�����ͣ�
* ���п��ܳ���ָ��ľ�̬�����뱻ɾ������Ķ�̬���Ͳ�������������磬�������\c deleteһ��<tt>Base*</tt>���͵�ָ�룬
* ���ָ���п���ʵ��ָ����һ��<tt>Derived</tt>���͵Ķ�����������Ļ����������ͱ��������Ҫִ�е���<tt>Derived</tt>������������
* ����������һ��������ͨ���ڻ����н�������������Ϊ�麯����ȷ��ִ����ȷ�����������汾��
* \code{.cpp}
  class Base
  {
  public:
	// �������ɾ������һ��ָ�����������Ļ���ָ�룬����Ҫ����������
	virtual ~Base() = default; //��̬����������
  };
  \endcode
  ���õ�˳��
  - ���캯�����ȵ��ø���ģ��ٵ�������Ĺ��캯��
  - �����������ȵ�������ģ��ٵ��ø������������
* @see C++ Primer Chapter 15.7.1 ����������
*/
class CNote2
{
public:
	class CNote2_base1
	{
	public:
		CNote2_base1() { std::cout << "  CNote2_base1 ctor" << std::endl; }
		virtual ~CNote2_base1() { std::cout << "  CNote2_base1 dtor: delete CNote2_base1" << std::endl; }
	};

	class CNote2_derived1 : public CNote2_base1
	{
	public:
		CNote2_derived1() { std::cout << "  CNote2_derived1 ctor" << std::endl; }
		~CNote2_derived1() { std::cout << "  CNote2_derived1 dtor: delete CNote2_derived1" << std::endl; }
	};


	class CNote2_base2
	{
	public:
		CNote2_base2() { std::cout << "  CNote2_base2 ctor" << std::endl; }
		~CNote2_base2() { std::cout << "  CNote2_base2 dtor: delete CNote2_base2" << std::endl; }
	};

	class CNote2_derived2 : public CNote2_base2
	{
	public:
		CNote2_derived2() { std::cout << "  CNote2_derived2 ctor" << std::endl; }
		~CNote2_derived2() { std::cout << "  CNote2_derived2 dtor: delete CNote2_derived2" << std::endl; }
	};

	void test()
	{
		std::cout << "\n-------------virtual deconstructor-------------\n" << std::endl;

		std::cout << "==CNote2_base1 that points to CNote2_base1" << std::endl;
		CNote2_base1 *p1 = new CNote2_base1;
		delete p1;	std::cout << std::endl;

		std::cout << "==CNote2_base1 that points to CNote2_derived1" << std::endl;
		CNote2_base1 *p2 = new CNote2_derived1;
		delete p2;	std::cout << std::endl;

		std::cout << "==CNote2_derived1 that points to CNote2_derived1" << std::endl;
		CNote2_derived1 *p3 = new CNote2_derived1;
		delete p3;	std::cout << std::endl;


		std::cout << "\n-------------non-virtual deconstructor-------------\n" << std::endl;
		std::cout << "==CNote2_base2 that points to CNote2_base2" << std::endl;
		CNote2_base2 *q1 = new CNote2_base2;
		delete q1;	std::cout << std::endl;

		std::cout << "==CNote2_derived2 that points to CNote2_derived2" << std::endl;
		CNote2_base2 *q2 = new CNote2_derived2;
		delete q2;	std::cout << std::endl;

		std::cout << "==CNote2_derived2 that points to CNote2_derived2" << std::endl;
		CNote2_derived2 *q3 = new CNote2_derived2;
		delete q3;	std::cout << std::endl;
	}
};


#ifdef RUN_CNOTE2
int main()
{
	
	CNote2 cn2;
	cn2.test();

	return 0;
}
#endif