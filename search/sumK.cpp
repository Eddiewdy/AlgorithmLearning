#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
const int maxn = 100;
int n, k, x, A[maxn];
int maxSum = -1;
vector<int> temp, ans;
void DFS(int index, int nowK, int sum, int sumQ)
{
    if (nowK == k && sum == x)
    {
        if (sumQ > maxSum)
        {
            ans = temp;
            maxSum = sumQ;
        }
        return;
    }
    if (index == n || nowK > k || sum > x)
    {
        return;
    }
    temp.push_back(A[index]);
    DFS(index + 1, nowK + 1, sum + A[index], sumQ + A[index] * A[index]);
    temp.pop_back();
    DFS(index + 1, nowK + 1, sum, sumQ);
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
