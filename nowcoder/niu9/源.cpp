#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class UnusualAdd {
public:
	int addAB(int A, int B) {
		// write code here
		int addNoCarry;
		int carry;
		while (B != 0) {
			addNoCarry = A ^ B;
			carry = (A & B) << 1;
			A = addNoCarry;
			B = carry;
		}
		return A;
	}
};
int main()
{
	UnusualAdd u;
	int ret=u.addAB(1,2);
	return 0;
}