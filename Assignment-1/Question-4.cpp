//
//  main.cpp
//  onlyDigits?
//
//  Created by HARSH AGGARWAL on 05/11/25.
//

#include <iostream>
using namespace std;

bool onlyDigit(string str){
    if(str=="") return true;
    if(str[0]<'0' || str[0]>'9'){
        return false;
    }
    return onlyDigit(str.substr(1));
}

int main(int argc, const char * argv[]) {
    cout<<onlyDigit("1234567");
    return 0;
}
