n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
top_area = sum(1 for i in range(n) for j in range(m) if a[i][j] > 0)
front_area = sum(max(a[i][j] for i in range(n)) for j in range(m))
left_area = sum(max(a[i]) for i in range(n))
print(f'{front_area} {left_area} {top_area}')
