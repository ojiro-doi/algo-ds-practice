#include <stdio.h>
#define MAX 100005
// NIL:節点番号として使われない値を設定
#define NIL -1

// p:親 l:左の子 r:右の兄弟
struct Node
{
  int p, l, r;
};

// T:節点のリスト
struct Node T[MAX];
// n:節点の個数 D:深さ
int n, D[MAX];

// 子のリストを表示
void printChildren(int u)
{
  int i, c;
  printf("node %d: ", u);
  printf("parent = %d, ", T[u].p);
  printf("depth = %d, ", D[u]);

  // 親がない
  if (T[u].p == NIL)
  {
    printf("root, ");
  }
  // 最も左の子がない
  else if (T[u].l == NIL)
  {
    printf("leaf, ");
  }
  else
  {
    printf("internal node, ");
  }
  printf("[");

  // 右の子が存在する限り繰り返す
  for (i = 0, c = T[u].l; c != NIL; i++, c = T[c].r)
  {
    if (i != 0)
    {
      printf(", ");
    }
    printf("%d", c);
  }
  printf("]\n");
}

// 節点の深さ(再帰的に全ての節点の深さを求める)
void setDepth(int u, int p)
{
  // 根から求めていく
  D[u] = p;
  if (T[u].r != NIL)
  {
    setDepth(T[u].r, p); // 再帰
  }
  if (T[u].l != NIL)
  {
    setDepth(T[u].l, p + 1); // 再帰
  }
}

int main()
{
  int i, j, d, v, c, l, r;

  // 節点の個数
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    T[i].p = T[i].l = T[i].r = NIL;
  }

  // 木の構築
  for (i = 0; i < n; i++)
  {
    // v:節点番号 d:vの次数
    scanf("%d %d", &v, &d);
    for (j = 0; j < d; j++)
    {
      // c:vの子の節点番号
      scanf("%d", &c);
      // vの最も左の子を代入
      if (j == 0)
      {
        T[v].l = c;
      }
      // vの子の右兄弟を順に代入
      else
      {
        T[l].r = c;
      }
      l = c;
      T[c].p = v;
    }
  }

  // 根を探す r:根の節点
  for (i = 0; i < n; i++)
  {
    if (T[i].p == NIL)
    {
      r = i;
    }
  }

  setDepth(r, 0);

  for (i = 0; i < n; i++)
  {
    printChildren(i);
  }

  return 0;
}