class Solution {
public:
    
    // This problem should be visualised as a tree and should be solved. This editorial has beautiful pictures for visualisation so see this.
    
    // SEE THIS : https://leetcode.com/problems/reaching-points/discuss/375429/Detailed-explanation.-or-full-through-process-or-Java-100-beat
    
    bool reachingPoints(int sx, int sy, int tx, int ty) 
    {
        while(sx<tx && sy<ty)
        {
            if(tx<ty)
            {
                ty%=tx;
            }
            else
            {
                tx%=ty;
            }
        }
        if(sx==tx && sy<=ty && (ty-sy)%sx==0)
        {
            return 1;
        }
        if(sy==ty && sx<=tx && (tx-sx)%sy==0)
        {
            return 1;
        }
        return 0;
    }
};