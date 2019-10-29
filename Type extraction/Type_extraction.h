#pragma once

#include<iostream>
using namespace std;
#include<string>

//来自自定义类型
struct TrueType
{};

// 对应自定义类型
struct FalseType
{};

//隐示实例化
template<class T>
struct TypeTraits
{
	typedef FalseType PODTYPE;  // plain old data
};

//显示实例化
template<>
struct TypeTraits<char>
{
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<short>
{
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<int>
{
	typedef TrueType PODTYPE;
};
template<>
struct TypeTraits<long>
{
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<long long>
{
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<float>
{
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<double>
{
	typedef TrueType PODTYPE;
};

void TestCopy();