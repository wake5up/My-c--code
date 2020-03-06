//二叉树的深度

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
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==nullptr)
            return 0;
        int nleft=TreeDepth(pRoot->left);
        int nright=TreeDepth(pRoot->right);
        int num=nleft>nright?nleft+1:nright+1;
        return num;
    }
};