#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
const int maxn = 100005;
vector<int> child[maxn];
double p, r, ans;
int n;
int maxdep = 0, num = 0;
void dfs(int root, int depth)
{
    if(child[root].size() == 0)
    {
        if(depth > maxdep)
        {
            maxdep = depth;
            num = 1;
        }else if(depth == maxdep)
        {
            num++;
        }
        return;
    }
    for (int i = 0; i < child[root].size(); i++)
    {
        dfs(child[root][i], depth+1);
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    int father, root;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &father);
        if(father!=-1)
        {
            child[father].push_back(i);
        }else {
            root = i;
        }
    }
    dfs(root, 0);
    printf("%.2f %d\n", p*pow(1+r,maxdep), num);
    return 0;
}


