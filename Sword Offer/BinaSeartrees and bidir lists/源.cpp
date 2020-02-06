//二叉搜索树与双向链表

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* pList=nullptr;
        Convert(pRootOfTree,pList);
        return pList;
    }
    void Convert(TreeNode* pRootOfTree,TreeNode*& pList)
    {
        if(pRootOfTree==nullptr)
            return;
        if(pRootOfTree->right!=nullptr)
            Convert(pRootOfTree->right,pList);
        pRootOfTree->right=pList;
        if (pList != nullptr)
            pList->left = pRootOfTree;
        pList = pRootOfTree;
        if (pRootOfTree->left != nullptr)
            Convert(pRootOfTree->left, pList);
    }
};