
#include <iostream>
#include <vector>
using namespace std;
/**
 * @brief `vector`元素连续存储，`size`和`capacity`的关系由编译器（具体实现）决定。
 *
 * @note 为了支持快速随机访问，`vector`将元素连续存储，如果没有空间容纳新元素，而不得不获取新的内存空间时，
 * `vector`和`string`的实现通常会分配比新的空间需求更大的内存空间，然后将已有元素从旧位置移动到新空间中，
 * 然后添加新元素，析构掉旧内存中的对象并释放旧存储空间。

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

        for (vector<int>::size_type ix = 0; ix != 24; ++ix)
            iVec.push_back(ix);
        cout << "size " << iVec.size() << "  capacity " << iVec.capacity() << "  | push_back 24" << endl;

        iVec.reserve(50);
        cout << "size " << iVec.size() << "  capacity " << iVec.capacity() << "  | reserve 50" << endl;

        while (iVec.size() != iVec.capacity())
            iVec.push_back(0);
        cout << "size " << iVec.size() << "  capacity " << iVec.capacity() << "  | push_back full" << endl;

        iVec.push_back(42);
        cout << "size " << iVec.size() << "  capacity " << iVec.capacity() << "  | push_back 1" << endl;

        iVec.shrink_to_fit();
        cout << "size " << iVec.size() << "  capacity " << iVec.capacity() << "  | shrink_to_fit" << endl;
    }
};


int main()
{
    CNote4 cn4;
    // cn4.test();
    cn4.testSizeCapacity();

    return 0;
}