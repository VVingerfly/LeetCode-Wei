#include <iostream>

using namespace std;

#define maxlen 50
#define maxresult 100000000
int x[maxlen], y[maxlen];
int ans[maxlen];
int result[maxlen];
int n, dst_x, dst_y;
int tmp;
#define ABS(a) ((a) < 0 ? -(a) : (a))

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    for (int i = 0; i < n; ++i)
        cin >> y[i];

    for (int i = 0; i < n; ++i) {
        result[i] = maxresult;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dst_x = x[i];
            dst_y = y[j];

            for (int k = 0; k < n; ++k) {
                ans[k] = maxresult;
            }
            for (int k = 0; k < n; ++k) {
                tmp = abs(dst_x - x[k]) + abs(dst_y - y[k]);
                int m = 0;
                for (m = 0; m < k; ++m) {
                    if (tmp < ans[m]) {
                        break;
                    }
                }
                for (int h = k; h > m; --h) {
                    ans[h] = ans[h - 1];
                }
                ans[m] = tmp;
            }
            for (int k = 1; k < n; ++k) {
                ans[k] += ans[k - 1];
            }
            for (int k = 0; k < n; ++k) {
                if (result[k] < ans[k]) {
                    result[k] = ans[k];
                }
            }
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        cout << ans[i] << '\t';
    }
    cout << ans[n - 1] << endl;

    cin >> n;
    return 0;
}
