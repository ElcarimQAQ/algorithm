#include <bits/stdc++.h>
using namespace std;

int main() 
{
    std::ios::sync_with_stdio(false);
    int n,m;
    string str1,word;
    int cnt = 0;
    getline(cin,str1); //对于string类读入，前面的输入是cin>>ss;的话，str会读取上一行的结束符。

    char str2[30];
    cin.getline(str2,30);//读入整行数据，它使用回车键输入的换行符来确定输入结尾。第一个参数用来存储输入行的数组名称，第二个参数len是要读取的字符数。
    cin.get(str2, 30);//和上面的区别在于不会读入换行符
  
    return 0;
}