#ifndef _BIG_INTEGER_H
#define _BIG_INTEGER_H

#include <string.h>

#define MAX(x,y) ((x) > (y)) ? (x) : (y)
#define MIN(x,y) ((x) > (y)) ? (y) : (x)

class BigFloat {
 public:
    BigFloat () {
        this->number = NULL;
        this->length = 0;
    }

    BigFloat (int length) {
        this->number = new int[this->length = length];
    }

    BigFloat (const char* number) {
        this->number = new int[this->length = strlen(number)];

        for (int i = 0; i < this->length; i++) {
            this->number[i] = (int) number[i] - (int) '0';
        }
    }
    
    ~BigFloat () {
        if (this->str != NULL) {
            delete this->str;
        }
    }

    int getLength () {
        return this->length;
    }

    char* getNumber () {
        char* result = new char[this->length];

        for (int i = 0; i < this->length; i++) {
            result[i] = char ((int) this->number[i] + (int) '0');
        }
        
        return result;
    }
    
    int operator [] (int i) {
        return this->str[i];
    }
    
 private:
    int* number;
    int length;
};

BigFloat operator + (BigFloat& left, BigFloat& right) {
    bool carry = false;
    BigFloat result (MAX(left.getLength (), right.getLength ()));
    return result;
}

BigFloat operator - (BigFloat& left, BigFloat& right) {
    bool carry = false;
    BigFloat result (MAX(left.getLength (), right.getLength ()));
    return result;
}

BigFloat operator * (BigFloat& left, BigFloat& right) {
    int carry = 0;
    BigFloat result (left.getLength () + right.getLength () - 1);
    int countFraction = 0;

    for (int i = left.getLength (); i > 0; i--) {
        for (int j = right.getLength (); j > 0; j--) {
            ((int) left[i] - 
        }
    }
    return result;
}

/*
BigFloat operator / (BigFloat& left, BigFloat& right) {
    return BigFloat();
}

BigFloat operator = (BigFloat& left, BigFloat& right) {
    return BigFloat();
}

BigFloat operator == (BigFloat& left, BigFloat& right) {
    return BigFloat();
}
*/
#endif
