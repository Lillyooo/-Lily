#include<stdio.h>
#include<stdlib.h>

const int n = 8;
int A[n] = { 8,7,6,5,4,3,2,1 };
int B[n];
void Merge(int A[],int low, int mid, int high)
{
	int x=low, y=low, z=mid+1;
	while (x<=mid&&z<=high)
	{
		if (A[x] < A[z])B[y++] = A[x++];
		else B[y++] = A[z++];
	}
	while (x <= mid)
	{
		B[y++] = A[x++];
	}
	while (z<=high)
	{
		B[y++] = A[z++];
	}
	for (y = low; y <= high; y++)
	{
		A[y] = B[y];
	}
}

void MergeSort(int A[],int low,int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(A,low, mid);
		MergeSort(A,mid + 1, high);
		Merge(A,low, mid, high);
	}
}


int main() 
{	
	MergeSort(A,0,n-1);
	for (int i = 0; i < n; i++) 
	{
		printf("%d ",A[i]);
	}
}
