 #include <iostream>
 using namespace std;


// 函数重载：必须在相同的作用域，函数名字必须相同，参数列表(个数、类型、类型次序)
// 如果两个函数仅仅是返回值类型不同，不能构成重载
 /*
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}


int main()
{
	// 编译器在编译阶段，根据对所传递实参类型推演,根据推演的实际结果选择调用
	// 对应类型的重载函数
	Add(1, 2);   // int int
	Add(1.0, 2.0); // double double
	
	Add(1, (int)2.0);
	// int, double---尝试对实参进行隐式类型转化int int
	//                                     double  double
	return 0;
}
*/

#if 0
 // 参数列表不同：参数个数、参数类型不同 类型的次序不同
 void TestFunc()
 {}

 void TestFunc(int a)
 {}

 void TestFunc(double a)
 {}

 void TestFunc(int a, double b)
 {}

 void TestFunc(double a, int b)
 {}

 int TestFunc(int a)
 {
	 return a;
 }

 int main()
 {
	 return 0;
 }
#endif

#if 0

// C语言不支持函数重载
// 原因：C语言编译器对函数名字的修饰规则---只是在函数名字前增加_
// int Add(int left, int right);   // _Add
//  {
// 	 return left + right;
//  }

 double Add(double left, double right);  // _Add
//  {
// 	 return left + right;
//  }

 int main()
 {
	 Add(1.0, 2.0); 
	 return 0;
 }
#endif

#if 0
 // vs 命名格式
 // C++编译器对函数名字修饰规则---将参数的类型增加到最终的名字中
 // ?Add@@YAHHH@Z   --- 猜测：H--->int
// int Add(int left, int right);
//  {
// 	 return left + right;
//  }
// 
 // ?Add@@YANNN@Z  ---猜测：N--->double
 double Add(double left, double right);
//  {
// 	 return left + right;
//  }

 // ?Add@@YAHHN@Z
 int Add(int left, double right);

 int main()
 {
	 //Add(1, 2);   // ?Add@@YAHHH@Z
	 // Add(1.0, 2.0);  // ?Add@@YANNN@Z
	 Add(1, 2.0);  //
	 return 0;
 }
#endif

#if 0
 // int Add(int left, int right);  ?Add@@YAHHH@Z
 // C++写了一个库： C++工程中使用   C工程 _Add
 extern "C" int Add(int left, int right);

 int main()
 {
	 Add(1, 2);
	 return 0;
 }
#endif

#if 0
 // 同名的无参函数和全缺省函数不要同时存在
 void TestFunc()
 {}

 void TestFunc(int a = 10)
 {}

 int main()
 {
	 //TestFunc();
	 return 0;
 }
#endif

#if 0
 // C语言中：函数传参有几种方式？
 // 传值和传址
 // 传值：
 // 优点：函数的副作用不会影响外部实参
 // 缺点：如果想要通过形参改变外部实参，传值做不到
 //      如果实参比较大，形参的拷贝---传参效率比较低，比较浪费空间
 void Swap(int left, int right)
 {
	 cout << &left << " " << &right << endl;

	 int temp = left;
	 left = right;
	 right = temp;
 }

 // 传址：
 // 优点：可以通过形参改变外部的实参，传参效率比较高
 // 缺陷：函数副作用会影响外部的实参，安全性不高，可读性差
 void Swap(int* pa, int* pb)
 {
	 int temp = *pa;
	 *pa = *pb;
	 *pb = temp;
 }

 int main()
 {
	 int a = 10;
	 int b = 20;

	 cout << &a << " " << &b << endl;

	 Swap(a, b);
	 Swap(&a, &b);
	 return 0;
 }
#endif

#if 0
 // 别名：C++中的引用
 void Swap(int left, int right)
 {
	 int temp = left;
	 left = right;
	 right = temp;
 }

 int main()
 {
	 int a = 10;
	 int b = 20;
	 Swap(a, b);
	 return 0;
 }
#endif

