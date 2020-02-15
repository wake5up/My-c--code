//从上往下打印二叉树

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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> v;
        if(root==nullptr)
            return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* pNode=q.front();
            q.pop();
            v.push_back(pNode->val);
            if(pNode->left!=nullptr)
                q.push(pNode->left);
            if(pNode->right!=nullptr)
                q.push(pNode->right);
        }
        return v;
    }
};