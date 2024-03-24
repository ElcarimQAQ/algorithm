#include <bits/stdc++.h>
using namespace std;


int main()
{
   int n;
   cin >> n;
    printf("%d=", n);  
   if(n == 1) cout<<1<<endl;
   else{
        bool is_fist = true;
        for(int i =2; i<= n / i; i ++) {
            if(n % i == 0){
                int k = 0;
                while (n % i == 0) n /= i, k++;
                if(!is_fist) cout<<'*';
                else is_fist = false;
                cout<<i;
                if(k > 1) cout<<'^'<<k;
            }
        }
        if(n > 1){
            if(!is_fist) cout<<'*';
            cout<<n;
        }
   }
    
    return 0;
}