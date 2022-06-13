class Solution {
public:
    
    // swapped[i] denotes number of swaps(cost) needed to MAKE THE ARRAY INCREASING and also BY performing a swap at (a[i],b[i])
    
    // notSwapped[i] denotes number of swaps(cost) needed to MAKE THE ARRAY INCREASING and also by NOT performing a swap at (a[i],b[i])
    
    // IF a[i-1] < a[i] && b[i-1] < b[i] then if we want to swap a[i] and b[i] then we need to also swap a[i-1] and b[i-1], so if we want to swap a[i-1] and b[i-1] then it is nothing but swapped[i-1] and also this a[i] and b[i] is swapped so +1 is added. similarly if we dont swap a[i] and b[i] then a[i-1] and b[i-1] should also be not swapped
    
    // example a[i-1]=5 and a[i]=10 and b[i-1]=11 and b[i]=13. 5 < 10 and 11 < 13 then if we swap a[i] and b[i] then it will be 5,13 and 11,10 which is not increasing so we have to also swap a[i-1] and b[i-1] then it will be 11,13 and 5,10. Similarly if we dont swap 10 and 13 then we should not swap 5 and 11 also.
    
    // You might ask a question why should we find this(swapped[i] for the above example), instead it can be there itself. if second array upcoming elements contains 11,12,13,14...... so making 5 and 10 to second array will lead to minimum operations.
    
    // atlast see take the minimum of swapped[n-1] and notSwapped[n-1] ( If this not clear see the definition at the top i.e. swapped[i] and notSwapped[i])
    
    int minSwap(vector<int>& a, vector<int>& b) 
    {
        int n=a.size();
        vector<int> swapped(n,n);
        vector<int> notSwapped(n,n);
        swapped[0]=1;
        notSwapped[0]=0;
        for(int i=1;i<n;i++)
        {
            if(a[i-1]<a[i] && b[i-1]<b[i])
            {
                swapped[i]=min(swapped[i],swapped[i-1]+1);
                notSwapped[i]=notSwapped[i-1];
            }
            if(a[i-1]<b[i] && b[i-1]<a[i])
            {
                swapped[i]=min(swapped[i],notSwapped[i-1]+1);
                notSwapped[i]=min(notSwapped[i],swapped[i-1]);
            }
        }
        return min({swapped[n-1],notSwapped[n-1]});
    }
};