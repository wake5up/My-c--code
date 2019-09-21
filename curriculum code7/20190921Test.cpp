#include <iostream>
using namespace std;

#if 0
int main()
{
	int* p = (int*)malloc(sizeof(int)* 10);
	free(p);
	return 0;
}
#endif

#if 0
// new/delete     new[]/delete[]
// malloc/free
// 注意：一定要匹配使用
// 1. new和delete不是函数，C++提供的新的操作符
// 2. new/new[] 只需在其后跟空间类型，不需要传递字节数
// 3. new 后跟的就是空间的类型，因此不需要强转
// 4. new/new[]可以进行初始化
// 5. new的结果不需要判空
// 6. 

int main()
{
	// new 申请单个类型元素的空间---默认情况：new出的空间在堆上
	int* p1 = new int;
	int* p2 = new int(10);
	int* p3 = new int[10];
	int* p4 = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	delete p1;
	delete p2;
	delete[] p3;
	delete[] p4;
	return 0;
}
#endif

#if 0
// 如果没有匹配使用，产生后果?
// 如果申请的是内置类型的空间，不会产生任何后果
void Test1()
{
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = (int*)malloc(sizeof(int));
	delete p1;
	delete[] p2;

	int* p3 = new int;
	int* p4 = new int;
	free(p3);
	delete[] p4;

	int* p5 = new int[10];
	int* p6 = new int[10];
	free(p5);
	delete p6;
}


// 自定义类型
class Test
{
public:
	Test()
	{
		_data = 10;
		_p = new int;
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		delete _p;
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
	int* _p;
};

// 对于自定义类型，只要涉及到[]，必然会崩溃
// new会调用构造函数
// free不会调用析构函数--对象中的资源不会被销毁
void Test2()
{
	//Test* p3 = new Test;
	//Test* p4 = new Test;
	//free(p3);
	//delete[] p4;


	// malloc申请空间时不会调用构造函数--申请的是与对象大小相同的一块内存空间
	//             不能讲该快内存空间看成是一个对象

	Test* p1 = (Test*)malloc(sizeof(Test));
	//Test* p2 = (Test*)malloc(sizeof(Test));
	delete p1;   // 需要调用析构函数清理对象中的资源
	//delete[] p2;



	//Test* p5 = new Test[10];
	//Test* p6 = new Test[10];
	//free(p5);
	//delete p6;
}

int main()
{
	//Test1();
	Test2();
	_CrtDumpMemoryLeaks();
	return 0;
}
#endif

#if 0
// 自定义类型
class Test
{
public:
	Test()
	{
		_data = 10;
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
};

int main()
{
	Test* pt = new Test[10];
	delete[] pt;
	return 0;
}
#endif

#if 0
/*
1. new--->能够将申请空间的信息打印
2. delete---> 能够将释放空间信息打印
*/

void* operator new(size_t size, const char* filename, const char* funName, size_t lineNo)
{
	cout << filename << "-" << funName << "-" << lineNo << "-" << size << endl;
	return malloc(size);
}

void operator delete(void* p, const char* filename, const char* funName, size_t lineNo)
{
	cout << filename << "-" << funName << "-" << lineNo << endl;
	free(p);
}

#define new new(__FILE__, __FUNCDNAME__, __LINE__)

int main()
{
	int* p = new int;
	delete p;
	return 0;
}
#endif

#if 0
struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	int _data;

	void* operator new(size_t n)
	{
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1);
		cout << "memory pool allocate" << endl;
		return p;
	}

	void operator delete(void* p)
	{
		allocator<ListNode>().deallocate((ListNode*)p, 1);
		cout << "memory pool deallocate" << endl;
	}
};

class List
{
public:
	List()
	{
		_head = new ListNode;
		_head->_next = _head;
		_head->_prev = _head;
	}
	~List()
	{
		ListNode* cur = _head->_next;
		while (cur != _head)
		{
			ListNode* next = cur->_next;
			delete cur;
			cur = next;
		}
		delete _head;
		_head = nullptr;
	}
private:
	ListNode* _head;
};

void TestList()
{
	List l;
}

