class Solution {
public:
    
    // in this problem we will traverse character by character and find how much will be added to the answer if we add add this charcter to the string
    
    // let the string be cdaba 
    
    // if just one character is present in the string then answer is 1 i.e. for 'c' character
    
    /* 
    
       two cases: 1) if this character was already present before 
                  2) if this character was not present before 
                  
    */
    
    // for example in that string 'b' is not already present so answer for this 'b' is previous cost (i.e. cda) + (index of 'b'+1). The reason is:
    
    /* 
        a 
        da
        cda
    
        this is previous and now 'b' is added to this
        
        ab
        dab
        cdab
        
        if the previous cost is x then for this 'b' the cost is x+3+1 because in this 'b' part the previous substring are present and b will added 4 times(ie. 3 times as shown above and then "b" of length 1) because this was not present before(i.e. distinct)
    */
    
    /*
    
        if this was already present, example 'a' then answer for this 'a', previous cost (i.e. cdab) + (current index of 'a' - previous index of 'a'). The reason is:
        
        b
        ab
        dab
        adab
        
        this is previous and now 'a' is added to this
        
        ba
        aba
        daba
        adaba
        
        if previous cost is x then it will added as it contains previous substrings and this 'a' will count only for 2 times i.e. "a" and "ba" before that all will contain another 'a' so it is not distinct so it will not be added
        
    */
    
    long long appealSum(string s) 
    {
        long long int ans=1;
        map<char,int> mp;
        long long int cur=0;
        long long int prev=1;
        mp[s[0]]=0;
        for(int i=1;i<s.length();i++)
        {
            if(mp.count(s[i]))
            {
                 cur=prev+(i-mp[s[i]]);
            }
            else
            {
                cur=prev+(i+1);
            }
            ans+=cur;
            prev=cur;
            mp[s[i]]=i;
        }
        return ans;
    }
};