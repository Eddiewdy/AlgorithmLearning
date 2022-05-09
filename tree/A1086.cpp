#include<stack>
#include<cstdio>
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
    root->data = pre[preL];
    int k;
    for (k = inL; k <= inR; k++)
    {
        if(in[k] == pre[preL])
        {
            break;
        }
    }
    int numL = k - inL;
    root->lnode = create_with_pre_in(preL+1, preL + numL, inL, k - 1);
    root->rnode = create_with_pre_in(preL + numL+1, preR, k + 1, inR);
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
void postOrder(node* root)
{
    if(root == NULL)
        return;
    postOrder(root->lnode);
    postOrder(root->rnode);
    printf("%d", root->data);
    num++;
    if(num<n)
    {
        printf(" ");
    }
}
int main(int argc, char const *argv[])
{
    stack<int> s;
    scanf("%d", &n);
    int x, preIndex = 0, inIndex = 0;
    char str[5];
    for (int i = 0; i < 2*n; i++)
    {
        scanf("%s", str);
        if(strcmp(str,"Push") == 0)
        {
            scanf("%d", &x);
            pre[preIndex++]=x;
            s.push(x);
        }else {
            in[inIndex++]=s.top();
            s.pop();
        }
    }
    
    node *root = create_with_pre_in(0, n - 1, 0, n - 1);
    postOrder(root);
    return 0;
}
