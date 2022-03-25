#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);

int main ()
{
    int t,y,X,sum;
    char x;
    cin>>t;
    while (t--){
        cin>>x>>y;
        if (x>='A'&&x<='Z'){
            X=x-'A'+1;

        }
        else
            X=(x-'a'+1)*(-1);
        sum=X+y;
        cout<<sum<<endl;
    }

	return 0;
}


