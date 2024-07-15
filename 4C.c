#include <stdio.h>
#include <string.h>

#define M 1046527
#define L 14
#define NIL (-1)

char H[M][L];

// 文字列を数値に変換
int getChar(char ch)
{
  if (ch == 'A')
  {
    return 1;
  }
  else if (ch == 'C')
  {
    return 2;
  }
  else if (ch == 'G')
  {
    return 3;
  }
  else if (ch == 'T')
  {
    return 4;
  }
  else
  {
    return 0;
  }
}

// 文字列から数値に変換してkeyを生成
long long getKey(char str[])
{
  long long sum = 0, p = 1, i;
  // strlen():文字列の長さ
  for (i = 0; i < strlen(str); i++)
  {
    sum += p * (getChar(str[i]));
    p *= 5;
  }
  return sum;
}

int h1(int key)
{
  return key % M;
}

int h2(int key)
{
  return 1 + (key % (M - 1));
}

int insert(char str[])
{
  long long key, i, h;
  key = getKey(str);

  // 文字列を格納するまでループ
  for (i = 0;; i++)
  {
    h = (h1(key) + i * h2(key)) % M;
    // 文字列が見つかったとき
    if (strcmp(H[h], str) == 0) // strcmp():文字列の比較
    {
      return 1;
    }
    // ハッシュテーブルの要素の長さが0のとき、文字列を格納する
    else if (strlen(H[h]) == 0) // H[h]はH[h][0]と同じ、先頭アドレスを指す
    {
      strcpy(H[h], str); // strcpy():文字列のコピー
      return 0;
    }
  }
  return 0;
}

int find(char str[])
{
  long long key, i, h;
  key = getKey(str);
  for (i = 0;; i++)
  {
    h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h], str) == 0)
    {
      return 1;
    }
    //空の場合、その位置にはこれ以上文字列は存在しない
    else if (strlen(H[h]) == 0)
    {
      return 0;
    }
  }
  return 0;
}

int main(void)
{
  int n, h;
  // str: 文字列, com: コマンド(命令)
  char str[L], com[9];

  for (int i = 0; i < M; i++)
  {
    H[i][0] = '\0';
  }

  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%s %s", com, str);
    if (com[0] == 'i')
    {
      insert(str);
    }
    else
    {
      if (find(str))
      {
        printf("yes\n");
      }
      else
      {
        printf("no\n");
      }
    }
  }

  return 0;
}