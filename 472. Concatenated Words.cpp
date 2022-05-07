class Solution {
public:
    
    // first sort the words based on the word length because for bigger words we can just check the previous words
    
    // for example cats dog catsdogcats be the array string
    
    // so after sorting it would be dog cats catsdogcats
    
    // now we have to check wthether this word is concatenated or not
    
    // we can check it by using dynammic programming
    
    // first we'll try wthether till the point i can we concatenate. example catsdogcats we ll iterate through i from 1 to the length
    
    // if i=4 then it means we are checking is there some words when concatenated we get answer till 4th position of the original word
    
    // i is using 1-index 
    
    // dp[i] denotes till i is there an answer
    
    // first cats will be generated and dp[4] will be set as 1
    
    // then dog will be generated and we have to check before that character 'd' are we having answer if we are having and this is a dog then dp[7] = 1
    
    unordered_map<string,int> st;
    static bool comp(string& s1, string& s2)
    {
        if(s1.length()!=s2.length())
        {
            return s1.length()<s2.length();
        }
        else
        {
            return s1<s2;
        }
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    {
        sort(words.begin(),words.end(),comp);
        vector<string> ans;
        for(int i=0;i<words.size();i++)
        {
            if(solve(words[i]))
            {
                ans.push_back(words[i]);
            }
            st[words[i]]++;
        }
        return ans;
    }
    int solve(string word)
    {
        if(st.size()==0)
        {
            return 0;
        }
        int dp[word.length()+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=word.length();i++)
        {
            for(int j=0;j<i;j++)
            {
                string s=word.substr(j,i-j);
                if(st.count(s) && dp[j]==1)
                {
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[word.length()];
    }
};