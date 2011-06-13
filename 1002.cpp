#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef map<string, int> Dictionary;

void formatString (string& str) {
    for (string::iterator iter = str.begin (); iter < str.end ();) {
        switch (*iter) {
            case '-':
                str.erase (iter);
                continue;
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
                break;
        }
        iter++;
    }
}

int main (int argc, char** argv) {
    Dictionary telephones;

    int repeat;
    string telephone;

    cin >> repeat;
    while (repeat-- > 0) {
        cin >> telephone;
        formatString (telephone);
        telephones[telephone]++;
#ifdef _DEBUG_
        cout << "_DEBUG_:" << telephone << " " << endl;
#endif        
    }

    bool noDup = true;
    
    for (Dictionary::iterator iter = telephones.begin ();
         iter != telephones.end ();
         iter++) {

        
        if ((*iter).second > 1) {
            string temp = (*iter).first;
            cout << temp.insert (3, "-") << " " << (*iter).second << endl;
            noDup = false;
        }
    }

    if (noDup) {
        cout << "No duplicates." << endl;
    }
    return 0;
}
