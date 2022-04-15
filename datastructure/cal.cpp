#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<map>
using namespace std;

struct node
{
    bool isAlpha;
    double num;
    char op;
};

stack<node> s;
queue<node> q;
string str;
map<char, int> op;
void Change()
{
    double num;
    node temp;
    for (int i = 0; i < str.length(); )
    {
        if(str[i] <= '9' && str[i] >= '0')
        {
            temp.isAlpha = true;
            temp.num = str[i++] - '0';
            while (i < str.length() && str[i] <= '9' && str[i] >= '0')
            {
                temp.num = temp.num * 10 + (str[i++] - '0');
            }
            q.push(temp);
        }
        else {
            temp.isAlpha = false;
            while(!s.empty() && op[s.top().op] >= op[str[i]])
            {
                q.push(s.top());
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);
            i++;
        }
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}
double Cal()
{
    node cur;
    node temp;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur.isAlpha == true)
        {
            s.push(cur);
        }
        else {
            double num2 = s.top().num;
            s.pop();
            double num1 = s.top().num;
            s.pop();
            temp.isAlpha = true;
            if(cur.op == '+')
                temp.num = num1 + num2;
            else if(cur.op == '-')
                temp.num = num1 - num2;
            else if(cur.op == '*')
                temp.num = num1 * num2;
            else if(cur.op == '/')
                temp.num = num1 / num2;
            s.push(temp);
        }
        
    }
    return s.top().num;
}
int main(int argc, char const *argv[])
{
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    while (getline(cin, str), str != "0")
    {
        for (string::iterator i = str.end(); i != str.begin(); i--)
        {
            if(*i == ' ')
                str.erase(i);
        }
        cout << str << endl;
        while(!s.empty())
            s.pop();
        Change();
        cout << Cal() << endl;
    }
    
    return 0;
}

