//二叉树寻路（之字形）

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int k=int(log(label)/log(2))+1;
        vector<int> ans(k);
        while(k)
        {
            ans[k-1]=label;
            int low=pow(2,k-1),high=pow(2,k)-1;
            int parent=((low+high)-label)/2;
            label=parent;
            k--;
        }
        return ans;
    }

};