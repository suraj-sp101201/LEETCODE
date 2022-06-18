class Solution {
public:
    
    // dp[i][j] denotes the number of non-empty palindromic subsequences from i to j
    
    // if s[i]!=s[j] then take the palindromic subsequences from i+1 to j and i to j-1 and subtract i+1 to j-1 as it will contain duplicates
    
    // example: aaabbc since a!=c, from here there can be no palindromic subsequences starting from a and ending at c as(a!=c). So take palindromic subsequences from index 0 to index 4 (it will be {a,aa,aaa,b,bb}) and take from index 1 to index 5 (it will be {a,aa,b,bb,c}). Notice here the duplicates, so subtract the common interval i.e. from index 1 to index 4 (it will be {a,aa,b,bb}). ab is not a palindrome
    
    // if s[i]==s[j] then look for left and right points in such a way that the characters that are present are equal to each other and also same as s[i] or s[j](as s[i] and s[j] both are same). Let it be left and right.
    
    // Note: in all those below examples I am taking i=0 and j=last index
    
    // if left>right then it means there are no same characters, so all subsequences will be distinct so ((dp[i+1][j-1]*2)+2) will be the answer. Example abcba then subsequences of i+1 to j-1 will be {b,bcb,bb,c} . It is multiplied by two because the previous subsequences can come and also {aba,abcba,abba,aca} (note 'a' is added to front and back of the previous subsequence) and +2 will come because {a,aa}
    
    // if left==right then there is only one character that is same. Example ababa, then i+1 to j-1 the sequences are {b,a,bab,bb} so this will come and {aba,aaa,ababa,abba} and just 1 is added because 1 is already counted and only {aa} needs to be counted
    
    // if left<right . Example aabcaa then i+1 to j-1 sequences are {a,b,c,aa,aba,aca} so this will come and also {aaa,aba,aca,aaaa,aabaa,aacaa} will come. Note here there are duplicates which comes {aba,aca} and it will be from left+1 to right-1. Proof for this is, If there is aabcaa and left and right is abca, then here since our i and j is a,a and left and right is a,a so whatever subsequences that come under this are duplicates.
    
    int countPalindromicSubsequences(string s) 
    {
        int n=s.length();
        long int dp[n][n];
        memset(dp,0,sizeof(dp));
        int mod=1000000007;
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        for(int len=1;len<n;len++)
        {
            for(int start=0;start<n-len;start++)
            {
                int end=start+len;
                if(s[start]==s[end])
                {
                    int left=start+1;
                    int right=end-1;
                    while(left<=right && s[left]!=s[end])
                    {
                        left++;
                    }
                    while(left<=right && s[right]!=s[end])
                    {
                        right--;
                    }
                    if(left==right)
                    {
                        dp[start][end]=dp[start+1][end-1]*2+1;
                    }
                    else if(left>right)
                    {
                        dp[start][end]=dp[start+1][end-1]*2+2;
                    }
                    else
                    {
                        dp[start][end]=dp[start+1][end-1]*2-dp[left+1][right-1];
                    }
                }
                else
                {
                    dp[start][end]=dp[start][end-1]+dp[start+1][end]-dp[start+1][end-1];
                }
                dp[start][end]=dp[start][end]<0?dp[start][end]+mod:dp[start][end]%mod;
            }
        }
        return dp[0][n-1];
    }
};