#if 0
 void Swap(int& left, int& right)
 {
	 int temp = left;
	 left = right;
	 right = temp;
 }

 int main()
 {
	 int a = 10;
	 int b = 20;
	 Swap(a, b);

	 int& ra = a;

	 ra = 100;
	 return 0;
 }
#endif

#if 0
 int main()
 {
	 int a = 10;
	 int& ra = a;
	 int& rra = a;
	 int& rrra = ra;

	 if (1)
	 {
		 int& rb = a;
	 }

	 rrra = 100;
	 return 0;
 }
#endif

#if 0
 int main()
 {
	 int a = 10;
	 int& ra = a;

	 int b = 20;
	 ra = b;
	 return 0;
 }
#endif

#if 0
 // const 类型引用
 int main()
 {
	 const int a = 10;
	 const int& ra = a;

	 const int& rb = 100;

	 double d = 12.34;
	 const int& rd = d;

	 d = 56.78;

	 return 0;
 }
#endif

#if 0
 // 采用引用做函数的参数
 void Swap(int& left, int& right)
 {
	 int temp = left;
	 left = right;
	 right = temp;
 }

 // 注意： 如果想要通过形参改变外部实参，形参类型：普通类型引用
 //       如果不想通过形参改变外部实参，形参类型：const类型引用

 // 引用作用
 int main()
 {
	 int a = 10;
	 int& ra = a;

	 return 0;
 }
#endif

#if 0
 // 引用：可以作为函数的返回值
 int g_a = 0;

 int& Add(int left, int right)
 {
	 int ret = left + right;
	 return ret;
 }

 int Sub(int left, int right)
 {
	 int ret = left - right;
	 return ret;
 }

 // 注意：不要返回函数栈上的空间


 int main()
 {
	 //
	 int& r = Add(1, 2);
	 //Sub(10, 5);
	 Add(3, 4);
	 return 0;
 }
#endif

#if 0
 int& TestFunc(int& ra)
 {
	 return ra;
 }

 int main()
 {
	 int a = 10;
	 int& rra = TestFunc(a);
	 return 0;
 }
#endif


#if 0
 // 传参效率比较：传值最慢(值得拷贝)，传地址和传引用效率几乎一样
#include <time.h>
 struct A
 {
	 int a[10000];
 };

 void TestFunc1(A* a)
 {}

 void TestFunc2(A& a)
 {}

 void TestRefAndValue()
 {
	 A a;
	// 以值作为函数参数
	size_t begin1 = clock();
	 for (size_t i = 0; i < 10000; ++i)
		 TestFunc1(&a);
	 size_t end1 = clock();

	 // 以引用作为函数参数
	 size_t begin2 = clock();
	 for (size_t i = 0; i < 10000; ++i)
		 TestFunc2(a);
	 size_t end2 = clock();
	 // 分别计算两个函数运行结束后的时间
	 cout << "TestFunc1(int*)-time:" << end1 - begin1 << endl;
	 cout << "TestFunc2(int&)-time:" << end2 - begin2 << endl;
 }

 // 运行多次，检测值和引用在传参方面的效率区别
 int main()
 {
	 for (int i = 0; i < 10; ++i)
	 {
		 TestRefAndValue();
	 }
	 return 0;
 }
#endif


#if 0
 // 引用和指针有什么区别？
 void Swap(int* pa, int* pb)
 {
	 int temp = *pa;
	 *pa = *pb;
	 *pb = temp;
 }

 void Swap(int& ra, int& rb)
 {
	 int temp = ra;
	 ra = rb;
	 rb = temp;
 }

 int main()
 {
	 int a = 10;
	 int b = 20;

	 int* pa = &a;
	 *pa = 20;

	 int& ra = a;
	 ra = 20;

	 Swap(&a, &b);
	 Swap(a, b); // 编译器在底层的实际操作：Swap(&a, &b);
	 return 0;
 }
#endif

