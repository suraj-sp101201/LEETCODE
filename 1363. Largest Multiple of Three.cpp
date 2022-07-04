class Solution {
public:
    
    // sort digits on descending order
    
    // calculate sum of digits if it is divisible by 3 then just take it
    
    // if remainder turns to be 1 or 2. Then remove the minimum number from it that has that remainder.
    
    // If there is no remainder that has exactly that remainder then we can remove in this way. If remainder is 1 then we can remove 2 numbers that has 2 as remainder and If remainder is 2 then we can remove 2 numbers that has 1 as remainder
    
    void removal(vector<int>& digits, int v, int f)
    {
        if(!f)
        {
            int idx=-1;
            for(int i=0;i<digits.size();i++)
            {
                if(digits[i]==v)
                {
                    idx=i;
                    break;
                }
            }
            digits.erase(digits.begin()+idx);
        }
        else
        {
            if(v==1)
            {
                v=2;
            }
            else
            {
                v=1;
            }
            int idx=-1;
            int mn=INT_MAX;
            for(int i=0;i<digits.size();i++)
            {
                if(digits[i]%3==v)
                {
                    if(mn>digits[i])
                    {
                        mn=digits[i];
                        idx=i;
                    }
                }
            }
            digits.erase(digits.begin()+idx);
        }
    }
    string largestMultipleOfThree(vector<int>& digits) 
    {
        int sum=0;
        for(int i=0;i<digits.size();i++)
        {
            sum+=digits[i];
        }
        int rem=sum%3;
        int f=1;
        if(rem!=0)
        {
            int mn=INT_MAX;
            for(int i=0;i<digits.size();i++)
            {
                if(digits[i]%3==rem)
                {
                    mn=min(mn,digits[i]);
                    f=0;
                }
            }
            if(f)
            {
                removal(digits,rem,1);
                removal(digits,rem,1);
                if(digits.size()==0)
                {
                    return "";
                }
            }
            else
            {
                removal(digits,mn,0);
            }
        }
        sort(digits.begin(),digits.end(),greater<int>());
        string ans="";
        for(int i=0;i<digits.size();i++)
        {
            char c=digits[i]+'0';
            ans+=c;
        }
        if(ans.length())
        {
            if(ans[0]=='0')
            {
                return "0";
            }
        }
        return ans;
    }
};