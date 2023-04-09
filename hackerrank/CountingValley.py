#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'countingValleys' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER steps
#  2. STRING path
#

def countingValleys(steps, path):
    s=res = 0
    isNeg = False
    for i,x in enumerate(path):
        s += 1 if x=='U' else -1
        if(s<0): isNeg = True
        if(s==0):
            res +=isNeg
            isNeg = False
    return res

if __name__ == '__main__':
    steps = int(input().strip())
    path = input()
    result = countingValleys(steps, path)
    print(result)

