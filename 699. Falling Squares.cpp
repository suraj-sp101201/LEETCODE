class Solution {
public:
    
    // insert as intervals. Insert interval as height, left_point, right_point. Update height while inserting intervals by checking all the previously inserted intervals
    
    // positions = [[1,2],[2,3],[6,1]]. Take 1,2 there are no intervals inserted so insert 2,1,3(height,left,right). Next [2,3] here we see that there is a overlap and height of that block is 2 so it will 2+3,2,5 i.e. 5,2,5
    
    // If no block is overlapping then the height will be same as the sideLength
    
    // Only process overlapping blocks. Non-overlapping blocks can be skipped. A block will be non-overlapping, if :
    
    // 1) current block left >= interval block right . 2) current block right <= interval block left
    
    // IF YOU DON'T UNDERSTAND SEE HERE : https://leetcode.com/problems/falling-squares/discuss/108766/Easy-Understood-O(n2)-Solution-with-explanation
    
    vector<pair<int,pair<int,int>>> intervals;
    int getHeight(pair<int,pair<int,int>>& cur)
    {
        int h=0;
        for(int i=0;i<intervals.size();i++)
        {
            if((cur.second.first>=intervals[i].second.second)||(intervals[i].second.first>=cur.second.second))
            {
                continue;
            }
            h=max(h,intervals[i].first);
        }
        cur.first+=h;
        intervals.push_back(cur);
        return cur.first;
    }
    vector<int> fallingSquares(vector<vector<int>>& positions) 
    {
        vector<int> ans;
        int h=0;
        for(int i=0;i<positions.size();i++)
        {
            int left=positions[i][0];
            int side=positions[i][1];
            int height=positions[i][1];
            pair<int,pair<int,int>> p;
            p.first=height;
            p.second.first=left;
            p.second.second=side+left;
            h=max(h,getHeight(p));
            ans.push_back(h);
        }
        return ans;
    }
};