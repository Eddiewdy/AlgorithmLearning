#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 100005;
const int table = 1000010;
struct Node
{
    int addr, data, next;
    int order;
}node[maxn];
// bool isExist[table] = {false};
set<int> s;
bool cmp(Node a, Node b)
{
    return a.order < b.order;
}
int main(int argc, char const *argv[])
{
    // memset(isExist, false, sizeof(isExist));
    for (int i = 0; i < maxn; i++)
    {
        node[i].order = maxn * 2;
    }
    int n, begin, address;
    scanf("%d%d", &begin, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &address);
        scanf("%d%d", &node[address].data, &node[address].next);
        node[address].addr = address;
    }
    int valid = 0, removed = 0;
    int p = begin;
    while(p != -1)
    {
        if(s.find(abs(node[p].data)) == s.end())
        {
            // isExist[abs(node[p].data)] = true;
            s.insert(abs(node[p].data));
            node[p].order = valid++;
        } else {
            node[p].order = maxn + removed++;
        }
        p = node[p].next;
    }
    sort(node, node + maxn, cmp);
    int count = valid + removed;
    for (int i = 0; i < count; i++)
    {
        if (i != valid-1 && i != count-1)
        {
            printf("%05d %d %05d\n", node[i].addr, node[i].data, node[i + 1].addr);
        } else {
            printf("%05d %d -1\n", node[i].addr, node[i].data);
        }
    }
    
    return 0;
}

