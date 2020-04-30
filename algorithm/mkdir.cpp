//合成mkdir -p语句

#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		deque<string> d;
		while (n--)
		{
			string s;
			cin >> s;
			d.push_back(s);
		}
		sort(d.begin(), d.end());
		int i = 0;
		for (i = 0; i<d.size()-1;)
		{
			if (d[i].size()<=d[i+1].size()&&d[i+1].substr(0,d[i].size())==d[i]&&d[i+1][d[i].size()]=='/')
			{
                d.erase(d.begin() + i);
			}
			else
            {
                cout << "mkdir -p " << d[i] << endl;
				i++;
            }
		}
		cout << "mkdir -p " << d[i] << endl;
		cout << endl;
	}
	return 0;
}