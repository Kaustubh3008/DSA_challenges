class Solution {
public:
    bool isPalindrome(int start, int end, string &str){
         while(start<= end){
             if(str[start++] != str[end--]){
                 return false;
             }
         }
         return true;
     }
    void helper(int ind, vector<string> &ds, vector<vector<string>> &ans, string &text){
         if(ind == text.size()){
             ans.push_back(ds);
             return;
         }
         for(int i = ind; i<text.size();i++){
             if(isPalindrome(ind,i,text)){
                 ds.push_back(text.substr(ind,i-ind+1));
                 helper(i+1,ds,ans,text);
                 ds.pop_back();
             }
         }
     }
    vector<vector<string>> partition(string text) {
        vector<vector<string>> ans;
        vector<string> ds;
        helper(0,ds,ans,text);
        return ans;
    }
};