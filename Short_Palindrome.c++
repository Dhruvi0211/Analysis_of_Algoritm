// Link- https://www.hackerrank.com/challenges/short-palindrome/problem

#include <bits/stdc++.h>

using namespace std;
#define fre     freopen("0.in","r",stdin);freopen("0.out","w",stdout)
#define abs(x) ((x)>0?(x):-(x))
#define MOD 1000000007
#define LL signed long long int
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)
#define rep(i,from,to) for(int i=(from);i <= (to); ++i)
#define pii pair<int,int>

vector<int> G[2*100000+5];
LL suf[654];
LL pre[654];
LL dp[29][29];

int main(){
    //fre;
    string S;
    cin>>S;
    int N = S.size();
    LL ans = 0;
    S = " " + S;
    for(int i=1;i<=N;++i)suf[S[i]-'a'+1]++;
    for(int i=1;i<=N;++i){
        int x = S[i]-'a'+1;
        suf[x]--;
        for(int j=1;j<=26;++j){
            ans += dp[j][x] * suf[j];
            ans %= MOD;
        }
        for(int j=1;j<=26;++j){
            dp[j][x] += pre[j];
        }
        pre[x]++;
    }
    cout<<ans;
}

