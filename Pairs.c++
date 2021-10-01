// Link - https://www.hackerrank.com/challenges/pairs/problem

#include <bits/stdc++.h>

using namespace std;
int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    int a[N];
    for(int n = 0; n<N; n++){
        scanf("%d", &a[n]);
    }
    sort(a, a+N);
    int count = 0;
    for(int n = 0; n<N; n++)
        if(binary_search(a, a+N, a[n]+K)) count++;
    printf("%d", count);
}
