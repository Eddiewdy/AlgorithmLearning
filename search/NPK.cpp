#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
int n,p,k, maxsum = -1;
vector<int> fac, ans, temp;
int P(int x)
{
    int ans = 1;
    for (int i = 0; i < p; i++)
    {
        ans = ans * x;
    }
    return ans;
}
void init()
{
    int temp = 0;
    int i = 0;
    while(temp <= n)
    {
        fac.push_back(temp);
        temp = P(++i);
        // printf("%d\n", temp);
    }
}
void dfs(int index, int nowK, int sum, int facsum)
{
    if(sum == n && nowK == k)
    {
        if(facsum > maxsum)
        {
            maxsum = facsum;
            ans = temp;
        }
        return;
    }
    if(sum > n || nowK > k)
        return;
    if(index - 1 >= 0)
    {
        temp.push_back(index);
        dfs(index, nowK + 1, sum + fac[index], facsum + index);
        temp.pop_back();
        dfs(index - 1, nowK, sum, facsum);
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &n, &k, &p);
    init();
    // printf("%d", fac.size());
    dfs(fac.size()-1, 0, 0, 0);
    if(maxsum == -1)
        printf("Impossible\n");
    else {
        printf("%d = %d^%d", n, ans[0], p);
        for (int i = 1; i < ans.size(); i++)
        {
            printf(" + %d^%d", ans[i], p);
        }
        
    }
    return 0;
}
