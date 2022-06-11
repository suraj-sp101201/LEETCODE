class Codec {
public:
    
    // root = [1,2,3,null,null,4,5]. We can convert this to a string like this "1,2,NULL,NULL,3,4,NULL,NULL,5,NULL,NULL,"
    
    // And recieve it and one element by element. Like take 1, fix as root then 1's left is the next element after a comma. Go to 2. Then go next element so left is NULL and go next element right is NULL so it will be like this
    
    /*
    
                2
               / \
            NULL  NULL 
            
        so this above will be returned and will be made as left to 1.
            
                1
               / 
              2
             / \
          NULL  NULL 
          
          AND SIMILARLY SAME PROCESS TO RIGHT
          
    */
    
    string serialize(TreeNode* root) 
    {
        if(!root)
        {
            return "NULL,";
        }
        return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
    }

    TreeNode* deserialize(string data) 
    {
        queue<string> q;
        string s="";
        for(int i=0;i<data.length();i++)
        {
            if(data[i]==',')
            {
                q.push(s);
                s="";
                continue;
            }
            s+=data[i];
        }
        return solve(q);
    }
    TreeNode* solve(queue<string>& q)
    {
        string s=q.front();
        q.pop();
        if(s=="NULL")
        {
            return NULL;
        }
        int val=stoi(s);
        TreeNode* root = new TreeNode(val);
        root->left = solve(q);
        root->right = solve(q);
        return root;
    }
};
