class Solution {
public:
    
    // build the answer string array word by word
    
    // example, ["hit"] then ["hit","hot"] then ["hit","hot","dot"] .... ["hit","hot","dot","dog","cog"]
    
    // notice that once you get a answer of size x(i.e. string array of size x) then you can directly omit sizes>x(sizes greater than x) as only smallest sequences are needed
    
    // level means number of elements during that time (example level 1 will have 1 element, level 10 will have 10 elements in the answer string array)
    
    // mark the visited strings and remove it once that level is done
    
    // the reason is lets say "dog" is visited, if the smallest distance/minimum words to make "dog" to endWord is x, then in future if "dog" comes with more elements(i.e. in higher level) then it is going to again take x elements so we can remove it as the size will become greater
    
    // to find the words that satisfy condition, it can be done by changing one letter at a time and checking if this is present in wordList or not
    
    unordered_map<string,int> mp;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        vector<vector<string>> ans;
        for(int i=0;i<wordList.size();i++)
        {
            mp[wordList[i]]++;
        }
        queue<vector<string>> q;
        set<string> st;
        q.push({beginWord});
        int sz=INT_MAX;
        unordered_set wordlist(wordList.begin(),wordList.end());
        while(!q.empty())
        {
            int size=q.size();
            int flag=0;
            for(int n=0;n<size;n++)
            {
                vector<string> v=q.front();
                q.pop();
                string s=v[v.size()-1];
                if(s==endWord)
                {
                    ans.push_back(v);
                    flag=1;
                    continue;
                }
                vector<string> neighbours=solve(s);
                for(int i=0;i<neighbours.size();i++)
                {
                    string neighbour=neighbours[i];
                    if(find(v.begin(),v.end(),neighbour)==v.end())
                    {
                        vector<string> temp=v;
                        temp.push_back(neighbour);
                        st.insert(neighbour);
                        q.push(temp);
                    }
                }
            }
            for(auto it:st)
            {
                if(mp.count(it))
                {
                    mp.erase(it);
                }
            }
            if(flag)
            {
                break;
            }
        }
        return ans;
    }
    vector<string> solve(string& s)
    {
        vector<string> ans;
        for(int i=0;i<s.length();i++)
        {
            char c=s[i];
            for(char j='a';j<='z';j++)
            {
                s[i]=j;
                if(mp.count(s))
                {
                    ans.push_back(s);
                }
            }
            s[i]=c;
        }
        return ans;
    }
};