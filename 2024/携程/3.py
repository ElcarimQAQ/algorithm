import heapq
n, k, l = map(int, input().split())
a = list(map(int, input().split()))

ll = l * k
# print(ll)
q = []
for i in range(n):
    heapq.heappush(q, (a[i], i))
# print(q)
pos0 = q[0][1]
# print(pos0)
for num, pos in q:
    if abs(pos - pos0 + 1) > ll:
        print(num)
        break
        
    pos0 = pos
    # print(num, pos)