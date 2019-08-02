#Time: O(n)
#Space: O(1)
import sys
import random

low2=low1=sys.maxsize

arr = [random.randint(1, 10**7) for i in range(random.randint(1,10000))]

for ele in arr:
    if ele<low1:
        low1,low2 = ele, low1
    elif ele<low2:
        low2 = ele

print(low1, low2)


mini = min(arr)
arr.remove(mini)
print(mini, min(arr))
