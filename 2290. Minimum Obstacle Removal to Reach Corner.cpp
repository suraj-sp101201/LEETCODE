class Solution {
public:
    
    // use bfs and dp concept to solve this problem
    
    // dp[i][j] denotes the minimum cost(minimum number of obstacles) from 0,0 to i,j
    
    // use a min-heap so that the lower costs are processed first
    
    // traverse in all 4 directions and process it
    
    // process i,j only if current cost is lesser than dp[i][j] (OPTIMIZATION)
    
    // example, assume minimum till now for dp[i][j] is 10. In future if some cost come with lesser than 10, only then process it, else do not because processing higher than 10 will increase the cost. 
    
    // More formally with 10 if we get some X as final answer then processing anything greater than 10 will give cost greater than X.
    
    // We need to get minimum so do not process higher than dp[i][j]

    int minimumObstacles(vector<vector<int>>& grid) 
    {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        int m=grid.size();
        int n=grid[0].size();
        vector<pair<int,int>> dir;
        dir.push_back({0,1});
        dir.push_back({1,0});
        dir.push_back({0,-1});
        dir.push_back({-1,0});
        while(!pq.empty())
        {
            pair<int,pair<int,int>> p=pq.top();
            pq.pop();
            int cost=p.first;
            int x=p.second.first;
            int y=p.second.second;
            if(x==m-1 && y==n-1)
            {
                return cost;
            }
            for(int i=0;i<dir.size();i++)
            {
                int l=dir[i].first;
                int r=dir[i].second;
                if(x+l>=0 && x+l<m && y+r>=0 && y+r<n)
                {
                    if(dp[x+l][y+r]>grid[x+l][y+r]+cost)
                    {
                        dp[x+l][y+r]=grid[x+l][y+r]+cost;
                        pq.push({grid[x+l][y+r]+cost,{x+l,y+r}});
                    }
                }
            }
        }
        return 0;
    }
};