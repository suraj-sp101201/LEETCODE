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
    
    // 0 means no need of camera here
    
    // 2 means there is no camera here and this has to be monitored / camera needed
    
    // 1 means camera is there
    
    // It is better to place a camera in such a way that this camera goes to child and parent i.e. placing in mid
    
    // a left node or right node that has a camera or leaf node will not need a camera. because leaf doesnt need at all. If left or right has camera then parent will get camera so no need camera
    
    // if left or right has no camera / camera needed then we have to place a camera here, so it will go to childrens and parent
    
    // if there is no need to place a camera here then there will be no camera above
    
    int ans;
    int dfs(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        int left=dfs(root->left);
        int right=dfs(root->right);
        if(left==2 || right==2)
        {
            ans++;
            return 1;
        }
        else if(left==1 || right==1)
        {
            return 0;
        }
        else
        {
            return 2;
        }
    }
    int minCameraCover(TreeNode* root) 
    {
        ans=0;
        if(dfs(root)==2)
        {
            ans++;
        }
        return ans;
    }
};