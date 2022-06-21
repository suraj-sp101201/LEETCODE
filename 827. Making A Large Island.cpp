class Solution {
public:
    
    // combine all groups and name the group as a number with greater than 1 so that we can differentiate upcoming 1's.
    
     /*
     
     1111              2222
     0000      ----->  0000
     1110              3330
     0001              0004
    
    */
    
    // add the sizes of each group. example size of group 2's is 4, size of group 3's is 3, size of group 4's is 1
    
    // So now if you find see a 0, see their neighbours and all those can be combined into a group. Example if this 0's neighbours are group 2,3,4,5 then we can combine 2,3,4,5. So answer will be size of group 2 + size of group 3 + size of group 4 + size of group 5 + 1(this 1 is because we are converting a 0 to 1) 
    
    /*
     
     -------
     Example:
     -------
     
     2222
     0000         
     3330
     0004
    
    Let's convert 0 to a 1 in index (1,1). Their neighbours are 2 and 3
    
    2222
    0100         
    3330
    0004
    
    so group 2 and group 3 can be combined
    
    -----------------
    One More example :
    -----------------
    
    2222
    0000         
    3330
    0004
    
    Let's convert 0 to a 1 in index (3,3). Their neighbours are 3 and 4
    
    2222
    0000         
    3331
    0004
    
    so group 3 and 4 can be combined
    
    ----------------
    One more example:
    -----------------
    
    22222
    00200
    33044
    33044
    33044
    
    Let's convert 0 to a 1 in index (2,2). Their neighbours are 2,3 and 4
    
    22222
    00200
    33144
    33044
    33044
    
    so group 2,3 and 4 can be combined
    
    */
    
    // if there is no zeros then it means all are 1's
    
    unordered_set<int> neighbours(int i, int j, vector<vector<int>>& grid, int n)
    {
        unordered_set<int> ans;
        if(i-1>=0)
        {
            ans.insert(grid[i-1][j]);
        }
        if(j-1>=0)
        {
            ans.insert(grid[i][j-1]);
        }
        if(i+1<n)
        {
            ans.insert(grid[i+1][j]);
        }
        if(j+1<n)
        {
            ans.insert(grid[i][j+1]);
        }
        return ans;
    }
    int dfs(int i, int j, vector<vector<int>>& grid, int counter, int n)
    {
        if(i<0 || j<0 || i>=n || j>=n || grid[i][j]!=1)
        {
            return 0;
        }
        grid[i][j]=counter;
        return 1+dfs(i-1,j,grid,counter,n)+dfs(i+1,j,grid,counter,n)+dfs(i,j-1,grid,counter,n)+dfs(i,j+1,grid,counter,n);
    }
    int largestIsland(vector<vector<int>>& grid) 
    {
        vector<int> sizes;
        int counter=2;
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int count=dfs(i,j,grid,counter,n);
                    counter++;
                    sizes.push_back(count);
                }
            }
        }
        int answer=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    int total=0;
                    unordered_set<int> all_neighbours=neighbours(i,j,grid,n);
                    for(auto it:all_neighbours)
                    {
                        if(it>=2)
                        {
                            total+=sizes[it-2];
                        }
                    }
                    answer=max(answer,total+1);
                }
            }
        }
        if(answer==-1)
        {
            return n*n;
        }
        return answer;
    }
};