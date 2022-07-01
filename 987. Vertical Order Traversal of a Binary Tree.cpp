/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    
    // store the nodes as (x,y) where x denotes row and y denotes column. both x and y can be any integer (-ve or +ve)
    
    // if current node has x as the value then its immediate children will have x+1 as x is the row number. But if current node has y as the value then the node at its left will have y-1 and at right will have y+1 as y is the column number
    
    // store the all the same y's (i.e. columns) in a hashmap with x and node value . Like if a node value is 9 and it is in 2nd row then store it like {2,9} and so on .... values that has y as columns i.e. all column number should be store in a single component, like  all columns with 0 should be stored in a same place
    
    // once stored, just sort it and put the values into the answer.  we have stored in this way : {row number, node value}. So that first row values come at first and if two values are in same row then the values coming in increasing order.
    
    map<int,vector<pair<int,int>>> points;
    void dfs(TreeNode* root, int x, int y)
    {
        if(root)
        {
            points[y].push_back({x,root->val});
            dfs(root->left,x+1,y-1);
            dfs(root->right,x+1,y+1);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        dfs(root,0,0);
        vector<vector<int>> ans;
        for(auto it:points)
        {
            vector<pair<int,int>> v=it.second;
            sort(v.begin(),v.end());
            vector<int> values;
            for(int i=0;i<v.size();i++)
            {
                values.push_back(v[i].second);
            }
            ans.push_back(values);
        }
        return ans;
    }
};