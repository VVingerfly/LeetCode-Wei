/*
如果一个数字序列逆置之后跟原序列是一样的就称这样的数字序列为回文序列。例如：
{ 1, 2, 1 }, { 15, 78, 78, 15 }, { 112 } 是回文序列,
{ 1, 2, 2 }, { 15, 78, 87, 51 }, { 112, 2, 11 } 不是回文序列。
现在给出一个数字序列，允许使用一种转换操作：
选择任意两个相邻的数，然后从序列移除这两个数，并用这两个数字的和插入到这两个数之前的位置(只插入一个和)。
现在对于所给序列要求出最少需要多少次操作可以将其变成回文序列。

输入描述 :
输入为两行，第一行为序列长度n(1 ≤ n ≤ 50)
第二行为序列中的n个整数item[i](1 ≤ iteam[i] ≤ 1000)，以空格分隔。


输出描述 :
输出一个数，表示最少需要的转换次数

输入例子 :
4
1 1 1 3

输出例子 :
    2
*/


#include <iostream>
#include <vector>

using namespace std;

int isHuiWen(const vector<int>& items)
{
    // return -1 : is HunWen xulie
    // return [0~size-1] is not HunWen, return the idx
    int head = 0;
    int rear = items.size() - 1;
    while (head < rear) {
        if (items.at(head) != items.at(rear)) {
            return head;
        }
        head++;
        rear--;
    }
    return -1;
}

void oneOperation(vector<int>& items, int id)
{
    if (id + 1 > items.size() - 1)
        return;

    int new_num = items.at(id) + items.at(id + 1);
    items.insert(items.begin() + id, new_num);
    items.erase(items.begin() + id + 1);
    items.erase(items.begin() + id + 1);
}

void printVector(const vector<int>& items)
{
    cout << "vector = [ ";
    for (size_t i = 0; i < items.size(); ++i) {
        cout << items.at(i);
        if (i != items.size() - 1) {
            cout << ", ";
        }
    }
    cout << " ] " << endl;
}


int main()
{
    // int nums[] = { 1, 1, 1, 3 };
    // vector<int> items(nums, nums + 4);
    int num;
    cin >> num;
    vector<int> items;
    for (int i = 0; i < num; i++) {
        int x;
        cin >> x;
        items.push_back(x);
    }

    int cnt = 0;
    while (true) {
        int id = isHuiWen(items);
        if (id == -1) {
            break;
        }
        oneOperation(items, id);
        printVector(items);
        cnt++;
    }
    cout << "total operations " << cnt << endl;

    return 0;
}
