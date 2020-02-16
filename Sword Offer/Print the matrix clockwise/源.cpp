//À≥ ±’Î¥Ú”°æÿ’Û
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ret;
        int row=matrix.size();
        int col=matrix[0].size();
        if(row<=0||col<=0)
            return ret;
        int start=0;
        while(row>start*2&&col>start*2)
        {
            for(int i=start;i<=col-1-start;i++)
            {
                ret.push_back(matrix[start][i]);
            }
            if(start<row-1-start)
            {
                for(int i=start+1;i<=row-1-start;i++)
                {
                    ret.push_back(matrix[i][col-1-start]);
                }
            }
            if(start<row-1-start&&start<col-1-start)
            {
                for(int i=col-2-start;i>=start;i--)
                {
                    ret.push_back(matrix[row-1-start][i]);
                }
            }
            if(start<row-2-start&&start<col-1-start)
            {
                for(int i=row-2-start;i>=start+1;i--)
                {
                    ret.push_back(matrix[i][start]);
                }
            }
            start++;
        }
        return ret;
    }
};