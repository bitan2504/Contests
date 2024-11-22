def solve():
    n = int(input())
    arr = [int(x) for x in input().split()]
    for i in range(1, n - 1):
        if arr[i] == 3 and arr[i - 1] + arr[i + 1] == 4:
            arr[i] = 1
    for i in range(n - 2, 0, -1):
        if arr[i] == 3 and arr[i - 1] + arr[i + 1] == 4:
            arr[i] = 1
    print(sum(arr))

tt = 1
tt = int(input())
for _ in range(tt):
    solve()