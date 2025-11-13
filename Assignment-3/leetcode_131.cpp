class Solution {
public:
    bool ispalindrome(string str){
        if(str.length()==0||str.length()==1) return true;
        int i=0;
        int j=str.size()-1;
        while(i<j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void func(vector<vector<string>> &ans,string s,vector<string> &curr,int index){
        if(index==s.length()){
            ans.push_back(curr);
            return;
        }
        for(int i=index,len=1;i<s.length();i++,len++){
            if(ispalindrome(s.substr(index,len))){
                curr.push_back(s.substr(index,len));
                func(ans,s,curr,index+len);
                curr.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        func(ans,s,curr,0);
        return ans;
    }
};