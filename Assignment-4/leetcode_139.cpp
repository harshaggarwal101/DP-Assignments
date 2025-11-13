class Solution {
public:
    bool func(string &s, int index,unordered_set<string> dict,vector<int> &dp) {
        if (index == s.length())
            return true;
        if(dp[index]!=-1) return dp[index];
        for (int len = 1; index + len <= s.length(); len++) {
            string sub = s.substr(index, len);
            if(dict.count(sub)) {
                if (func(s, index + len,dict,dp))
                    return dp[index]=true;

            }
        }
        return dp[index]=false;
    }

    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length(), -1);
        return func(s, 0,dict,dp);
    }
};
