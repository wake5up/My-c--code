#include <iostream>
using namespace std;

#if 0
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}

	void PrintBase()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}

private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};

class Derived : public Base
{};

int main()
{
	// 可以验证：派生类将基类中的成员变量继承到子类中
	cout << sizeof(Derived) << endl;

	// 验证：基类中的成员函数释放被子类继承
	Derived d;
	d.SetBase(10, 20, 30);
	d.PrintBase();
	return 0;
}
#endif

#if 0
// public继承方式：

class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}

	void PrintBase()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}

private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};

// 继承权限--public
// 基类中public/protected的成员在子类中权限不变
// 基类中private的成员在子类中不可见(不能用---该成员变量确实已经继承到子类中)
class Derived : public Base
{
public:
	void SetDerived(int priD, int proD, int pubD)
	{
		_priD = priD;
		_proD = proD;
		_pubD = pubD;

		_pro = 10;
		// _pri = 20; // 编译报错，在派生类中不能访问基类中私有的成员变量
	}

	// 访问权限：限定该成员变量是否可以直接在类外进行调用
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

class D : public Derived
{
public:
	void Test()
	{
		_pro = 10;
	}
};

int main()
{
	Derived d;
	cout << sizeof(d) << endl;

	d._pub = 10;
	// d._pro = 10;
	return 0;
}
#endif


#if 0
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}

	void PrintBase()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}

private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};


// 继承方式--protected
// 基类中public的成员在子类中访问权限已经变成protected
// 基类中protected的成员在子类中访问权限不变
// 基类中private的成员在子类中不可见(不能用---该成员变量确实已经继承到子类中)
class Derived : protected Base
{
public:
	void SetDerived(int priD, int proD, int pubD)
	{
		_priD = priD;
		_proD = proD;
		_pubD = pubD;

		_pro = 10;
		// _pri = 20; // 编译报错，在派生类中不能访问基类中私有的成员变量
	}

	// 访问权限：限定该成员变量是否可以直接在类外进行调用
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

class D : public Derived
{
public:
	void Test()
	{
		_pub = 10;
		_pro = 20;
	}
};

int main()
{
	Derived d;
	// d._pub = 10;
	return 0;
}
#endif

#if 0
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}

	void PrintBase()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}

private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};


// 继承方式--private
// 基类中public的成员在子类中访问权限已经变成private
// 基类中protected的成员在子类中访问权限已经变成private
// 基类中private的成员在子类中不可见(不能用---该成员变量确实已经继承到子类中)
class Derived : private Base
{
public:
	void SetDerived(int priD, int proD, int pubD)
	{
		_priD = priD;
		_proD = proD;
		_pubD = pubD;

		_pro = 10;
		// _pri = 20; // 编译报错，在派生类中不能访问基类中私有的成员变量
	}

	// 访问权限：限定该成员变量是否可以直接在类外进行调用
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

class D : public Derived
{
public:
	void Test()
	{
		// _pub = 10;
		//_pro = 20;
	}
};

int main()
{
	Derived d;
	 d._pub = 10;
	return 0;
}
#endif


#if 0
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}

	void PrintBase()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}

private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};

 
// class 和 struct的默认继承权限
// class默认继承权限---priavet
// struct默认继承权限---public
struct Derived : Base
{
public:
	void SetDerived(int priD, int proD, int pubD)
	{
		_priD = priD;
		_proD = proD;
		_pubD = pubD;

		_pro = 10;
		// _pri = 20; // 编译报错，在派生类中不能访问基类中私有的成员变量
	}

public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

class D : public Derived
{
public:
	void Test()
	{
		_pub = 10;
	}
};

int main()
{
	D d;
	d._pub = 10;
	return 0;
}
#endif

#if 0
class B
{
public:
	void SetB(int b)
	{
		_b = b;
	}

protected:
	int _b;
};

class D : public B
{
public:
	void SetD(int b, int d)
	{
		_b = b;
		_d = d;
	}

//protected:
	int _d;
};

// 赋值兼容规则：前提---->public
// 如果是public继承方式：派生类与基类对象之间是--is-a的关系
// is-a: 是一个，可以将一个子类对象看成是一个基类对象
// 所有用到基类对象的位置都可以使用子类对象进行代替
int main()
{
	B b;
	b.SetB(10);

	D d;
	//d.SetB(10);
	d.SetD(20, 30);

	// 可以用子类对象来给基类对象进行赋值
	b = d;

	// 一个基类指针可以指向子类对象，
	// 一个子类的指针不能直接指向一个基类的对象
	B* pb = &d;

	D* pd = (D*)&b;
	pd->_d = 10;

	B& rb = d;
	//D& rd = b;

	// d = b;
	return 0;
}
#endif

#if 0
class B
{
public:
	void SetB(int b)
	{
		_b = b;
	}

	void Test(int a)
	{}

// protected:
	char _b;
};

// 同名隐藏：基类和派生类中具有相同名称的成员(成员变量 || 成员函数)
// 如果通过派生类对象直接访问同名成员，优先访问到的是派生类自己的，基类的
// 同名成员不能直接访问到(派生类将基类中的同名成员隐藏)

// 成员变量：与变量类型是否相同无关
// 成员函数：与成员函数原型是否相同无关
class D : public B
{
public:
	void SetD(int b, int d)
	{
		_b = b;
	}

	void Test()
	{}

//protected:
	int _b;
};

int main()
{
	cout << sizeof(D) << endl;

	D d;
	d._b = '1';
	d.B::_b = '2';

	d.Test(10);
	d.B::Test(10);

	d.SetD(1, 2);
	return 0;
}
#endif

#if 0
// 如果基类的构造函数是无参或者全缺省的构造函数，
// 在派生类构造函数初始化列表的位置调用或不调用都可以
// 如果用户没有调用，则编译器会默认调用
class B
{
public:
	B()
	{
		cout << "B()" << endl;
	}

protected:
	int _b;
};

class D : public B
{
public:
	D()
	{
		cout << "D()" << endl;
	}

protected:
	int _d;
};

int main()
{
	D d;
	return 0;
}
#endif

#if 0
class B
{
public:
	B(int b)
	{
		cout << "B()" << endl;
	}

protected:
	int _b;
};

// 如果基类的构造函数带有参数的构造函数，用户必须在
// 派生类构造函数初始化列表的位置显式调用，以完成基类
// 部分成员的初始化
class D : public B
{
public:
	D()
		: B(1)
		, _d(2)
	{
		cout << "D()" << endl;
	}

protected:
	int _d;
};

int main()
{
	D d;
	return 0;
}
#endif

class B
{
public:
	B(int b)
		: _b(b)
	{
		cout << "B()" << endl;
	}

	B(const B& b)
		: _b(b._b)
	{}

	B& operator=(const B& b)
	{
		if (this != &b)
		{
			_b = b._b;
		}

		return *this;
	}

protected:
	int _b;
};

// 如果基类的构造函数带有参数的构造函数，用户必须在
// 派生类构造函数初始化列表的位置显式调用，以完成基类
// 部分成员的初始化
class D : public B
{
public:
	D(int b, int d)
		: B(b)
		, _d(d)
	{
		cout << "D()" << endl;
	}

	D(const D& d)
		: B(d)
		, _d(d._d)
	{}

	D& operator=(const D& d)
	{
		if (this != &d)
		{
			//*this = d;
			B::operator=(d);
			_d = d._d;
		}

		return *this;
	}
protected:
	int _d;
};

int main()
{
	D d1(1, 2);
	D d2(d1);

	D d3(3, 4);
	d2 = d3;
	return 0;
}