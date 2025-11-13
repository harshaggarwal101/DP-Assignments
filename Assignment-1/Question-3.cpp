//
//  main.cpp
//3. Check if an Array is Sorted (Strictly Increasing) using Recursion
//  Created by HARSH AGGARWAL on 05/11/25.
//

#include <iostream>
using namespace std;

bool isSorted(int arr[],int index,int size){
    if(index==size-1){
        return true;
    }
    if(arr[index]>arr[index+1]){
        return false;
    }
    return isSorted(arr,index+1,size);
}

int main(int argc, const char * argv[]) {
    int arr[]={1,2,3,4,9,5,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<isSorted(arr,0,size);
    return 0;
}
