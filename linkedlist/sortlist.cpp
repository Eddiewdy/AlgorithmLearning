#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100005;

struct Node
{
    int addr, data, next;
    bool flag;
}node[maxn];
bool cmp(Node a, Node b)
{
    if(a.flag == false || b.flag == false)
    {
        return a.flag > b.flag;
    } else {
        return a.data < b.data;
    }
}
int main(int argc, char const *argv[])
{
    for (int i = 0; i < maxn; i++)
    {
        node[i].flag = false;
    }
    int N, head;
    int addr, data, next;
    scanf("%d%d", &N, &head);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &addr);
        scanf("%d%d", &node[addr].data, &node[addr].next);
        node[addr].addr = addr;
    }
    int count = 0, p = head;
    while(p != -1) {
        node[p].flag = true;
        count++;
        p = node[p].next;
    }
    if(count == 0)
    {
        printf("0 -1");
    } else {
        sort(node, node + maxn, cmp);
        printf("%d %05d\n", count, node[0].addr);
        for (int i = 0; i < count; i++)
        {
            if(i != count-1)
            {
                printf("%05d %d %05d\n", node[i].addr, node[i].data, node[i+1].addr);
            } else {
                printf("%05d %d -1\n", node[i].addr, node[i].data);
            }
        }
    }
    return 0;
}
