#include<iostream>
#include<stack>
#include<vector>
class Solution
{
	public:
		bool IsPopOrder(vector<int> pushV,vector<int> popV)
		{
			stack<int> s;
			int j;
			for(int i=0;i<pushV.size();i++)
			{
				s.push(pushV[i]);
				while(!s.empty()&&s.top()==popV[j])
				{
					s.pop();
					j++;
				}
			}
			return s.empty();
		}
};
