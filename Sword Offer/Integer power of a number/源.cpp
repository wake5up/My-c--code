//数值的整数次幂
class Solution {
public:
	double Power(double base, int exponent) {
		bool flag = false;
		if ((base - 0.0<1e-8) && exponent<0)
		{
			flag = true;
			return 0.0;
		}
		unsigned int uiExponent = (unsigned int)exponent;
		if (exponent<0)
			uiExponent = (unsigned int)-exponent;
		double result = Sum(base, uiExponent);
		if (exponent<0)
			result = 1.0 / result;
		return result;
	}
	double Sum(double base, int exponent)
	{
		if (exponent == 0)
			return 1;
		else if (exponent == 1)
			return base;
		double ret = Sum(base, exponent >> 1);
		ret *= ret;
		if (exponent & 1 == 1)
			ret *= base;
		return ret;
	}
};