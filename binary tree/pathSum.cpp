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
    vector<int> v;
    vector<vector<int>> ret;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==nullptr)
            return {};
        path(root,sum);
        return ret;
    }
    void path(TreeNode* root,int sum)
    {
        v.push_back(root->val);
        if(root->left==nullptr&&root->right==nullptr&&sum==root->val)
        {
            ret.push_back(v);
        }
        if(root->left!=nullptr)
            path(root->left,sum-root->val);
        if(root->right!=nullptr)
            path(root->right,sum-root->val);
        v.pop_back();
    }
};