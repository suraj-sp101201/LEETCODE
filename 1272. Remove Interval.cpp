class Solution {
public:
    
    // there are 3 cases for a interval to contain toBeRemoved section
    
    // case 1: intervals 5 9 , removed 6 8
    
    // case 2: intervals 5 9, removed 3 10
    
    // case 3: intervals 5 9, removed 7 11
    
    // then start from intervals[i][0] till removed[0] and removed[1] to intervals[i][1]
    
    // example intervals 5 10, removed 2 12 then 2 5 and 10 12 are possible 
    
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) 
    {
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++)
        {
            if((intervals[i][1]<=toBeRemoved[1] && toBeRemoved[0]<=intervals[i][0])||(intervals[i][1]>=toBeRemoved[0] && toBeRemoved[0]>=intervals[i][0]) || (intervals[i][0]>=toBeRemoved[0] && toBeRemoved[1]>=intervals[i][0]))
            {
                int start1=intervals[i][0];
                int end1=toBeRemoved[0];
                if(end1-start1>=1)
                {
                    ans.push_back({start1,end1});
                }
                int start2=toBeRemoved[1];
                int end2=intervals[i][1];
                if(end2-start2>=1)
                {
                    ans.push_back({start2,end2});
                }
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};