// 2. GFG – Delete Middle of Stack Using Recursion
#include <bits/stdc++.h>
using namespace std;

class Solution {
    void solve(stack<int>& s, int k) {
        if (k == 1) {
            s.pop();
            return;
        }
        int top = s.top();
        s.pop();
        solve(s, k - 1);
        s.push(top);
    }

public:
    void deleteMid(stack<int>& s) {
        int k = (s.size() / 2) + 1;
        solve(s, k);
    }
};
