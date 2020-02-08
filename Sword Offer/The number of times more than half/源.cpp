//数组中出现次数超过一半的数字

//第一种方法（利用快排中的Partition函数）

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int length = numbers.size();
		if (length <= 0)
			return 0;
		int start = 0;
		int end = length - 1;
		int index = Partition(numbers, start, end);
		int mid = length >> 1;
		while (index != mid)
		{
			if (index>mid)
			{
				end = index - 1;
				index = Partition(numbers, start, end);
			}
			else if (index<mid)
			{
				start = index + 1;
				index = Partition(numbers, start, end);
			}
		}
		if (!Check(numbers, numbers[index]))
			return 0;
		return numbers[index];
	}
	int Partition(vector<int> num, int start, int end)
	{
		int index = start;
		int sum = num[start];
		for (int i = start + 1; i<end; ++i)
		{
			if (num[i]<sum)
			{
				++index;
				swap(num[i], num[index]);
			}
		}
		swap(num[start], num[index]);
		return index;
	}
	bool Check(vector<int> num, int result)
	{
		int count = 0;
		for (int i = 0; i<num.size(); ++i)
		{
			if (num[i] == result)
				++count;
		}
		if (count * 2>num.size())
			return true;
		return false;
	}
};

//第二种方法（计数法）
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size()<=0)
            return 0;
        int result=numbers[0];
        int i=1;
        int count=1;
        for(;i<numbers.size();++i)
        {
            if(count==0)
            {
                result=numbers[i];
                count=1;
            }
            else if(result==numbers[i])
                ++count;
            else
                --count;
        }
        if(!Check(numbers,result))
                result=0;
        return result;
    }
    bool Check(vector<int> num,int result)
    {
        int count=0;
        for(int i=0;i<num.size();++i)
        {
            if(num[i]==result)
                ++count;
        }
        if(count*2>num.size())
            return true;
        return false;
    }
};