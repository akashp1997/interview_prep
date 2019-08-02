arr1 = [900]
arr2 = [5, 8, 10, 20]

def median(arr1, arr2):
    m, n = sorted([arr1, arr2], key=lambda x: len(x))
    mid = len(n)//2
    if len(m)==0:
        if len(n) & 1:
            return n[mid]
        else:
            return (n[mid]+n[mid+1])/2
    if len(m)==1:
        if len(n)==1:
            return (m[0]+n[0])/2
        elif len(n) & 1:
            if m[0]<n[mid-1]:
                return (n[mid]+n[mid-1])/2
            if m[0]>=n[mid-1] and m[0]<n[mid]:
                return (m[0]+ n[mid])/2
            if m[0]>=n[mid] and m[0]<n[mid+1]:
                return (m[0]+n[mid+1])/2
            if m[0]>=n[mid+1]:
                return (n[mid]+n[mid+1])/2
        else:
            if m[0]<n[mid]:
                return n[mid]
            elif m[0]>=n[mid] and m[0]<n[mid]:
                return m[0]
            else:
                return n[mid+1]
    if len(m)==2:
        if len(n) & 1:
            return median([], [n[mid], n[mid-1], max(m[0], n[mid-2]), min(m[1], n[mid+1])])
        else:
            return median([], [n[mid], max(m[0], n[mid-1]), min(m[1], n[mid+1])])

print(median(arr2, arr1))
