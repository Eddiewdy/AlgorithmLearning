#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 120;
struct node
{
    int weight;
    vector<int> child;
}Node[maxn];
int n, m, s;
int path[maxn];
bool cmp(int a, int b)
{
    return Node[a].weight > Node[b].weight;
}
void dfs(int index, int nodenum, int sum)
{
    if(sum > s)
        return;
    if (sum == s)
    {
        if (Node[index].child.size()!=0)
        {
            return;
        }
        for (int i = 0; i < nodenum; i++)
        {
            printf("%d", Node[path[i]].weight);
            if(i < nodenum-1)
                printf(" ");
            else
                printf("\n");
        }
        return;
    }
    for (int i = 0; i < Node[index].child.size(); i++)
    {
        int child = Node[index].child[i];
        path[nodenum] = child;
        dfs(child, nodenum + 1, sum + Node[child].weight);
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Node[i].weight);
    }
    if(n == 0)
    {
        printf("0");
        return 0;
    }
    int parent, child, num;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &parent, &num);
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &child);
            Node[parent].child.push_back(child);
        }
        sort(Node[parent].child.begin(), Node[parent].child.end(), cmp);
    }
    path[0] = 0;
    dfs(0, 1, Node[0].weight);

    return 0;
}
