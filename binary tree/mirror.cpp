//二叉树的镜像

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
    TreeNode* temp=nullptr;
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==nullptr)
            return root;
        temp=root->left;
        root->left=root->right;
        root->right=temp;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};