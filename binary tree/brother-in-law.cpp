//二叉树堂兄弟节点

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
    TreeNode* curx;
    TreeNode* cury;
    int depthx=0,depthy=0;
    void dfs(TreeNode* root,int x,int y,int depth)
    {
        if(depthx!=0&&depthy!=0)
            return;
        if(root->left)
        {
            if(root->left->val==x)
            {
                depthx=depth+1;
                curx=root;
            }
            if(root->left->val==y)
            {
                depthy=depth+1;
                cury=root;
            }
            dfs(root->left,x,y,depth+1);
        }
        if(root->right)
        {
            if(root->right->val==x)
            {
                depthx=depth+1;
                curx=root;
            }
            if(root->right->val==y)
            {
                depthy=depth+1;
                cury=root;
            }
            dfs(root->right,x,y,depth+1);
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int depth=0;
        dfs(root,x,y,depth);
        if(depthx==depthy&&curx!=cury)
            return true;
        return false;
    }
};