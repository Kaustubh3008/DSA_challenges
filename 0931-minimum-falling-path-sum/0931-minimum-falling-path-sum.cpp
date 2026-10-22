class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }
        for(int i=1; i<m;i++){
            for(int j =0;j<n;j++){
                int up = dp[i-1][j];
                int leftDiag = INT_MAX;
                if(j > 0) leftDiag = dp[i-1][j-1];
                int rightDiag = INT_MAX;
                if(j < n-1) rightDiag = dp[i-1][j+1];
                dp[i][j] = matrix[i][j] + min({up, leftDiag, rightDiag});
            }
        }
        int ans = INT_MAX;
        for(int i =0 ;i<n;i++){
            ans = min(ans,dp[m-1][i]);
        }
        return ans;
    }
};