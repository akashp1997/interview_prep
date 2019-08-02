#Time: O(n)
#Space: O(n)

import random

arr = [random.randint(1, 10**7) for i in range(random.randint(1,10000))]

def minmax(arr):
    if len(arr)==1:
        return arr[0], arr[0]
    if len(arr)==2:
        return arr[0] if arr[0]<arr[1] else arr[1], arr[0] if arr[0]>arr[1] else arr[1]
    mid = len(arr)//2
    minl, maxl = minmax(arr[:mid])
    minr, maxr = minmax(arr[mid:])
    return minl if minl<minr else minr, maxl if maxl>=maxr else maxr

print(*minmax(arr))

print(min(arr), max(arr))