#if 0
 int main()
 {

	 int* pa;

	 int a = 10;
	 //int& ra;

	 int b = 20;

	 pa = &a;
	 pa = &b;

	 int& ra = a;
	 ra++;
	 //r = b;

	 char c = 'c';
	 char* pc = &c;
	 char& rc = c;
	 cout << sizeof(pc) << endl;
	 cout << sizeof(rc) << endl;

	 int** p;

	 // 右值引用
	 const int&& r = 10;
	 return 0;
 }
#endif

#if 0
 // 代码能否通过编译？ 能否正常运行？ 可能会在那块出错？
 void Swap(int& ra, int& rb)
 {
	 int temp = ra;
	 ra = rb;
	 rb = temp;
 }

 int main()
 {
	 int a = 10;
	 int* pb = NULL;
	 //*pb = 100;

	 Swap(a, *pb);
	 return 0;
 }
#endif


#if 0
 // C++中，被const修饰的变量---->常量
 // 具有宏替换的特性--->在编译节点进行替换--->会参与类型检测
 int main()
 {
	 const int a = 10;

	 int* pa = (int*)&a;
	 *pa = 100;

	 printf("%d", /*a*/ 10);
	 printf("%d", *pa);

	 return 0;
 }
#endif


#if 0
 // 宏函数缺陷：副作用  在预处理节点替换，不会进行类型检测  不可以调试
                
#define MAX(a, b)   ((a) > (b)? (a) : (b))

 int main()
 {
	 int a = 10;
	 int b = 20;

	 cout << MAX(++b, a);
	 return 0;
 }
#endif

#if 0
 inline int Add(int left, int right)
 {
	 //Add(left, right);
	 return left + right;
 }

 int main()
 {
	int a = 10;
	int b = 20;
	int c = Add(a, b);
	cout << 30 << endl;
	 return 0;
 }
#endif

#if 0
//#include "a.h"

 inline int Add(int left, int right)
 {
	 return left + right;
 }

 int main()
 {
	 Add(1, 2);
	 return 0;
 }
#endif


#if 0
 // 编译器在编译阶段，根据提供的初始化表达式实际类型，来确定变量的类型
 int main()
 {
	 auto a = 10;
	 auto b = 12.34;
	 //auto c;
	 cout << typeid(a).name() << endl;
	 cout << typeid(b).name() << endl;
	 return 0;
 }
#endif

#if 0
#include <map>
#include <string>

 int main()
 {
	 std::map<std::string, std::string> m{ { "apple", "苹果" }, { "peach", "桃子" } };

	 // C++98语法
	 //std::map<std::string, std::string>::iterator it = m.begin();
	 auto it = m.begin();
	 while (it != m.end())
	 {
		 cout << it->first << "-->" << it->second << endl;
		 ++it;
	 }
	 cout << endl;
	 return 0;
 }
#endif

#if 0
 int main()
 {
	 int a = 10;
	 auto pa1 = &a;
	 auto* pa2 = &a;

	 cout << typeid(pa1).name() << endl;
	 cout << typeid(pa2).name() << endl;


	 auto ra = a;
	 ra = 20;

	 auto& rra = a;
	 rra = 30;

	 return 0;
 }
#endif

#if 0
 int main()
 {
	 auto a = 1, b = 2.0, c = 3;

	 return 0;
 }
#endif


//  void TestFunc(auto a)
//  {}

#if 0
 int main()
 {
	 int arr1[10] = { 1, 2, 3 };
	 //auto arr2[] = { 1, 2, 3 };
	 return 0;
 }
#endif


#if 0
 int main()
 {
	 // [array, array+sizeof(array) / sizeof(array[0]) );
	 /*
	 int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	 for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		 array[i] *= 2;

	 for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		 cout<<array[i]<<" ";
	 cout << endl;
	 */


	 // 范围for循环
	 int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	 for (auto& e : array)
		 e *= 2;

	 for (auto e : array)
		 cout << e << " ";
	 cout << endl;

	 return 0;
 }
#endif

 void TestFunc(int* array)
 {
	 for (auto e : array)
		 cout << e << " ";
 }


 int main()
 {
	 int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	 TestFunc(array);
	 return 0;
 }



