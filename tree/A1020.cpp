#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define typename int
int pre[100];
int in[100];
int n;
struct node
{
    typename data;
    node* lnode;
    node* rnode;
};
node* newNode(int v)
{
    node *Node = new node;
    Node->data = v;
    Node->lnode = NULL;
    Node->rnode = NULL;
    return Node;
}

node* create_with_pre_in(int preL, int preR, int inL, int inR)
{
    if(preL > preR)
    {
        return NULL;
    }
    node* root = new node;
    root->data = pre[preR];
    int k;
    for (k = inL; k <= inR; k++)
    {
        if(in[k] == pre[preR])
        {
            break;
        }
    }
    int numL = k - inL;
    root->lnode = create_with_pre_in(preL, preL + numL-1, inL, k - 1);
    root->rnode = create_with_pre_in(preL + numL, preR-1, k + 1, inR);
    return root;
}
int num = 0;
void bfs(node *root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node *now = q.front();
        q.pop();
        printf("%d", now->data);
        num++;
        if(num<n)
        {
            printf(" ");
        }
        if(now->lnode!=NULL)
            q.push(now->lnode);
        if(now->rnode!=NULL)
            q.push(now->rnode);
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &in[i]);
    }
    node *root = create_with_pre_in(0, n - 1, 0, n - 1);
    bfs(root);
    return 0;
}
