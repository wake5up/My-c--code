
//给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为
//升序排序
class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		vector<int> v = nums;
		sort(v.begin(), v.end());
		int i = 0, j = nums.size() - 1;
		for (i = 0; i<nums.size(); i++)
		{
			if (nums[i] != v[i])
				break;
		}
		if (i == nums.size())
			return 0;
		for (; j >= 0; j--)
		{
			if (nums[j] != v[j])
				break;
		}
		return j - i + 1;
	}
};

//根据逆波兰表示法，求表达式的值。有效的运算符包括 + , - , * , / 。每个运算对象可以是整数，也可以是
//另一个逆波兰表达式
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack <int> values;
		for (auto& str : tokens)
		{
			if (str == "*" || str == "/" || str == "+" || str == "-")
				resolve(values, str);
			else
				values.push(atoi(str.c_str())); //string to int
		}
		return values.top();
	}
	void resolve(stack <int>& num_stack, string operation)
	{
		int obj1, obj2;
		obj2 = num_stack.top();
		num_stack.pop();
		obj1 = num_stack.top();
		num_stack.pop();
		num_stack.push(calc(obj1, obj2, operation));
	}
	int calc(int obj1, int obj2, string operation)
	{
		switch (operation[0])
		{
		case '+':
			obj1 = obj1 + obj2;
			break;
		case '-':
			obj1 = obj1 - obj2;
			break;
		case '*':
			obj1 = obj1 * obj2;
			break;
		case '/':
			obj1 = obj1 / obj2;
			break;
		}
		return obj1;
	}
};