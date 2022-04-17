#include<queue>
#include<cstdio>
using namespace std;
const int maxn = 1010;
struct mice
{
    int rank;
    int weight;
}mice[maxn];
queue<int> q;
int main(int argc, char const *argv[])
{
    int np, ng;
    scanf("%d%d", &np, &ng);
    for (int i = 0; i < np; i++)
    {
        scanf("%d", &mice[i].weight);
    }
    for (int i = 0; i < np; i++)
    {
        int order;
        scanf("%d", &order);
        q.push(order);
    }
    int temp = np, group;
    while (q.size() != 1)
    {
        if (temp % ng == 0)
        {
            group = temp / ng;
        } else {
            group = temp / ng + 1;
        }
        for (int i = 0; i < group; i++)
        {
            int k = q.front();
            for (int j = 0; j < ng; j++)
            {
                if(i * ng + j >= temp)
                {
                    break;
                }
                int front = q.front();
                if(mice[front].weight > mice[k].weight)
                {
                    k = front;
                }
                mice[front].rank = group + 1;
                q.pop();
            }
            q.push(k);
        }
        temp = group;
    }
    mice[q.front()].rank = 1;
    for (int i = 0; i < np; i++)
    {
        printf("%d", mice[i].rank);
        if(i < np-1)
        {
            printf(" ");
        }
    }
    
    return 0;
}

