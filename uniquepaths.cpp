class Solution {
public:
int solve(int i,int j,vector<vector<int>>& dp,int m,int n){
    if(i==m-1 && j==n-1){
        return 1;
    }
    int paths=0;

    if(i>=m || j>=n){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    paths+=solve(i+1,j,dp,m,n);

    paths+=solve(i,j+1,dp,m,n);

    return dp[i][j]=paths;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int i=0;
        int j=0;
        return solve(i,j,dp,m,n);

    }
};