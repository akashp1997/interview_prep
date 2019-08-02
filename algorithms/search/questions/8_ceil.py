def ceil(arr, ele):
    low = 0
    high = len(arr)
    while high-low>1:
        mid = (low+high)//2
        if arr[mid]>=ele: high = mid
        else: low = mid
    return arr[low]

arr = [1, 2, 8, 10, 10, 12, 19]

print(ceil(arr, 3))
