#include <vector>
class qSort
{
public:
	qSort(std::vector<int>& _v) :v(_v) {}
	void sort(int, int);
private:
	int partition(int ,int);
private:
	std::vector<int> &v;
};

int qSort::partition(int left, int right)
{
	int pivot = v[left];
	int tmp = left;
	while (left != right)
	{
		while (v[right] >= pivot && left < right)
			right--;
		while (v[left] <= pivot && left < right)
			left++;
		if(left < right)
			std::swap(v[left], v[right]);
	}
	std::swap(v[tmp], v[left]);
	return left;
}

void qSort::sort(int left, int right)
{
	if (left > right)
		return;
	int part = partition(left, right);
	sort(left, part - 1);
	sort(part + 1, right);
}

int solution3(const std::vector<int> &v)
{
	std::vector<int> arr = v;
	qSort sortArr(arr);
	sortArr.sort(0, v.size()-1);
	int last = arr[0];
	for (int i = 1; i != arr.size(); i++)
	{
		if (arr[i] == last)
			return last;
		last = arr[i];
	}
	return -1;
}