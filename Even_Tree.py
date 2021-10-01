# Link - https://www.hackerrank.com/challenges/even-tree/problem
#!/bin/python3

import math
import os
import random
import re
import sys

tn, te = map(int, input().rstrip().split())
ch = {}
tr = {}
for i in range(te):
    tf, tt = map(int, input().rstrip().split())
    if tt not in tr.keys(): tr[tt] = [tf]
    else: tr[tt].append(tf)
    ch[i] = 1

for i in range(te+1, 1, -1):
    if i not in tr.keys():
        ch[i] = 1
    else:
        for j in tr[i]:
            ch[i] += ch[j]

c = 0
for i in range(te):
    if ch[i] % 2 == 0:
        c+=1

print(c)