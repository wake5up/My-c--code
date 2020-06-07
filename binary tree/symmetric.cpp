//对称二叉树

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
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
            return true;
        return isSymmetric(root,root);
    }
    bool isSymmetric(TreeNode* lroot,TreeNode* rroot)
    {
        if(lroot==nullptr&&rroot==nullptr)
            return true;
        else if(lroot==nullptr||rroot==nullptr)
            return false;
        if(lroot->val!=rroot->val)
            return false;
        return isSymmetric(lroot->left,rroot->right)&&isSymmetric(lroot->right,rroot->left);
    }
};