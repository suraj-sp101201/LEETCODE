class Solution {
public:
    
    // IF YOU DON'T KNOW ABOUT GRAHAM SCAN THEN SEE THIS VIDEO : https://youtu.be/B2AJoQSZf4M
    
    // EDITORIAL : https://leetcode.com/problems/erect-the-fence/discuss/1442271/Day-3-or-Erect-the-Fence-or-Convex-Hull-Algorithm-or-C%2B%2B-or-With-graphical-explanation
    
    vector<vector<int>> ans;
    void unique(vector<vector<int>> leftHull)
    {
        set<vector<int>> points;
        for(int i=0;i<leftHull.size();i++)
        {
            if(!points.count(leftHull[i]))
            {
                points.insert(leftHull[i]);
            }
        }
        for(auto it:points)
        {
            ans.push_back(it);
        }
    }
    int getDirection(vector<int>& p1, vector<int>& p2, vector<int>& p3)
    {
        return (((p2[0]-p1[0])*(p3[1]-p2[1]))-((p2[1]-p1[1])*(p3[0]-p2[0])));
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) 
    {
        if(trees.size()<=3)
        {
            return trees;
        }
        sort(trees.begin(),trees.end());
        vector<vector<int>> leftHull;
        leftHull.push_back(trees[0]);
        leftHull.push_back(trees[1]);
        for(int i=2;i<trees.size();i++)
        {
            int size=leftHull.size();
            while(size>=2 && getDirection(leftHull[size-1],leftHull[size-2],trees[i])>0)
            {
                leftHull.pop_back();
                size--;
            }
            leftHull.push_back(trees[i]);
        }
        vector<vector<int>> rightHull;
        rightHull.push_back(trees[trees.size()-1]);
        rightHull.push_back(trees[trees.size()-2]);
        for(int i=trees.size()-3;i>=0;i--)
        {
            int size=rightHull.size();
            while(size>=2 && getDirection(rightHull[size-1],rightHull[size-2],trees[i])>0)
            {
                rightHull.pop_back();
                size--;
            }
            rightHull.push_back(trees[i]);
        }
        leftHull.pop_back();
        rightHull.pop_back();
        for(int i=0;i<rightHull.size();i++)
        {
            leftHull.push_back(rightHull[i]);
        }
        unique(leftHull);
        return ans;
    }
};