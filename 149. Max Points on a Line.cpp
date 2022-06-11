class Solution {
public:
    
    // take two elements and put a line and see how many points can come in this line.
    
    // finding the Number of points of a pure horizontal line and vertical line is easy like it can be done by this:
    
    // 1) For horizontal line, x axis remains same so take all elements that are there with that x
    
    // 2) For vertical line, y axis remains same so take all elements that are there with that y
    
    // For remianing types of straight lines, take slope and find how many lines fall on this.
    
    int solve(vector<int>& v1, vector<int>& v2, map<double,int>& mp)
    {
        double x1=v1[0];
        double y1=v1[1];
        double x2=v2[0];
        double y2=v2[1];
        double slope=(y2-y1)*1.0/(x2-x1);
        if(mp.count(slope))
        {
            mp[slope]++;
            return mp[slope];
        }
        mp[slope]=2;
        return mp[slope];
    }
    int maxPoints(vector<vector<int>>& points) 
    {
        map<int,int> mp1,mp2;
        for(int i=0;i<points.size();i++)
        {
            mp1[points[i][0]]++;
            mp2[points[i][1]]++;
        }
        int ans=1;
        for(int i=0;i<points.size();i++)
        {
            map<double,int> mp;
            for(int j=i+1;j<points.size();j++)
            {
                int x_change=abs(points[i][0]-points[j][0]);
                int y_change=abs(points[i][1]-points[j][1]);
                if(x_change==0)
                {
                    ans=max(ans,mp1[points[i][0]]);
                }
                else if(y_change==0)
                {
                    ans=max(ans,mp2[points[i][1]]);
                }
                else
                {
                    int answer=solve(points[i],points[j],mp);
                    ans=max(ans,answer);
                }
            }
        }
        return ans;
    }
};