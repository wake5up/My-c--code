//修剪二叉搜索树

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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root==nullptr)
            return nullptr;
        TreeNode* new_root=root;
        if(root->val<L)
            new_root=trimBST(root->right,L,R);
        else if(root->val>R)
            new_root=trimBST(root->left,L,R);
        else
        {
            new_root->left=trimBST(root->left,L,R);
            new_root->right=trimBST(root->right,L,R);
        }
        return new_root;
    }
};