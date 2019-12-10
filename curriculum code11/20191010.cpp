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

#include <assert.h>

namespace ht
{
	template<class T>
	class vector
	{
	public:
		// vector的迭代器实际就是原生态指针
		typedef T* iterator;

	public:
		/////////////////////////////////////
		// 构造与销毁
		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		vector(int n, const T& data)
			: _start(new T[n])
		{
			for (size_t i = 0; i < n; ++i)
				_start[i] = data;

			_finish = _start + n;
			_endofstorage = _finish;
		}

		// [first, last)
		template<class Iterator>
		vector(Iterator fisrt, Iterator last)
		{
			// 计算[first, last)区间中元素的个数
			size_t n = 0;
			auto it = fisrt;
			while (it != last)
			{
				++it;
				++n;
			}

			_start = new T[n];

			// 将[first, last)区间中的元素放置到_start的空间中
			for (size_t i = 0; i < n; ++i)
				_start[i] = *fisrt++;

			_finish = _start + n;
			_endofstorage = _start + n;
		}

		vector(const vector<T>& v);
		vector<T>& operator=(const vector<T>& v);

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

		/////////////////////////////////////
		// 迭代器
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		/////////////////////////////////////
		// 容量操作
		size_t size()const
		{
			return _finish - _start;
		}

		size_t capacity()const
		{
			return _endofstorage - _start;
		}

		bool empty()const
		{
			return _start == _finish;
		}

		// T():
		// 如果T代表内置类型，T()--->0
		// 如果T代表自定义类型，T()---> 调用该类的无参构造函数
		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (newsize > oldsize)
			{
				size_t cap = capacity();
				if (newsize > cap)
					reserve(newsize);

				for (; oldsize < newsize; ++oldsize)
					_start[oldsize] = data;//*_finish++ = data;
				
			}

			_finish = _start + newsize;
		}


		void reserve(size_t newCapacity)
		{
			size_t oldCapcity = capacity();
			if (newCapacity > oldCapcity)
			{
				// 1. 申请新空间
				T* temp = new T[newCapacity];

				// 2. 拷贝元素
				//memcpy(temp, _start, size()*sizeof(T));
				// 如果_start指向的空间存在
				size_t n = size();
				if (_start)
				{
					for (size_t i = 0; i < n; ++i)
					{
						temp[i] = _start[i];
					}

					// 3. 释放旧空间
					delete[] _start;
				}
				
				_start = temp;
				_finish = _start + n;
				_endofstorage = _start + newCapacity;
			}
		}

		///////////////////////////////////////////////
		// access
		// v[0] = 10; v如果是普通类型的
		T& operator[](size_t index)
		{
			assert(index < size());
			return _start[index];
		}

		const T& operator[](size_t index)const
		{
			assert(index < size());
			return _start[index];
		}

		T& front()
		{
			return *_start;
		}

		const T& front()const
		{
			return *_start;
		}

		T& back()
		{
			return *(_finish-1);
		}

		const T& back()const
		{
			return *(_finish-1);
		}

		////////////////////////////////
		// 修改
		// 时间复杂度：O(1)
		void push_back(const T& data)
		{
			// 检测是否需要扩容
			if (_finish == _endofstorage)
			{
				reserve(capacity() * 2 + 3);
			}

			*_finish++ = data;
		}

		void pop_back()
		{
			--_finish;
		}

		// 返回值含义：返回新插入元素的位置
		iterator insert(iterator pos, const T& data)
		{
			// 检测是否需要扩容
			if (_finish == _endofstorage)
				reserve(capacity() * 2);

			// 将[pos, finish)之间所有元素整体向后搬移一个位置
			auto it = _finish;
			while (it > pos)
			{
				*it = *(it - 1);
				it--;
			}

			// 插入新元素
			*pos = data;
			++_finish;
			return pos;
		}

		iterator erase(iterator pos)
		{
			if (pos == end())
				return pos;

			// it代表待搬移元素的位置
			auto it = pos + 1;
			while (it != _finish)
			{
				*(it-1) = *it;
				++it;
			}

			--_finish;
			return pos;
		}

		void clear()
		{
			_finish = _start;
		}
	private:
		T* _start;
		T* _finish;
		T* _endofstorage;
	};
}


void TestVector()
{
	ht::vector<int> v1;
	ht::vector<int> v2(10, 5);

	int array[] = { 1, 2, 3, 4, 5 };
	ht::vector<int> v3(array, array+sizeof(array)/sizeof(array[0]));

	cout << v2.size() << endl;
	cout << v2.capacity() << endl;
	cout << v3.front() << endl;
	cout << v3.back() << endl;

	for (size_t i = 0; i < v3.size(); ++i)
		cout << v3[i] << " ";
	cout << endl;

	//ht::vector<int>::iterator it = v3.begin();
	auto it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto& e : v3)
		e *= 2;

	for (auto e : v3)
		cout << e << " ";
	cout << endl;
}


void TestVector2()
{
	ht::vector<int> v;
	v.push_back(1);  // 3
	v.push_back(2);
	v.push_back(3);
	v.push_back(4); // 9
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	cout << v.back() << endl;

	v.pop_back();
	cout << v.back() << endl;
	cout << v.size() << endl;

	cout << v.front() << endl;
	v.insert(v.begin(), 0);
	cout << v.front() << endl;
	cout << v.size() << endl;
}

#include <vector>

void TestVector3()
{
	vector<int> vv;
	ht::vector<int> v(10, 5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(8);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(20, 5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}

int main()
{
	//TestVector();
	//TestVector2();
	TestVector3();
	return 0;
}