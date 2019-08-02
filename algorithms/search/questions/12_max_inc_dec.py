#arr = [8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1]
arr = [1, 3, 50, 10, 9, 7, 6]

def maximum(arr):
    low = 0
    high = len(arr)-1
    while low<high:
        mid = (low+high)//2
        prev = mid-1 if mid>0 else 0
        next = mid+1 if mid<len(arr) else len(arr)-1
        if arr[mid]>arr[next] and arr[mid]>arr[prev]:
            return mid
        elif arr[mid]>arr[prev]:
            low = mid
        else:
            high = mid
    return -1

print(maximum(arr))
