class Solution {
public:
    
    // take a current string and change the first letter. If this is not found then this means we can convert that character to some other character
    
    // example ["coffee","donuts","time","toffee"] . for coffee see wthether I can convert 'c' to 'a' i.e coffee to aofee. There is no aofee so I can convert, but we need to check for one more also. Will say that below
    
    // similarly do for all strings i.e check wthether this character can be converted to some other character
    
    // count of 'c' to 'a' = 2 denotes there are two strings that start with 'c' and it can be converted to 'a' i.e. after changing first letter of it to 'a' (means there are no same strings that are found in ideas after changing those strings from 'c' to 'a')
    
    // we can convert it to a pair only if there is strings that can be converted from 'c' to 'a' and 'a' to 'c'. If not, it is not possible
    
    // example if we can convert count['c']['a'] is 3 and count['a']['c'] is 2. Then 6 pairs are possible. Example call,cat,cad (then there is no aall, aat, aad) AND at,ad(then there is no ct,cd) . So (call,at), (cat,at), (cad,at), (call,ad), (cat,ad), (cad,ad). If there is ct in ideas then we can't take, as taking it with any of those 3 strings will give ct. 
    
    // note: count of same characters will be 0. i.e count['c']['c'] will be 0 as swapping c with c is same and will be found so two same characters cant be swapped
    
    long long distinctNames(vector<string>& ideas) 
    {
        unordered_map<string,int> mp;
        for(int i=0;i<ideas.size();i++)
        {
            mp[ideas[i]]++;
        }
        int count[26][26];
        memset(count,0,sizeof(count));
        for(int i=0;i<ideas.size();i++)
        {
            int idx=ideas[i][0]-'a';
            for(char c='a';c<='z';c++)
            {
                string str=ideas[i];
                str[0]=c;
                if(!mp.count(str))
                {
                    int id=c-'a';
                    count[idx][id]++;
                }
            }
        }
        long long int ans=0;
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(count[i][j]>0 && count[j][i]>0)
                {
                    long long int v=count[i][j];
                    v*=count[j][i];
                    ans+=v;
                }
            }
        }
        return ans;
    }
};