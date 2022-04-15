/*

let first candidate be 0 for the answer. if someone is not knowing the candidate, then it means this he can be the possible candidate. now we would have possible candidate, if this candidate knows someone or if some i does not know him, then there is no celebrity

*/

class Solution {
public:
    int findCelebrity(int n) 
    {
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(!knows(i,ans))
            {
                ans=i;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i==ans)
            {
                continue;
            }
            if(knows(ans,i) || !knows(i,ans))
            {
                return -1;
            }
        }
        return ans;
    }
};