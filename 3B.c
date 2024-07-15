#include <stdio.h>
#include <string.h>
#define MAX 100005

// プロセス(問題文)を表す構造体
typedef struct pp
{
  char name[100];
  int time;
} P;

P Q[MAX];
int head;
int tail;
int n;

int isEmpty()
{
  return head == tail;
}

int isFull()
{
  return head == (tail + 1) % MAX;
}

void enqueue(P x)
{
  if (isFull())
  {
    printf("error: queue is full\n");
    return;
  }

  Q[tail] = x;
  tail = (tail + 1) % MAX;
}

P dequeue()
{
  if (isEmpty())
  {
    printf("error: queue is empty\n");
  }
  P x = Q[head];
  head = (head + 1) % MAX;
  return x;
}

int min(int a, int b)
{
  return a < b ? a : b;
}

int main(void)
{
  int total_time = 0, c;
  int q;
  P u;
  scanf("%d %d", &n, &q);

  // キューに追加する
  for (int i = 1; i <= n; i++)
  {
    scanf("%s", Q[i].name);
    scanf("%d", &Q[i].time);
  }
  head = 1; // 0空けておく(常に一つの席を空けておく)
  tail = n + 1;

  while (!isEmpty())
  {
    u = dequeue();
    c = min(q, u.time); // クオンタムかプロセス処理時間
    
    u.time -= c;
    total_time += c;

    // プロセスがまだ完了していないとき
    if (u.time > 0)
    {
      enqueue(u);
    }
    // プロセスが完了したとき
    else
    {
      printf("%s %d\n", u.name, total_time);
    }
  }
}