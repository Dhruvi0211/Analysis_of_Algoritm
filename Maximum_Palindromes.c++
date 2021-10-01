// Link - https://www.hackerrank.com/challenges/maximum-palindromes/problem#include<bits/stdc++.h>

#include<bits/stdc++.h>
using namespace std;
# define N 1000000007
long long int power(long long int a, long long int b, long long int c)
{
    if(b==0)
    {
        return 1;
    }
    long long int p = power(a,b/2,c)%c;
    p= (p*p) % c;
    return (b%2==0)? p:(a*p)%c;
}
int main()
{
    int testcase;
    string str;
    int length;
    cin>>str;
    cin>>testcase;
    length= str.length();
    long long int fact[length+1], inverse[length+1];//modular multiplicaive inverse
    fact[0]=1;
    inverse[0]=1;
    for(int i=1; i<=length; i++)
    {
        fact[i]=(fact[i-1]*i) % N;
        inverse[i]= power(fact[i],N-2,N); 
    }
    int freq[length+1][26];

    memset(freq,0, sizeof(freq)); 
     for (int i = 1; i <=length; ++i)
    {
        freq[i][str[i-1]-'a']++;

    }

    for (int i = 2; i <=length; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            freq[i][j]+=freq[i-1][j];
        }
    }
    while(testcase--)
    {
        int l,r;
        cin>>l>>r;
        long long int deno=1;
        long long int nume=0;
        int value=0;
        int odd=0;
        int even=0;
        for (int i = 0; i < 26; ++i)
        {
            value=freq[r][i]-freq[l-1][i];
            if(value%2!=0)
            {
                odd++;
            }
            even+=value/2;
        deno=( (deno*inverse[value/2])%N);
        }
        nume= fact[even];
        long long int res= (nume*deno)%N;
        if(odd)
        {
            res=(res*odd)%N ;
        }
        cout<<res<<endl;
    }
return 0;
}
