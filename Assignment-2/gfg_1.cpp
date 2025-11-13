// GFG – N-bit Binary Numbers (More 1s than 0s)
class Solution {
public:
    void generate(int n, int ones, int zeros, string current, vector<string> &res) {
        if (current.size() == n) {
            res.push_back(current);
            return;
        }
        generate(n, ones + 1, zeros, current + '1', res);
        if (ones > zeros)
            generate(n, ones, zeros + 1, current + '0', res);
    }

    vector<string> NBitBinary(int n) {
        vector<string> res;
        generate(n, 0, 0, "", res);
        return res;
    }
};
