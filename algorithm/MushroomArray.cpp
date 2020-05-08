//蘑菇阵（矩阵概率问题）

#include<stdio.h>
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
 
int main(){
    int n, m, k;
    while(cin>>n>>m>>k)
    {
        vector<vector<int>> table((n+1), vector<int>(m+1));
        vector<vector<double>> P((n+1), vector<double>(m+1));
        int x, y;
        for(int i = 0; i < k; i++)
        {
            cin>>x>>y;
            table[x][y] = 1;
        }
        P[1][1] = 1.0;      //起点概率为1
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(!(i == 1 && j ==1))
                {      //跳过起点
                    if(table[i][j] == 1) 
                    {
                        P[i][j] = 0;//如果该点有蘑菇，概率置为0
                        continue;
                    }
                    //边界的时候，概率为1
                    //第一行，第一列为0，第二行，第二列刚好计算正确
                    P[i][j] = P[i-1][j]*(j == m? 1 : 0.5) + P[i][j-1]*(i == n?1:0.5);
                }
            }
        }
        printf("%.2lf\n", P[n][m]);
    }
}