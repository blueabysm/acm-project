#include <iostream>
#include <string.h>
using namespace std;

class BigFloat {
public:
    BigFloat (const char* numberString) {
        int* temp =
        this->_numberSeq = new int[this->_length = strlen (numberString)];

        this->_fractionDigits = 0;

        bool isFraction = false;

        while (*numberString != '\0') {
            if (*numberString == '.') {
                *numberString++;
                isFraction = true;
                break;
            }

            *temp = *numberString - '0';
            temp++; numberString++;
        }

        if (isFraction) {
            while (*numberString != '\0') {
                *temp = *numberString - '0';
                temp++; numberString++;
                this->_fractionDigits++;
            }

            //由于这个数是小数，所以移除小数点之后，数组会空出一个元素来，把这个元素删了
            this->_length--;
        }
            
    }

    BigFloat (int length) {
        this->_fractionDigits = 0;
        this->_numberSeq = new int[this->_length = length];
        for (int i = 0; i < this->_length; i++) {
            this->_numberSeq[i] = 0;
        }
    }

    ~BigFloat () {
        if (this->_numberSeq != NULL)
            delete this->_numberSeq;
    }

    friend BigFloat& operator + (BigFloat& left, BigFloat& right);
    friend BigFloat& operator - (BigFloat& left, BigFloat& right);
    friend BigFloat& operator * (BigFloat& left, BigFloat& right);
    friend BigFloat& operator / (BigFloat& left, BigFloat& right);

    friend ostream& operator << (ostream& os, BigFloat& bigFloat);
    friend istream& operator >> (istream& is, BigFloat& bigFloat);
    
private:
    char* _getNumber () {
        int start = 0;
        int end = this->_length - 1;

        if (this->_fractionDigits < this->_length) {
            while (start < this->_length - this->_fractionDigits
                   &&
                   this->_numberSeq[start] == 0) {
                start++;
            }
        }

        if (this->_fractionDigits != 0) {
            while (end >= this->_length - this->_fractionDigits
                   &&
                   this->_numberSeq[end] == 0) {
                end--;
            }
        }

        this->_fractionDigits -= this->_length - 1 - end;

        char* temp = NULL;
        int length = end - start + 1;
        
        //if it is a pure fraction
        if (this->_fractionDigits == length) {
            temp = new char[length + 2];
            temp[0] = '.';
            for (int i = 0; i < length; i++) {
                temp[i + 1] = this->_numberSeq[i + start] + '0';
            }
            temp[length + 1] = '\0';
            return temp;
        }

        //if it is an integer
        if (this->_fractionDigits == 0) {
            temp = new char[length + 1];
            for (int i = 0; i < length; i++) {
                temp[i] = this->_numberSeq[i + start] + '0';
            }
            temp[length] = '\0';
            return temp;
        }

        temp = new char[length + 2];
        int i;
        for (i = 0; i < length - this->_fractionDigits; i++) {
            temp[i] = this->_numberSeq[i + start] + '0';
        }

        temp[i] = '.';

        for (; i < length; i++) {
            temp[i + 1] = this->_numberSeq[i + start] + '0';
        }

        temp[i + 1] = '\0';

        return temp;
            
    }
    
    int* _numberSeq;
    int _length;
    int _fractionDigits;
};

BigFloat& operator * (BigFloat& left, BigFloat& right) {
    //check for zero
    bool zeroParam = true;
    for (int i = 0; i < left._length; i++)
        if (left._numberSeq[i] != 0)
            zeroParam = false;

    for (int j = 0; j < right._length; j++)
        if (right._numberSeq[j] != 0)
            zeroParam = false;

    if (zeroParam)
        return *(new BigFloat("0"));

    //check for integer

    BigFloat* result = new BigFloat (left._length + right._length);

    for (int i = 0; i < left._length; i++) {
        for (int j = 0; j < right._length; j++) {
            result->_numberSeq[i + j + 1] +=
                left._numberSeq[i] * right._numberSeq[j];
        }
    }

    int carry = 0;
    int i = result->_length;

    while (--i >= 0) {
        result->_numberSeq[i] += carry;
        carry = result->_numberSeq[i] / 10;
        result->_numberSeq[i] %= 10;
    }

    result->_fractionDigits = left._fractionDigits + right._fractionDigits;
    //    result->_defrag ();
    return *result;
}

ostream& operator << (ostream& os, BigFloat& bigFloat) {
    os << bigFloat._getNumber ();
    return os;
}

BigFloat& pow (BigFloat& base, int exp) {
    if (exp == 0)
        return *(new BigFloat ("1"));
    if (exp == 1)
        return base;
    if (exp % 2 == 0)
        return pow (base * base, exp / 2);
    else
        return pow (base * base, exp / 2) * base;
}

int main (int argc, char** argv) {
    char* numberString = new char[7];
    int exp;
    BigFloat* base = NULL;

    while (cin >> numberString >> exp) {
        numberString[6] = '\0';
        base = new BigFloat(numberString);
#ifdef _DEBUG_
        cout << "base = " << numberString << "; " << "exp = " << exp << endl;
#endif
        cout << pow (*base, exp) << endl;
        delete base;
    }

    return 0;
}
