class Solution {
public:
    
    // if maximum element is greater than rest of elements then (rest of element*2 +1 ) because lets say max is 11 and rest of sum of elements except this max is 9 then 9*2 + 1=19 because the best strategy is pick max, pick other, pick max, pick other....pick max.
    
    // else if sum of rest of elements is greater than max, then we can complete all. Example if max is 10 and rest sum is 15 then we can remove that max and finally have total 5 in such a way that we can reduce that 5 also
    
    // exmaple 10 3 4 5 2 1,then we can change it to 0 1 1 2 1 1 , then we can change it to 0 0 0 0 1 1, then we can change it to 0 0 0 0 0 0
    
    
    long long numberOfWeeks(vector<int>& milestones) 
    {
        long long sum=0;
        int mx=INT_MIN;
        for(int i=0;i<milestones.size();i++)
        {
            sum+=milestones[i];
            mx=max(mx,milestones[i]);
        }
        if(sum-mx>=mx)
        {
            return sum;
        }
        return (((sum-mx)*2)+1);
    }
};