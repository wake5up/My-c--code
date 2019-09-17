#include <iostream>
using namespace std;

#if 0
// 初始化列表作用：初始化类中的成员变量，并且每个成员变量只能在初始化列表中出现一次
class Date
{
public:
	Date(int year, int month, int day) 
		: _year(year)
		, _month(month)
		, _day(day)
		, a(10)
		, b(_year)
	{
		// 构造函数体中：赋初值
		_year = year;
		_month = month;
		_day = day;
		//a = 10;
	}

private:
	int _year;
	int _month;
	int _day;

	const int a;
	int& b;
};

int main()
{
	const int a = 10;
	return 0;
}
#endif


#if 0
class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}

private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
		//, _t(19,24,30)// , _t()
	{
		cout << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{

	// Date d1(2019, 9, 16);
	return 0;
}
#endif

#if 0
// 建议：尽量不要使用成员初始化成员
//      初始化列表中成员的出现次序最好与其在类中的声明次序保持一致
class Date
{
public:
	Date(int year, int day)
		: _year(year)
		, _day(day)
		, _month(_day)
	{
		cout << this << endl;
	}

	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}

	void TestFunc(int year)
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
	// 单参类型的构造函数具有类型转化的作用
	// explicit: 修饰单参构造函数，意思是禁止单参构造函数类型转化的作用
	explicit Date(int year)
		: _year(year)
	{
		cout << this << endl;
	}

	Date& operator=(const Date& d)
	{
		cout << this << " = " << &d << endl;
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{

	Date d1(2018);
	d1 = 2019;
	return 0;
}
#endif


// Date总共创建了多少个有效对象？
// 构造构造  拷贝构造函数 析构函数  
// 最终需要结果：对象的个数---计数--int

#if 0
int _count = 0;
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(_day)
		, _day(day)
	{
		_count++;
	}

	Date(Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		++_count;
	}

	~Date()
	{
		_count--;
	}

private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	Date d3(2019, 9, 16);
	Date d4(d3);
	Date d5(2019, 9, 16);
	cout << _count << endl;
}

int main()
{
	Date d1(2019, 9, 16);
	Date d2(d1);
	cout << _count << endl;

	_count = 0;
	TestDate();

	_count = 100;
	cout << _count << endl;
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(_day)
		, _day(day)
	{
		_count++;
	}

	Date(Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		++_count;
	}

	~Date()
	{
		_count--;
	}

private:
	int _year;
	int _month;
	int _day;

public:
	static int _count;
};

int Date::_count = 0;

void TestDate()
{
	Date d3(2019, 9, 16);
	Date d4(d3);
	Date d5(2019, 9, 16);
	
}

int main()
{
	Date d1(2019, 9, 16);
	Date d2(d1);
	
	// 静态成员变量是所有类对象共享的成员变量
	// 不属于某个具体的对象
	cout << &d1._count << " " << &d2._count << endl;
	
	// 静态成员变量是类的属性
	cout << Date::_count << endl;

	cout << sizeof(Date) << endl;
	TestDate();

	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(_day)
		, _day(day)
	{
		_count++;
	}

	Date(Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		++_count;
	}

	~Date()
	{
		_count--;
	}

	void TestFunc()
	{
		_day++;
		cout << _count << endl;
		GetCount();
	}


	static int GetCount()
	{
		//TestFunc();
		//cout << this << endl;
		//_day++;
		return _count;
	}

private:
	int _year;
	int _month;
	int _day;
	static int _count;
};

int Date::_count = 0;

void TestDate()
{
	Date d3(2019, 9, 16);
	Date d4(d3);
	Date d5(2019, 9, 16);
	cout << Date::GetCount() << endl;
}

int main()
{
	cout << Date::GetCount() << endl;
	Date d1(2019, 9, 16);
	Date d2(d1);

	cout << Date::GetCount() << endl;
	TestDate();
	cout << Date::GetCount() << endl;
	return 0;
}
#endif

class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(_day)
		, _day(day)
	{
		_count++;
	}

	Date(Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		++_count;
	}

	~Date()
	{
		_count--;
	}

	void TestFunc()
	{
		_day++;
		cout << _count << endl;
		GetCount();
	}


	static int GetCount()
	{
		//TestFunc();
		//cout << this << endl;
		//_day++;
		return _count;
	}

private:
	int _year;
	int _month;
	int _day;
	static int _count;
};

int Date::_count = 0;


int main()
{
	int sum = 0;

	Date d1(2019,9,16);
	sum += Date::GetCount();

	Date d2(d1);
	sum += Date::GetCount();

	Date d3(d1);
	sum += Date::GetCount();
	return 0;
}