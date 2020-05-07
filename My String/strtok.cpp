//strtok函数

#include <iostream>
#include <string>
#include <cstring> 
#include <vector>
using namespace std;
int main()
{
    string s="1a2c3,.45,.  6 7?8&9";
    char* ss=new char[s.size()+1];
    strcpy(ss,s.c_str());
    char* str=strtok(ss,",. &?abc");
    vector<string> v;
    while(str!=NULL)
    {
    	v.push_back(str);
    	str=strtok(NULL,",. ?&abc");
	}
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<endl;
	}
    return 0;
}