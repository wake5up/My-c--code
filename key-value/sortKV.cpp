key-value结构：给定一个字符串，统计每个字符出现频率，先按value降序，再按key升序

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(pair<char, int> v1, pair<char, int> v2)
{
	if (v1.second == v2.second)
		return v1.first < v2.first;
	return v1.second>v2.second;
}

struct Cmp
{
	bool operator()(pair<char, int> v1, pair<char, int> v2)
	{
		if (v1.second == v2.second)
			return v1.first < v2.first;
		return v1.second>v2.second;
	}
};

int main()
{
	string s;
	while (cin >> s)
	{
		unordered_map<char, int> m;
		for (auto& e : s)
		{
			m[e]++;
		}
		vector<pair<char, int>> v;
		for (auto& e : m)
		{
			v.emplace_back(e.first, e.second);
		}
		/*第一种
		sort(v.begin(), v.end(), [](pair<char,int> v1, pair<char,int> v2){
		if (v1.second == v2.second)
		return v1.first < v2.first;
		return v1.second>v2.second;
		});
		*/

		/*第二种
		sort(v.begin(), v.end(), cmp);
		*/

		/*第三种
		sort(v.begin(), v.end(), Cmp());
		*/
	}
	return 0;
}