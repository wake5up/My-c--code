
//树的子结构

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
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool flag = false;
		if (pRoot1 != nullptr&&pRoot2 != nullptr)
		{
			if (Equal(pRoot1->val, pRoot2->val))
				flag = DelTree(pRoot1, pRoot2);
			if (!flag)
				flag = HasSubtree(pRoot1->left, pRoot2);
			if (!flag)
				flag = HasSubtree(pRoot1->right, pRoot2);
		}
		return flag;
	}
	bool DelTree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot2 == nullptr)
			return true;
		if (pRoot1 == nullptr)
			return false;
		if (!Equal(pRoot1->val, pRoot2->val))
			return false;
		return DelTree(pRoot1->left, pRoot2->left) && DelTree(pRoot1->right, pRoot2->right);
	}
	bool Equal(double num1, double num2)
	{
		if (num1 - num2<0.0000001&&num1 - num2>-0.0000001)
			return true;
		return false;
	}
};