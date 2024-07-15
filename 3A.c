#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int top;
int MAX = 1000;
int S[1000]; // スタック

// スタックのS[0]は0にして、空にしておく
void initialize()
{
  top = 0;
}

int isEmpty()
{
  return top == 0;
}

int isFull()
{
  return top >= MAX - 1;
}

// 追加
void push(int x)
{
  // オーバーフロー判定
  if (isFull())
  {
    printf("error: stack is full\n");
    return;
  }
  top++;
  S[top] = x;
}

// 取り出す
int pop()
{
  // アンダーフロー判定
  if (isEmpty())
  {
    printf("error: stack is empty\n");
    return -1;
  }
  top--;
  return S[top + 1];
}

int main(void)
{
  int a, b;
  char s[MAX]; // 文字列で入力を受け取る　
  int c = 1;   // 条件(なくてもよい)

  initialize();

  while (scanf("%s", s) != EOF)
  {
    if (s[0] == '+')
    {
      a = pop();
      b = pop();
      push(a + b);
      c++;
    }
    else if (s[0] == '-')
    {
      b = pop();
      a = pop();
      push(a - b); // 順番注意
      c++;
    }
    else if (s[0] == '*')
    {
      a = pop();
      b = pop();
      push(a * b);
      c++;
    }
    else if (s[0] == '/')
    {
      a = pop();
      b = pop();
      push(a / b);
      c++;
    }
    else
    {
      push(atoi(s)); // atoi()は文字列の数をint型にする変換する
    }
    if (c > 100)
    {
      return -1;
    }
  }
  printf("%d\n", pop());

  return 0;
}