#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int M = 26 * 26 * 26 * 10 + 1;
vector<int> select[M];

int Hash(char s[])
{
    int id = 0;
    for (int i = 0; i < 3; i++)
    {
        id = id * 10 + s[i] - 'A';
    }
    id = id * 10 + s[3] - '0';
    return id;
}

int main(int argc, char const *argv[])
{
    char name[5];
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        int course, student;
        scanf("%d%d", &course, &student);
        for (int j = 0; j < student; j++)
        {
            scanf("%s", name);
            int id = Hash(name);
            select[id].push_back(course);
        }
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%s", name);
        int sid = Hash(name);
        sort(select[sid].begin(), select[sid].end());
        printf("%s %d", name, select[sid].size());
        for (int j = 0; j < select[sid].size(); j++)
        {
            printf(" %d", select[sid][j]);
        }
        printf("\n");
    }
    
    return 0;
}
