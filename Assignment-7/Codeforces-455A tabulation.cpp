#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long func(vector<long long>& f) {
    int m = f.size();
    vector<long long> d(m, 0);

    if (m == 0) return 0;
    if (m == 1) return 0;

    d[0] = 0;
    d[1] = f[1] * 1;

    for (int i = 2; i < m; i++) {
        long long t = f[i] * i + d[i - 2];
        long long s = d[i - 1];
        d[i] = max(t, s);
    }

    return d[m - 1];
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int mx = *max_element(a.begin(), a.end());
    vector<long long> fr(mx + 1, 0);

    for (int x : a) fr[x]++;

    cout << func(fr) << endl;
}
