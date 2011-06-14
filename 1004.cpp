#include <iostream>
using namespace std;

int main (int argc, char** argv) {
    int i = 12;
    double temp;
    double sum = 0;
    while (i-- > 0) {
        cin >> temp;
        sum += temp;
    }

    cout << "$" << sum / 12 << endl;
    return 0;
}
