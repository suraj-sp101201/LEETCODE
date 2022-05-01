class Solution {
public:
    
    // traverse in only one direction
    
    // example if guard is 1,1 then he cant see 2,2 , if you go in all 4 directions then from 1,1 it will go to 1,2 and then to 2,2 where it should not go
    
    // so pick a direction like left,right,up,down and traverse only in that direction and mark the cells
    
    // mark the 'G' as 1 and the cells that he can see as '2' and then cells of 'W' as -1. the reason why we are not supposed to mark 'G' and the cells(that he can see) as same is because then it would start dfs on that cell
    
    // example if guard is in 1,1 the he can see 1,2 but if you mark 1,2 as 1 then it should dfs on this point and mark 1,3 as visited but 1,3 is actually not possible
    
    void dfs(vector<vector<int>>& v, int i, int j, int m, int n, int f, int gf)
    {
        if(i<0 || j<0 || i>=m || j>=n || (v[i][j]!=0 && v[i][j]!=2 && gf))
        {
            return;
        }
        if(gf!=0)
        {
            v[i][j]=2;
        }
        if(f==0)
        {
            dfs(v,i-1,j,m,n,f,1);
        }
        if(f==1)
        {
            dfs(v,i+1,j,m,n,f,1);
        }
        if(f==2)
        {
            dfs(v,i,j-1,m,n,f,1);
        }
        if(f==3)
        {
            dfs(v,i,j+1,m,n,f,1);
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
    {
        vector<vector<int>> v(m,vector<int>(n,0));
        for(int i=0;i<guards.size();i++)
        {
            v[guards[i][0]][guards[i][1]]=1;
        }
        for(int i=0;i<walls.size();i++)
        {
            v[walls[i][0]][walls[i][1]]=-1;
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==1)
                {
                    dfs(v,i,j,m,n,0,0);
                    dfs(v,i,j,m,n,1,0);
                    dfs(v,i,j,m,n,2,0);
                    dfs(v,i,j,m,n,3,0);
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==0)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
