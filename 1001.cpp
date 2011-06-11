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
    void _defrag () {
        if (this->_numberSeq == NULL)
            return;
        
        int i = this->_length;
        int j = 0;

        while (this->_length - i < this->_fractionDigits) {
            if (this->_numberSeq[--i] == 0) {
                this->_fractionDigits--;
                this->_length--;
            } else {
                break;
            }
        }

        while (j <= this->_length - this->_fractionDigits) {
            if (this->_numberSeq[j] == 0) {
                this->_length--;
                j++;
            } else {
                break;
            }
        }

        int* temp = new int[this->_length];
        for (int k = j; k <= i; k++) {
            temp[k - j] = this->_numberSeq[k];
        }

        delete this->_numberSeq;
        this->_numberSeq = temp;
    }

    char* _getNumber () {
        char* temp = new char[this->_length + 1];
        int i = 0;

        while (i < this->_length - this->_fractionDigits) {
            temp[i] = this->_numberSeq[i] + '0';
            i++;
        }

        if (i < this->_length - 1) {
            temp[i++] = '.';
            while (i < this->_length + 1) {
                temp[i] = this->_numberSeq[i - 1] + '0';
                i++;
            }
        }

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
    result->_defrag ();
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
    char* numberString = new char[6];
    int exp;
    BigFloat* base = NULL;

    while (cin >> numberString >> exp) {
        
        base = new BigFloat(numberString);
        cout << pow (*base, exp) << endl;
        delete base;
    }

    return 0;
}
