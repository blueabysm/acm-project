#include <iostream>
#include <string.h>
using namespace std;

class BigFloat {
public:
    BigFloat () {
        this->_numberString = NULL;
        this->_length = 0;
        this->_fractionDigits = 0;
    }
    
    BigFloat (const char* numberString) {
        this->_fractionDigits = 0;
        this->_numberString = new char[this->_length = strlen (numberString)];
        char* temp = this->_numberString;
        
        bool isFraction = false;
        while (*numberString != '\0') {
            if (*numberString == '.') {
                isFraction = true;
                numberString++;
            }

            if (isFraction) {
                this->_fractionDigits++;
            }

            *temp = *numberString;
            temp++;
            numberString++;
        }

        *(++temp) = '\0';
    }
    
    BigFloat (int length) {
        this->_fractionDigits = 0;
        this->_numberString = new char[this->_length = length];
    }

    char* getNumber () {
        char* temp = new char[this->_length];

        if (this->_fractionDigits == 0) {
            strcpy (temp, this->_numberString);
            return temp;
        }

        int i = 0;
                
        while (i < this->_length - this->_fractionDigits - 1) {
            temp[i] = this->_numberString[i];
            i++;
        }

        temp[i] = '.';
        
        while (++i < this->_length) {
            temp[i] = this->_numberString[i - 1];
        }

        return temp;
    }

    friend BigFloat& operator * (BigFloat& left, BigFloat& right);
    
private:
    char* _numberString;
    int _length;
    int _fractionDigits;
};

BigFloat& operator * (BigFloat& left, BigFloat& right) {
    BigFloat result = new BigFloat (left._length + right._length);
    int carry = 0;
    
    int currentStart = resultStart;
    for (int i = 0; i < left._length; i++) {
        for (int j = 0; j < right._length; j++) {
            
                
}



int main (int argc, char** argv) {
    BigFloat f1 ("3.141592653");
    BigFloat f2 ("3.142857");
    BigFloat f3 ("0.12345");
    BigFloat f4 (".12345");
    BigFloat f5 ("12345");

    char* number = f1.getNumber ();
    return 0;
}
