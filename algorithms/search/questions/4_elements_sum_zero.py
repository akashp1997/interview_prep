#Time: O(nlogn)
#Space: O(n)

import sys
def mergesort(arr):
    if len(arr)<2:
        return arr
    mid = len(arr)//2
    L = mergesort(arr[:mid])
    R = mergesort(arr[mid:])
    arr = []
    while len(L)!=0 and len(R)!=0:
        if L[0]<=R[0]:
            arr.append(L.pop(0))
        else:
            arr.append(R.pop(0))
    while len(L)!=0:
        arr.append(L.pop(0))

    while len(R)!=0:
        arr.append(R.pop(0))
    return arr

arr = mergesort([1, 60, -10, 70, -80, 85])
l = 0
r = len(arr)-1
minsum = sys.maxsize
while l<r:
    sum_lr = arr[l]+arr[r]
    if abs(sum_lr)<minsum: minsum = sum_lr
    if minsum==0: break
    if sum_lr>0: r -= 1
    else: l += 1

print(minsum)
