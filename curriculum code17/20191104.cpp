#include <iostream>
using namespace std;

#include <string>


#if 0
// 买票
// 普通人
class Person
{
public:
	Person(const string& name, const string& gender, int age)
		: _name(name)
		, _gender(gender)
		, _age(age)
	{}

	// 虚函数
	virtual void BuyTicket()
	{
		cout << "全价票" << endl;
	}

protected:
	string _name;
	string _gender;
	int _age;
};

class Student : public Person
{
public:
	Student(const string& name, const string& gender, int age, int stuId)
		: Person(name, gender, age)
		, _stuId(stuId)
	{}

	virtual void BuyTicket()
	{
		cout << "半价票" << endl;
	}
protected:
	int _stuId;
};

class Soilder : public Person
{
public:
	Soilder(const string& name, const string& gender, int age, const string& rank)
		: Person(name, gender, age)
		, _rank(rank)
	{}

	void BuyTicket()
	{
		cout << "免费" << endl;
	}

protected:
	string _rank;
};


// 必须通过基类的指针或引用来调用
// 多态的体现：代码编译时，不能确定到底调用那个类的虚函数
//           在代码运行时，根据p所指向的实际对象选择调用对应类的虚函数
// 如果多态的实现条件没有完全满足：1. 重写失败(基类函数不是虚函数，函数原型不一致)
//                            2. 没有通过基类的指针或者引用调用虚函数 
//   
void TestBuyTicket(Person& p)
{
	p.BuyTicket();
}

/*
void TestBuyTicket(Person& p)
{
	p.BuyTicket();
}

void TestBuyTicket(Student& p)
{
	p.BuyTicket();
}

void TestBuyTicket(Soilder& p)
{
	p.BuyTicket();
}
*/

int main()
{
	Person p("Peter", "男", 18);
	Student st("小帅", "女", 19, 1000);
	Soilder so("威武", "男", 23, "班长");

	TestBuyTicket(p);
	TestBuyTicket(st);
	TestBuyTicket(so);
	return 0;
}
#endif


#if 0
struct A{};
struct B:public A{};

class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	virtual void TestFunc2(int)
	{
		cout << "Base::TestFunc2()" << endl;
	}

	void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "Base::TestFunc4()" << endl;
	}

	virtual Base* TestFunc5()
	{
		cout << "Base::TestFunc5()" << endl;
		return this;
	}

	virtual A& TestFunc6(A& a)
	{
		cout << "Base::TestFunc6()" << endl;
		return a;
	}
};

class Derived : public Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Derived::TestFunc2()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Derived::TestFunc3()" << endl;
	}

	void TestFunc4()
	{
		cout << "Derived::TestFunc4()" << endl;
	}

	virtual Derived* TestFunc5()
	{
		cout << "Derived::TestFunc5()" << endl;
		return this;
	}

	virtual B& TestFunc6(A& a)
	{
		cout << "Derived::TestFunc6()" << endl;
		return *(new B);
	}
};


void TestVirtualFunc(Base* pb)
{
	pb->TestFunc1();
	pb->TestFunc2(10);
	pb->TestFunc3();
	pb->TestFunc4();
	pb->TestFunc5();

	A a;
	pb->TestFunc6(a);
}

int main()
{
	Base b;
	Derived d;

	TestVirtualFunc(&b);
	TestVirtualFunc(&d);
	return 0;
}
#endif

#if 0
class Base
{
public:
	Base(int b)
		: _b(b)
	{
		cout << "Base::Base()" << endl;
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
		, _p(new int[10])
	{
		cout << "Derived::Derived(int)" << endl;
	}

	~Derived()
	{
		delete[] _p;
		cout << "Derived::~Derived()" << endl;
	}

protected:
	int* _p;
};

void TestDestroy()
{
	Base* pb = new Derived(10);
	delete pb;
}

int main()
{
	TestDestroy();
	return 0;
}
#endif

#if 0
// C++11:
// override: 只能修饰派生类的虚函数
//           作用：让编译器帮助用户检测派生列中某个虚函数是否重写了基类的那个虚函数
class Base
{
public:
	virtual void TestFunc()
	{
		cout << "Base::TestFunc()" << endl;
	}

	int _b;
};

class Derived : public Base
{
public:
	virtual void TestFunc()override
	{
		cout << "Derived::TestFunc()" << endl;
	}

	int _d;
};

void TestVirtualFunc(Base* pb)
{
	pb->TestFunc();
}


int main()
{
	Base b;
	Derived d;
	TestVirtualFunc(&b);
	TestVirtualFunc(&d);
	return 0;
}
#endif

#if 0
// final: 修饰类--->表示该类不能被继承
//        修饰虚函数函数--->


class Base
{
public:
	virtual void TestFunc()const
	{
		cout << "Base::TestFunc()" << endl;
	}

	int _b;
};

// 假设在Derived的子类中，不想让其子类重写TestFunc的虚函数
// C++98中做不到
// C++11:提供的final的关键字可以作用
// final修饰虚函数，表明该虚函数不想让其在子类中被重写(一般final修饰子类的虚函数)
class Derived : public Base
{
public:
	virtual void TestFunc()const override
	{
		cout << "Derived::TestFunc()" << endl;
	}

	int _d;
};
#endif

#if 0
#include <string>


class WC
{
public:
	void GoToManRoom()
	{
		cout << "go to left" << endl;
	}

	void GoToWoManRoom()
	{
		cout << "go to right" << endl;
	}
};

// 抽象类--包含有纯虚函数的类
// 特性：不能实例化对象，但可以创建该类的指针(引用)
// 作用：规范后序接口
class Person
{
public:
	// 纯虚函数
	virtual void GoToWC(WC& wc) = 0;

