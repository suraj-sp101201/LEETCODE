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

/*

first compute the height of the whole tree, if height is 0 then answer 0, if height is 1 then answer is 1, if height is 4 then in above 3 levels nodes are completely filled i.e. 2^3 -1 nodes will be there i.e. 7 .

So the problem is all about finding the number of nodes in the last level. We can binary search and find the answer. 

example if there can be 32 nodes in last level and we need to check whether 23th node is there or not. 

first lets find the mid point i.e. 16, 16<23 the node we need to search is on right side, so see from 17 to 32 so now mid is 24, 24>23 so it is on left and similarly goes on. 

*/

class Solution {
public:
    int exists(int val, TreeNode* root, int d)
    {
        int start=1;
        int end=pow(2,d-1);
        for(int i=1;i<d;i++)
        {
            int mid=(start+end)/2;
            if(mid<val)
            {
                root=root->right;
                start=mid+1;
            }
            else
            {
                root=root->left;
                end=mid;
            }
        }
        return root!=NULL;
    }
    int height(TreeNode* root)
    {
        if(root!=NULL)
        {
            return 1+height(root->left);
        }
        else
        {
            return 0;
        }
        return 0;
    }
    int countNodes(TreeNode* root) 
    {
        int h=height(root);
        if(h==0)
        {
            return 0;
        }
        if(h==1)
        {
            return 1;
        }
        int ans=(1<<h-1)-1;
        int d=h;
        int start=1;
        int end=pow(2,h-1);
        int temp=0;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(exists(mid,root,d))
            {
                temp=mid;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return ans+temp;
    }
};