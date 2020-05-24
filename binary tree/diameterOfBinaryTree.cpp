//二叉树的直径

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
    int diameterOfBinaryTree(TreeNode* root) {
        int max_num=0;
        Depth(root,max_num);
        return max_num;
    }
    int Depth(TreeNode* root,int& max_num)
    {
        if(root==nullptr)
            return 0;
        int left=Depth(root->left,max_num);
        int right=Depth(root->right,max_num);
        max_num=max(max_num,left+right);
        return max(left,right)+1;
    }
};