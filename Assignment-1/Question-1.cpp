// 1. Count the Number of Digits in a Number
#include <iostream>
using namespace std;
int count(int n){
    if(n<0) n=-n;
    if(n<10) return 1;
    if(n==0){
        return 0;
    }
    return 1+count(n/10);
}

int main(int argc, const char * argv[]) {
    int n=345;
    cout<<count(n)<<" digits"<<endl;
}
