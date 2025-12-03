#include <iostream>


void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;

}
void QuickSort(int input[], int start, int end)
{
	if (end <= start)
	{
		return;
	}
	int left = start;
	int right = end;
	int pivot = input[(start + end) / 2];

	do {
	

		while (input[left] < pivot)
		{
			left++;
		}
		while (input[right] > pivot)
		{
			right--;
		}
		if (left <= right)
		{
			Swap(input[left], input[right]);
			left++;
			right--;
		}


	} while (left <= right);

	if (start < right)
	{
		QuickSort(input, start, right);
	}
	if (left < end)
	{
		QuickSort(input, left, end);
	}

}

void Merge(int input[], int start, int half, int end, int temp[])
{
	int i = start;
	int j = half + 1;
	int tempIndex = 0;


	while (i <= half && j <= end)
	{
		if (input[i] < input[j])
		{
			temp[tempIndex++] = input[i++];
		}
		else
		{
			temp[tempIndex++] = input[j++];
		}
	}

	while (i <= half)
	{
		temp[tempIndex++] = input[i++];
	}
	while (j <= end)
	{
		temp[tempIndex++] = input[j++];
	}

	int tempIndex2 = 0;
	for (int i = start; i <= end; ++i)
	{
		input[i] = temp[tempIndex2++];
	}
	
}

void MergeSort(int input[], int start, int end, int temp[])
{
	if (start >= end)
	{
		return;
	}

	int half = (start + end) / 2;
	
	MergeSort(input, start, half, temp);
	MergeSort(input, half + 1, end, temp);
	Merge(input, start, half, end, temp);
}
int main()
{
	const int size = 5;
	int array[size]{ 8,7,2,3,1 };
	int temp[100];
	//QuickSort(array, 0, size - 1);
	MergeSort(array, 0, size - 1, temp);


	for (int i = 0; i < size; ++i)
	{
		std::cout << array[i] << " , ";
	}
}
