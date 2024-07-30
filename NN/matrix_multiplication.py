import numpy as np

def matrix_muti(A, B):
    m, n = A.shape
    n, p = B.shape
    C = np.zeros((m, p))
    for i in range(m):
        for j in range(p):
            for k in range(n):
                C[i, j] += A[i, k] * B[k, j]
                
    return C



if __name__ == "__main__":
    A = np.random.randn(3, 2)
    B = np.random.randn(2, 3)
    print(A)
    print(B)
    print(matrix_muti(A, B))