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



