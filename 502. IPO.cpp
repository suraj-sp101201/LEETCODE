class Solution {
public:
    
    // sort based on the capital and take the maximum profit that is available till this point
    
    // best data structure for that is max-heap
    
    // Let Current capital be ans. Initialy it is zero. So push all the values that can be taken for this capital(i.e. all capitals that are lesser than this or equal can be taken)
    
    // after all are pushed, take the maximum profit and now you will have more capital
    
    // with this capital, we can take some capitals that are lesser or equal to this so push all those and take the maximum profit
    
    // this process will continue till k becomes 0
    
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        vector<pair<int,int>> vp;
        for(int i=0;i<profits.size();i++)
        {
            vp.push_back({capital[i],profits[i]});
        }
        sort(vp.begin(),vp.end());
        int ans=w;
        priority_queue<int> pq;
        int idx=0;
        int n=vp.size();
        while(k--)
        {
            while(idx<n && vp[idx].first<=ans)
            {
                pq.push({vp[idx].second});
                idx++;
            }
            if(pq.size())
            {
                int v=pq.top();
                pq.pop();
                ans+=v;
            }
        }
        return ans;
    }
};