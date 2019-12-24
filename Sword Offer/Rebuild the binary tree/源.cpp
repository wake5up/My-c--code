/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		int inlen = vin.size();
		if (inlen <= 0)
			return NULL;
		vector<int> left_pre, right_pre, left_vin, right_vin;
		TreeNode *phead = new TreeNode(pre[0]);
		int gen = 0;
		for (int i = 0; i<inlen; i++)
		{
			if (pre[0] == vin[i])
			{
				gen = i;
				break;
			}
		}
		for (int i = 0; i<gen; i++)
		{
			left_pre.push_back(pre[i + 1]);
			left_vin.push_back(vin[i]);
		}
		for (int i = gen + 1; i<inlen; i++)
		{
			right_pre.push_back(pre[i]);
			right_vin.push_back(vin[i]);
		}
		phead->left = reConstructBinaryTree(left_pre, left_vin);
		phead->right = reConstructBinaryTree(right_pre, right_vin);
		return phead;
	}
};