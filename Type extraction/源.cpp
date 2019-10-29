#define _CRT_SECURE_NO_WARNINGS 1

#include"Type_extraction.h"

template<class T>
void Copy(T* dst, T* src, size_t size, TrueType)
{
	// T的类型：内置类型
	memcpy(dst, src, sizeof(T)*size);
}

template<class T>
void Copy(T* dst, T* src, size_t size, FalseType)
{
	// T的类型：自定义类型---原因：自定义类型中可能会存在浅拷贝
	for (size_t i = 0; i < size; ++i)
		dst[i] = src[i];
}

template<class T>
void Copy(T* dst, T* src, size_t size)
{
	Copy(dst, src, size, TypeTraits<T>::PODTYPE());
}

void TestCopy()
{
	int array1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int array2[10];
	Copy(array2, array1, 10);

	string s1[3] = { "1111", "2222", "3333" };
	string s2[3];
	Copy(s2, s1, 3);
}


