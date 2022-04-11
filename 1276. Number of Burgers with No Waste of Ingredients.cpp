class Solution {
public:
    /* 
    
    number of units totally should be cheeseSlices as for both products we will be taking 1. so let's call it count, if lets say count is 12 and if we dont have atleast 24 tehn its not possible to find the answer and also if count is 8 and if tomatoSlices are more than 32 the it is not able to find the answer and if tomatoSlices is odd then its not possible as both products taken even numbers and we should make it to 0 at the end. lets do a binary search from 0 to count and fix the the number of Jumbo Burger and take remaining Small Burger
    
    */
    
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) 
    {
        int count=cheeseSlices;
        if(tomatoSlices<count*2 || count*4<tomatoSlices || tomatoSlices%2==1)
        {
            return {};
        }
        int start=0;
        int end=cheeseSlices;
        while(start<=end)
        {
            int mid=(start+end)/2;
            int v=(mid*4)+((cheeseSlices-mid)*2);
            if(v==tomatoSlices)
            {
                return {mid,cheeseSlices-mid};
            }
            if(v>tomatoSlices)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return {};
    }
};