class Solution {
public:
    
    // isPalindrome[i][j] is 1 if index from i to j in the string is a palindrome
    
    // cost[i] denotes the minimum cuts needed from i to end
    
    // if from i to end is a palindrome then cost[i] is 0 as zero cuts
    
    // if from i to j is a palindrome then cost[i] is minimum of cost[j+1]+1
    
    // the reason for cost[j+1]+1 is, from i to j is a palindrome so I can make a cut here and take the minimum cuts needed from j+1 to end (which is donoted by cost[j+1]) so it is cost[j+1]+1
    
    int minCut(string s) 
    {
        int isPalindrome[s.length()][s.length()];
        memset(isPalindrome,0,sizeof(isPalindrome));
        int cost[s.length()+1];
        cost[s.length()]=0;
        for(int start=s.length()-1;start>=0;start--)
        {
            cost[start]=s.length()-1-start;
            for(int end=start;end<s.length();end++)
            {
                if(s[start]==s[end] && (end-start<2 || isPalindrome[start+1][end-1]))
                {
                    isPalindrome[start][end]=1;
                    if(end==s.length()-1)
                    {
                        cost[start]=0;
                    }
                    else if(cost[start]>cost[end+1]+1)
                    {
                        cost[start]=cost[end+1]+1;
                    }
                }
            }
        }
        return cost[0];
    }
};