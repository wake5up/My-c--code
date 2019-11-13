#include <iostream>
using namespace std;

#include <string>

#if 0
// 虚函数一定是成员函数，成员函数不一定全部都可以作为虚函数
// 验证：类中那些函数可以作为虚函数
class Base
{
public:
	// 构造函数不能作为虚函数
	// 一个类中如果包含虚函数，该类的构造函数作用：
	// 1. 初始化类中的成员变量---->是用户
	// 2. 将虚表指针放在对象的前4个字节---->编译器完成

	// 假设：构造函数可以作为虚函数：创建对象 + 虚函数调用
	// 构造函数假设其已经是虚函数--->一定在虚线表中
	// 创建对象--->要调用构造函数
	// 构造函数调用---->需要通过虚表--->从对象前4个字节中获取虚表地址-
	// 要从对象前4个字节中找虚表--->找构造函数--->对象就可以创建完整:即将虚表指针放在对象的前4个字节中
	virtual Base()
	{}

	//virtual inline void Test1()
	//{}

	// 静态成员函数不能作为虚函数
	// 原因：静态成员函数没有this指针，可以不同通过对象调用
	// 如果静态成员函数可以作为虚函数，必须通过虚表调用，
	// 而静态成员函数没有this指针，可以不通过对象调用，虚表就无法找到
	// 静态成员函数就无法找到--->不能调用
	//virtual static void Test2()
	//{}
};

void TestVirtual(Base* pb)
{
	// 假设已经是内联函数--->如果编译器将一个函数作为内联函数处理
	// 在编译阶段，会将该函数展开
	// 如果展开，就先不要通过虚表调用，就不能实现多态
	// 结论：内联函数不能作为虚函数
	pb->Test1();
	//pb->Test2();
	//Base::Test2();
}
#endif


#if 0
// 析构函数---可以作为虚函数---->重写的一种特例
// 如果派生类中涉及到动态资源管理(比如：子类从堆上申请空间)，建议：基类的析构函数最好设置成虚函数，否则可能就会存在内存泄漏)
class Base
{
public:
	Base(int b)
		: _b(b)
	{
		cout << "Base::Base(int)" << endl;
	}

	virtual ~Base()
	{
		cout << "Base::~Base()" << endl;
	}

	int _b;
};

class Derived : public Base
{
public:
	Derived(int b)
		: Base(b)
	{
		_p = new int[10];
	}

	~Derived()
	{
		delete[] _p;
	}
private:
	int* _p;
};

int main()
{
	// 静态类型：声明变量时的类型---->在编译期间起作用
	// 动态类型：实际引用(指向)的类型---->在运行时确定调用那个类的虚函数
	Base* pb = new Derived(10);
	delete pb;
	// delete: 1. 调用析构函数释放对象中的资源
	//         2. 调用void operator delete(void* p)释放对象的空间

	return 0;
}
#endif



#if 0
class B
{
public:
	virtual void Test()
	{}
};

int g_a = 10;
int main()
{
	const char* p = "hello world";

	printf("全局变量: %p \n", &g_a);
	printf("常量: %p \n", p);

	B b;
	printf("虚表: %p \n", *(int*)&b);

	// 从打印结果中看出：虚表地址距离常量地址非常近---->虚表应该在代码段
	return 0;
}
#endif


#if 0
class A
{
public:
	A(int a)
		: _a(a)
	{}

	void SetA(int a)
	{
		_a = a;
	}

	int GetA()
	{
		return _a;
	}
protected:
	int _a;
};


// B 和 A的关系：is-a
class B : public A
{
public:
	B(int a, int b)
		: A(a)
		, _b(b)
	{}

	void SetB(int b)
	{
		_b = b;
	}

	int GetB()
	{
		return _b;
	}
protected:
	int _b;
};


// 组合：C类中包含有一个A类的对象   has-a
class C
{
public:
	C(int a, int c)
		: _a(a)
		, _c(c)
	{}

	void SetA(int a)
	{
		_a.SetA(a);
	}

	void SetC(int c)
	{
		_c = c;
	}

	int GetC()
	{
		return _c;
	}

private:
	A _a;
	int _c;
};


