class Solution {
public:
    
    // use a min-heap of size of k elements and store all the first elements of the k lists and have a variable to see the maximum value present in heap
    
    // for example [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]], heap consists of 0,4,5 so the answer is [0,5] . Next remove the minimum element i.e. 0 and add the next greater element in that list i.e. 4,5,9 the range is [4,9]
    
    // Next 5,9,10 [5,10] . Next [9,10,18] [9,18] . Next [10,12,18] [10,18] . Next [12,15,18] [12,18] . Next [15,18,20] [15,20] . Next [18,20,24] [18,24] . Next [20,22,24] [20,24] so this is the smallest range
    
    // while you pop you will have the minimum element and mx variable will have the maximum element present in heap so answer is minimum difference of these two, so you will get the minimum range.
    
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i][0],{i,0}});
            mx=max(mx,nums[i][0]);
        }
        int start=0;
        int end=INT_MAX;
        while(1)
        {
            pair<int,pair<int,int>> p=pq.top();
            pq.pop();
            int val=p.first;
            int row=p.second.first;
            int column=p.second.second;
            if(end-start>mx-val)
            {
                start=val;
                end=mx;
            }
            if(column+1==nums[row].size())
            {
                break;
            }
            pq.push({nums[row][column+1],{row,column+1}});
            mx=max(mx,nums[row][column+1]);
        }
        vector<int> ans(2);
        ans[0]=start;
        ans[1]=end;
        return ans;
    }
};