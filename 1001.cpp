#include <iostream>
#include <string>
#include "utils/biginteger.hpp"
using namespace std;

/*string operator * (string left, string right) {
    string result;
    int decimalLength = 0

    for (int i = left.size (); i > 0; i--) {
        for (int j = right.size (); j > 0; j--) {
            result.append ('');
        }
    }
}

int main (int argc, char** argv) {
    string str = "This is a test";

    for (int i = str.size (); i > 0; i--) {
        cout << str.at (i - 1) << endl;
    }
    
    return 0;
}
*/

int main (int argc, char** argv) {
    BigFloat f ("3.1415926535");

    for (int i = 0; i < 12; i++) {
        cout << f[i] + 1 << endl;
    }
    return 0;
}
