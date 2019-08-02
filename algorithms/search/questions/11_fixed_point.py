arr = [-10, -5, 0, 3, 7]

def fixed(arr):
    low = 0
    high = len(arr)-1
    while low<=high:
        mid = (low+high)//2
        if arr[mid]==mid:
            return mid
        elif arr[mid]<mid:
            low = mid
        else:
            high = mid
    return -1


print(fixed(arr))
