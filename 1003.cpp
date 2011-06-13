/*
目前P1003的解法还很恶心，竟然每次都做循环来找那个数字，
实际上，这个调和级数的和近似于：
Sum(1/i) = ln(i + 1) + r(i)
其中r(i)是欧拉常数，随着n的变化趋向于一个常数，约是0.57721566...
问题在于，这个r是个变量，如果使用精度很高的r，那么在项数比较小的时候，误差很大。
如果能解决这个问题，这道题就可以用O(1)的复杂度解决了（不考虑math.h里pow的实现）。
如果考虑pow的实现，那么也是O(1) + O(logN) = O(logN)
*/
#include <iostream>
#include <math.h>
using namespace std;

int main () {
    double length;
    
    while (cin >> length) {
        if (length == 0)
            break;

        double sum = 0;
        for (int i = 2; true; i++) {
            sum += (double)1 / i;
            if (sum > length) {
                cout << i - 1 << " card(s)" << endl;
                break;
            }
        }
    }
    return 0;
}
