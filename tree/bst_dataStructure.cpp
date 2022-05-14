#include<cstdio>
#include<vector>
using namespace std;
#define typename int
struct node
{
    typename data;
    node* lnode;
    node* rnode;
};
void insert(node* &root, int val)
{
    if(root == NULL)
    {
        root = new node;
        root->data = val;
        root->lnode = root->rnode = NULL;
        return;
    }
    if(val >= root->data)
        insert(root->rnode, val);
    else
        insert(root->lnode, val);
}
void preOrder(node* root, vector<int>&vi)
{
    if(root == NULL)
        return;
    vi.push_back(root->data);
    preOrder(root->lnode, vi);
    preOrder(root->rnode, vi);
}
void preOrderMirror(node* root, vector<int> &vi)
{
    if(root == NULL)
        return;
    vi.push_back(root->data);
    preOrderMirror(root->rnode, vi);
    preOrderMirror(root->lnode, vi);
}
void postOrder(node* root, vector<int> &vi)
{
    if(root == NULL)
        return;
    postOrder(root->lnode, vi);
    postOrder(root->rnode, vi);
    vi.push_back(root->data);
}
void postOrderMirror(node* root, vector<int> &vi)
{
    if(root == NULL)
        return;
    postOrderMirror(root->rnode, vi);
    postOrderMirror(root->lnode, vi);
    vi.push_back(root->data);
}
vector<int> origin, pre, preM, post, postM;
int main(int argc, char const *argv[])
{

    int n, data;
    node *root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        origin.push_back(data);
        insert(root, data);
    }
    preOrder(root, pre);
    preOrderMirror(root, preM);
    postOrder(root, post);
    postOrderMirror(root, postM);
    if(origin == pre)
    {
        printf("YES\n");
        for (int i = 0; i < post.size(); i++)
        {
            printf("%d", post[i]);
            if(i < post.size()-1)
                printf(" ");
        }
    } else if(origin == preM)
    {
        printf("YES\n");
        for (int i = 0; i < postM.size(); i++)
        {
            printf("%d", postM[i]);
            if(i < postM.size()-1)
                printf(" ");
        }
    } else {
        printf("NO\n");
    }
    return 0;
}
