#ifndef _BIG_INTEGER_H
#define _BIG_INTEGER_H

class BigFloat {
 public:
    BigFloat (const char* number) {
        this->str = number;
    }
    
    ~BigFloat () {}
    
    BigFloat* operator + (BigFloat* right) {
        return new BigFloat ("hahaha");
    }

    BigFloat* operator - (BigFloat* right) {
        return new BigFloat ("hahaha");
    }

    BigFloat* operator * (BigFloat* right) {
        return new BigFloat ("hahaha");
    }

    BigFloat* operator / (BigFloat* right) {
        return new BigFloat ("hahaha");
    }

    BigFloat* operator = (char* right) {
        return new BigFloat ("hahaha");
    }

    int operator [] (int i) {
        return (int) str[i] - (int) '0';
    }
 private:
    const char* str;
};
#endif
