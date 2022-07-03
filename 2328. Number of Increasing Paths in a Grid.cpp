class Solution {
public:
    
    // dp[i][j] denotes the number of increasing paths ending at i,j
    
    // we have to dfs for all nodes that are adjancent and lesser than this, and first we have to find those lesser and then solve for it and after that only, we solve for current i,j
    
    long int dp[1000][1000];
    vector<int> dir = {0,-1,0,1,0};
    int solve(int m, int n, vector<vector<int>>& grid)
    {
        if(dp[m][n]!=-1)
        {
            return dp[m][n];
        }
        long int ans=1;
        for(int i=0;i<dir.size()-1;i++)
        {
            int x=m+dir[i];
            int y=n+dir[i+1];
            if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]<grid[m][n])
            {
                ans+=(solve(x,y,grid));
                ans%=1000000007;
            }
        }
        return dp[m][n]=ans;
    }
    int countPaths(vector<vector<int>>& grid) 
    {
        memset(dp,-1,sizeof(dp));
        long long int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(dp[i][j]==-1)
                {
                    solve(i,j,grid);
                }
                ans+=dp[i][j];
                ans%=1000000007;
            }
        }
        return ans;
    }
};