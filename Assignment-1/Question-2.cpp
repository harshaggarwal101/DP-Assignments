// 2. Find the Maximum Element in an Array using Recursion
//
//  main.cpp
//
//  Created by HARSH AGGARWAL on 05/11/25.
//

#include <iostream>
using namespace std;

int maxim(int arr[],int index,int size){
    if(index==size-1){
        return arr[index];
    }
    return max(arr[index],maxim(arr,index+1,size));
}

int main(int argc, const char * argv[]) {
    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum element:"<<maxim(arr,0,size)<<endl;
    return 0;
}