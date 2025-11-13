class Solution {
public:
    vector<vector<int>> res;
    void func(int n,int k,vector<int> curr,int start){
        if(curr.size()==k){
            res.push_back(curr);
            return;
        }
        for(int i=start;i<=n;i++){
            curr.push_back(i);
            func(n,k,curr,i+1);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        func(n, k, curr,1);
        return res;
    }
};