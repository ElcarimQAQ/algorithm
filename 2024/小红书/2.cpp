
// from math import sqrt
// vis = [10**9] * 15000
// a = [0] * 15000 
// b = [0] * 15000
// c = [0] * 15000
// def init():
//     for i in range(1, 3400):
//         for j in range(i+1, 3400):
//             k = int(sqrt(i**2 + j**2 + 0.5))
//             if i + j + k > 15000:
//                 break
//             if k**2 == i**2 + j**2:
//                 if vis[i+j+k] > i+j+k:
//                     vis[i+j+k] = i+j+k
//                     a[i+j+k] = i
//                     b[i+j+k] = j
//                     c[i+j+k] = k
//     la = lb = lc = 10**7
//     for i in range(14999, 0, -1):
//         if vis[i] != 10**9:
//             la = a[i]
//             lb = b[i]
//             lc = c[i]
//         else:
//             a[i] = la
//             b[i] = lb
//             c[i] = lc
// t = int(input())
// init()
// print(a)
// for _ in range(t):
//     k = int(input())
//     # print(a)
//     print(f'{a[k]} {b[k]} {c[k]}')

#include <bits/stdc++.h>
using namespace std;
const int N = 50000;
int vis[N], a[N], b[N], c[N];

void init(){
    for (int i = 1; i <= 50000; i++)
    {
        vis[i] = 1e9;
    }
    for(int i = 1; i < 10000; i++){
        for(int j = i+1; j < 10000; j++){
            int k = sqrt(i*i + j*j + 0.5);
            if(i+j+k > N) break;
            if(k*k == i*i + j*j){
                if(vis[i+j+k] > i+j+k){
                    vis[i+j+k] = i+j+k;
                    a[i+j+k] = i;
                    b[i+j+k] = j;
                    c[i+j+k] = k;
                }
            }
        }
    }
    int la = 1e7, lb = 1e7, lc = 1e7;
    for(int i = N; i > 0; i--){
        if(vis[i] != 1e9){
            la = a[i];
            lb = b[i];
            lc = c[i];
        }else{
            a[i] = la;
            b[i] = lb;
            c[i] = lc;
        }
    }
}

int main(){
    // fast;
    int t;
    cin >> t;
    init();
    for(int i = 0; i < t; i++){
        int k;
        cin >> k;
        cout << a[k] << " " << b[k] << " " << c[k] << endl;
    }
    return 0;
}