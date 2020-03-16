//二叉搜索树的最低公共祖先
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;
        while(root)
        {
            if(root->val>p->val&&root->val>q->val)
            {
                root=root->left;
            }
            else if(root->val<p->val&&root->val<q->val)
            {
                root=root->right;
            }
            else
            {
                break;
            }
        }
        return root;
    }
};

//树中两节点的最低公共祖先
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||p==root||q==root)
            return root;
        TreeNode* l=lowestCommonAncestor(root->left,p,q);
        TreeNode* r=lowestCommonAncestor(root->right,p,q);
        if(!l&&!r)
            return nullptr;
        else if(!l&&r)
            return r;
        else if(l&&!r)
            return l;
        else
            return root;
    }
};