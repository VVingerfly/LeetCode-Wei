
#include "../global.h"
#include <iostream>
#include <vector>
using namespace std;
/**
 * @brief `vector`Ԫ�������洢��`size`��`capacity`�Ĺ�ϵ�ɱ�����������ʵ�֣�������
 *
 * @note Ϊ��֧�ֿ���������ʣ�`vector`��Ԫ�������洢�����û�пռ�������Ԫ�أ������ò���ȡ�µ��ڴ�ռ�ʱ��
 * `vector`��`string`��ʵ��ͨ���������µĿռ����������ڴ�ռ䣬Ȼ������Ԫ�شӾ�λ���ƶ����¿ռ��У�
 * Ȼ�������Ԫ�أ����������ڴ��еĶ����ͷžɴ洢�ռ䡣

 * @see http://www.cnblogs.com/biyeymyhjob/archive/2012/09/12/2674004.html
*/
class CNote4
{
public:
	class Point
	{
	public:
		Point() { cout << "Ctor" << endl; }
		Point(const Point& p) { cout << "copy Ctor" << endl; }
		~Point() { cout << "Dtor" << endl; }
	};

	void test()
	{
		vector<Point> pVec;
		cout << "size " << pVec.size() << "  cap " << pVec.max_size() << " cap " << pVec.capacity() << endl;
		cout << "\npush back a -------------" << endl;
		Point a;
		pVec.push_back(a);
		cout << "size " << pVec.size() << "  cap " << pVec.max_size() << " cap " << pVec.capacity() << endl;

		cout << "\npush back b -------------" << endl;
		Point b;
		pVec.push_back(b);
		cout << "size " << pVec.size() << "  cap " << pVec.max_size() << " cap " << pVec.capacity() << endl;

		cout << "\npush back c -------------" << endl;
		Point c;
		pVec.push_back(c);
		cout << "size " << pVec.size() << "  cap " << pVec.max_size() << " cap " << pVec.capacity() << endl;

		cout << "\npush back d -------------" << endl;
		Point d;
		pVec.push_back(d);
		cout << "size " << pVec.size() << "  cap " << pVec.max_size() << " cap " << pVec.capacity() << endl;

		cout << "\n-------------------------" << endl;
	}

	void testSizeCapacity()
	{
		vector<int> iVec;
		cout << "size " << iVec.size() << "   capacity " << iVec.capacity() << "   | initalize 0" << endl;
		
		for (vector<int>::size_type ix = 0; ix != 24; ++ix) iVec.push_back(ix);
		cout << "size " << iVec.size() << "  capacity " << iVec.capacity() << "  | push_back 24" << endl;
		
		iVec.reserve(50);
		cout << "size " << iVec.size() << "  capacity " << iVec.capacity() << "  | reserve 50" << endl;
		
		while (iVec.size() != iVec.capacity()) iVec.push_back(0);
		cout << "size " << iVec.size() << "  capacity " << iVec.capacity() << "  | push_back full" << endl;

		iVec.push_back(42);
		cout << "size " << iVec.size() << "  capacity " << iVec.capacity() << "  | push_back 1" << endl;

		iVec.shrink_to_fit();
		cout << "size " << iVec.size() << "  capacity " << iVec.capacity() << "  | shrink_to_fit" << endl;

	}
};


#ifdef RUN_CNOTE4
int main()
{

	CNote4 cn4;
	//cn4.test();
	cn4.testSizeCapacity();

	return 0;
}
#endif