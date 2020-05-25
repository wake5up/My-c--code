//二叉树的坡度

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
    int left=0,right=0;
    int findTilt(TreeNode* root) {
        if(!root)
            return 0;
        int num=0;
        findTilt(root,num);
        return num;
    }
    int findTilt(TreeNode* root,int& num)
    {
        if(root==nullptr)
            return 0;
        int left=findTilt(root->left,num);
        int right=findTilt(root->right,num);
        num+=abs(left-right);
        return left+right+root->val;
    }
};