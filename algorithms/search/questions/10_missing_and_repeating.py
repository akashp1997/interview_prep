#TODO
arr = [1,3,4,5,5,6,2]
xor = arr[0] ^ 1
elements = set()
for i in range(1, len(arr)):
    xor = (xor ^ arr[i]) ^ (i+1)

set_bit = xor & (~xor-1)

print(set_bit)

x = 0
y = 0

for i in range(len(arr)):
    if set_bit & arr[i]:
        x = x^arr[i]
    else:
        y = y^arr[i]
    if (i+1) & set_bit:
        x = x ^ (i+1)
        y = y ^ (i+1)

print(x, y)