int main()
{
	TestList();
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test(int data)
	{
		_data = 10;
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
};

// placement-new
// 定位new表达式：在已经存在的空间上执行构造函数
// 语法： new(地址) Test(参数);


/*
用来申请空间的new操作符---C++提供的关键字---专门用来申请空间
 1. 调用void* operator new(size_t size)
       {
	       // 调用malloc循环申请 + 空间不足应对措施
	   }
 2. 调用构造函数

 void* operator new(size_t size)是一个函数，一般情况下不需要自己给出
 除非需要定制特殊功能

 定位new表达式：
  new(p) T
    1. void* operator new(size_t size, void* where)
	   {
	        return where;
	   }

	2. 执行构造函数
*/

int main()
{
	Test* pt = (Test*)malloc(sizeof(Test));

	// 只需在pt指向的空间上执行构造函数
	/*
	定位new表达式：调用operator new
	void* operator new(size_t size, void* where)
	{
	     return where;
	}
	*/
	new(pt) Test(10);

	//delete pt;
	pt->~Test();
	free(pt);
	// 需要将pt指向的空间当成对象来用
	return 0;
}
#endif

#if 0
class Test
{
public:
	~Test()
	{
		Test* p = new Test;
		delete p;
	}
};

int main()
{
	Test* pt = new Test;
	delete pt;
	return 0;
}
#endif

#if 0
// 涉及一个类，该类只能在堆上创建对象
class Object
{
public:
	static Object* GetObject(int data)
	{
		return new Object(data);
	}

	~Object()
	{}


	// C++98
//private:
//	Object(const Object& o);

	// C++11
	// 1. 释放new的空间
	// 2. 在默认成员函数后跟上=delete, 删除默认的拷贝构造函数
	Object(const Object& o) = delete;
private:
	Object(int data)
	{}
};


//用户
//Object::Object(const Object&)
//{}

int main()
{
	Object* p= Object::GetObject(10);
	delete p;

	Object o(*p);  // 拷贝构造函数
	return 0;
}
#endif


#if 0
// 64位系统 & 程序按照64位方式编译---指针就是8个字节
#include <iostream>
using namespace std;

int main()
{
	cout << sizeof(int*) << endl;
	void* p = new char[0xfffffffful];
	cout << "new:" << p << endl;
	return 0;
}
#endif

#if 0
// 写一个通用的加法函数？--任意类型都可以处理
// 函数重载
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

char Add(char left, char right)
{
	return left + right;
}


int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	return 0;
}
#endif

#if 0
// 与类型无关
// Add函数模板
//template<class T1, class T2>       // 模板参数列表
//T1 Add(T1 left, T2 right)  // 参数列表
//{
//	cout << typeid(T1).name() << endl;
//	return left + right;
//}

template<class T>       // 模板参数列表
T Add(T left, T right)  // 参数列表
{
	cout << typeid(T).name() << endl;
	return left + right;
}

int main()
{
	// 对函数模板进行实例化
	// 在编译阶段，如果编译器检测到对某个函数模板进行了实例化
	// 对实参的类型进行推演，根据推演的结果，确认模板参数列表中T的实际类型
	// 结合函数模板生成处理具体类型的函数
	// 隐式实例化
	Add(1, 2);  // int, int--T==>int 生成intAdd函数--->Add<int>
	Add(1.0, 2.0); //double, double--> T==>double 生成double Add函数--->Add<double>
	Add('1', '2'); //char char-->T==char 生成char Add函数--->Add<char>
	
	// 模板参数一般不会进行类型转化
	//Add(1, 2.0);   // int double--> T
	Add(1, (int)2.0);


	// 显式实例化---直接指定参数T的实际类型
	// 编译器：可能会进隐式类型转化
	Add<int>(1, 2.0);
	return 0;
}
#endif

#if 0
int Add(int left, int right)
{
	return left + right;
}

template<class T>
T Add(T left, T right)
{
	return left + right;
}

int main()
{
	Add(1, 2);


	// 对函数模板进行隐式实例化
	// 同名函数与函数模板同时存在时，优先使用模板生成的同名函数
	Add<>(1, 2);   


	Add<int>(1, 2);
	return 0;
}
#endif

#if 0
int Add(int left, int right)
{
	return left + right;
}

template<class T1, class T2>
T1 Add(T1 left, T2 right)
{
	return left + right;
}

int main()
{
	Add(1, 2);

	Add(1.0, 2);
	return 0;
}
#endif

#if 0
#include <assert.h>

// 顺序表  链表  栈和队列  二叉树  堆  排序

// typedef int DataType;

//动态类型顺序表
template<class T>
class SeqList
{
public:
	SeqList(size_t capacity = 10)
		: _array(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}

	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}

	// 尾部
	void PushBack(const T& data);
	void PopBack()
	{
		--_size;
	}

	// 任意位置插入和删除
	//void Insert(size_t pos, const T& data);
	//void Erase(size_t pos);

	// 在const类型成员函数中不能修改成员变量
	// 修饰this指针
	size_t size()const
	{
		return _size;
	}

	size_t Capacity()const
	{
		return _capacity;
	}

	bool Empty()const
	{
		return 0 == _size;
	}

	//////////////////////////
	T& operator[](size_t index)
	{
		assert(index < _size);
		return _array[index];
	}

	const T& operator[](size_t index)const
	{
		assert(index < _size);
		return _array[index];
	}

private:
	void _CheckCapacity()
	{
		if (_size == _capacity)
		{
			// 开辟新空间
			T* array = new T[2 * _capacity];

			// 拷贝元素
			// memcpy(array, _array, _size*sizeof(T));
			for (size_t i = 0; i < _size; ++i)
			{
				array[i] = _array[i];
			}

			// 释放旧空间
			delete[] _array;
			_array = array;
			_capacity *= 2;
		}
	}
private:
	T* _array;
	size_t _size;
	size_t _capacity;
};

template<class T>
void SeqList<T>::PushBack(const T& data)
{
	_CheckCapacity();
	_array[_size++] = data;
}


void TestSeqList()
{
	SeqList<int>  s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	cout << s1.size() << endl;
	cout << s1.Capacity() << endl;

	cout << s1[2] << endl;
	s1[2] = 10;

	const SeqList<double>  s2;
	s2[0];
}

int main()
{
	TestSeqList();
	return 0;
}
#endif

int main()
{
	return 0;
}