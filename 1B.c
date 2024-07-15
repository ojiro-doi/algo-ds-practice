#include <stdio.h>

int gcd(int x, int y)
{
  // xがyより小さい場合、xとyを交換
  if (x < y)
  {
    int temp = x;
    x = y;
    y = temp;
  }

  while (y != 0)
  {
    int a;
    a = x % y;
    x = y;
    y = a;
  }
  return x;
}

int main(void)
{
  int x, y;
  scanf("%d %d", &x, &y);

  printf("%d\n", gcd(x, y));

  return 0;
}