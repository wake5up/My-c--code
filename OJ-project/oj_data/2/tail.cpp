#ifndef CompileOnline
// 这是为了编写用例的时候有语法提示. 实际线上编译的过程中这个操作是不生效的.
#include "header.cpp"
#endif

void Test1() 
{
    int num=121;
    bool ret = Solution().isPalindrome(num);
    if (ret) 
    {
        std::cout << "Test1 ok!" << std::endl; 
    } 
    else 
    {
        std::cout << "Test1 failed!" << std::endl;          
    }
}

void Test2() 
{
    int num=-121;
    bool ret = Solution().isPalindrome(num);
    if (!ret) 
    {
        std::cout << "Test2 ok!" << std::endl;
    } 
    else 
    {
        std::cout << "Test2 failed!" << std::endl;
    }
}

int main() 
{
    Test1();
    Test2();
    return 0;
}
