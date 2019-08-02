#Time: O(nlogn)
#Space: O(n)
import random
import sys
sys.setrecursionlimit(20000)
#arr1 = [1, 12, 15, 26, 38]
#arr2 = [2, 13, 17, 30, 45]

def mergesort(arr1):
    if len(arr1)<2:
        return arr1
    mid = len(arr1)//2
    L = mergesort(arr1[:mid])
    R = mergesort(arr1[mid:])
    arr1 = []
    while len(L)!=0 and len(R)!=0:
        if L[0]<=R[0]:
            arr1.append(L.pop(0))
        else:
            arr1.append(R.pop(0))
    while len(L)!=0:
        arr1.append(L.pop(0))
    while len(R)!=0:
        arr1.append(R.pop(0))
    return arr1

#1 2 12 13 15  17  26 30 38 45
n = random.randint(1,10000)
arr1 = mergesort([random.randint(1,10**7) for i in range(n)])
arr2 = mergesort([random.randint(1,10**7) for i in range(n)])

def median(arr1, arr2):
    if len(arr1)==1 and len(arr2)==1:
        return (arr1[0]+arr2[0])//2
    if len(arr1)==2 and len(arr2)==2:
        return (max(arr1[0], arr2[0])+min(arr1[1], arr2[1]))//2
    mid = len(arr1)//2
    if arr1[mid]==arr2[mid]:
        return arr1[mid]
    if arr1[mid]>arr2[mid]:
        #print(arr1[:mid+1], arr2[mid:])
        return median(arr1[:mid+1], arr2[mid:])

    else:
        #print(arr1[mid:], arr2[:mid+1])
        return median(arr1[mid:], arr2[:mid+1])

print(median(arr1, arr2))
