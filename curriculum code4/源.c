#include <iostream>
using namespace std;

#if 0
class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}

	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};


void TestDate()
{
	Date d2(2019, 9, 14);
}

int main()
{
	int a;
	a = 10;

	int b = 10;
	int c(10);

 	Date d1;
// 	d1.SetDate(2019, 9, 14);
// 	d1.PrintDate();

	// 
	TestDate();
	return 0;
}
#endif

#if 0
// 类中如果没有显式(用户是否直接定义)任何构造函数，
// 编译器将会生成一个默认的构造函数---无参构造函数
class Date
{
public:
// 	Date()
// 	{
// 		_year = 1900;
// 		_month = 1;
// 		_day = 1;
// 	}

	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1;  // 需要不带参数的构造函数
	Date d2(2019, 9, 14);   // 带有参数的构造函数
	return 0;
}
#endif


#if 0
class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
	{
		cout << "Time(int,int,int)" << endl;
		_hour = hour;
		_minute = minute;
		_second = second;
	}

private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};


int main()
{
	Date d1;
	return 0;
}
#endif

#if 0
#include <assert.h>
#include <malloc.h>

typedef int DataType;

class SeqList
{
public:
	SeqList(size_t capacity = 10)
	{
		cout << "SeqList(size_t)" << endl;

		_array = (DataType*)malloc(sizeof(DataType)*capacity);
		if (nullptr == _array)
		{
			assert(0);
			return;
		}

		_capacity = 0;
		_size = 0;
	}

	~SeqList()
	{
		cout << "~SeqList()" << endl;
		if (_array)
		{
			free(_array);
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}

private:
	DataType* _array;
	size_t _size;
	size_t _capacity;
};


void TestSeqList()
{
	SeqList s;
}

int main()
{
	TestSeqList();
	// _CrtDumpMemoryLeaks();
	return 0;
}
#endif

#if 0
// 关于编译器生成的默认的析构函数
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		if (_str)
		{
			free(_str);
		}
	}
private:
	char* _str;
};

class Person
{
private:
	String _name;
	String _gender;
	int _age;
};


void TestPerson()
{
	Person p;
}

int main()
{
	TestPerson();
	return 0;
}
#endif


#if 0
// 拷贝构造函数：用户没有显式提供，编译器会生成一个默认的拷贝构造函数
// 
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		if (_str)
		{
			free(_str);
		}
	}
private:
	char* _str;
};

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	Date d1(2019, 9, 14);
	Date d2(d1);
}

void TestString()
{
	String s1("hello");
	String s2(s1);
}

int main()
{
	TestString();
	TestDate();
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2019, 9, 14);
	Date d2(d1);
	return 0;
}
#endif

#if 0
// 什么是运算符重载？
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	bool operator>(const Date& d)
	{
		if (_year > d._year ||
			_year == d._year && _month > d._month ||
			_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}

		return false;
	}

	bool operator==(const Date& d)
	{
		return _year == d._year &&
			   _month == d._month &&
			   _day == d._day;
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	bool IsGreater(const Date& d)
	{
		if (_year > d._year ||
			_year == d._year && _month > d._month ||
			_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}

		return false;
	}

private:
	int _year;
	int _month;
	int _day;
};

// bool operator@(int a, int b)
// {
// 	return true;
// }


Date operator+(Date a, int b)
{
	return a;
}


int main()
{
	int a = 10;
	int b = 20;
	if (a > b)
		cout << "a" << endl;
	else
		cout << "b" << endl;


	Date d1(2019, 9, 14);
	Date d2(2019, 9, 15);
	Date d3(2020, 9, 14);

	d3 = d1;

	if (d1>d2)
		cout << "d1 > d2" << endl;
	else
		cout << "d1 <= d2" << endl;

	return 0;
}
#endif

#if 0
// 赋值运算符重载：如果用户没有显式提供，编译器将会生成一份默认的赋值运算符重载
// 如果一个类中涉及到资源管理，用户必须提供赋值运算符重载
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		if (_str)
		{
			free(_str);
		}
	}
private:
	char* _str;
};

void TestString()
{
	String s1("hello");
	String s2("world");

	s1 = s2;
}

