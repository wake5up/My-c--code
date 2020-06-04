//假定一种编码的编码范围是a ~ y的25个字母，从1位到4位的编码，如果我们把该编码按字典序排序
//形成一个数组如下： a, aa, aaa, aaaa, aaab, aaac, … …, b, ba, baa, baaa, baab, baac … …, yyyw, yyyx, yyyy 其中a的Index为0
//aa的Index为1，aaa的Index为2，以此类推。 编写一个函数，输入是任意一个编码，输出这个编码对应的Index.

#include <string>
#include <iostream>
using namespace std;

int main()
{
    string str;
    while(cin>>str)
    {
        int temp=0;
        int num=0;
        for(int i=0;i<str.size();i++)
        {
            temp=temp*25+(str[i]-'a');
            if(i<(str.size()-1))
                num+=temp+1;
            else
                num+=temp;
        }
        for(int i=str.size();i<4;i++)
        {
            temp=temp*25;
            num+=temp;
        }
        cout<<num<<endl;
    }
    return 0;
}