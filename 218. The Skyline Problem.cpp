class Solution {
public:
    
    // Record the height and end points in a max heap(greater height and greater end point at top)
    
    // Initially take first element and put in heap. Put all elements of the same left. Example if first element's left is 2. Then put all buildings with left as 2. Now take the maximum height present in heap so it is the Skyline
    
    // a point will be noted, only if their height differs i.e. if there is a height of 10 and this is also a height of 10 then it will be straight line and will not be recorded
    
    // remove a point only after it life gets expired (i.e end point).
    
    // buildings = [[2,9,10],[3,7,15],[5,12,12]]. First 10,9 will be in heap and 2,10 is pushed to answer. 9 is the end point and current left point is 3 so the first building can live for some more time. Now {15,7} are pushed and height is changed for this point so push 3,15 to answer. end point is 7 which means till 7, the maximum height is 15 and current point starts with 5 so this can live for some more time so 12,12 is pushed into heap now here nothing is pushed to answer as the top height remains same and it can live for some more time. Now end point 7 is taken and next point is greater than 7 so this cant live any more and all points that are live and less than this also cant live anymore so lets pop and here there is a new height that is present in heap ie. 12 so it is pushed to answer as 7,12 . Now end point 12 is taken and next point is greater than 12 so this cant live any more and all points that live less than this also cant live anymore so lets pop. Now no points are there for this end point so 12,0 is pushed to answer
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        priority_queue<pair<int,int>> pq;
        int idx=0;
        int n=buildings.size();
        vector<vector<int>> ans;
        while(idx<n || !pq.empty())
        {
            int x=pq.size()==0?buildings[idx][0]:pq.top().second;
            if(idx==n || buildings[idx][0]>x)
            {
                while(!pq.empty() && pq.top().second<=x)
                {
                    pq.pop();
                }
            }
            else
            {
                x=buildings[idx][0];
                while(idx<n && buildings[idx][0]==x)
                {
                    pq.push({buildings[idx][2],buildings[idx][1]});
                    idx++;
                }
            }
            int h=pq.size()==0?0:pq.top().first;
            if(ans.empty() || ans[ans.size()-1][1]!=h)
            {
                ans.push_back({x,h});
            }
        }
        return ans;
    }
};