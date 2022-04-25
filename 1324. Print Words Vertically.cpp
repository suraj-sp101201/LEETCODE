class Solution {
public:
    
    // first find the length of the maximum word and create a array of that size
    
    // if you take a word, then take index by index for that one word and append that character to the array with that index
    
    // example "how are you", here in "how" index 0 is h, in "are" index 0 is a, in "you" index 0 is y, add these values to the first string in answer
    
    // when some word has a smaller length then in that places add empty string
    
    // example if max length of word is 5, and some word is there with length 2, then for remaining 3 places put ' '
    
    // finally remove the trailing spaces if it exists
    
    
    vector<string> printVertically(string s) 
    {
        int len=0;
        int cur=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
            {
                cur++;
            }
            else
            {
                len=max(len,cur);
                cur=0;
            }
        }
        len=max(len,cur);
        vector<string> ans(len,"");
        cur=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
            {
                ans[cur]+=s[i];
                cur++;
            }
            else
            {
                while(cur<len)
                {
                    ans[cur]+=' ';
                    cur++;
                }
                cur=0;
            }
        }
        for(int i=0;i<ans.size();i++)
        {
            int idx=-1;
            for(int j=ans[i].length()-1;j>=0;j--)
            {
                if(ans[i][j]!=' ')
                {
                    idx=j;
                    break;
                }
            }
            string str=ans[i];
            string s=str.substr(0,idx+1);
            ans[i]=s;
        }
        return ans;
    }
};