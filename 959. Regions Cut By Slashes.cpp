class Solution {
public:
    
    /*
    
    There is only 3 types of characters. they are '/', '\\', ' '. there is no '\' as it is a escaped character.
    
    We can convert this into n*3 x n*3 grid and convert the characters into ones according to their angle, then this problem would be converted to finding the number of groups with 0's .
    
    example 
    
    if '/' then 001
                010
                100
    
    if '\\' then 100
                 010
                 001
    
    example, grid = ["/\\","\\/"]
    
    0 0 1 1 0 0 
    0 1 0 0 1 0 
    1 0 0 0 0 1 
    1 0 0 0 0 1 
    0 1 0 0 1 0 
    0 0 1 1 0 0 
    
    */
    
    void dfs(vector<vector<int>>&grid, int i, int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==1)
        {
            return;
        }
        grid[i][j]=1;
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
    }
    int regionsBySlashes(vector<string>& grid) 
    {
        int ans=0;
        int n=grid.size();
        vector<vector<int>> g(n*3,vector<int>(n*3,0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='/')
                {
                    g[i*3][j*3+2]=1;
                    g[i*3+1][j*3+1]=1;
                    g[i*3+2][j*3]=1;
                }
                else if(grid[i][j]=='\\')
                {
                    g[i*3][j*3]=1;
                    g[i*3+1][j*3+1]=1;
                    g[i*3+2][j*3+2]=1;
                }
            }
        }
        for(int i=0;i<n*3;i++)
        {
            for(int j=0;j<n*3;j++)
            {
                if(g[i][j]==0)
                {
                    dfs(g,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};