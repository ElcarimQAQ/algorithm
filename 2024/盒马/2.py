from collections import Counter


t = int(input())
for _ in range(t):
    n = int(input())
    s = str(input())

    co = Counter()
    co['0'] = 0
    co['1'] = 0
    ans = []
    for c in s:
        if c == '0':
            co['0'] += 1
            ans.append(co['1'])
        else:
            co['1'] += 1
            ans.append(co['0'])
    # print: 0 0 2 1
    print(' '.join(map(str, ans)))
