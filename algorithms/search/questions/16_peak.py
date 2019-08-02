#arr = [1, 3, 4, 20, 1, 0]
arr = [10, 20, 30, 40, 50]

def peak(arr):
    low = 0
    high = len(arr)-1
    if arr[-1]>arr[0] and arr[-1]>arr[len(arr)//2]: return len(arr)-1
    if arr[0]>arr[-1] and arr[0]>arr[len(arr)//2]: return 0
    while low<high:
        mid = (low+high)//2
        print(arr[low:mid], arr[mid:high])
        next = mid+1 if mid<len(arr) else len(arr)-1
        prev = mid-1 if mid>0 else 0
        if arr[mid]>arr[next] and arr[mid]>arr[prev]:
            return mid
        elif arr[mid]<arr[next]:
            low = mid
        else:
            high = mid
    return -1
    if len(arr)==1:
        return arr[0]
    if len(arr)==2:
        return arr[0] if arr[0]>arr[1] else arr[1]

print(peak(arr))
