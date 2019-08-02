arr = [5, 20, 3, 2, 50, 80]

def pair(arr, n):
    arr.sort()
    i,j=0,1
    while i<j and j<len(arr):
        if arr[j]-arr[i]==n:
            return arr[i],arr[j]
        elif arr[j]-arr[i]<n:
            j += 1
        else:
            i += 1

print(pair(arr, 78))
