//
//  reverse_array.cpp
//  Created by HARSH AGGARWAL on 05/11/25.
//

#include <iostream>
#include <vector>
using namespace std;

void rev_arr(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int tmp = a[l];
    a[l] = a[r];
    a[r] = tmp;
    rev_arr(a, l + 1, r - 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    rev_arr(a, 0, n - 1);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
