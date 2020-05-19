//判断是否为二叉搜索树

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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,LONG_MIN,LONG_MAX);
    }
    bool isValidBST(TreeNode* root,long long minNum,long long maxNum)
    {
        if(root==nullptr)
            return true;
        else if(root->val<=minNum||root->val>=maxNum)
            return false;
        return isValidBST(root->left,minNum,root->val)&&isValidBST(root->right,root->val,maxNum);
    }
};


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
    bool isValidBST(TreeNode* root) 
    {
        stack<TreeNode*> s;
        long long minNum=LONG_MIN;
        while(!s.empty()||root!=nullptr)
        {
            while(root)
            {
                s.push(root);               
                root=root->left; 
            }
            root=s.top();
            s.pop();
            if(root->val<=minNum)
                return false;
            minNum=root->val;
            root=root->right;
        }
        return true;
    }
};