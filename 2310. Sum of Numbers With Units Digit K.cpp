class Solution {
public:
    
    // take the greatest number with k as unit digit and less than or equal to num and try to solve it.
    
    // Note down the count of numbers taken. if remaining is 0 then, then ans is that count only and no need to check for any other numbers because whatever that satisfies first will have smaller count as we have are always taking greater number and trying to solve it
    
    int ans;
    void solve(int num, int count, int k)
    {
        if(num==0)
        {
            ans=count;
            return;
        }
        else if(num<0)
        {
            return;
        }
        if(ans!=-1)
        {
            return;
        }
        int temp=num;
        while(temp>=0 && temp%10!=k)
        {
            temp--;
        }
        for(int start=temp;start>=0;start-=10)
        {
            if(ans!=-1)
            {
                return;
            }
            solve(num-start,count+1,k);
        }
    }
    int minimumNumbers(int num, int k) 
    {
        if(num==0)
        {
            return 0;
        }
        int last=num%10;
        int f=0;
        for(int i=1;i<=10;i++)
        {
            int v=i*k;
            if(v%10 == last)
            {
                f=1;
                break;
            }
        }
        if(!f)
        {
            return -1;
        }
        ans=-1;
        solve(num,0,k);
        return ans;
    }
};
