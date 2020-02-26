//平衡二叉树

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot==nullptr)
            return true;
        int result=0;
        return IsBalanced_Solution(pRoot,&result);
    }
    bool IsBalanced_Solution(TreeNode* pRoot,int* result)
    {
        if(pRoot==nullptr)
        {
            *result=0;
            return true;
        }
        int nleft,nright;
        if(IsBalanced_Solution(pRoot->left,&nleft)&&IsBalanced_Solution(pRoot->right,&nright))
        {
            int num=nleft-nright;
            if(num>=-1&&num<=1)
            {
                *result=1+(nleft>nright?nleft:nright);
                return true;
            }
        }
        return false;
    }
};