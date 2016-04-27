#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//堆排序
#include<assert.h>

void AdjustDown(int* a,int parent, int size)
{
	int child = 2 * parent + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child] < a[child + 1])
		{
			++child;
		}
		if (a[child]>a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}


void Print(int*a, int size)
{
	cout << "升序序列为："<<endl;
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}


void HeapSort(int* a,int size)
{
	assert(a);
	
	//建成最大堆
	for (int i = (size - 2) / 2; i >=0; i--)
	{
		AdjustDown(a,i, size);
	}

	//交换顺序
	for (int i = 0; i < size; i++)
	{
		swap(a[0], a[size - i - 1]);
		AdjustDown(a, 0, size-i-1);
	}	
}

 
void Test()
{
	int arr[] = { 12, 2, 10, 4, 6, 8, 54, 67,100,34,678, 25, 178 };
	int size = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, size);	
	Print(arr,size);
}


int main()
{
	Test();
	system("pause");
	return 0;
}