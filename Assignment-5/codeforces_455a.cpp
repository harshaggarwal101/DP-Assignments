#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solve(vector<long long>& freq, vector<long long>& dp, int idx) {
    if (idx >= freq.size()) return 0;
    if (dp[idx] != -1) return dp[idx];
    return dp[idx] = max(freq[idx] * idx + solve(freq, dp, idx + 2), solve(freq, dp, idx + 1));
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxVal = *max_element(arr.begin(), arr.end());
    vector<long long> freq(maxVal + 1, 0);

    for (int x : arr) freq[x]++;

    vector<long long> dp(maxVal + 1, -1);

    cout << solve(freq, dp, 0) << endl;
    return 0;
}

