class Solution {
public:
    
    // As we can only stay or move to zero, if last character is '1' then it is not possible
    
    // increment can_reach_here[i] by 1 if we can reach i
    
    // if can_reach_here[i-minJump+1]-can_reach_here[i-maxJump]==0 then it means we cant reach here because it means in this range [i-maxJump,i-minJum+1] there is no position that is reachable
    
    // can_reach_here[n]-can_reach_here[n-1]==0 is just to check wthether the last value ( i.e. can_reach_here[n] ) is reachable or not. example if last before value is 5, then this will get 5, if we can reach here then we would have incremented this by 1 so 6 then it means this is reachable because(6-5), if we can't reach here then we would have 5 then it means this is not reachable because(5-5)
    
    bool canReach(string s, int minJump, int maxJump) 
    {
        int n=s.length();
        if(s[n-1]=='1')
        {
            return 0;
        }
        int can_reach_here[n+1];
        can_reach_here[0]=0;
        for(int i=1;i<=minJump;i++)
        {
            can_reach_here[i]=1;
        }
        for(int i=minJump;i<n;i++)
        {
            can_reach_here[i+1]=can_reach_here[i];
            if(s[i]=='0')
            {
                if(i-maxJump>=0 && can_reach_here[i-minJump+1]-can_reach_here[i-maxJump]==0)
                {
                    // do nothing
                }
                else if(i-maxJump<0 && can_reach_here[i-minJump+1]-can_reach_here[0]==0)
                {
                    // do nothing
                }
                else
                {
                    can_reach_here[i+1]++;
                }
            }
        }
        if(can_reach_here[n]-can_reach_here[n-1]==0)
        {
            return 0;
        }
        return 1;
    }
};