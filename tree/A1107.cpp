#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1010;
int father[N];
int isRoot[N]={0};
int course[N]={0};

int findFather(int x)
{
    if(x == father[x])
        return x;
    else 
        return father[x] = findFather(father[x]);
}

void Union(int a, int b)
{
    int Fa = findFather(a);
    int Fb = findFather(b);
    if(Fa != Fb)
        father[Fa] = Fb;
}

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        father[i] = i;
        isRoot[i] = 0;
    }
}
bool cmp(int a, int b)
{
    return a > b;
}
int main(int argc, char const *argv[])
{
    
    int n, k, h;
    scanf("%d", &n);
    init(n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d:", &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &h);
            if(course[h] == 0)
            {
                course[h] = i;
            }
            Union(i, findFather(course[h]));
        }
    }
    for (int i = 1; i <= n; i++)
    {
        isRoot[findFather(i)]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        /* code */
        if(isRoot[i]!=0)
        {
            ans++;
        }
    }
    printf("%d\n", ans);
    sort(isRoot + 1, isRoot+1+n,cmp);
    for (int i = 1; i <= ans; i++)
    {
        printf("%d", isRoot[i]);
        if(i < ans)
            printf(" ");
    }
    
    return 0;
}
