class Solution {
public:
    
    // take all the minimum values and add 1
    
    // lets say the values are 8,1,2 and k=4 if we add 4 for 8 then answer will be 24 (12*1*2) but if we make it as 8,4,3 then answer will be 96
    
    // Because multiplying bigger value with very small value will lead to smaller answer
    
    // example values are 4 2 and k=2 if we make 6 2 then answer 12, if we make 5 3 answer is 15,other possibility if we make 4 4 answer is 16 
    
    int maximumProduct(vector<int>& nums, int k) 
    {
        priority_queue <int, vector<int>, greater<int>> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        while(k--)
        {
            int v=pq.top();
            pq.pop();
            v++;
            pq.push(v);
        }
        long long int ans=1;
        while(!pq.empty())
        {
            int v=pq.top();
            pq.pop();
            ans*=v;
            ans%=1000000007;
        }
        return ans;
    }
};