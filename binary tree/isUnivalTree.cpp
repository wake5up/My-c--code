//单值二叉树

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
    bool isUnivalTree(TreeNode* root) {
        return isUnivalTree(root,root->val);
    }
    bool isUnivalTree(TreeNode* root,int num)
    {
        if(root==nullptr)
            return true;
        bool lflag=isUnivalTree(root->left,num);
        if(root->val!=num)
            return false;
        bool rflag=isUnivalTree(root->right,num);
        return lflag&&rflag;
    }
};