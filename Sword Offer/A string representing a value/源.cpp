//表示数值的字符串
class Solution {
public:
	bool isNumeric(char* str)
	{
		if (str == nullptr)
			return false;
		if (*str == '+' || *str == '-')
			++str;
		if (*str == '\0')
			return false;
		int dot = 0, num = 0, nume = 0;
		while (*str != '\0')
		{
			if (*str >= '0'&&*str <= '9')
			{
				++str;
				num = 1;
			}
			else if (*str == '.')
			{
				if (dot>0 || nume>0)
					return false;
				++str;
				dot = 1;
			}
			else if (*str == 'e' || *str == 'E')
			{
				if (num == 0 || nume>0)
					return false;
				++str;
				nume = 1;
				if (*str == '+' || *str == '-')
				{
					++str;
				}
				if (*str == '\0')
					return false;
			}
			else
				return false;
		}
		return true;
	}

};