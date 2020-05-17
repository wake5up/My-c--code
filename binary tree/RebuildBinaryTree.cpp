// 重建二叉树

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()||inorder.empty())
            return nullptr;
        int len=preorder.size();
        vector<int> left_pre, right_pre,left_in,right_in;
        TreeNode* root=new TreeNode(preorder[0]);
        int gen=0;
        for(int i=0;i<len;i++)
        {
            if(inorder[i]==preorder[0])
            {
                gen=i;
                break;
            }
        }
        for(int i=0;i<gen;i++)
        {
            left_pre.push_back(preorder[i+1]);
            left_in.push_back(inorder[i]);
        }
        for(int i=gen+1;i<len;i++)
        {
            right_pre.push_back(preorder[i]);
            right_in.push_back(inorder[i]);
        }
        root->left=buildTree(left_pre,left_in);
        root->right=buildTree(right_pre,right_in);
        return root;
    }
};