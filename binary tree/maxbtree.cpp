//最大二叉树

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums,0,nums.size()-1);
    }
    TreeNode* dfs(vector<int>& nums,int l,int r)
    {
        if(l>r)
            return nullptr;
        int index=l;
        for(int i=l+1;i<=r;i++)
        {
            if(nums[i]>nums[index])
            {
                index=i;
            }
        }
        TreeNode* root=new TreeNode(nums[index]);
        root->left=dfs(nums,l,index-1);
        root->right=dfs(nums,index+1,r);
        return root;
    }
};