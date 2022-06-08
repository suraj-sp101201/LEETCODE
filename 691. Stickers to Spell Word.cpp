class Solution {
public:
    
    // This is not a greedy problem. Example stickers = ["ttt","tte"], target = "tttteee".
    
    // If you pick the more t's i.e. stickers[0] two times then the target will be "eee", so next you will pick stickers[1] three times so it will be 2+3=5. But it is not the case. Just pick three stickers[1], it is enough so answer will be 3.
    
    // Check if all characters of target are present in stickers, if not then we can't do at all so return -1.
    
    // use a sticker only if any of the characters present in the sticker are present in target, else do not use this sticker. Use this Optimisation for selecting the stickers from the give sticker array, as well as for selecting a sticker for target string.
    
    // if target string becomes empty then we have achieved, so choose the miminum number of stickers used.
    
    // Use Dynamic programming because same target string may repeat. example if target is "the" and if you find again "the" use the answer of the previous, for this sub-problem.
    
    map<string,int> dp;
    bool contains(vector<int>& temp, vector<int>& cnt)
    {
        for(int i=0;i<26;i++)
        {
            if(cnt[i]>0 && temp[i]>0)
            {
                return 1;
            }
        }
        return 0;
    }
    vector<int> count(string& s)
    {
        vector<int> ans(26,0);
        for(int i=0;i<s.length();i++)
        {
            int v=s[i]-'a';
            ans[v]++;
        }
        return ans;
    }
    int solve(vector<vector<int>>& nums, string s)
    {
        if(s=="")
        {
            return 0;
        }
        if(dp.count(s))
        {
            return dp[s];
        }
        int ans=INT_MAX;
        vector<int> cnt=count(s);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i][s[0]-'a']==0)
            {
                continue;
            }
            string str="";
            for(int j=0;j<26;j++)
            {
                if(cnt[j]-nums[i][j]>0)
                {
                    str+=string(cnt[j]-nums[i][j],'a'+j);
                }
            }
            ans=min(ans,1+solve(nums,str));
        }
        return dp[s]=ans;
    }
    int minStickers(vector<string>& stickers, string target) 
    {
        map<char,int> mp;
        for(int i=0;i<stickers.size();i++)
        {
            string s=stickers[i];
            for(int j=0;j<s.length();j++)
            {
                mp[s[j]]++;
            }
        }
        for(int i=0;i<target.length();i++)
        {
            if(!(mp.count(target[i])))
            {
                return -1;
            }
        }
        vector<vector<int>> v;
        vector<int> cnt=count(target);
        for(int i=0;i<stickers.size();i++)
        {
            vector<int> temp=count(stickers[i]);
            if(contains(temp,cnt))
            {
                v.push_back(temp);
            }
        }
        return solve(v,target);
    }
};