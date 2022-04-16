#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
const int N = 51;
set<int> st[N];
void compare(int x, int y)
{
    int totalnum = st[y].size();
    int commonnum = 0;
    for (set<int>::iterator it = st[x].begin(); it != st[x].end(); it++)
    {
        if(st[y].find(*it) != st[y].end())
        {
            commonnum++;
        } else {
            totalnum++;
        }
    }
    printf("%.1f%\n", commonnum * 100.0 / totalnum);
}

int main(int argc, char const *argv[])
{
    int n, m, num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &num);
            st[i + 1].insert(num);
        }
    }
    int q, st1,st2;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &st1, &st2);
        compare(st1, st2);
    }
    
    return 0;
}
