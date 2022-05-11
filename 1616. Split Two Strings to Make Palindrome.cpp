class Solution {
public:
    
    // traverse until a point from left and right until you find a different character and checking if that range is palindrome
    
    // example abcdefghij abcdaadcba so we we can see that abcd from left and dcba from right is matching so we ll check in between that is a palindrome or not. 
    
    // ef is the middle element in left string and aa is the middle element in right string
    
    // since aa is a palindrome abcdaadcba is palindrome (abcd from left)(aadcba from right)
    
    bool palindrome(string s, int l, int r)
    {
        int length=(r-l+1);
        for(int i=0;i<length/2;i++)
        {
            if(s[l+i]!=s[r-i])
            {
                return 0;
            }
        }
        return 1;
    }
    bool solve(string s1, string s2)
    {
        int l=0;
        int r=s1.length()-1;
        while(l<r)
        {
            if(s1[l]==s2[r])
            {
                l++;
                r--;
            }
            else
            {
                break;
            }
        }
        return (palindrome(s1,l,r)||palindrome(s2,l,r));
    }
    bool checkPalindromeFormation(string a, string b) 
    {
        return (solve(a,b)||solve(b,a));
    }
};