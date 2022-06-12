class Solution {
public:
    
    // use two pointer approach
    
    // traverse element by element and see how many subarray's will come for this elememt
    
    // current element index is i. See how many subarrays will come from left side of i
    
    // IMPORTANT OBSERVATION: adding an element to a SUBARRAY, increase the number of subarray's count by the length
    
    // PROOF: [1] number of subrrays is 1. [1,2] number of subarrays for this 3( 1 [this 1 came from before] + 2 ). [1,2,7] number of subarrays is 6 because previously for [1,2] the number of subarrays was 3 and now it is 6 which means 3 subarrays are coming after adding this element becuuse [7] can be a subarray and this 7 will come with [1,2,7] and [2,7]. 
    
    // If there are 5 elements and 6th element is coming then extra 6 subarrays will come . They are [1st elem, 2nd elem, 3rd elem, 4th elem, 5th elem, 6th elem] , [2nd elem, 3rd elem, 4th elem, 5th elem, 6th elem] , [3rd elem, 4th elem, 5th elem, 6th elem] , [4th elem, 5th elem, 6th elem] , [5th elem, 6th elem], [6th elem]
    
    // example nums = [2,1,4,3,5]. For 2 answer is 1 as in left no elements are there. Next 1, this can accompany with 2 i.e. [2,1] is possible so add 2 to the answer as there will be two subarrays i.e. [1], [2,1]. Now 4, 4 can't accompany because adding it, will make the score greater than k so move the first pointer (before the first pointer was on 0th index, now it will be in 1st index). now this satifies i.e. [1,4] satifies so 2 will be added to answer as [4] and [1,4] are possible and so on.....
    
    long long countSubarrays(vector<int>& nums, long long k) 
    {
        long long int ans=0;
        unsigned long long int sum=0;
        int n=nums.size();
        int j=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            while(j<=i && ((sum*(i-j+1))>=k))
            {
                sum-=nums[j];
                j++;
            }
            ans+=(i-j+1);
        }
        return ans;
    }
};
