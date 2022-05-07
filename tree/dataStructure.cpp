#include<cstdio>
using namespace std;
#define typename int
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

void search(node* root, int x, int newV)
{
    if(root == NULL)
        return;
    if(root->data == x)
    {
        root->data = newV;
        return;
    }
    search(root->lnode, x, newV);
    search(root->rnode, x, newV);
}

void insert(node* &root, int x)
{
    if(root == NULL)
    {
        root = newNode(x);
        return;
    }
}
int pre[100];
int in[100];
// using pre and in to construct a tree
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
    root->lnode = create_with_pre_in(preL + 1, preL + numL, inL, k - 1);
    root->rnode = create_with_pre_in(preL + numL + 1, preR, k + 1, inR);
    return root;
}
