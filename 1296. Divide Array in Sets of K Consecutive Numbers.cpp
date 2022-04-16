class Solution {
public:
    
    // greedily check for next elements. Always start with smallest element or with highest element, do not pick a random element and start.
    
    // Example 1,2,3,4,5,6,7,8,9 k=3, if we start from beginning (1,2,3) (4,5,6) (7,8,9), if we start from end (9,8,7) (6,5,4) (3,2,1)
    
    // but if randomly pick like 5, then grouping will be either (5,6,7) or (5,4,3) then we ll be left with 2 elements on the side. i.e. 
    
    //if we pick (5,6,7) then 8,9 will be left and there is no 7 to combine

    //if we pick (5,4,3) then 1,2 will be left and there is no 3 to combine
    
    
    bool isPossibleDivide(vector<int>& nums, int k) 
    {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        while(1)
        {
            int f=1;
            for(auto it:mp)
            {
                if(it.second>0)
                {
                    f=0;
                    int cur=it.first;
                    mp[cur]--;
                    int temp=k-1;
                    while(temp>0)
                    {
                        if(mp[cur+1]>=1)
                        {
                            mp[cur+1]--;
                            cur++;
                        }
                        else
                        {
                            return 0;
                        }
                        temp--;
                    }
                    if(temp==0)
                    {
                        break;
                    }
                }
            }
            if(f)
            {
                break;
            }
        }
        return 1;
    }
};