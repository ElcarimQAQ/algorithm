int main()
{
    int n,d,t,x,y;
    while(~scanf("%d %d", &n, &d))
    {
        scanf("%d", &t);
        while(t--)
        {
            scanf("%d %d", &x, &y);
            if(y >= x - d && y <= x + d && y >= d - x && y <= 2 * n - d - x)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }

    return 0;
}
