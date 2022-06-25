class Solution {
public:
    
    // If xor is initially zero then Alice wins
    
    // xor will be not zero if there are some elements that are present odd number of times. If all elements are present even number of times, then xor will be 0.
    
    // lets say xor of all elements is x, if we remove an element say v then new_xor(i.e. x) will be x^v (that operator is a xor operator and not power operator). So it will be zero when we pick a value v that is equal to x i.e. x^x=0
    
    // if number of elements is even, Alice would win and if number of elements is odd, Bob would win.
     
    // Reason is, lets say xor of all elements is x (x!=0) so greedily we have to pick elements such that they are not equal to x(x is the xor of all elements).  If you pick a value x, then it will become zero so dont do that. At the end, we will be left with elements with value x which will be present odd number of times only. It cant be present even number of times, because then it would have already been zero.
    
    // Now, we dont have any choice, we have to remove a element with value x. On removing, it will be 0. 
    
    // So x is present odd number of times only. Two cases: 1) N is odd 2) N is even. If N is odd, then even number of elements has already been removed. If N is even, then odd number of elements has already been removed. Because Odd(x) + Even(removed) = Odd, Odd(x) + Odd(removed) = Even. Odd+Odd=Even, Odd+Even=Odd. Odd(x) means total x elements are odd, Even(removed) means total removed elements are even, Odd(removed) means total removed elements are odd.
    
    // So if N is odd then, even elements are removed so it will be alice turn and he will pick x and lose so Bob will win. If N is even then, odd elements are removed so it will be bob turn and he will pick x and lose so Alice will win.
    
    bool xorGame(vector<int>& nums) 
    {
        int x=0;
        for(int i=0;i<nums.size();i++)
        {
            x^=nums[i];
        }
        return x==0 || nums.size()%2==0;
    }
};