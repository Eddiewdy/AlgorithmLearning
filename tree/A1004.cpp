#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 110;
vector<int> Node[maxn];
vector<int> res;
void bfs(int root)
{
    queue<int> q;
    int depth = 1;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            int temp = q.front();
            q.pop();
            if(Node[temp].size() == 0)
            {
                count++;
                continue;
            }
            for (int j = 0; j < Node[temp].size(); j++)
            {
                q.push(Node[temp][j]);
            }
        }
        res.emplace_back(count);
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
    for (int i = 0; i < res.size()-1; i++)
    {
        printf("%d ", res[i]);
    }
    printf("%d", res.back());
    return 0;
}
