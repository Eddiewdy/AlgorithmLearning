#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int cbn[maxn], nums[maxn], n, inde = 1;
void inOrder(int root)
{
    if(root > n)return;
    inOrder(root*2);
    cbn[root] = nums[inde++];
    inOrder(root*2+1);
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &nums[i]);
    }
    sort(nums+1, nums+n+1);
    inOrder(1);
    for (int i = 1; i <= n; i++)
    {
        printf("%d", cbn[i]);
        if(i < n)
            printf(" ");
    }
    
    return 0;
}
