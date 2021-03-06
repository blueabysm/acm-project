#include <iostream>
using namespace std;

#define P_CYCLE 23
#define E_CYCLE 28
#define I_CYCLE 33
#define MAX_TRIPLE 21252

int max2 (int x, int y) {
    return x > y ? x : y;
}

int max3 (int x, int y, int z) {
    return max2 (max2 (x, y), z);
}

int main (int argc, char** argv) {
    int physical, emotional, intellectual, current;
    int caseNumber = 0;

    while (true) {
        cin >> physical >> emotional >> intellectual >> current;
                
        if (physical == -1 &&
            emotional == -1 &&
            intellectual == -1 &&
            current == -1) {
            break;
        }

        caseNumber++;
        int i;
        i = max3 (physical, emotional, intellectual);
        //之前在while循环上加上了条件，这样是不对的，应该相信，该找到的数字总是会找到的。
        while (true) {
            if ((i - intellectual) % I_CYCLE == 0 &&
                (i - emotional) % E_CYCLE == 0 &&
                (i - physical) % P_CYCLE == 0) {
                //考虑到算出来的i有可能是绝对值很大的负数，比如-21282，假设current == 0， 那么下一次triple peaks应该是-21282加上若干个MAX_TRIPLE
                //直到大于current。在这个例子里就是-21282 + 21252 + 21252 = 21222。具体的算法就是下面这个式子：
                i = (i - current) % MAX_TRIPLE;
                if (i <= 0)
                    i = MAX_TRIPLE - (-i % MAX_TRIPLE);
                #ifdef _DEBUG_
                cout << "physical = " << physical << " emotional = " << emotional << " intellectual = " << intellectual << " current = " << current <<endl;
                #endif
                cout << "Case " << caseNumber << ": the next triple peak occurs in " << i << " days." << endl;
                break;
            }
            i += P_CYCLE;
        }
    }
    return 0;
}
