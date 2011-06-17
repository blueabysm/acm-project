#include <iostream>
#include <string>
#include <map>

#define TEL_LENGTH 6
using namespace std;

typedef map<char*, int> Dictionary;

char* formatString (string& str) {
    char* result = new[TEL_LENGTH + 1];
    for (int i = 0, j = 0; i < TEL_LENGTH && j < str.size ();) {
        switch (str[j]) {
        case '-':
            j++;
            break;
        case 'A':
        case 'B':
        case 'C':
            result[i] = '2';
            break;
        case 'D':
        case 'E':
        case 'F':
            result[i] = '3';
            break;
        case 'G':
        case 'H':
        case 'I':
            result[i] = '4';
            break;
        case 'J':
        case 'K':
        case 'L':
            result[i] = '5';
            break;
        case 'M':
        case 'N':
        case 'O':
            result[i] = '6';
            break;
        case 'P':
        case 'R':
        case 'S':
            result[i] = '7';
            break;
        case 'T':
        case 'U':
        case 'V':
            result[i] = '8';
            break;
        case 'W':
        case 'X':
        case 'Y':
            result[i] = '9';
            break;
        default:
            break;
        }
        i++;
    }
    result[TEL_LENGTH] = '\0';
    return result;
}

int main (int argc, char** argv) {
    Dictionary telephones;

    int repeat;
    string telephone;

    char* temp;

    cin >> repeat;
    while (repeat-- > 0) {
        cin >> telephone;
        temp = formatString (telephone);
        telephones[temp]++;
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
