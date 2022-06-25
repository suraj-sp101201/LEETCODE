class Solution {
public:
    
    // remove all the optimised swaps like example, in ith index 'a' is present but 'd' is needed and in jth index 'd' is present and 'a' is needed, then this would take only 1 swap.
    
    // DO BFS. if s1[i]==s2[i] then dont do anything. if s1[i]!=s2[i] then see where can I put this s1[i]. I can put it in some jth index (i.e. in s2[j]) where s2[j]=s1[i]. Try all possible swaps and see the minimum. 
    
    // NOTE : I have done a lot of code in main function that does removing the optimised swaps. It is not neccessary but doing it will drastically reduce bfs time as the string size decreases, as string size decreases all possible swap combinations will reduce drastically, but you can also directly call just bfs for s1 and s2 also (i.e. remove everything in main function and just put "return bfs(s1,s2);" )
    
    unordered_set<string> getNeighbours(string s1, string s2)
    {
        unordered_set<string> ans;
        int i=0;
        for(;i<s1.length();i++)
        {
            if(s1[i]!=s2[i])
            {
                break;
            }
        }
        for(int j=i+1;j<s1.length();j++)
        {
            if(s1[i]==s2[j])
            {
                swap(s1[i],s1[j]);
                ans.insert(s1);
                swap(s1[i],s1[j]);
            }
        }
        return ans;
    }
    int bfs(string s1, string s2)
    {
        unordered_set<string> visited;
        queue<string> str;
        str.push(s1);
        int ans=0;
        while(!str.empty())
        {
            int size=str.size();
            for(int i=0;i<size;i++)
            {
                string s=str.front();
                str.pop();
                if(s==s2)
                {
                    return ans;
                }
                unordered_set<string> neighbours=getNeighbours(s,s2);
                for(auto it:neighbours)
                {
                    if(!visited.count(it))
                    {
                        str.push(it);
                        visited.insert(it);
                    }
                }
            }
            ans++;
        }
        return 0;
    }
    int kSimilarity(string s1, string s2) 
    {
        unordered_map<string,int> count;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]!=s2[i])
            {
                string s="";
                s+=s1[i];
                s+=s2[i];
                count[s]++;
            }
        }
        int ans=0;
        while(count.size())
        {
            int f=0;
            for(auto it1:count)
            {
                vector<string> toBeErased;
                for(auto it2:count)
                {
                    if(it1.first!=it2.first)
                    {
                        string s1=it1.first;
                        string s2=it2.first;
                        string s2Rev=s2;
                        reverse(s2Rev.begin(),s2Rev.end());
                        if(s1==s2Rev)
                        {
                            int mn=min(it1.second,it2.second);
                            ans+=mn;
                            count[s1]-=mn;
                            count[s2]-=mn;
                            if(count[s2]==0)
                            {
                                toBeErased.push_back(s2);
                            }
                            if(count[s1]==0)
                            {
                                toBeErased.push_back(s1);
                                break;
                            }
                        }
                    }
                }
                for(int i=0;i<toBeErased.size();i++)
                {
                    count.erase(toBeErased[i]);
                }
                if(toBeErased.size())
                {
                    f=1;
                    break;
                }
            }
            if(!f)
            {
                break;
            }
        }
        if(count.size()==0)
        {
            return ans;
        }
        s1="";
        s2="";
        for(auto it:count)
        {
            int cnt=it.second;
            while(cnt--)
            {
                s1+=it.first[0];
                s2+=it.first[1];
            }
            
        }
        return ans+bfs(s1,s2);
    }
};