	string _name;
	int _age;
};

class Man : public Person
{
public:
	void GoToWC(WC& wc)
	{
		wc.GoToManRoom();
	}
};

class Woman : public Person
{
public:
	void GoToWC(WC& wc)
	{
		wc.GoToWoManRoom();
	}
};

// Monster类也是抽象类，因为该类没有重写基类中的纯虚函数
class Monster : public Person
{};


#include <windows.h>
#include <time.h>

void TestWC(int n)
{
	WC wc;
	srand(time(nullptr));

	for (int i = 0; i < n; ++i)
	{
		Person* pGuard; // 厕所管理员
		if (rand() % 2 == 0)
			pGuard = new Man;
		else
			pGuard = new Woman;

		pGuard->GoToWC(wc);

		delete pGuard;

		Sleep(1000);
	}
}

int main()
{
	Person* p;

	//Monster m;
	TestWC(10);
	return 0;
}
#endif

#if 0
//如果一个类中包含有虚函数，类大小会多四个字节
//编译器会给该类生成一个默认的构造函数
class Base
{
public:
// 	Base()
// 	{}
	virtual void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}

	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}

	int _b;
};


int main()
{
	cout << sizeof(Base) << endl;

	Base b;
	b._b = 1;

	return 0;
}
#endif

#if 0
class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}

	int _b;
};

class Derived : public Base
{
public:
	virtual void TestFunc5()
	{
		cout << "Derived::TestFunc5()" << endl;
	}

	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Derived::TestFunc3()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "Derived::TestFunc4()" << endl;
	}

	int _d;
};

typedef void (*PVFT)();

void PrintTable(Base& b, const string& str)
{
	cout << str << endl;
	//&b;  // 指向对象本身
	//(int*)&b; // 指向对象的前4个字节
	//*(int*)&b; // 对象前4个字节中内容--->是整形数字

	// 将整形数字转化成表格的首地址--->需要知道表格中元素的类型--->前期已经假设表格中存储的是虚函数的地址
	PVFT* pVFT = (PVFT*)(*(int*)&b);

	while (*pVFT)
	{
		(*pVFT)();
		++pVFT;
	}
	cout << endl;
}

int main()
{
	cout << sizeof(Base) << endl;

	Base b1, b2;

	Base b;
	b._b = 1;

	cout << sizeof(Derived) << endl;
	Derived d;
	d._b = 1;
	d._d = 2;

	PrintTable(b, "Base VFT:");
	PrintTable(d, "Derived VFT:");

	// 确认TestFunc4和TestFunc5的入口地址
	d.TestFunc4();
	d.TestFunc5();



	return 0;
}
#endif

#if 0
class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}

	void TestFunc4()
	{
		cout << "Base::TestFunc4()" << endl;
	}

	int _b;
};

class Derived : public Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Derived::TestFunc2()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Derived::TestFunc3()" << endl;
	}

	int _d;
};

// 虚函数的调用：通过基类的指针或者引用调用虚函数
void TestVirtual(Base* pb)
{
	pb->TestFunc1(); // call Base::TestFunc1
	pb->TestFunc2(); // call Base::TestFunc2
	pb->TestFunc3(); // call Base::TestFunc3
	pb->TestFunc4(); // call Base::TestFunc4
}

int main()
{
	Base b;
	Derived d;

	TestVirtual(&b);
	TestVirtual(&d);

	// 
	Base* pb = (Base*)&d;
	pb->TestFunc1();
	return 0;
}
#endif

#if 0
// 带有虚函数的多继承派生类的对象模型

// 8
class B1
{
public:
	virtual void TestFunc1()
	{
		cout << "B1::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "B1::TestFunc2()" << endl;
	}
	int _b1;
};

// 8
class B2
{
public:
	virtual void TestFunc3()
	{
		cout << "B2::TestFunc3()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "B2::TestFunc4()" << endl;
	}
	int _b2;
};

// 20   24
class D : public B1, public B2
{
public:
	virtual void TestFunc1()
	{
		cout << "D::TestFunc1()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "D::TestFunc4()" << endl;
	}

	virtual void TestFunc5()
	{
		cout << "D::TestFunc5()" << endl;
	}

	int _d;
};


typedef void(*PVFT)();

void PrintVFT1(B1& b, const string& str)
{
	cout << "D重写B1基类的虚表" << endl;
	PVFT* pVFT = (PVFT*)(*(int*)&b);
	while (*pVFT)
	{
		(*pVFT)();
		++pVFT;
	}
	cout << endl;
}

void PrintVFT2(B2& b, const string& str)
{
	cout << str << endl;
	PVFT* pVFT = (PVFT*)(*(int*)&b);
	while (*pVFT)
	{
		(*pVFT)();
		++pVFT;
	}
	cout << endl;
}

int main()
{
	cout << sizeof(D) << endl;

	D d;
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;

	PrintVFT1(d, "D重写B1基类的虚表");
	PrintVFT2(d, "D重写B2基类的虚表");

	return 0;
}
// 自己研究：菱形继承&菱形虚拟继承---增加虚函数
#endif

// 虚函数一定是成员函数，成员函数不一定全部都可以作为虚函数
// 验证：类中那些函数可以作为虚函数
class Base
{
public:
	virtual inline void Test1()
	{}

	virtual static void Test2()
	{}


};

void TestVirtual(Base* pb)
{
	// 假设已经是内联函数--->如果编译器将一个函数作为内联函数处理
	// 在编译阶段，会将该函数展开
	// 如果展开，就先不要通过虚表调用，就不能实现多态
	// 结论：内联函数不能作为虚函数
	pb->Test2();
}

int main()
{
	return 0;
}