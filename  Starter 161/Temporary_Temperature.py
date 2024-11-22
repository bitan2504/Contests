def solve():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    left, right, ans = 0, 10**9, 0
    while left <= right:
        mid = left + (right - left) // 2
        mini, maxi, cnt, temp = arr[0], arr[0], 0, 0
        flag = True
        for i in range(n):
            mini = min(arr[i], mini)
            maxi = max(arr[i], maxi)
            if maxi - mini > 2 * mid:
                cnt += 1
                mini = maxi = arr[i]
                if cnt > k:
                    flag = False
                    break
        if flag:
            right = mid - 1
            ans = mid
        else:
            left = mid + 1

    print(ans)

tt = 1
tt = int(input())
for _ in range(tt):
    solve()