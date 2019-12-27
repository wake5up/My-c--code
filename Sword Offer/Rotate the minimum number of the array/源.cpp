class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int len = rotateArray.size();
		if (len <= 0)
			return 0;
		int left = 0;
		int right = len - 1;
		int mid = left;
		while (rotateArray[left] >= rotateArray[right])
		{
			if (right - left == 1)
			{
				mid = right;
				break;
			}

			mid = (left + right) / 2;
			if (rotateArray[mid] == rotateArray[right] && rotateArray[mid] == rotateArray[left])
			{
				int ret = rotateArray[left];
				for (int i = left + 1; i <= right; i++)
				{
					if (ret>rotateArray[i])
						ret = rotateArray[i];
				}
				return ret;
			}
			if (rotateArray[mid] >= rotateArray[left])
				left = mid;
			else if (rotateArray[mid] <= rotateArray[right])
				right = mid;
		}
		return rotateArray[mid];
	}
};