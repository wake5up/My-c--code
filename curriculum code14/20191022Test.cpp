#include <iostream>
using namespace std;

#if 0
// 非类型模板参数
// C++11: array

namespace bite
{
	template<class T, size_t N>
	class array
	{
	public:
		void push_back(const T& data)
		{
			// N = 10;
			_array[_size++] = data;
		}

		T& operator[](size_t index)
		{
			assert(index < _size);
			return _array[index];
		}

		bool empty()const
		{
			return 0 == _size;
		}

		size_t size()const
		{
			return _size;
		}
	private:
		T _array[N];
		size_t _size;
	};
}



int main()
{
	int a = 10;
	int b = 20;

	// 非类型模板参数必须在编译其确认其结果
	//bite::array<int, a+b> arr;
	bite::array<int, 10+20> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	return 0;
}
#endif

#if 0
template<class T>
T& Max(T& left, T& right)
{
	return left > right? left : right;
}

// 函数模板的特化
// template<>
// char*& Max<char*>(char*& left, char*& right)
// {
// 	if (strcmp(left, right) > 0)
// 		return left;
// 
// 	return right;
// }

// 函数模板一般不需要特化，直接将不能处理类型的具体函数给出
char* Max(char* left, char* right)
{
	if (strcmp(left, right) > 0)
		return left;

	return right;
}

class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator>(const Date& d)const
	{
		return _day > d._day;
	}

	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "/" << d._month << "/" << d._day;
		return _cout;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int a = 10;
	int b = 20;

	cout << Max(a, b) << endl;  //Max<int>
	cout << Max(b, a) << endl;

	Date d1(2019, 10, 22);
	Date d2(2019, 10, 23);

	cout << Max(d1, d2) << endl;
	cout << Max(d2, d1) << endl;

	char* p1 = "world";
	char* p2 = "hello";
	cout << Max(p1, p2) << endl;
	cout << Max(p2, p1) << endl;
	return 0;
}
#endif

#if 0
template<class T>
const T& Max(const T& left, const T& right)
{
	return left > right ? left : right;
}

template<>
const char*& Max<const char*&>(const char*& left, const char*& right)
{
	if (strcmp(left, right) > 0)
		return left;

	return right;
}


int main()
{
	int a = 10;
	int b = 20;

	Max(a, b);
	Max(10, 20);

	char* p1 = "world";
	char* p2 = "hello";
	cout << Max(p1, p2) << endl;
	cout << Max(p2, p1) << endl;
	return 0;
}
#endif

#if 0
template<class T>
void Test(const T& p) // const int*& p<---错误 int*& const p
{
	*p = 100;

	int b = 20;
	p = &b;
}

int main()
{
	int a = 10;
	int* pa = &a;

	const int b1 = 10;
	int const b2 = 20;

	Test(pa); // int*
	return 0;
}
#endif

#if 0
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};


// 全特化---对所有类型参数进行特化
template<>
class Data<int, int>
{
public:
	Data() 
	{
		cout << "Data<int, int>" << endl; 
	}
private:
	int _d1;
	int _d2;
};


int main()
{
	Data<int, double> d1;
	Data<int, int> d2;
	return 0;
}
#endif

#if 0
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};


// 偏特化：部分特化--->将模板参数列表中部分参数类型化
template<class T1>
class Data<T1, int>
{
public:
	Data() 
	{
		cout << "Data<T1, int>" << endl; 
	}

private:
	T1 _d1;
	int _d2;
};


int main()
{
	Data<int, double> d1;
	Data<int, int> d2;
	Data<double, int> d3;
	return 0;
}
#endif

#if 0
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

// 偏特化：让模板参数列表中的类型限制更加严格
template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data() 
	{ 
		cout << "Data<T1*, T2*>" << endl; 
	}
private:
	T1* _d1;
	T2* _d2;
};


int main()
{
	Data<int*, int> d1;
	Data<int, int*> d2;
	Data<int*, int*> d3;
	Data<int*, double*> d4;
	return 0;
}
#endif

class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* str = new char[strlen(s._str) + 1];
			strcpy(str, s._str);
			delete[] _str;
			_str = str;
		}
	}

	~String()
	{
		delete[] _str;
	}

private:
	char* _str;
};

// 写一个通用的拷贝函数，要求：效率尽可能高
template<class T>
void Copy(T* dst, T* src, size_t size)
{
	memcpy(dst, src, sizeof(T)*size);
}



void TestCopy()
{
	int array1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int array2[10];
	Copy(array2, array1, 10);

	String s1[3] = { "1111", "2222", "3333" };
	String s2[3];
	Copy(s2, s1, 3);
}

int main()
{
	TestCopy();
	return 0;
}