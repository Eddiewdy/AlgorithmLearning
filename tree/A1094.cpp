#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 110;
vector<int> Node[maxn];
int hashtable[maxn] = {0};
void bfs(int root)
{
    queue<int> q;
    int depth = 1;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        hashtable[depth] = size;
        for (int i = 0; i < size; i++)
        {
            int temp = q.front();
            q.pop();
            for (int j = 0; j < Node[temp].size(); j++)
            {
                q.push(Node[temp][j]);
            }
        }
        depth++;
    }
}
int main(int argc, char const *argv[])
{
    int n, m, parent, k, child;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &parent, &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &child);
            Node[parent].emplace_back(child);
        }
    }
    bfs(1);
    int maxlevel = -1, maxval = 0;
    for (int i = 1; i < maxn; i++)
    {
        if(hashtable[i] > maxval)
        {
            maxval = hashtable[i];
            maxlevel = i;
        }
    }
    printf("%d %d", maxval, maxlevel);

    return 0;
}
