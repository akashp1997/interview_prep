arr = [3, 4, 5, 1, 2]

def search(arr, ele):
    low = 0
    high = len(arr)-1
    while low<high:
        print(low, high)
        mid = len(arr)//2
        if arr[mid]==ele:
            return mid
        if arr[low]<=arr[mid]:
            if arr[low]<=ele and arr[mid]>=ele:
                high = mid-1
            else:
                low = mid+1
        else:
            if arr[mid]<=ele and arr[high]>=ele:
                low = mid+1
            else:
                high = mid-1
    return -1


print(search(arr, 3))
