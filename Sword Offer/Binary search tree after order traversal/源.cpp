//二叉搜索树后序遍历

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        return VerifySquenceOfBST(sequence,0,sequence.size()-1);
    }
    bool VerifySquenceOfBST(vector<int> sequence,int begin,int end){
        if(sequence.empty()||begin>end)
            return false;
        int root=sequence[end];
        int i=begin;
        for(;i<end;i++)
        {
            if(sequence[i]>root)
                break;
        }
        for(int j=i;j<end;j++)
        {
            if(sequence[j]<root)
                return false;
        }
        bool left=true;
        if(i>begin)
            left=VerifySquenceOfBST(sequence,begin,i-1);
        bool right=true;
        if(i<end-1)
            right=VerifySquenceOfBST(sequence,i,end-1);
        return left&&right;
    }
};