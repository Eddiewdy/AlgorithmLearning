#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    // cout << "hello";
    // return 0;
    vector<int> vi;
    for (int i = 0; i < 6; i++)
    {
        vi.push_back(i);
    }
    for (vector<int>::iterator it = vi.begin(); it != vi.end(); it++)
    {
        printf("%d", *it);
    }
    vi.pop_back();
    for (vector<int>::iterator it = vi.begin(); it != vi.end(); it++)
    {
        printf("%d", *it);
    }
    vi.insert(vi.begin()+2, 1);
    for (vector<int>::iterator it = vi.begin(); it != vi.end(); it++)
    {
        printf("%d", *it);
    }
}
