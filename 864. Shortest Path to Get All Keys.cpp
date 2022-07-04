class Solution {
public:
    
    // dp[i][j][k] denotes if co-ordinate (i,j) with bitmask k is visited or not
    
    // since k<=6 maximum will be 111111 . 110101 means a,c,e,f keys I have got. Mark the bitmask as visited so that we dont process again the same bitmask in future. Example in 10th operation we have got 110101 then some in 20th operation if I get same 110101 for same (i,j) then dont process
    
    vector<int> direction = {1,0,-1,0,1};
    queue<pair<int,pair<int,int>>> q;
    int valid(int x, int y, int m, int n, vector<string>& grid)
    {
        if(x>=0 && x<m && y>=0 && y<n && grid[x][y]!='#')
        {
            return 1;
        }
        return 0;
    }
    int count(vector<string>& grid)
    {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]>='a' && grid[i][j]<='z')
                {
                    ans++;
                }
                if(grid[i][j]=='@')
                {
                    q.push({0,{i,j}});
                }
            }
        }
        return ans;
    }
    bool canPass(vector<string>& grid, int x, int y, int bitmask)
    {
        int v=grid[x][y]-'A';
        if(bitmask & (1<<v))
        {
            return 1;
        }
        return 0;
    }
    int bfs(vector<string>& grid, int count)
    {
        int m=grid.size();
        int n=grid[0].size();
        int dp[m][n][64];
        memset(dp,0,sizeof(dp));
        int ans=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                pair<int,pair<int,int>> p=q.front();
                q.pop();
                int temp=p.first;
                if(temp==(1<<count)-1)
                {
                    return ans;
                }
                int x=p.second.first;
                int y=p.second.second;
                for(int i=0;i<direction.size()-1;i++)
                {
                    int nx=x+direction[i];
                    int ny=y+direction[i+1];
                    int value=temp;
                    if(valid(nx,ny,m,n,grid))
                    {
                        int v=grid[nx][ny]-'a';
                        if(v>=0 && v<=5)
                        {
                            value|=(1<<v);
                        }
                        if(grid[nx][ny]>='A' && grid[nx][ny]<='Z')
                        {
                            if(canPass(grid,nx,ny,value) && !dp[nx][ny][value])
                            {
                                q.push({value,{nx,ny}});
                                dp[nx][ny][value]=1;
                            }
                        }
                        else if(!dp[nx][ny][value])
                        {
                            q.push({value,{nx,ny}});
                            dp[nx][ny][value]=1;
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
    int shortestPathAllKeys(vector<string>& grid) 
    {
        int count_of_keys=count(grid);
        return bfs(grid,count_of_keys);
    }
};