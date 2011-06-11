#include <string.h>

void multiply(char* a,char* b,char* c) {
    int i,j,ca,cb,* s;
    ca=strlen(a);
    cb=strlen(b);
    s = new int[ca + cb];
    for (i=0;i<ca+cb;i++)
        s[i]=0;
    for (i=0;i<ca;i++)
        for (j=0;j<cb;j++)
            s[i+j+1]+=(a[i]-'0')*(b[j]-'0');
    for (i=ca+cb-1;i>=0;i--)
        if (s[i]>=10)
            {
                s[i-1]+=s[i]/10;
                s[i]%=10;
            }
    i=0;
    while (s[i]==0)
        i++;
    for (j=0;i<ca+cb;i++,j++)
        c[j]=s[i]+'0';
    c[j]='\0';
    delete s;
}

int main () {
    char* result = new char[12];
    multiply ("123456", "512452", result);
    return 0;
}
