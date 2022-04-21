class Solution {
public:
    
    /* 
    
    Observation
    Count the frequency of mod3 = 0,1,2.

    Firstly, don't consider the multiples of 3.
    Alice starts with mod3 = 1, Alice and Bob have to pick 1,1,2,1,2... in order.
    Alice starts with mod3 = 2, Alice and Bob have to pick 2,2,1,2,1... in order.

    If Alice starts with 1, then Alice needs 1 and Bob needs 2.
    If 1 is much more than 2, then Bob is going to lose.

    So if cnt[0] == 0, the result can be decided by Alice.

    Then, consider the number of multiples of 3.
    If cnt[0] is even,
    Bob picks a 3, Alice can always picks one another.
    the result won't be affected.

    If cnt[0] is odd,
    the final result will be reversed,
    (unless the case Bob win for all numbers consumed)


    Missing Case
    [1,1,1,3] gave by @mittal582 and @qingqi_lei,
    which can hack some solution.


    Explanation
    If cnt[1] == 0, Alice needs to start with mod3 = 2,
    If cnt[2] == 0, Alice needs to start with mod3 = 1.
    Alice can win if max(cnt[1], cnt[2]) > 2 && cnt[0] % 2 > 0,
    for example [1,1,1,3].

    If cnt[0] % 2 == 0, easy case for Alice.
    Alice can win in at leasy one of the two options, picking the less one.

    Otherwise cnt[0] % 2 == 1, this will reverse the result.
    If abs(cnt[1] - cnt[2]) > 2,
    Alice will pick mod3=2 if mod3=2 is more
    Alice will pick mod3=1 if mod3=1 is more
    If abs(cnt[1] - cnt[2]) <= 2,
    Alice will lose for no number remaining.
    
    
    */
    
    int solve(int v1, int v2, int v3)
    {
        int ans;
        v1-=2;
        v2-=1;
        ans=3;
        int mn=min(v1,v2);
        ans+=(mn*2);
        v1-=mn;
        v2-=mn;
        if(v1>0)
        {
            ans++;
        }
        ans+=v3;
        return ans;
    }
    bool stoneGameIX(vector<int>& stones) 
    {
        map<int,int> mp;
        for(int i=0;i<stones.size();i++)
        {
            int v=stones[i]%3;
            mp[v]++;
        }
        if(mp[1]>=1 || mp[2]>=1)
        {
            int c=min(mp[1],mp[2]);
            int three=mp[0];
            if(three%2==0 && c==1)
            {
                return 1;
            }
            if(mp[1]==mp[2])
            {
                c=mp[1]+mp[2]-1;
            }
            else if(mp[1]==0 || mp[2]==0)
            {
                if(mp[1]==0)
                {
                    c=min(mp[2],2);
                }
                else
                {
                    c=min(mp[1],2);
                }
            }
            else
            {
                int c1,c2;
                c1=solve(mp[1],mp[2],mp[0]);
                c2=solve(mp[2],mp[1],mp[0]);
                if((c1%2==1 && c1!=stones.size()) || (c2%2==1 && c2!=stones.size()))
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            c+=mp[0];
            if(c==stones.size())
            {
                return 0;
            }
            if(c%2==1)
            {
                return 1;
            }
            else
            {
                
                return 0;
            }
        }
        return 0;
    }
};