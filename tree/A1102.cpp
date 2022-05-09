#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 15;
int n;
struct node
{
    int lchild;
    int rchild;
}Node[maxn];
bool notHead[maxn] = {false};
int findRoot()
{
    for (int i = 0; i < n; i++)
    {
        if (notHead[i] == false)
        {
            return i;
        }
    }
    
}
void postOrder(int root)
{
    if(root == -1)
        return;
    postOrder(Node[root].lchild);
    postOrder(Node[root].rchild);
    swap(Node[root].lchild, Node[root].rchild);
}
int num = 0;
void bfs(int root)
{
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        printf("%d", temp);
        num++;
        if(num < n)
            printf(" ");
        if(Node[temp].lchild != -1)
            q.push(Node[temp].lchild);
        if(Node[temp].rchild != -1)
            q.push(Node[temp].rchild);
    }
}
int num1 = 0;
void inOrder(int root)
{
    if(root==-1)
        return;
    inOrder(Node[root].lchild);
    printf("%d", root);
    num1++;
    if(num1 < n)
        printf(" ");
    inOrder(Node[root].rchild);
}
int strToInt(char c)
{
    if (c == '-')
    {
        return -1;
    } else {
        notHead[c-'0'] = true;
        return c-'0';
    }
}
int main(int argc, char const *argv[])
{
    int lnode, rnode;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%*c%c %c", &lnode, &rnode);
        Node[i].lchild = strToInt(lnode);
        Node[i].rchild = strToInt(rnode);
    }
    int root = findRoot();
    postOrder(root);
    bfs(root);
    printf("\n");
    inOrder(root);
    return 0;
}
