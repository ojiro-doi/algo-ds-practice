#include <stdio.h>
#include <math.h>

int isPrime(int x)
{
  if (x == 2)
  {
    return 1;
  }

  if (x < 2 || x % 2 == 0)
  {
    return 0;
  }

  for (int p = 3; p <= sqrt(x); p += 2)
  {
    if (x % p == 0)
    {
      return 0;
    }
  }
  return 1;
}

int main(void)
{
  int n;
  scanf("%d", &n);

  if (n < 1 || n > 100000)
  {
    return -1;
  }

  int a[n];
  for (int i = 0; i < n; i++)
  {
    a[i] = 0;
  }

  for (int i = 0; i < n; i++)
  {
    scanf('%d',&a[i]);
  }

  int count = 0;
  for (int i = 0; i < n; i++)
  {
    //true(１である)のとき
    if (isPrime(a[i]) == 1)
    {
      count++;
    }
  }

  printf("%d\n", count);
  return 0;
}