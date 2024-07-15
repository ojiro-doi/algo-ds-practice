#include <stdio.h>

// 二分探索
int binarySearch(int A[], int n, int key)
{
  int left = 0;
  int right = n;
  int mid;

  // 探索範囲が存在するまで繰り返す
  while (left < right)
  {
    mid = (left + right) / 2;
    if (A[mid] == key)
    {
      return 1;
    }
    if (A[mid] < key)
    {
      left = mid + 1;
    }
    else if (key < A[mid])
    {
      right = mid;
    }
  }
  return 0;
}

int main(void)
{
  int n, A[100000], q, key, count = 0;

  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  scanf("%d", &q);
  for (int i; i < q; i++)
  {
    scanf("%d", &key);
    if (binarySearch(A, n, key))
    {
      count++;
    }
  }
  printf("%d\n", count);

  return 0;
}