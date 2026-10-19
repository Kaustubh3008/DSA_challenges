class Solution {
public:
    void helper(int ind, vector<int> &ds, vector<vector<int>> &ans, int target,vector<int>& candidates){
         if(target == 0){
            ans.push_back(ds);
            return;
         }
         for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            helper(i+1,ds,ans,target-candidates[i],candidates);
            ds.pop_back();
         }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        helper(0,ds,ans,target,candidates);
        return ans;
    }
};