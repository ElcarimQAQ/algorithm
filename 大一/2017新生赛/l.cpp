using namespace std;


int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
     int t,n,p;
     cin>>t;
     while(t--){
        cin>>n>>p;
        double sum;
        sum=1-pow(1-0.01*p,n);
        printf("%.6lf\n",sum);
     }
     return 0;
}

