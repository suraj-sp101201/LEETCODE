class Solution {
public:
    
    // count the number of steps to complete a letter from the key string from both backside and frontside and take the minimum
    
    // for frontside and backside there is 2 cases. let the current character be 'a' and searching is 'c' and x be some random characters. xcxxxax here it is so simple just take the absolute difference between both indices. 
    
    // xxxacx here you can't like that because taking, it will give ans as 1 but is is not. forward means, moves can be made only to right so you have to go to x(at rightside) then x,again x,again x, then only to a. Similarly do the same for backside also
    
    // THIS IS NOT GREEDY. EXAMPLE RING="XXXXGXAXXGD" AND KEY IS "AGD" SO YOU WILL GO TO 'A', FROM HERE IF YOU PICK CLOSEST 'G', THAT IS LEFT 'G' THEN YOU HAVE TO GO TO THE 'D' THAT IS PRESENT AT THE LAST, INSTEAD IF YOU GO TO RIGHT 'G', THEN IN NEXT MOVE WE CAN ALSO COMPLETE 'D'
    
    // so recursively doing this is easy but it is not efficient so use dynamic programming to solve sub-problems
    
    // sub-problems are dp[last index that was taken][current index of key]
    
    // last index means example if we are searching for 'c' and 'c' is present in ring at 0,3,7,8 so we will be choosing all indices one by one. so last will be this index
    
    // example if last index that was taken is 4 and now I have completed 3 characters of the key string and in future if last index that was taken was 4 and 3 characters are completed then do not solve it again, instead use dynamic programming
    
    map<pair<int,int>,int> dp;
    int solve(string key, map<char,vector<int>>& mp, int index, char cur, int last, int n)
    {
        if(index==key.length())
        {
            return 0;
        }
        pair<int,int> p;
        p.first=index;
        p.second=last;
        if(dp.count(p))
        {
            return dp[p];
        }
        int ans=INT_MAX;
        if(cur==key[index])
        {
            ans=1+solve(key,mp,index+1,cur,last,n);
        }
        else
        {
            for(int i=0;i<mp[key[index]].size();i++)
            {
                int front,back;
                if(last>mp[key[index]][i])
                {
                    front=n-last+mp[key[index]][i];
                }
                else
                {
                    front=abs(mp[key[index]][i]-last);
                }
                if(last>mp[key[index]][i])
                {
                    back=abs(mp[key[index]][i]-last);
                }
                else
                {
                    back=last+n-mp[key[index]][i];
                }
                ans=min(ans,front+1+solve(key,mp,index+1,key[index],mp[key[index]][i],n));
                ans=min(ans,back+1+solve(key,mp,index+1,key[index],mp[key[index]][i],n));
            }
        }
        dp[p]=ans;
        return ans;
    }
    int findRotateSteps(string ring, string key) 
    {
        map<char,vector<int>> mp;
        for(int i=0;i<ring.length();i++)
        {
            mp[ring[i]].push_back(i);
        }
        return solve(key,mp,0,ring[0],0,ring.length());
    }
};