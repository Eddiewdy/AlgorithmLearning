#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 110;
struct node
{
    int val;
    int lnode;
    int rnode;
}Node[maxn];
int nums[maxn], n, inde = 0;
void inOrder(int root)
{
    if(root == -1)
        return;
    inOrder(Node[root].lnode);
    Node[root].val = nums[inde++];
    inOrder(Node[root].rnode);
}
void BFS(int root)
{
    queue<int> q;
    q.push(root);
    int num = 0;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        printf("%d", Node[temp].val);
        num++;
        if (num < n)
        {
            printf(" ");
        }
        if(Node[temp].lnode != -1) q.push(Node[temp].lnode);
        if(Node[temp].rnode != -1) q.push(Node[temp].rnode);
    }
    
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    int lnode, rnode;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &lnode, &rnode);
        Node[i].lnode = lnode;
        Node[i].rnode = rnode;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    sort(nums, nums+n);
    inOrder(0);
    BFS(0);
    return 0;
}

