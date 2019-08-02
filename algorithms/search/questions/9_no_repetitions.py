def floor(arr, ele):
    low = -1
    high = len(arr)-1
    while high-low>1:
        mid = (low+high)//2
        if arr[mid]>=ele: high = mid
        else: low = mid
    return high

def ceil(arr, ele):
    low = 0
    high = len(arr)
    while high-low>1:
        mid = (low+high)//2
        if arr[mid]<=ele: low = mid
        else: high = mid
    return low

def count(arr, ele):
    f = floor(arr, ele)
    c = ceil(arr, ele)
    return c-f+1 if (arr[f]==ele and arr[c]==ele) else 0

arr = [1, 2, 2, 3, 3, 3, 3]

print(count(arr, 3))
