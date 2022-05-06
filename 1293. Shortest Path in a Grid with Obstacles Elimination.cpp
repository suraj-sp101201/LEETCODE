class Solution {
public:
    
    // have a queue with these values: the number of remaining moves, current x position, current y position
    
    // visited[i][j] denotes the maximum k that was available when we reached i,j
    
    // if current k is lesser than or equal to visited[i][j] then we need not process as there was some thing that came before to this with bigger k, process only bigger k the reason is lets say there is 2k's like 4 and 6 that is coming to a point, we can just process 6 as this has some extra k and will remove many walls
    
    // see all 4 directions if it is a wall then decrement k by 1, else dont remove
    
    // return the mimimum moves made to reach m-1,n-1 
    
    bool invalid(int i, int j, int m, int n)
    {
        if(i<0 || j<0 || i>=m || j>=n)
        {
            return 1;
        }
        return 0;
    }
    int shortestPath(vector<vector<int>>& grid, int k) 
    {
        int vis[40][40];
        memset(vis,-1,sizeof(vis));
        if(grid.size()==1 && grid[0].size()==1)
        {
            return 0;
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({k,{0,0}});
        int ans=INT_MAX;
        int move=0;
        vector<pair<int,int>> directions;
        directions.push_back({0,1});
        directions.push_back({1,0});
        directions.push_back({-1,0});
        directions.push_back({0,-1});
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                pair<int,pair<int,int>> p=q.front();
                q.pop();
                int remaining=p.first;
                int x=p.second.first;
                int y=p.second.second;
                if(vis[x][y]!=-1 && vis[x][y]>=remaining)
                {
                    continue;
                }
                vis[x][y]=remaining;
                for(int i=0;i<directions.size();i++)
                {
                    int newx=x+directions[i].first;
                    int newy=y+directions[i].second;
                    if(invalid(newx,newy,grid.size(),grid[0].size()))
                    {
                        continue;
                    }
                    if(newx==grid.size()-1 && newy==grid[0].size()-1)
                    {
                        ans=min(ans,move+1);
                        continue;
                    }
                    if(grid[newx][newy]==1 && remaining-1>=0)
                    {
                        q.push({remaining-1,{newx,newy}});
                    }
                    else if(grid[newx][newy]==0)
                    {
                        q.push({remaining,{newx,newy}});
                    }
                }
            }
            move++;
        }
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};