int main()
{
	B b(1,2);
	b.SetA(10);

	C c(1, 2);
	c.SetA(10);
	return 0;
}
#endif


#if 0
class Base1 
{
public:
	int _b1;
};

class Base2 
{
public:
	int _b2;
};

class Derive : public Base1, public Base2 
{
public:
	int _d;
};


int main()
{
	// A. p1 == p2 == p3
	// B. p1 < p2 < p3
	// C. p1 == p3 != p2
	// D. p1 != p2 != p3

	Derive d;
	Base1* p1 = &d;
	Base2* p2 = &d;
	Derive* p3 = &d;
	return 0;
}
#endif


#if 0
// 比较暴力，不是很友好
int Div(int left, int right)
{
	if (0 == right)
		exit(0);

	return left / right;
}
#endif

#if 0
#include <windows.h>

void Test()
{
	FILE* pf = fopen("2222.txt", "rb");
	if (nullptr == pf)
	{
		// 获取最近发生错误的错误码(是windows操作系统维护的)
		int errNo = GetLastError();
		cout << errNo << endl;

		return;
	}

	// ....
	fclose(pf);
}

int main()
{
	Test();
	//Test1();
	return 0;
}
#endif

#if 0
void Test()
{
	FILE* pf = fopen("2222.txt", "rb");
	if (nullptr == pf)
	{
		// 获取最近发生错误的错误码(是windows操作系统维护的)
		int errNo = GetLastError();
		cout << errNo << endl;

		goto L;
	}

	// ....
	fclose(pf);

	L:
}
#endif


#if 0
int main()
{
    https://www.baidu.com;

	return 0;
}
#endif

#if 0
#include <malloc.h>

#include <setjmp.h>

// 该全局变量中将来保存的是longjmp函数的跳转位置
jmp_buf buff;  // 有setjmp来设置buff的跳转信息

void Test1()
{
	char* p = (char*)malloc(0x7fffffff);
	if (nullptr == p)
	{
		// 一旦申请空间失败时，longjmp会跳转到buff指定的位置
		longjmp(buff, 1);
	}

	///正常操作
}

void Test2()
{
	FILE* pf = fopen("2222.txt", "rb");
	if (nullptr == pf)
	{
		longjmp(buff, 2);
	}

	// ....
	fclose(pf);
}

int main()
{
	// setjmp设置longjmp函数的跳转点
	// 注意：setjmp在首次调用时，一定会返回0
	int iState = 0;//setjmp(buff);
	if (0 == iState)
	{
		// 正常操作
		Test1();
		Test2();
	}
	else
	{
		// 程序遇到非法情况，longjmp跳转到此位置
		// 一般情况：写的是程序的错误处理代码
		switch (iState)
		{
		case 1:
			cout << "malloc申请空间失败" << endl;
			break;
		case 2:
			cout << "打开文件失败" << endl;
			break;
		default:
			cout << "未知错误" << endl;
		}
	}

	iState = setjmp(buff);
	return 0;
}
#endif


#if 0
void Test1()
{
	FILE* pf = fopen("2222.txt", "rb");
	if (nullptr == pf)
	{
		throw 1;
	}

	// ...
	// 进行常规的文件操作

	fclose(pf);
}


void Test2()
{
	char* p = (char*)malloc(0x7fffffff);
	if (nullptr == p)
	{
		throw 1.0;
	}

	///正常操作
	free(p);
}


int main()
{
	int a = 10;
	double d = 12.34;
	a = d; // double和int之间可以发生隐式类型转化

	// 异常捕获是按照类型来进行捕获的
	// 而且之间基本不会发生类型转化
	try
	{
		Test2();
		Test1();
	}
	catch (int e)
	{
		// 捕获所有int类型的异常
		// 错误处理流程
		cout << e << endl;
	}
	catch (double e)
	{
		cout << e << endl;
	}
	//...
	return 0;
}
#endif


#if 0
void Test1()
{
	FILE* pf = fopen("2222.txt", "rb");
	if (nullptr == pf)
		throw 1;

	// ...
	fclose(pf);
}


