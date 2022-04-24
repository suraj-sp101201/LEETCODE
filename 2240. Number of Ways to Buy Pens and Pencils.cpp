class Solution {
public:
    
    // first buy 0 pen and check how many pencils you can buy, then buy 1 pen and check how many pencils you can buy, next buy 2 pens and so on... all time 1 is added because 0 pencils can also be present
    
    long long waysToBuyPensPencils(int total, int cost1, int cost2) 
    {
        long long int ans=0;
        long long int count=0;
        while(count*cost1<=total)
        {
            long long int v=total-(count*cost1);
            v/=cost2;
            ans+=v;
            ans++;
            count++;
        }
        return ans;
    }
};
