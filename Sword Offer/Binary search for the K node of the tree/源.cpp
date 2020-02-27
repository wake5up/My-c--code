//二叉树的第k个节点

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    int count=0;
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==nullptr||k==0)
            return nullptr;
        TreeNode* pCur=nullptr;
        if(pRoot->left!=nullptr)
            pCur=KthNode(pRoot->left,k);
        if(pCur==nullptr)
        {
            count++;
            if(k==count)
                pCur=pRoot;
        }
        if(pCur==nullptr&&pRoot->right!=nullptr)
            pCur=KthNode(pRoot->right,k);
        return pCur;
    }
};