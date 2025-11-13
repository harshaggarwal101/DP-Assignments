class Solution {
public:

    void func(string digits,vector<string> &ans,unordered_map<char, string> mapping,string &curr,int index){
        if(curr.length()==digits.length()){
            ans.push_back(curr);
            return;
        }
        string letters = mapping[digits[index]];
        for (char ch : letters) {
            curr.push_back(ch);
            func(digits,ans,mapping,curr,index+1);
            curr.pop_back(); 
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
       unordered_map<char, string> mapping = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        string curr;
        func(digits,ans,mapping,curr,0);
        return ans;
    }
};