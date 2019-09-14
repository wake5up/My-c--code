#include <iostream>
using namespace std;


#if 0
// 类
struct Student
{
	// 成员方法 || 行为
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudent()
	{
		cout << _name << ":" << _gender << ":" << _age << endl;
	}

	// 成员变量 || 属性
	char _name[20];
	char _gender[3];
	int _age;
};


int main()
{
	Student s;
	s.SetStudentInfo("Peter", "男", 29);
	s.PrintStudent();

	return 0;
}
#endif

// 面相对象程序：封装  继承  多态
// 封装：将一个事物的内部实现细节隐藏起来，提供一个公有接口让对象之间进行交互

// C++实现封装：类(通过类将对象的属性和行为包装在一起)
//   访问权限：private  protected  public
// public: 被public修饰的成员，可以直接在类外被访问
// protected/private: 不能直接在类外进行访问

//int _age = 10;

// void SetStudentInfo(char* name)
// {}

#if 0
class Student
{
public:
	// 成员方法 || 行为
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudent()
	{
		cout << _name << ":" << _gender << ":" << _age << endl;
	}

private:
	// 成员变量 || 属性
	char _name[20];
	char _gender[3];
	int _age;
};


int g_a = 10;
int main()
{
	Student s;
	s.SetStudentInfo("Peter", "男", 29);
	s.PrintStudent();

	// s._age = 30;
	cout << g_a << endl;
	return 0;
}
#endif

#if 0
struct Student
{
public:
	// 成员方法 || 行为
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudent()
	{
		cout << _name << ":" << _gender << ":" << _age << endl;
	}

private:
	// 成员变量 || 属性
	char _name[20];
	char _gender[3];
	int _age;
};

int main()
{
	Student s1,s2,s3;
	cout << sizeof(s1) << endl;

	s1.SetStudentInfo("Peter", "男", 29);
	s2.SetStudentInfo("静静", "女", 30);
	s3.SetStudentInfo("summer", "公", 4);


	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	return 0;
}
#endif

#if 0
class A
{
public:
	void TestFun()
	{}
};


// 空类的大小？主流编译器中空类的大小是1
class B
{};


// 
int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;

	B b1, b2, b3;


	return 0;
}
#endif

#if 0
struct Student
{
	char _name[20];
	char _gender[3];
	int _age;
};

void SetStudentInfo(Student* ps, char* name, char* gender, int age)
{
	strcpy(ps->_name, name);
	strcpy(ps->_gender, gender);
	ps->_age = age;
}

void PrintStudent(Student* ps)
{
	printf("%s %s %d", ps->_name, ps->_gender, ps->_age);
}
#endif




#if 0
class Student
{
public:
	void SetStudentInfo(char* name, char* gender, int age)
	{
		// Student* const
		//this = nullptr;
		cout << this << endl;
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		this->_age = age;
	}

	void PrintStudent()
	{
		cout << this->_name << ":" << this->_gender << ":" << this->_age << endl;
	}

	// 不定参数
	void TestFunc(...)
	{
		cout << this << endl;
	}

private:
	// 成员变量 || 属性
	char _name[20];
	char _gender[3];
	int _age;
};
#endif

/*
女朋友
未来女朋友的一些基本信息
做饭 & 


1. 先识别类名
2. 识别类中的成员变量
3. 识别类中的成员函数并且对类中的成员函数进行改写
*/
#if 0
class Student
{
public:
	/*
	void SetStudentInfo(Student* const this, char* name, char* gender, int age)
	{
	strcpy(this->_name, name);
	strcpy(this->_gender, gender);
	this->_age = age;
	}
	*/
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	/*
	void PrintStudent(Student* const this)
	{
	cout << this->_name << ":" << this->_age << endl;
	}
	*/
	void PrintStudent()
	{
		cout << _name << ":" << _age << endl;
	}

private:
	// 成员变量 || 属性
	char _name[20];
	char _gender[3];
	int _age;
};


int main()
{
	//cout << this << endl;
	Student s1, s2, s3;
	s1.TestFunc(10);

	cout << &s1 << endl;
	s1.SetStudentInfo("Peter", "男", 29);
	
	cout << &s2 << endl;
	s2.SetStudentInfo("静静", "女", 30);
	
	cout << &s3 << endl;
	s3.SetStudentInfo("summer", "公", 4);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	return 0;
}
#endif

class A
{
public:
	void PrintA()
	{
		cout << this << endl;
		cout << this->_a << endl;
	}

	void Show()
	{
		cout << this << endl;
		cout << "Show()" << endl;
	}
private:
	int _a;
};

int main()
{
	A* p = NULL;
	p->Show();
	p->PrintA();
	

	return 0;
}


