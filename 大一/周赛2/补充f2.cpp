#include<cstdio>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d%d",&a,&b);
        char s[100];
        scanf("%s",s);
        int x=0,y=0,i=4;
        for(;s[i]!='\0';i++){
            if(s[i]=='.') break;
            x=x*10+s[i]-'0';
        }
        if(s[i]!='\0'){
            i++;
            for(;s[i]!='\0';i++){
                y=y*10+s[i]-'0';
            }
        }
        if(s[3]=='-'){
            x=-x;
            y=-y;
        }
        x-=8;
        b+=y*6;
        while(b>=60){
            a+=1;
            b-=60;
        }
        while(b<0){
            a-=1;
            b+=60;
        }
        a+=x;
        while(a>23){
            a-=24;
        }
        while(a<0){
            a+=24;
        }
        printf("%02d:%02d\n",a,b);
    }
    return 0;
}

