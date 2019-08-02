def pivot(arr):
    low = 0
    high = len(arr)-1
    if arr[low]<arr[high]:
        return arr[low]
    while low<high:
        mid = (low+high)//2
        if arr[mid]>arr[mid+1]:
            return arr[mid+1]
        if arr[mid]<arr[mid-1]:
            return arr[mid]
        if mid>low and arr[mid]<arr[low]:
            high = mid
        if mid<high and arr[mid]>arr[high]:
            low = mid
    return -1

arr = [1, 2, 3, 4]

print(pivot(arr))
