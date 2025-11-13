class Solution {
public:

    void func(vector<int>& nums,set<vector<int>> &ans,vector<int> &used,vector<int> &curr){
        if(curr.size()==nums.size()){
            ans.insert(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            used[i]=1;
            curr.push_back(nums[i]);
            func(nums,ans,used,curr);
            used[i]=0;
            curr.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> used(nums.size(),0);
        vector<int> curr;
        func(nums,ans,used,curr);
        vector<vector<int>> ansf(ans.begin(),ans.end());
        return ansf;
    }
};