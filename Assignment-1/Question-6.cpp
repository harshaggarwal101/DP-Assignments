//
//  main.cpp
//  Decimal to Binary
//
//  Created by HARSH AGGARWAL on 05/11/25.
//

#include <iostream>
using namespace std;

string toBinary(int num){
    if(num==0){
        return "";
    }
    return toBinary(num/2)+ to_string(num%2);
    
}

int main(int argc, const char * argv[]) {
    cout<<toBinary(36)<<endl;
    return 0;
}
