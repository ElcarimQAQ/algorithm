# [ [0, 0, 0, 0, '0'], [0, 0, 0, 1, '0'], [0, 1, 0, 1, '1'], [0, 1, 1, 0, '1'], [0, 0, 0, 0, '0'], [1, 0, 0, 0, '0'] ]

import math
import sys
from collections import Counter


def entory(inputs):
    labels = [line[-1] for line in inputs]
    # print(labels)
    labels_count = Counter(labels)
    probs =  [c/len(labels) for c in labels_count.values()]
    entory = -sum(p * math.log2(p) for p in probs)
    return round(entory,3)

# inputs = [[0, 0, 0, 0, '0'], [0, 0, 0, 1, '0'], [0, 1, 0, 1, '1'], [0, 1, 1, 0, '1'], [0, 0, 0, 0, '0'], [1, 0, 0, 0, '0']]
# data = inputs
# data = []
data = str(sys.stdin.readline().strip())
data = eval(data)
# data = [list(map(int, line.strip().split(','))) for line in data]

print(entory(data))