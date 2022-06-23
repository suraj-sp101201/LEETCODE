class Solution {
public:
    
    // VIDEO SOLUTION : https://www.youtube.com/watch?v=pPks_UrfETo
    
    /* 
        EDITORIALS I SAW : 
        
        https://leetcode.com/problems/transform-to-chessboard/discuss/114847/C%2B%2BJavaPython-Solution-with-Explanation
        
        https://leetcode.com/problems/transform-to-chessboard/discuss/440085/Python-detailed-explanation
        
        https://leetcode.com/problems/transform-to-chessboard/discuss/1487265/C%2B%2B-solution-with-Image-explanation
        
    */
    
    bool invalidPattern(vector<vector<int>>& board)
    {
        string s="";
        for(int i=0;i<board.size();i++)
        {
            char c=board[0][i]+'0';
            s+=c;
        }
        string sReverse=s;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='0')
            {
                sReverse[i]='1';
            }
            else
            {
                sReverse[i]='0';
            }
        }
        for(int i=1;i<board.size();i++)
        {
            string temp="";
            for(int j=0;j<board.size();j++)
            {
                char c=board[i][j]+'0';
                temp+=c;
            }
            if(s!=temp && sReverse!=temp)
            {
                return 1;
            }
        }
        return 0;
    }
    int movesToChessboard(vector<vector<int>>& board) 
    {
        if(invalidPattern(board))
        {
            return -1;
        }
        int n=board.size();
        int rowSum=0;
        int colSum=0;
        int rowMisplaced=0;
        int colMisplaced=0;
        for(int i=0;i<n;i++)
        {
            rowSum+=board[i][0];
            colSum+=board[0][i];
            rowMisplaced+=(board[i][0]==i%2);
            colMisplaced+=(board[0][i]==i%2);
        }
        if(((rowSum==n/2) || (rowSum==((n+1)/2))) && ((colSum==n/2) || (colSum==((n+1)/2))))
        {
            int swapRow,swapCol;
            if(n%2==0)
            {
                swapRow=min(rowMisplaced,n-rowMisplaced);
                swapCol=min(colMisplaced,n-colMisplaced);
            }
            else
            {
                swapRow=rowMisplaced;
                swapCol=colMisplaced;
                if(rowMisplaced%2==1)
                {
                    swapRow=n-rowMisplaced;
                }
                if(colMisplaced%2==1)
                {
                    swapCol=n-colMisplaced;
                }
            }
            return ((swapRow+swapCol)/2);
        }
        return -1;
    }
};