class Solution {
public:
    
    // Note that the number of powers of 2 is at most 21 so this turns the problem to a classic find the number of pairs that sum to a certain value but for 21 values
    
    // count the number of elements
    
    // if you take this element then check with what all element, i can get a 2^x value when added and take it from the hash table
    
    // if the count of 1 is 2 and count of 7 is 3 then 3*2=6
    
    // if v is 4 and remaining is 4 and the count of 4 is 3 then answer is 3 because 4,4 4,4 4,4
    
    int countPairs(vector<int>& deliciousness) 
    {
        map<long long int,long long int> mp;
        for(int i=0;i<deliciousness.size();i++)
        {
            mp[deliciousness[i]]++;
        }
        long long int ans=0;
        for(auto it:mp)
        {
            for(int i=0;i<=21;i++)
            {
                long long int v=pow(2,i);
                long long int rem=v-it.first;
                if(rem>=it.first)
                {
                    if(rem==it.first)
                    {
                        ans+=((it.second*(it.second-1))/2);
                    }
                    else if(mp.count(rem))
                    {
                        ans+=(it.second*mp[rem]);
                    }
                    ans%=1000000007;
                }
            }
        }
        return ans;
    }
};