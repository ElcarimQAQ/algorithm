#include <stdio.h>
#include <string.h>
int main()
{
    char a[50];
	//�Ӽ���������ַ������浽�ַ�����a��
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
