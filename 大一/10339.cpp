#include <stdio.h>
#include <string.h>
int main()
{
    char a[50];
	//从键盘输入的字符串保存到字符数组a中
	scanf("%s",a);
    int cnt,i;
    cnt=0;
    for(i=0;a[i]!='\0';i++);{
    	printf("?\n");
        if(a[i]=='b'&&a[i+1]=='d'){
            cnt++;
            //printf("%d",cnt);
        }
    }
	//write your code here
    //printf("%d",cnt);
    
	return 0;
}
