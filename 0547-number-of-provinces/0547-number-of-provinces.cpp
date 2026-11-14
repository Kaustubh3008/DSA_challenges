class Solution {
public:
    void dfs(int i, vector<int> &vis, vector<vector<int>>& isConnected,vector<vector<int>> &adjL){
        vis[i] =1;
        for(auto it: adjL[i]){
            if(!vis[it]){
                dfs(it, vis, isConnected,adjL);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        int m= isConnected[0].size();
        vector<vector<int>> adjL(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int cnt =0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,isConnected,adjL);
            }
        }
        return cnt;
    }
};