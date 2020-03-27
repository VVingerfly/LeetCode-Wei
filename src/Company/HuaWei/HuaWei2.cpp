/*

*/

#include <iostream>
#include <vector>

using namespace std;

int pairs[7] = { -1, 2, 1, 4, 3, 6, 5 };

void opeStep(int& l, int& f, int& t, char c)
{
    switch (c) {
        int temp;
        case 'L':
            temp = l;
            l = t;
            t = pairs[temp];
            break;
        case 'R':
            temp = t;
            t = l;
            l = pairs[temp];
            break;
        case 'F':
            temp = f;
            f = t;
            t = pairs[temp];
            break;
        case 'B':
            temp = t;
            t = f;
            f = pairs[temp];
            break;
        case 'A':
            temp = f;
            f = l;
            l = pairs[f];
            break;
        case 'C':
            temp = l;
            l = f;
            f = pairs[temp];
            break;
        default:
            break;
    }
}


int main()
{
    string op = "RA";
    int l = 1;
    int f = 3;
    int t = 5;
    for (int i = 0; i < op.length(); ++i) {
        cout << "step " << i << "  " << l << pairs[l] << f << pairs[f] << t << pairs[t] << endl;
        opeStep(l, f, t, op.at(i));
    }
    cout << l << pairs[l] << f << pairs[f] << t << pairs[t] << endl;

    return 0;
}
