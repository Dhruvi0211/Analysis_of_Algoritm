# Link - https://www.hackerrank.com/challenges/coin-change/problem

#!/bin/python3
import math
import os
import random
import re
import sys
def getWays(n, c):
    n_perms = [1]+[0]*n
    for coin in c:
        for i in range(coin, n+1):
            n_perms[i] += n_perms[i-coin]
    return n_perms[n]
    
n, m = map(int, input().split())
c = list(map(int, input().split()))
print(getWays(n, c))