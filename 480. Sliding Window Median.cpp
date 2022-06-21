class Solution {
public:
    
    // First put k elements in a multiset. In multiset elements will be sorted in order
    
    // Put a mid pointer to middle of the element. If k is even we have to take value of mid and value of left of mid and divide by 2. Example k=6 mid is 3 ((val[3]+val[2])/2) is answer
    
    // mid is a pointer or like a index. IT IS NOT A VALUE/ELEMENT HERE
    
    // move as window. Like insert one element and delete one element
    
    // Move mid pointer according only. 4 cases are possible. In that 2 cases are so easy. If a value that is getting added and value that is getting removed, if they both are less than mid, then mid remains same. Similarly If a value that is getting added and value that is getting removed, if they both are greater than mid, then mid remains same. So 2 cases are covered. Remaining 2 cases
    
    // if a value is getting removed is less than mid and if value is getting added is greater than mid, then mid will be incremented by one position. Example 2,3,4 mid is 3,if 2 is getting removed and 5 is added then 3,4,5 and 4 will be mid
    
    // if a value is getting removed is greater than mid and if value is getting added is lesser than mid, then will be decremented by one position. Example 2,3,4 mid is 3,if 4 is getting removed and 1 is added then 1,2,3 and 2 will be mid
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) 
    {
        multiset<int> elements(nums.begin(),nums.begin()+k);
        auto mid=next(elements.begin(),k/2);
        vector<double> answer;
        for(int i=k;i<=nums.size();i++)
        {
            answer.push_back(((double)*mid+*prev(mid,1-k%2))/2);
            if(i!=nums.size())
            {
                elements.insert(nums[i]);
                if(nums[i]<*mid)
                {
                    mid--;
                }
                if(nums[i-k]<=*mid)
                {
                    mid++;
                }
                elements.erase(lower_bound(elements.begin(),elements.end(),nums[i-k]));
            }
        }
        return answer;
    }
};