void Test2()
{
	int* p = new int[10];

	// ...
	try
	{
		Test1();
	}
	catch (int e)
	{
		delete[] p;
		cout << e << endl;
		return;
	}
	

	// ...
	delete[] p;
}

int main()
{
	try
	{
		Test2();
		Test1();
	}
	catch (int e)
	{
		cout << e << endl;
	}

	return 0;
}
#endif

#if 0
void Test()
{
	int a = 10;
	cout << &a << endl;

	// 在抛异常时，并不是将a本身抛出，而是抛出了一份a的副本
	throw a;
}

int main()
{
	try
	{
		Test();
	}
	catch (int& ra)
	{
		cout << &ra << endl;
	}
	return 0;
}
#endif


#if 0
class A
{
public:
	A()
	{
		cout << "A::A()" <<this<< endl;
	}

	A(const A& a)
	{
		cout << "AA::(const A&):" << this << endl;
	}

	~A()
	{
		cout << "A::~A()" <<this<< endl;
	}
};
void Test()
{
	A  a;
	cout << &a << endl;

	// 在抛异常时，并不是将a本身抛出，而是抛出了一份a的副本
	throw a;  // 实际抛的是a的副本
}

int main()
{
	try
	{
		Test();
	}
// 	catch (A& ra)
// 	{
// 		cout << &ra << endl;
// 	}
	catch (...) // 万能捕获，即：任意类型的异常都可以采用catch(...)的方式进行捕获
	{
		cout << "A" << endl;
	}
	return 0;
}
#endif

#if 0
void Test1()
{
	FILE* pf = fopen("2222.txt", "rb");
	if (nullptr == pf)
		throw 1;

	// ...
	fclose(pf);
}


void Test2()
{
	int* p = new int[10];

	// ...
	try
	{
		Test1();
	}
	catch (...)
	{
		// 1. 假设Test2现在根本不知道Test1抛出异常的类型
		// 2. 假设Test2知道Test1所抛出异常的类型，但是Test2没有必要必须要解决Test1抛出的异常
		delete[] p;
		throw;   // 异常的重新抛出
	}

	// ...
	delete[] p;
}

int main()
{
	try
	{
		Test2();
	}
	catch (int e)
	{
		cout << e << endl;
	}
	
	return 0;
}
#endif

#if 0
void Test()
{
	throw 1;
}


template<class T>
void Test2(T a)
{
	throw a;
}

template<class T>
void Test3(T a)
{
	try
	{
		Test2(a);
	}
	catch (T a)
	{
		cout << a << endl;
	}
}

int main()
{
	Test3(10);
	return 0;
}
#endif

#if 0
// 如果抛异常，只能抛出整形的异常
// 否则：在编译期间就会报错
void Test1()throw(int)
{
	throw 1.0;
}

// 该函数一定不会抛出异常
// 否则：在编译期间就会报错
void Test2()throw()
{
	throw 1;
}

int main()
{
	return 0;
}
#endif

class Exception
{
public:
	Exception(const string& errInfo, int errNo)
		: _errInfo(errInfo)
		, _errNo(errNo)
	{}

	virtual void What() = 0;

protected:
	string _errInfo;
	int _errNo;
};

class NetException : public Exception
{
public:
	NetException(const string& errInfo, int errNo)
		: Exception(errInfo, errNo)
	{}

	virtual void What()
	{
		cout << _errInfo << ":" << _errNo << endl;
	}
};


// 
class DBException : public Exception
{
public:
	DBException(const string& errInfo, int errNo)
		: Exception(errInfo, errNo)
	{}

	virtual void What()
	{
		cout << _errInfo << ":" << _errNo << endl;
	}
};

// 通过网络传递数据
void Test1()
{
	NetException e("网络中断", 400);
	throw e;
}

// 操作数据库
void Test2()
{
	DBException e("数据库未打开", 500);
}

int main()
{
	try
	{
		char* p = new char[0x7fffffff];

		Test1();
		Test2();
		
	}
	catch (Exception& e)
	{
		e.What();
	}
	catch (exception& e)
	{
		e.what();
	}
	catch (...)
	{
		cout << "未知异常" << endl;
	}
	
	return 0;
}