class Solution {
public:
    void helper(int ind, vector<int> &ds,vector<vector<int>> &ans, int n, vector<int>& nums){
        if(ind == n){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        helper(ind+1,ds,ans,n,nums);
        ds.pop_back();
        helper(ind+1,ds,ans,n,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        helper(0,ds,ans,n,nums);
        return ans;
    }
};