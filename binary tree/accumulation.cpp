//把二叉搜索树转换为累加树

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
    TreeNode* convertBST(TreeNode* root) {
        if(root==nullptr)
            return nullptr;
        int num=0;
        convertBST(root,num);
        return root;
    }
    void convertBST(TreeNode* root,int& num)
    {
        if(root==nullptr)
            return;
        convertBST(root->right,num);
        num+=root->val;
        root->val=num;
        convertBST(root->left,num);
    }
};