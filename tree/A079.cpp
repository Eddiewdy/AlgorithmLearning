#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
const int maxn = 100005;
struct node
{
    double data;
    vector<int> child; 
}Node[maxn];
double p, r, ans;
int n, child;
void dfs(int root, int depth)
{
    if(Node[root].child.size() == 0)
    {
        ans += Node[root].data * pow(1+r,depth);
    }
    for (int i = 0; i < Node[root].child.size(); i++)
    {
        dfs(Node[root].child[i], depth+1);
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        if(t == 0)
        {
            scanf("%lf", &Node[i].data);
        } else {
            for (int j = 0; j < t; j++)
            {
                scanf("%d", &child);
                Node[i].child.push_back(child);
            }
        }
    }
    dfs(0, 0);
    printf("%.1f\n", p*ans);
    return 0;
}


