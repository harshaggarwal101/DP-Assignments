//
//  reverse_digits.cpp
//  Created by HARSH AGGARWAL on 05/11/25.
//

#include <iostream>
using namespace std;

long long revhelp(long long x, long long acc) {
    if (x == 0) return acc;
    return revhelp(x / 10, acc * 10 + (x % 10));
}

long long reverse_digits(long long n) {
    if (n == 0) return 0;
    bool neg = n < 0;
    if (neg) n = -n;
    long long ans = revhelp(n, 0LL);
    return neg ? -ans : ans;
}

int main() {
    long long n;
    cin >> n;
    cout << reverse_digits(n);
    return 0;
}

