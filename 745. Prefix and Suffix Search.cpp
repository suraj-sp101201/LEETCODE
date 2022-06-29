// Lets convert this prefix and suffix string into one string in some way and search it. If found, then maximum index will be the answer

// So for finding it efficiently we can use TRIE

// if apple is the word. Then we can put apple{apple , pple{apple , ple{apple , le{apple , e{apple, {apple 

// the part of word that is before the '{' is suffix and after it is prefix

// so if this is Find["a", "e"], then lets convert this to "e{a" and search this, so it will see what all strings are there with starting 'e'. e{apple is there . So e is matched so go to next. Next is '{' , '{' is also matched so go for next. Next is 'a', 'a' is also matched. So now nothing is there to search, so see till here only and dont go further. See the maximum index here and return it.

class TrieNode
{
    public:
    TrieNode *children[27];
    int index;
    TrieNode()
    {
        for(int i=0;i<27;i++)
        {
            children[i]=NULL;
            index=-1;
        }
    }
};
class WordFilter {
public:
    TrieNode* root;
    void insert(string s, int idx)
    {
        TrieNode* cur=root;
        for(int i=0;i<s.length();i++)
        {
            int v=s[i]-'a';
            if(cur->children[v]==NULL)
            {
                cur->children[v]=new TrieNode();
            }
            cur=cur->children[v];
            cur->index=idx;
        }
    }
    int find(string s)
    {
        TrieNode* cur=root;
        for(int i=0;i<s.length();i++)
        {
            int v=s[i]-'a';
            if(cur->children[v]==NULL)
            {
                return -1;
            }
            cur=cur->children[v];
        }
        return cur->index;
    }
    WordFilter(vector<string>& words) 
    {
        root=new TrieNode();
        for(int i=0;i<words.size();i++)
        {
            string s="{"+words[i];
            insert(s,i);
            for(int j=0;j<s.length();j++)
            {
                string str=words[i].substr(j);
                insert(str+s,i);
            }
        }
    }
    
    int f(string pref, string suff) 
    {
        string s=suff+"{"+pref;
        return find(s);
    }
};