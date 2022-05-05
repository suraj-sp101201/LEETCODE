class Solution {
public:
    
    // the used values are denoted with the data vector. data[i]=1 denotes i is used
    
    // so create a bitmask with the used values, for example used is 0110 then value is 6 because 2^1 + 2^2
    
    // so use this as dp state and check with this state can he win or not
    
    // note: there is no parameter for checking who won, is it the first player or second player
    
    // it is not needed because we can determine with the number of 1's in used. example in first player turn, the number of 1's can only be even and for second player the number of 1's will be odd
    
    // example for first player: 0000, 0101, 1001 etc....
    
    unordered_map<int,int> mp;
    vector<int> data;
    int change(vector<int>& data)
    {
        int v=0;
        for(int i=1;i<data.size();i++)
        {
            v<<=1;
            if(data[i]==1)
            {
                v|=1;
            }
        }
        return v;
    }
    int recurse(int rem)
    {
        if(rem<=0)
        {
            return 0;
        }
        int v=change(data);
        if(mp.count(v))
        {
            return mp[v];
        }
        for(int i=1;i<data.size();i++)
        {
            if(data[i]==0)
            {
                data[i]=1;
                if(!recurse(rem-i))
                {
                    mp[v]=1;
                    data[i]=0;
                    return 1;
                }
                data[i]=0;
            }
        }
        if(!mp.count(v))
        {
            mp[v]=0;
        }
        return mp[v];
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) 
    {
        if(desiredTotal<=1)
        {
            return 1;
        }
        int s=(maxChoosableInteger*(maxChoosableInteger+1))/2;
        if(s<desiredTotal)
        {
            return 0;
        }
        for(int i=0;i<=maxChoosableInteger;i++)
        {
            data.push_back(0);
        }
        return recurse(desiredTotal);
        
    }
};