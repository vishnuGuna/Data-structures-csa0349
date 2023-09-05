\\insertion in an array
#include <stdio.h>
int insertSorted(int arr[], int n, int key, int capacity)
{
	if (n >= capacity)
		return n;
	arr[n] = key;
	return (n + 1);
}
int main()
{
	int arr[20] = { 12, 16, 20, 40, 50, 70 };
	int capacity = sizeof(arr) / sizeof(arr[0]);
	int n = 6;
	int i, key = 26;
	printf("\n Before Insertion: ");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	n = insertSorted(arr, n, key, capacity);
	printf("\n After Insertion: ");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	return 0;
}

\\delete from an array
#include <stdio.h>
int findElement(int arr[], int n, int key);
int deleteElement(int arr[], int n, int key)
{
	int pos = findElement(arr, n, key);
	if (pos == -1) {
		printf("Element not found");
		return n;
	}
	int i;
	for (i = pos; i < n - 1; i++)
		arr[i] = arr[i + 1];
	return n - 1;
}
int findElement(int arr[], int n, int key)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == key)
			return i;
	return -1;
}
int main()
{
	int i;
	int arr[] = { 10, 50, 30, 40, 20 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 30;
	printf("Array before deletion\n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	n = deleteElement(arr, n, key);
	printf("\nArray after deletion\n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	return 0;
}

\\search operation in an array
#include <stdio.h>
int findElement(int arr[], int n, int key)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == key)
			return i;
	return -1;
}
int main()
{
	int arr[] = { 12, 34, 10, 6, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 40;
	int position = findElement(arr, n, key);
	if (position == -1)
		printf("Element not found");
	else
		printf("Element Found at Position: %d",
			position + 1);
	return 0;
}
