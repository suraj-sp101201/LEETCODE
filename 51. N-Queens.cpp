class Solution {
public:
    
    // place a queen only if it doesn't violate the condition
    
    // conditions: no queen on the same column, no queen on left diagonal and right diagonal
    
    // no need to check left, right and below. 
    
    // The reason why you need not check left and right is because we are placing only one queen at a time in the row, so no queen can be there in left or right
    
    // similarly no need to check below because we are going from top to bottom so there will be no queen in bottom
    
    // if we have kept/placed all queens then we can add it to our answer
    
    vector<vector<string>> ans;
    bool valid(vector<vector<char>>& v, int row, int col)
    {
        for(int i=row;i>=0;i--)
        {
            if(v[i][col]=='Q')
            {
                return 0;
            }
        }
        for(int i=row,j=col;i>=0 && j>=0;i--,j--)
        {
            if(v[i][j]=='Q')
            {
                return 0;
            }
        }
        for(int i=row,j=col;i>=0 && j<v.size();i--,j++)
        {
            if(v[i][j]=='Q')
            {
                return 0;
            }
        }
        return 1;
    }
    void solve(int kept, int n, vector<vector<char>>& v)
    {
        if(kept==n)
        {
            vector<string> temp;
            for(int i=0;i<n;i++)
            {
                string s="";
                for(int j=0;j<n;j++)
                {
                    s+=v[i][j];
                }
                temp.push_back(s);
            }
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(valid(v,kept,i))
            {
                v[kept][i]='Q';
                solve(kept+1,n,v);
                v[kept][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<char>> v(n,vector<char>(n,'.'));
        solve(0,n,v);
        return ans;
    }
};