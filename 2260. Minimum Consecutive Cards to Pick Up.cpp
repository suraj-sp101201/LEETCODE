class Solution {
public:
    
    // if there is no 2 same cards then -1
    
    // fix a index and see till which index i can add cards such that a pair of matching cards are present
    
    // once this is found next move the first pointer and again see till which index i can add cards such that a pair of matching cards are present
    
    // so use two pointer approach
    
    int minimumCardPickup(vector<int>& cards) 
    {
        map<int,int> mp;
        int i1=0;
        int i2=0;
        int n=cards.size();
        int ans=n;
        int f=1;
        for(int i=0;i<cards.size();i++)
        {
            mp[cards[i]]++;
            if(mp[cards[i]]==2)
            {
                f=0;
                break;
            }
        }
        if(f)
        {
            return -1;
        }
        mp.clear();
        while(i2<n)
        {
            while(i2<n && mp[cards[i2]]==0)
            {
                mp[cards[i2]]++;
                i2++;
            }
            ans=min(ans,i2-i1+1);
            mp[cards[i1]]--;
            i1++;
        }
        return ans;
    }
};
