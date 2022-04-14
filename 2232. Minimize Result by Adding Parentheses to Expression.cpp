class Solution {
public:
    
    // find the position at which '+' is there and fix '(' before that position and ')' after that position
    
    // example: take any string of length 6 and assume '+' is at index 3 then fix (0,4) (0,5) (0,6) (1,4) (1,5) (1,6) .....
    
    // find the number that is before '(' and after ')' and finally multiply with the sum
    
    // if there is no before or after,then make it 1, multiplying with 0 will always lead to 0
    
    
    int solve(string s, int p, int q, int m)
    {
        int before=0;
        int after=0;
        for(int i=0;i<=p-1;i++)
        {
            before*=10;
            int v=s[i]-'0';
            before+=v;
        }
        for(int i=q+1;i<s.length();i++)
        {
            after*=10;
            int v=s[i]-'0';
            after+=v;
        }
        int sum=0;
        int v1=0;
        int v2=0;
        for(int i=p;i<m;i++)
        {
            v1*=10;
            int v=s[i]-'0';
            v1+=v;
        }
        for(int i=m+1;i<=q;i++)
        {
            v2*=10;
            int v=s[i]-'0';
            v2+=v;
        }
        if(before==0)
        {
            before=1;
        }
        if(after==0)
        {
            after=1;
        }
        return (before*(v1+v2)*after);
    }
    string minimizeResult(string expression) 
    {
        int idx=-1;
        for(int i=0;i<expression.length();i++)
        {
            if(expression[i]=='+')
            {
                idx=i;
                break;
            }
        }
        int mn=INT_MAX;
        string ans="";
        for(int i=0;i<idx;i++)
        {
            for(int j=idx+1;j<expression.length();j++)
            {
                int v=solve(expression,i,j,idx);
                if(mn>v)
                {
                    string temp=expression;
                    if(j==expression.length()-1)
                    {
                        temp+=')';
                    }
                    else
                    {
                        temp.insert(j+1,")");
                    }
                    temp.insert(i,"(");
                    ans=temp;
                    mn=v;
                }
            }
        }
        return ans;
    }
};
