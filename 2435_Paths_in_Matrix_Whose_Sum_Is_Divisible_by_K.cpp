// https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/

class Solution {
public:
int K,m,n;
#define MOD 1000000007
vector<vector<vector<int> >> dp;
int f(int i,int j,int r,vector<vector<int>>& grid){
    if(dp[i][j][r]!=-1) return dp[i][j][r];
    if(i==m-1 && j==n-1){
        return dp[i][j][r]=((r+grid[i][j])%K==0);
    }
    int right=0,down=0;
    if(j+1<n){
        right=f(i,j+1,(r+grid[i][j])%K,grid)%MOD;
    }
    if((i+1)<m){
        down=f(i+1,j,(r+grid[i][j])%K,grid)%MOD;
    }
    return dp[i][j][r]=(right+down)%MOD;
}
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        K=k;
        m=grid.size();n=grid[0].size();
        dp.resize(m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return f(0,0,0,grid);
    }
};
