#include<iostream>
#include<vector>
#include<map>

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;

}
void QuickSort(int input[], int start, int end)
{
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

	if (start <= right)
	{
		QuickSort(input, start, right);
	}
	if (left <= end)
	{
		QuickSort(input, left, end);

	}
}

int main()
{
	const int size = 5;
	int array[size]{ 8,7,2,3,1 };
	int temp[100];
	QuickSort(array, 0, size - 1);
	for (int i = 0; i < size; ++i)
	{
		std::cout << array[i] << " , ";
	}
	// 직사각형의 좌표 3개가 주어질 때, 나머지 한 점의 좌표를 구하시오.
	// 
	// 
	// Test Case 1
	std::vector<std::vector<int>> v = { {1,4}, {3,4}, {3,10} };
	int x = 0;
	int y = 0;



// 직사각형이 되기 위해서는 무조건 x,y의 같은 좌표가 2개씩 있어야 한다.
// 예를들어, 1,4 3,4 3,10 이 주어졌을 때 직사각형이 되기 위해서는 1,10이 필요하다. 문제를 보면 자연수만 이기에 음수는 생각 안해도 된다.
// x좌표 1이 2개, 3이 2개
// y좌표 4가 2개, 10이 2개



	// x 좌표 찾기
	if (v[0][0] == v[1][0])
	{
		x = v[2][0];
	}
	else if (v[0][0] == v[2][0])
	{
		x = v[1][0];
	}
	else
	{
		x = v[0][0];
	}

	// y 좌표 찾기
	if (v[0][1] == v[1][1])
	{
		y = v[2][1];
	}
	else if (v[0][1] == v[2][1])
	{
		y = v[1][1];
	}
	else
	{
		y = v[0][1];
	}

	std::cout << "(" << x << " , " << y << ")" << std::endl;

}