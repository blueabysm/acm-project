#include <iostream>
#include <math.h>

const double PI = 3.141592653;

using namespace std;

double getDistant (double x, double y) {
    return sqrt (x * x + y * y);
}

double getSemiCircleArea (double radius) {
    return radius * radius * PI / 2;
}

int main (int argc, char** argv) {
    int repeat = 0;
    cin >> repeat;
    int i = 0;
    while (repeat-- > 0) {
        double x, y, area;
        cin >> x >> y;
        area = getSemiCircleArea (getDistant (x, y));
        int year = area / 50 + 1;
        cout << "Property " << ++i << ": This property will begin eroding in year " << year << "." << endl;
    }
    cout << "END OF OUTPUT." << endl;
    return 0;
}
