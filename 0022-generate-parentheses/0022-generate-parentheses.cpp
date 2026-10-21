class Solution {
public:
    void helper(int open, int close, int n, string &ds, vector<string> &ans){
        if(ds.size() == 2 * n){
            ans.push_back(ds);
            return;
        }
        if(open < n){
            ds.push_back('(');
            helper(open+1,close,n,ds,ans);
            ds.pop_back();
        }
        if(close<open){
            ds.push_back(')');
            helper(open,close+1,n,ds,ans);
            ds.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string ds;
        helper(0,0,n,ds,ans);
        return ans;
    }
};