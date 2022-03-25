const int N=1e7+1;//先打素数表
int prime[N];
int b[N];
int cnt=0,max1=1e7;
int init()
{
    memset(b,1,sizeof(b));
    b[0]=b[1]=0;
    for(int i=2;i<=max1;i++)
    {
        if(b[i])
        {
            prime(++cnt)=i;
        }
        for(int j=1;j<=cnt&&prime[j]*i<=max1;j++)
        {
            b[prime[j]*i]=0;
            if(i%prime[j]==0) break;
        }
    }
    return 0;
}
void getprimefactor(long long n)//分解质因数
{
    int cas=2;//第一个素数是2
    for(int i=2;i<len&&prime[i]*prime[i]<=n;i++)
    {
        while(n%prime[i]==0)
        {
            factor[cas]++;//第cas个质数的个数+1
            n/=prime[i];
        }
        if(factor[cas]!=0)//分解结果中第cas个质数的个数
            cas++;
    }
}