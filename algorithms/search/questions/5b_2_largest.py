#Time: O(nlogn)
#Space: O(2*n)
import random

class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

arr = [random.randint(1, 10**7) for i in range(random.randint(1,10000))]

while len(arr)>2:
    i = 0
    while i<len(arr)-1:
        if arr[i]>arr[i+1]:
            arr.pop(i)
        else:
            arr.pop(i+1)
        i += 1

print(", ".join(map(str, arr)))

mini = min(arr)
arr.remove(mini)
print(mini, min(arr))
