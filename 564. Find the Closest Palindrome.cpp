class Solution {
public:
    
    /*
    
    Take a palindrome number 12321 for example, the next bigger palindrome should be 12421, and the next smaller one should be 12221.

That is, if we define 123 as palindromeRoot of 12321, the next bigger palindrome number's palindromeRoot ispalindromeRoot + 1 (124), while the next smaller one's palindromeRoot ispalindromeRoot - 1(122).

For palindrome numbers with even digits, e.g., 123321, the change of palindromeRoot follows the same pattern.

The closest palindromic one should be among the palindromic numbers formed by these 2 palindromeRoots.

For numbers which are not palindromic, e.g., 12345, we still focus on the front half of the number, i.e., palindromeRoot as 123 in the example. Except for the bigger one formed by palindromeRoot + 1(124), the smaller one formed by palindromeRoot - 1(122), there should be one more possibility, i.e., the number formed by palindromeRoot (123). We chose the closest one among these 3 palindromic numbers formed.

There are some cases missing the rules above,
case 1. <= 10, OR equal to 100, 1000, 10000, ... We simply decrease n by 1.
case 2. 11, 101, 1001, 10001, 100001, ... We simply decrease n by 2.
case 3. 99, 999, 9999, 99999, ... We simply increase n by 2.
    
    */
    unsigned long long int dif(unsigned long long int v1, unsigned long long int v2)
    {
        if(v2>v1)
        {
            swap(v1,v2);
        }
        return v1-v2;
    }
    unsigned long long int convert(string s)
    {
        unsigned long long int ans=0;
        for(int i=0;i<s.length();i++)
        {
            int v=s[i]-'0';
            ans+=v;
            ans*=10;
        }
        ans/=10;
        return ans;
    }
    string solve(unsigned long long int v, int f)
    {
        string s1=to_string(v);
        string s2=s1;
        reverse(s2.begin(),s2.end());
        if(f)
        {
            return s1+s2;
        }
        else
        {
            string s=s1;
            for(int i=1;i<s2.length();i++)
            {
                s+=s2[i];
            }
            return s;
        }
    }
    int check(unsigned long long int v)
    {
        string s=to_string(v);
        if(s[0]!='1')
        {
            return 0;
        }
        for(int i=1;i<s.length();i++)
        {
            if(s[i]!='0')
            {
                return 0;
            }
        }
        return 1;
    }
    int allNine(unsigned long long int v)
    {
        string s=to_string(v);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='9')
            {
                return 0;
            }
        }
        return 1;
    }
    string nearestPalindromic(string s) 
    {
        unsigned long long int v=0;
        
        for(int i=0;i<s.length();i++)
        {
            int val=s[i]-'0';
            v+=val;
            v*=10;
        }
        v/=10;
        if(v<=10 || (v%10==0 && check(v)))
        {
            return to_string(v-1);
        }
        if(v==11 || (((v-1)%10==0)&&check(v-1)))
       {
            return to_string(v-2);
       }
        if(allNine(v))
       {
            return to_string(v+2);
       }
        int even_length=0;
        string str;
        if(s.length()%2==0)
        {
            even_length=1;
            str=s.substr(0,s.length()/2);
        }
        else
        {
            str=s.substr(0,(s.length()/2)+1);
        }
        unsigned long long int cur=convert(str);
        unsigned long long int prev=cur-1;
        unsigned long long int next=cur+1;
        string s1=solve(cur,even_length);
        string s2=solve(prev,even_length);
        string s3=solve(next,even_length);
        cur=convert(s1);
        prev=convert(s2);
        next=convert(s3);
        unsigned long long int diff=dif(v,prev);
        if(v!=cur)
        {
            diff=min(diff,dif(v,cur));
        }
        diff=min(diff,dif(v,next));
        unsigned long long int ans=next;
        unsigned long long int diff1=dif(v,cur);
        unsigned long long int diff2=dif(v,prev);
        unsigned long long int diff3=dif(v,next);
        if(diff==diff1 && cur!=v)
        {
            ans=min(ans,cur);
        }
        if(diff==diff2 && prev!=v)
        {
            ans=min(ans,prev);
        }
        if(diff==diff3 && next!=v)
        {
            ans=min(ans,next);
        }
        return to_string(ans);
    }
};