#include<iostream>
#include<string>
using namespace std;
int n;
string deal(string s, int& e)
{
    int k = 0;
    while(s.length() > 0 && s[0] == '0')
    {
        s.erase(s.begin());
    }
    if (s[0] == '.')
    {
        s.erase(s.begin());
        while(s.length() > 0 && s[0] == '0')
        {
            s.erase(s.begin());
            e--;
        }
    }else {
        while (k < s.length() && s[k] != '.')
        {
            k++;
            e++;
        }
        if(k < s.length())
        {
            s.erase(s.begin() + k);
        }
    }
    if(s.length() == 0)
    {
        e = 0;
    }
    string res;
    int num = 0;
    while(num < n) {
        if(num < s.length())
            res += s[num];
        else
            res += '0';
        num++;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    string s1, s2, s3, s4;
    cin >> n;
    cin >> s1;
    cin >> s2;
    int e1 = 0, e2 = 0;
    s3 = deal(s1, e1);
    s4 = deal(s2, e2);
    cout << s3 << " " << e1 << endl;
    cout << s4 << " " << e2 << endl;
    return 0;
}
