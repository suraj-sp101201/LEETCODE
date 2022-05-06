class Solution {
public:
    
    // do a binary search and check till what time he can wait, if he can wait till 5 min then he can also wait for 4,3,2,1 mins so check above 5 only and if he can't wait for 15 min then he can't wait for 16,17..... so check only below
    
    // fire[i][j] denotes at what time the first fire (i.e. closest fire that will reach) will reach to i,j
    
    // fireTime function is used to calculate all fire[i][j]
    
    // temp[i][j] is used for processing the time of the man with the waiting time
    
    // binary search for a value and assign temp[0][0] as that value. example you want to check wthether he can wait for 4 min so assign temp[0][0] as 4, then start bfs to next points if he reaches a point were the time he reached and the fire[i][j] (i.e. fastest fire) are the same or the time he reached is greater than fire[i][j] then with this waiting time it is not possible because by the time he reaches fire would have come 
    
    // if he has reached a point on or before fire[i][j] then it is possible
    
    long long int fire[300][300];
    long long int temp[300][300];
    vector<pair<int,int>> directions;
    bool invalid(int i, int j, vector<vector<int>>& grid)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==2)
        {
            return 1;
        }
        return 0;
    }
    void fireTime(vector<vector<int>>& grid)
    {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                fire[i][j]=INT_MAX;
            }
        }
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    fire[i][j]=0;
                }
            }
        }
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            for(int i=0;i<directions.size();i++)
            {
                int newx=x+directions[i].first;
                int newy=y+directions[i].second;
                if(invalid(newx,newy,grid))
                {
                    continue;
                }
                if(fire[newx][newy]>=fire[x][y]+1)
                {
                    fire[newx][newy]=fire[x][y]+1;
                    q.push({newx,newy});
                }
            }
        }
    }
    long long int solve(int value, vector<vector<int>>& grid)
    {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                temp[i][j]=INT_MAX;
            }
        }
        temp[0][0]=value;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            for(int i=0;i<directions.size();i++)
            {
                int newx=x+directions[i].first;
                int newy=y+directions[i].second;
                if(invalid(newx,newy,grid))
                {
                    continue;
                }
                int v=min(temp[newx][newy],temp[x][y]+1);
                if(newx==grid.size()-1 && newy==grid[0].size()-1)
                {
                    return v;
                }
                if(v>=fire[newx][newy])
                {
                    continue;
                }
                if(temp[newx][newy]>temp[x][y]+1)
                {
                    temp[newx][newy]=temp[x][y]+1;
                    q.push({newx,newy});
                }
            }
        }
        long long int va=INT_MAX;
        return va+1;
    }
    int binarySearch(vector<vector<int>>& grid)
    {
        int low=0;
        int high=20001;
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;
            long long int v=solve(mid,grid);
            if(v<=fire[grid.size()-1][grid[0].size()-1])
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        if(ans==INT_MAX)
        {
            return -1;
        }
        if(ans==20001)
        {
            return 1000000000;
        }
        return ans;
    }
    int maximumMinutes(vector<vector<int>>& grid) 
    {
        directions.push_back({0,1});
        directions.push_back({1,0});
        directions.push_back({0,-1});
        directions.push_back({-1,0});
        fireTime(grid);
        return binarySearch(grid);
    }
};