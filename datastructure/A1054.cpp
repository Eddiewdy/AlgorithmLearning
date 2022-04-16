#include<cstdio>
#include<map>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, m;
    int num;
    scanf("%d %d", &n, &m);
    map<int, int> count;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &num);
            if(count.find(num) != count.end())
                count[num]++;
            else
                count[num] = 1;
        }
        
    }
    int k = 0, max = 0;
    for (map<int, int>::iterator it = count.begin(); it != count.end(); it++)
    {
        if(it->second > max)
        {
            max = it->second;
            k = it->first;
        }
    }
    printf("%d\n", k);
    return 0;
}
