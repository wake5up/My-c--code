#include <iostream>
using namespace std;

#if 0
// vector底层结构：动态类型的顺序表
// vector<char>  string
#include <vector>

void TestVector1()
{
	vector<int> v1;
	vector<int> v2(10, 5);
	vector<int> v3(v2);

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> v4(array, array + sizeof(array) / sizeof(array[0]));

	vector<int> v5{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	for (size_t i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;

	for (auto e : v3)
		cout << e << " ";
	cout << endl;

	//vector<int>::iterator it = v4.begin();
	auto it1 = v4.begin();
	while (it1 != v4.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;


	auto it2 = v5.rbegin();
	while (it2 != v5.rend())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;
}

void TestVector2()
{
	vector<int> v5{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << v5.size() << endl;
	cout << v5.capacity() << endl;
	cout << v5.front() << endl;
	cout << v5.back() << endl;

	v5.push_back(1);
	v5.push_back(2);
	v5.push_back(3);
	cout << v5.size() << endl;
	cout << v5.capacity() << endl;
	cout << v5.front() << endl;
	cout << v5.back() << endl;

	v5.erase(v5.begin());
	v5.erase(v5.end()-1);

	auto pos = find(v5.begin(), v5.end(), 5);
	if (pos != v5.end())
		v5.erase(pos);

	v5.clear();
}

void TestVector3()
{
	vector<vector<int>> vv;
	// 10 * 10---> 6
	vv.resize(10); // 设置总的行数

	// 给每行设置元素
	for (size_t i = 0; i < 10; ++i)
	{
		vv[i].resize(10, 6);
	}
}

int main()
{
	//TestVector1();
	//TestVector2();
	TestVector3();
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
int main()
{
	size_t sz;
	std::vector<int> foo;
	foo.reserve(100);
	foo[0] = 10;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i) 
	{
		foo.push_back(i);//SeqList 扩容方式：开辟新空间  拷贝元素 释放旧空间
		if (sz != foo.capacity()) 
		{
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	return 0;
}
#endif

#if 0
#include <vector>

int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	//v.reserve(20);
	for (size_t i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	// 迭代器：类似是指针的一种类型，可以将迭代器定义的对象当成是指针的方式进行应用
	// 作用：帮助用户透明的(用户可以不用知道该容器的底层数据结构)遍历容器中的元素
	//v.assign(20, 8);
	//vector<int>::iterator it = v.begin();
	auto it = v.begin();

	v.push_back(1);  // 可能会导致迭代器it失效

	// 解决方式：给it迭代器重新赋值
	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	return 0;
}
#endif

#if 0
// 将vector中所有元素清除掉
#include <vector>

int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	// v.resize(0);

	//v.clear();
	//v.erase(v.begin(), v.end());

	auto it = v.begin();
	while (it != v.end())
	{
		it = v.erase(it);
		//++it;
	}

	cout << v.size() << endl;
	return 0;
}
#endif

#if 0
// 引用会不会失效
#include <vector>
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int& ra = v[0];
	ra = 10;

	v.push_back(1);
	ra = 100;
	return 0;
}
#endif

int main()
{
	return 0;
}