int main()
{
	TestString();
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// s3 = s2 = s1;
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		
		return *this;
	}

	// 前置++
	Date& operator++()
	{
		_day += 1;
		return *this;
	}

	// 后置++
	Date operator++(int)
	{
		Date temp(*this);
		_day += 1;

		return temp;
	}

	Date& operator--()
	{
		_day -= 1;
		return *this;
	}

	Date operator--(int)
	{
		Date temp(*this);
		_day -= 1;

		return temp;
	}

	bool operator>(const Date& d)
	{
		if (_year > d._year ||
			_year == d._year && _month > d._month ||
			_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}

		return false;
	}

	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);

	//d + 10000;
	Date operator+(int days);
	Date operator-(int days);
	size_t operator-(const Date& d);

	bool operator==(const Date& d)
	{
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int a = 1;
	int b = 2;
	int c = 3;

	a = b = c;
	c++;
	++c;

	Date d1(2019, 9, 14);
	Date d2(2019, 9, 15);
	Date d3(2019, 9, 13);

	d2 = ++d3;  // 给d3加1之后的结果给d2进行赋值
	d2.operator=(d3.operator++());

	d2 = d3++;  // 加之前的旧值给d2赋值
	d2.operator=(d3.operator++(0));
	
	//d3 = d3;

	d2 = d1;
	d2.operator=(d1);   // operator=(&d2, &d1);
	
	d3 = d2 = d1;
	d3.operator=(d2.operator=(d1));

	Date& d4 = d3;






	d4 = d3;
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

int GetDaysOfMonth(int year, int month)
{
	int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if ((0 == year % 4 && 0 != year % 100) || 0 == year % 400)
	{
		days[2] += 1;
	}

	return days[month];
}

bool IsValidDay(int year, int month, int day)
{
	if (year > 0 &&
		(month > 0 && month < 13) &&
		(day > 0 && day <= GetDaysOfMonth(year, month)))
	{
		return true;
	}

	return false;
}

int main()
{
	int year, month, day;
	size_t totalDays = 0;
	cin >> year >> month >> day;

	if (IsValidDay(year, month, day))
	{
		for (size_t i = 1; i < month; ++i)
			totalDays += GetDaysOfMonth(year, i);

		totalDays += day;
		cout << totalDays << endl;
	}
	else
	{
		return -1;
	}

	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	Date* operator&()
	{
		_day++;
		return this;
	}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2019, 9, 14);
	cout << &d1 << endl;

	const Date d2(2019, 9, 15);
	cout << &d2 << endl;
	return 0;
}
#endif

#if 0
// 被const修饰的成员函数，称作为const类型的成员函数
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	Date* operator&()
	{
		_day++;
		return this;
	}

	// 在const成员函数中，不能修改类的任何成员变量
	void PrintDate()const
	{
		_day++;
		//_year++;
		// const Date* const
		//this->_month++;
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	mutable int _day;
};
#endif

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}


// 	void PrintDate()
// 	{
// 		_day++;
// 		cout << _year << "-" << _month << "-" << _day << endl;
// 	}

	void PrintDate()/*const*/
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	mutable int _day;
};


int main()
{
	// const类型的对象不能调用普通类型的成员函数
	// 原因：const类型对象中的成员不允许被修改
	//      在普通类型成员函数中可以修改成员变量
	// 如果编译器允许const类型对象调用普通类型成员，在普通类型成员函数中可能会修改const类型对象中的内容
	// 操作不安全
	const Date d1(2019, 9, 14);
	//d1.PrintDate();
	
	// 普通类型的对象既可以调用普通类型的成员函数，也可以调用const类型的成员函数
	// 普通类型对象时可读写
	Date d2(2019, 9, 15);
	d2.PrintDate();
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	// const类型的成员函数只读的函数，不能修改对象中的任何成员变量
	// 除非该成员变量被mutable
	// const Date* const
	void TestFunc1()const
	{
		//TestFunc2(/*this*/);
	}

	// 普通类型的成员函数是可读写的函数
	// 可能会在该成员函数中修改成员变量
	// Date* const 
	void TestFunc2()
	{}


private:
	int _year;
	int _month;
	int _day;
};
#endif


#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	// const类型的成员函数只读的函数，不能修改对象中的任何成员变量
	// 除非该成员变量被mutable
	// const Date* const
	void TestFunc1()const
	{}

	// 普通类型的成员函数是可读写的函数
	// 可能会在该成员函数中修改成员变量
	// Date* const 
	void TestFunc2()
	{
		TestFunc1();
	}

	Date* operator&()
	{
		return this;
	}

	const Date* operator&()const
	{
		return this;
	}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2019, 9, 14);
	const Date d2(2019, 9, 15);

	cout << &d1 << endl;
	cout << &d2 << endl;
	return 0;
}
#endif

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	~Date()
	{}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	return 0;
}



