class Solution {
public:
    
    // count the steps needed to go from x to x+1 like, from 1 to 2
    
    // if the count is equal to k then x+1 is answer, if count<k then we will move to 2(if x was 1) because the answer can start on 2 or after 2, if count>k then we will move to x*10
    
    // example if n=23 and k=5, start with 1, steps needed to go from 1(1 is already counted) to 2 is 11 because 10,11,12,13,14,15,16,17,18,19,2. K=4(as 1 counted) here count>k i.e. 11>4 so answer will start with 1 as the first digit only.
    
    // k=12, element 1 is subtracted so k is 11. steps needed from 1 to 2 is 11(count) so 2 is the answer because count is equal to k
    
    // k=14, element 1 is subtracted so k is 13. steps needed from 1 to 2 is 11(count) so answer will be greater than 2 because count<k
    
    // n=23,steps between 1 and 2 can be counted by this way. 1 to 2 the gap is 1(i.e element 2) so add 1, 10 to 20 the gap is 10(10,11,....19) and 20 to 23, 4 should be added because(20,21,22,23), both 20 and 23 will come.
    
    // IF YOU DON'T UNDERSTAND SEE HERE : https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/discuss/92242/ConciseEasy-to-understand-Java-5ms-solution-with-Explaination
    
    int findKthNumber(int n, int k) 
    {
        int ans=1;
        k--;
        while(k>0)
        {
            int steps=count(n,ans,ans+1);
            if(steps==k)
            {
                return ans+1;
            }
            else if(steps>k)
            {
                ans*=10;
                k-=1;
            }
            else
            {
                ans+=1;
                k-=steps;
            }
        }
        return ans;
    }
    int count(long int n, long int n1, long int n2)
    {
        int steps=0;
        while(n1<=n)
        {
            steps+=((min(n+1,n2))-n1);
            n1*=10;
            n2*=10;
        }
        return steps;
    }
};