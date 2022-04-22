#include<cstdio>
#include<queue>
using namespace std;
struct node
{
    int x, y, z;
}Node;
int n, m, slice, t;
int pixel[1290][130][61];
bool vis[1290][130][61];
int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};
bool judge(int x, int y, int z)
{
    if(x < 0 || x >= n || y < 0 || y >= m || z < 0 || z >=slice)
        return false;
    if(pixel[x][y][z] == 0 || vis[x][y][z] == true)
        return false;
    return true;
}
int BFS(int x, int y, int z)
{
    Node.x = x, Node.y = y, Node.z = z;
    queue<node> q;
    int count = 0;
    q.push(Node);
    vis[x][y][z] = true;
    while (!q.empty())
    {
        node temp = q.front();
        q.pop();
        count++;
        for (int i = 0; i < 6; i++)
        {
            int newX = temp.x + X[i];
            int newY = temp.y + Y[i];
            int newZ = temp.z + Z[i];
            if (judge(newX, newY, newZ))
            {
                Node.x = newX, Node.y = newY, Node.z = newZ;
                q.push(Node);
                vis[newX][newY][newZ] = true;
            }
        }
    }
    if (count >= t)
    {
        return count;
    }
    else return 0;
}
int main(int argc, char const *argv[])
{
    scanf("%d%d%d%d", &n, &m, &slice, &t);
    for (int i = 0; i < slice; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                scanf("%d", &pixel[j][k][i]);
            }
        } 
    }
    int ans = 0;
    for (int z = 0; z < slice; z++)
    {
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < m; y++)
            {
                if(pixel[x][y][z] == 1 && vis[x][y][z] == false)
                {
                    ans += BFS(x, y, z);
                }
            }
            
        }
        
    }
    printf("%d", ans);
    return 0;
}
