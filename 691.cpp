#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int m;
string target;
vector<string> stickers;
vector<int> dp;
int dphelp(int mask)
{
    if (dp[mask] != -1) {
        return dp[mask];
    }
    dp[mask] = m + 1;
    for (auto & sticker : stickers) {
        int left = mask;
        vector<int> cnt(26);
        for (char & c : sticker) {
            cnt[c - 'a']++;
        }
        for (int i = 0; i < m; i++) {
            if ((mask >> i & 1) && cnt[target[i] - 'a'] > 0) {
                cnt[target[i] - 'a']--;
                left ^= 1 << i;                    }
            }
            if (left < mask) {
                dp[mask] = min(dp[mask], dphelp(left) + 1);
            }
        }
    return dp[mask];
}
int minStickers() {
    m = target.size();
    // printf("%d", m);
    // this->target = target;
        // this->stk = stickers;
        // vector<int> dp(1 << m,-1);
        // dph.reserve(1 << m,-1);
    dp = vector<int>(1 << m,-1);
    dp[0] = 0;
    for (auto & i : dp)
    {
        printf("%d\n", i);
    }
    
    // int s = 1 << m;
    int res = dphelp((1 << m)-1);
    return res > m ? -1 : res;
}
int main(int argc, char const *argv[])
{
    target = "thehat";
    stickers.push_back("with");
    stickers.push_back("example");
    stickers.push_back("science");
    // cout<<target;
    int p = minStickers();
    printf("%d", p);
    return 0;
}
