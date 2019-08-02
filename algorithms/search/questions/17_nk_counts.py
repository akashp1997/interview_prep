arr = [4, 5, 6, 7, 8, 4, 4]
k = 3

def counts(arr, k):
    dict1 = {}
    a = []
    for i in arr:
        if i in dict1:
            dict1[i] += 1
            if dict1[i]==len(arr)//k:
                a.append(i)
                del dict1[i]
        else:
            dict1[i] = 1
    return a

counts(arr, k)
