class Solution {
public:
    
    // use prefixsum concept and store the sum
    
    // let the array be [a,b,c,d,e,f,g,h]. let the answer for [a,b,c,d] be x and [e,f,g,h] be y. Then answer is x+y+(count of ranges of the left half elements that are there in second half)
    
    // the left half and right half are sorted
    
    // example [-2,5,-1,-2,10] . [-2,5] answer for this is 1, [-1,-2,10] answer for this is 2. [-2,5][-1,-2,10] find the count of ranges in left half elements. for element -2 it will begin at -1(i.e. at index 2) and end at -2(i.e at index 3) so 3-2+1=2. It means for this -2 there will be 2 ranges that satisfy condition. and those subarrays [-2,5] [-1,-2,10] will further be divided
    
    // similarly for 5 it will begin at -2 and end at -2 so answer is 1. So 2+1=3. so 1+2+3(x+y+count) = 6
    
    // instead of using this values use prefix sum of this [0,-2,3,2,0,10]
    
    // left half will be [0,-2,3], right half will be [2,0,10]
    
    // its sorted so [-2,0,3], [0,2,10]
    
    // for -2 answer is 1 and for 0 answer is 2. for -2 the subarray starts at 5 and for 0 the subarray starts at -2. Now look how many subarrays are there that start with 5 just 1, it is [5,-1,-2] and Now look how many subarrays are there that start with -2 answer is 2, it is [-2,5,-1] [-2,5,-1,-2]
    
    /*
        If you still don't understand then look at this articles
        
        https://leetcode.com/problems/count-of-range-sum/discuss/77990/Share-my-solution
        
        https://leetcode.com/problems/count-of-range-sum/discuss/1267104/C%2B%2B-SIMPLE-explanation-for-BEGINNERS-to-HARD-problems
        
        https://leetcode.com/problems/count-of-range-sum/discuss/1251996/C%2B%2B-clear-explanation-thought-process-and-code
        
    */
    

    int mergeSort(vector<long long int>& sum, int lower, int upper, int low, int high)
    {
        if(high-low<=1)
        {
            return 0;
        }
        int mid=(low+high)/2;
        int count=mergeSort(sum,lower,upper,low,mid)+mergeSort(sum,lower,upper,mid,high);
        int l=mid;
        int r=mid;
        for(int i=low;i<mid;i++)
        {
            while(l<high && sum[l]-sum[i]<lower)
            {
                l++;
            }
            while(r<high && sum[r]-sum[i]<=upper)
            {
                r++;
            }
            count+=(r-l);
        }
        inplace_merge(sum.begin()+low,sum.begin()+mid,sum.begin()+high);
        return count;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) 
    {
        int n=nums.size();
        vector<long long int> sum(n+1);
        sum[0]=0;
        for(int i=0;i<n;i++)
        {
            sum[i+1]=sum[i]+nums[i];
        }
        return mergeSort(sum,lower,upper,0,n+1);
    }
};