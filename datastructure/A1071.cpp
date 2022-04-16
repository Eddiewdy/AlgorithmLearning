#include<iostream>
#include<string>
#include<map>
using namespace std;

bool check(char c)
{
    if(c >= '0' && c <= '9')
        return true;
    else if(c >= 'a' && c <= 'z')
        return true;
    else if(c >= 'A' && c <= 'Z')
        return true;
    return false;
}

int main(int argc, char const *argv[])
{
    string str;
    map<string, int> count;
    getline(cin, str);
    int i = 0;
    while(i < str.length())
    {
        string word;
        while(i < str.length() && check(str[i]) == true)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] += 32;
            }
            word += str[i];
            i++;
        }
        if(word != "")
        {
            if (count.find(word) != count.end())
                count[word]++;
            else
                count[word] = 1;
        }
        while(i < str.length() && check(str[i]) == false)
        {
            i++;
        }
    }
    int max = 0;
    string res;
    for (map<string, int>::iterator it = count.begin(); it != count.end(); it++)
    {
        if(it->second > max)
        {
            max = it->second;
            res = it->first;
        }
    }
    cout << res << " " << max << endl;
    return 0;
}
