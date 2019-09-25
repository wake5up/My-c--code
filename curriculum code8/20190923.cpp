#include <iostream>
using namespace std;


#if 0
#include <string>

void TestString1()
{
	string s1;
	string s2("hello");
	string s3(10, '$');
	string s4(s3);

	cin >> s1;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}

// 容量相关方式
void TestString2()
{
	string s("hello");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	
	if (s.empty())
		cout << "NULL string" << endl;
	else
		cout << "Not NULL string" << endl;

	// 只清空string类中有效字符个数，不会改变底层空间的总大小
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	if (s.empty())
		cout << "NULL string" << endl;
	else
		cout << "Not NULL string" << endl;
}

// resize / reserve
// void resize(size_t n, char ch): 
//   功能--将string类中的有效字符改变到n个，多的字符采用ch进行填充
// 注意： 1. 如果是将string类中的有效元素缩小，只改变有效元素个数，不会改变底层空间大小
//       2. 如果是将string类中的有效元素增多，可能需要扩容
void TestString3()
{
	string s("hello");
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(10, '!');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;


	s.resize(20, '8');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(6);
	cout << s << endl;

	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

// void reserve(size_t newcapacity): 扩容
// newcapacity > oldcapacity(string类旧空间大小)：空间增多--->容量改变(最终容量大小 >= newCapacity)，有效元素个数不变
// newcapacity < oldcapacity(string类旧空间大小)：空间缩小，该函数直接返回 除非newcapacity < 15
// 注意：只改变容量大小，不会改变有效元素个数
void TestString4()
{
	string s(20, '$');
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(20);
	cout << s.size() << endl;
	cout << s.capacity() << endl;


	s.reserve(40);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(24);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}


void TestString5()
{
	string s("hello");
	cout << s[0] << endl;
	s[0] = 'H';
	// 如果越界---assert触发
	//cout << s[10] << endl;

	cout << s.at(2) << endl;
	s.at(2) = 'L';

	// 如果越界---抛出out_of_range异常
	//cout << s.at(10) << endl;
}

void TestString6()
{
	string s1;
	s1.push_back('I');

	s1 += " Love ";

	string s2("you");
	s1 += s2;

	s1.append(1, ',');
	s1.append("祖国");
	s1.append(3, '!');
}

// 1. string类的扩容机制---vs--PJ  1.5倍
//                      linux--SGI 2倍
// 2. 如果提前知道大概要往string类存放多少个元素，可以提前通过reserve将空间提供好
void TestPushBack()
{
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

void TestString7()
{
	string s("12345");
	int ret = atoi(s.c_str());
}

// find  rfind
void TestString8()
{
	string s("hello world");
	size_t pos = s.find(' ');
	if (pos != string::npos)
	{
		cout << ' ' << " is in s" << pos<<endl;
	}

	pos = s.find("world");
	if (pos != string::npos)
	{
		cout << "world" << " is in s" << pos << endl;
	}

	// 获取文件的后缀 - 20190923.cpp.cpp
	string ss("20190923.cpp.cpp");
	pos = ss.rfind('.') + 1;

	string filepox = ss.substr(pos);
	cout << filepox << endl;
}

void TestString9()
{
	string s("hello");

	for (auto e : s)
		cout << e;
	cout << endl;

	for (size_t i = 0; i < s.size(); ++i)
		cout << s[i];
	cout << endl;

	// char*
	// C++98
	//string::iterator it = s.begin();

	// C++11
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
}

void reversestring(string& s)
{
// 	char* begin = (char*)s.c_str();
// 	char* end = begin + s.size() - 1;
// 	while (begin < end)
// 	{
// 		swap(*begin, *end);
// 		begin++;
// 		end--;
// 	}

	reverse(s.begin(), s.end());
}



int main()
{


	string s;
	getline(cin, s);
	cout << s << endl;
	//TestString1();
	//TestString2();
	//TestString3();
	//TestString4();

	//TestString5();
	//TestString6();
	//TestString7();
	//TestString8();
	//TestString9();
	//TestPushBack();

// 	string s("hello");
// 	cout << s << endl;
// 	reversestring(s);
// 	cout << s << endl;
	return 0;
}
#endif

#if 0
// 借助string来解决浅拷贝问题
// string类动态管理字符串
namespace bite
{
	// 反例
	class string
	{
	public:
		string(char* str = "")
		{
			if (nullptr == str)
				str = "";

			// 申请空间
			_str = new char[strlen(str)+1];

			// 存放str中的字符
			strcpy(_str, str);
		}

		// 将s对象中内容原封不动的拷贝到新对象中
		// 值得拷贝---比特位的拷贝
		string(const string& s)
			: _str(s._str)
		{}

		// 编译器生成的默认拷贝构造函数--浅拷贝 & 资源泄漏
		string& operator=(const string& s)
		{
			_str = s._str;
			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
}

void TestString()
{
	bite::string s1("hello");
	bite::string s2(nullptr);
	// bite::string s3(s1);  // 默认的拷贝构造是浅拷贝
	
	// 调用编译器提供的默认赋值运算符重载
	s2 = s1;
}

int main()
{
	TestString();
	return 0;
}
#endif

#if 0
namespace bite
{
	// 深拷贝--传统版
	class string
	{
	public:
		string(char* str = "")
		{
			if (nullptr == str)
				str = "";

			// 申请空间
			_str = new char[strlen(str) + 1];

			// 存放str中的字符
			strcpy(_str, str);
		}

		string(const string& s)
			: _str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
		}

		// s2 = s1;
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* temp = new char[strlen(s._str) + 1];
				strcpy(temp, s._str);
				delete[] _str;
				_str = temp;
			}

			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
}
#endif

#if 0
namespace bite
{
	// 深拷贝--简介版
	class string
	{
	public:
		string(char* str = "")
		{
			if (nullptr == str)
				str = "";

			// 申请空间
			_str = new char[strlen(str) + 1];

			// 存放str中的字符
			strcpy(_str, str);
		}

		// vs2013: _str指针的默认值给的是nullptr
		// 其他编译器：_str指针的默认值给的可能是随机值
		string(const string& s)
			: _str(nullptr)
		{
			string strTemp(s._str);
			swap(_str, strTemp._str);
		}

		// s2 = s1;
#if 0
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string strTemp(s);
				swap(_str, strTemp._str);
			}
			return *this;
		}
#endif
		string& operator=(string s)
		{
			swap(_str, s._str);
			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
}

void TestString()
{
	bite::string s1("hello");
	bite::string s2(s1);
	//bite::string s3;

	//s3 = s1;
}

int main()
{
	TestString();
	return 0;
}
#endif


#if 0
// 解决浅拷贝：浅拷贝 + 引用计数
// 在类中增加int类的成员变量-----不行
// 普通的整形成员变量，每个对象中都有一份，一个对象在修改该计数时候，不会影响其他对象
// 导致：资源没有释放
namespace bite
{
	class string
	{
	public:
		string(char* str = "")
		{
			if (nullptr == str)
				str = "";

			// 申请空间
			_str = new char[strlen(str) + 1];
			_count = 1;
			// 存放str中的字符
			strcpy(_str, str);
		}

		string(string& s)
			: _str(s._str)
			, _count(++s._count)
		{}

		// s2 = s1;
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				// ...
			}

			return *this;
		}

		~string()
		{
			if (_str && 0 == --_count)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
		int _count;
	};
}
#endif

#if 0
// 将计数给成静态类型的成员变量---->不行
// 原因：静态类型成员变量是所有对象共享
//      计数应该与资源个数保持一致
namespace bite
{
	class string
	{
	public:
		string(char* str = "")
		{
			if (nullptr == str)
				str = "";

			// 申请空间
			_str = new char[strlen(str) + 1];
			_count = 1;
			// 存放str中的字符
			strcpy(_str, str);
		}

		string(const string& s)
			: _str(s._str)
		{
			++_count;
		}

		// s2 = s1;
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				// ...
			}

			return *this;
		}

		~string()
		{
			if (_str && 0 == --_count)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
		static int _count;
	};

	int string::_count = 0;
}

#endif


namespace bite
{
	class string
	{
	public:
		string(char* str = "")
			: _pCount(new int(1))
		{
			if (nullptr == str)
				str = "";

			// 申请空间
			_str = new char[strlen(str) + 1];
			
			// 存放str中的字符
			strcpy(_str, str);
		}

		string(const string& s)
			: _str(s._str)
			, _pCount(s._pCount)
		{
			++(*_pCount);
		}

		// s2 = s1;
		// 1. s2原来的资源将不再使用--- 应该给原来计数-1
		//                         计数：非0  0
		// 2. s2应该与s1共享同一份资源  计数++
		
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				// 让当前对象与其管理资源分离开
				if (0 == --*_pCount)
				{
					delete[] _str;
					delete _pCount;
				}

				// 与s共享资源
				_str = s._str;
				_pCount = s._pCount;
				++(*_pCount);
			}

			return *this;
		}

		~string()
		{
			if (_str && 0 == --*_pCount)
			{
				delete[] _str;
				_str = nullptr;

				delete _pCount;
				_pCount = nullptr;
			}
		}

		char& operator[](size_t index)
		{
			return _str[index];
		}
	private:
		char* _str;
		int* _pCount;
	};
}


void TestString()
{
	bite::string s1("hello");
	bite::string s2(s1);

	bite::string s3("wrold");
	bite::string s4(s3);

	// s3不需要释放原来的资源，因为还有s4在用
	s3 = s1;

	// s4是最后使用资源的对象， 赋值期间必须释放原来的资源
	s4 = s1;

	s1[0] = 'H';
}

int main()
{
	TestString();
	return 0;
}