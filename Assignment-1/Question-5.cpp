//
//  main.cpp
//  No of Zeros
//
//  Created by HARSH AGGARWAL on 05/11/25.
//

#include <iostream>
using namespace std;;
int count;
int countZero(int num){
    if(num<0) num=-num;
    if(num==0) return 1;
    if(num<10) return (num==0)?1:0;
    if(num%10==0) return 1+countZero(num/10);
    else return countZero(num/10);
}

int main(int argc, const char * argv[]) {
    cout<<countZero(300456040);
    return 0;
}
