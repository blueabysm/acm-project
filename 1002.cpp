#include <iostream>
#include <string>
#include <map>
using namespace std;

void uniformString (string& str) {
    for (string::iterator iter = str.begin (); iter < str.end (); iter++) {
        if (*iter == '-')
            str.erase (iter);
    }
    
    for (string::iterator iter = str.begin (); iter < str.end (); iter++) {
        switch (*iter) {
            case 'A':
            case 'B':
            case 'C':
                str.replace (iter, iter + 1, "2");
                break;
            case 'D':
            case 'E':
            case 'F':
                str.replace (iter, iter + 1, "3");
                break;
            case 'G':
            case 'H':
            case 'I':
                str.replace (iter, iter + 1, "4");            
                break;
            case 'J':
            case 'K':
            case 'L':
                str.replace (iter, iter + 1, "5");
                break;
            case 'M':
            case 'N':
            case 'O':
                str.replace (iter, iter + 1, "6");
                break;
            case 'P':
            case 'R':
            case 'S':
                str.replace (iter, iter + 1, "7");
                break;
            case 'T':
            case 'U':
            case 'V':
                str.replace (iter, iter + 1, "8");
                break;
            case 'W':
            case 'X':
            case 'Y':
                str.replace (iter, iter + 1, "9");
                break;
            default:
                str.replace (iter, iter + 1, "0");
        }
    }
}

int main (int argc, char** argv) {
    map<string, int> telephones;

    int repeat;
    string telephone;

    cin >> repeat;
    while (repeat-- > 0) {
        cin >> telephone;
        uniformString (telephone);
        telephones[telephone]++;
    }

    

    return 0;
}
