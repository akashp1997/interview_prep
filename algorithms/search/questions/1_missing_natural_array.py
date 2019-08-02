#Time: O(n)
#Space: O(1)

arr = [1,2,3,4,6]

xor_arr = 0
xor = 1
for i in range(len(arr)):
    xor_arr = xor_arr ^ arr[i]
    xor = xor ^ (i+2)

print(xor_arr^xor)
