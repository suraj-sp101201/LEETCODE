class Solution {
public:
    
    // if sum is equal to goal then answer is 0
    
    // find the difference between sum and goal, and greedly add maximum elements.
    
    // example -4 is sum and goal is 7 then difference is 11 and if limit is 3 then add 3 three times so sum will become 5 so add 2 just once to get answer
    
    // example 4 is sum and goal is -7 then difference is -11 and if limit is 3 then add -3 three times so sum will become -5 so add -2 just once to get answer
    
    int minElements(vector<int>& nums, long long int limit, long long int goal) 
    {
        long long int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum==goal)
        {
            return 0;
        }
        long long int diff=abs(goal-sum);
        if(limit<0)
        {
            limit*=-1;
        }
        long long int ans=diff/limit;
        if(diff%limit)
        {
            ans++;
        }
        return ans;
    }
};