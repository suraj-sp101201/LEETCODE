class Solution {
public:
    
    // Solve the problem by reverse
    
    // If there is a substring that is same as stamp then we have to put the stamp in that place at the last
    
    // example, stamp = "abca", target = "aabcaca" . In index 1 we can see that both the substrings of length stamp are same so the last operation will be placing a stamp at index 1. So see all windows that are exactly same as stamp and those will be replaced at the last.
    
    // so make the replaced characters as "*". So Target will be "a****ca" . So here, see where will the next stamp come. Take each window by window. If the characters match or if it is a star then we can replace. Example "a***" is same as "abca" and also "**ca" is same as "abca".
    
    // the reason why it is same is because, we dont care about the '*' because in future anyway we are going to replace it
    
    // Try all windows from start to end. If we see that we have not replaced anything. Then in next iteration or in future also we can't, so return a empty array
    
    // if all are made stars then it is over and we have replaced
    
    bool possibleReplace(string target, string stamp, int start, int end)
    {
        for(int i=start;i<=end;i++)
        {
            if(target[i]!='*' && target[i]!=stamp[i-start])
            {
                return 0;
            }
        }
        return 1;
    }
    int doReplace(string& target, int start, int end)     
    {
        int count=0;
        for(int i=start;i<=end;i++)
        {
            if(target[i]!='*')
            {
                target[i]='*';
                count++;
            }
        }
        return count;
    }
    vector<int> movesToStamp(string stamp, string target) 
    {
        vector<int> ans;
        int replaced=0;
        vector<int> visited(target.length(),0);
        int start=0;
        int end=stamp.length()-1;
        int replacedFlag=0;
        while(replaced<target.length())
        {
            if(end<target.length() && !visited[start] &&   possibleReplace(target,stamp,start,end))
            {
                replaced+=doReplace(target,start,end);
                visited[start]=1;
                ans.push_back(start);
                replacedFlag=1;
            }
            start++;
            end++;
            if(end==target.length())
            {
                start=0;
                end=stamp.length()-1;
                if(!replacedFlag)
                {
                    return {};
                }
                replacedFlag=0;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};