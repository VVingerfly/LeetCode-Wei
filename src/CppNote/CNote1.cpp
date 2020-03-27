#include <iostream>

/**
 * @brief 成员变量的初始化顺序只与它们在类中声明的顺序有关，与在初始化列表中的顺序无关。
 *
 * @note 在C++中，成员变量的初始化顺序\b只与它们在类中声明的顺序有关>，而与<b>在初始化列表中的顺序无关</b>。\n
 * 此例中，n1先于n2声明，因此n1也会在n2之前初始化，所以先用n2+2初始化n1，此时n2的值是随机的，
 * 故n1也是一个随机值，然后用0初始化n2.
 */
class CNote1
{
private:
    int n1;
    int n2;

public:
    CNote1() : n2(0), n1(n2 + 2) {}
    CNote1(int n)
    {
        n2 = n;
        n1 = n2 + 2;
    }
    void Print() { std::cout << "n1: " << n1 << ", n2: " << n2 << std::endl; }
};


int main()
{
    CNote1 a;
    a.Print();
    CNote1 b(0);
    b.Print();
    return 0;
}