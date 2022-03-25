#include <iostream>
#include <string>
#include <fstream>
#define T 2     //最小支持度
#define M 9     //样本数
#define N 5     //数据项数
 
using namespace std;
 
//候选频繁项集：维数，频度，具体数据，获取频度
class freq_item{
public:
	int dim;
	int freq;
	string item[100];
	freq_item(){
		dim = 1;
		freq = 0;
		for(int i = 0; i < 100; i++)
			item[i] = "\0";
	}
	void getFreg(string *db,int m,int n);
};
 
void freq_item::getFreg(string *db,int m,int n){
	freq = 0;
	for(int i = 0; i < m; i++){
		//db的每一行，即样本集的每一条
		int cnt = 0;
		for(int k = 0; k < dim; k++){
			//在样本集的每一条中寻找项集的每个元素，记录存在的个数
			bool flag = false;
			for(int j = 0; j < n; j++){
				if(item[k] == db[j+i*n]){
					cnt++;
					flag = true;
					break;
				}
			}
			if(flag == false)
				break;
		}
		if(cnt == dim)	//存在的个数等于维数，说明这条样本包括项集
			freq++;
	}
}
 
int num[N];                  //每一维频繁项集的个数
string data[M][N];           //要处理的数据
freq_item res[100];          //各维频繁项集
 
//获取2维频繁项集，因不用剪枝，单独处理
void get2dim(){
	res[99].dim = 2;
	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			//res[99].freq = 0;
			res[99].item[0] = res[i].item[0];
			res[99].item[1] = res[j].item[0];
			res[99].getFreg(&data[0][0],M,N);
			if(res[99].freq >= T){
				res[num[0]+num[1]].item[0] = res[99].item[0];
				res[num[0]+num[1]].item[1] = res[99].item[1];
				res[num[0]+num[1]].freq = res[99].freq;
				res[num[0]+num[1]].dim = res[99].dim;
				num[1]++;
			}
		}
	}
}
 
//获取2维以上的频繁项集
int getNdim(){
	//i+1项集，其数据为item[0]~item[i]
	for(int i = 2; i < N; i++){
		res[99].dim = i+1;
		//begin是第一个i项集的下标，end-1是最后一个i项集的下标
		int begin = 0,end = 0;
		for(int j = 0; j < i; j++)
			end += num[j];
		for(int j = 0; j < i-1; j++)
			begin += num[j];
		for(int p = begin; p < end; p++){
			for(int q = p+1; q < end; q++){
				//判断两个i项集的item[0]~item[i-2]是否相等
				bool flag = true;
				for(int d = 0; d < i-1; d++){
					if(res[p].item[d] != res[q].item[d]){
						flag = false;
						break;
					}
				}
				//相等则判断两个i项集的item[i-1]组成的2项集是否频繁，即剪枝
				if(flag == true){
					bool flag1 = false;
					for(int u = num[0]; u < num[0]+num[1]; u++){
						if(res[p].item[i-1] == res[u].item[0] && res[q].item[i-1] == res[u].item[1]){
							flag1 = true;
							break;
						}
					}
					//计算频度，判断是否为频繁项集
					if(flag1 == true){
						//res[99].freq = 0;
						for(int v = 0; v < i; v++)
							res[99].item[v] = res[p].item[v];
						res[99].item[i] = res[q].item[i-1];
						res[99].getFreg(&data[0][0],M,N);
						if(res[99].freq >= T){
							for(int c = 0; c < i+1; c++)
								res[num[i]+end].item[c] = res[99].item[c];
							res[num[i]+end].freq = res[99].freq;
							res[num[i]+end].dim = res[99].dim;
							num[i]++;
						}
					}
				}
			}
		}
		//若i+1项集无频繁的，则i频繁项集为所求
		if(num[i] == 0){
			/*for(int j = begin; j < end; j++){
				for(int d = 0; d < i; d++)
					cout << res[j].item[d] << " ";
				cout << "   frequence: " << res[j].freq << endl;
			}*/
			return i;
		}
	}
}
 
int main(){
	ifstream input;
	string a;
	input.open("data.txt");
	if(input.fail()){
		cout << "The file doesn't exist!\n";
		return 0;
	}
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			input >> a;
			if(a == "#")
				break;
			data[i][j] = a;
		}
	}
	//读入频繁1项集
	for(int i = 0; i < N; i++){
		input >> res[i].item[0];
		res[i].getFreg(&data[0][0],M,N);
		if(res[i].freq >= T)
			num[0]++;
	}
	input.close();
	get2dim();
	//getNdim();
	//输出所有频繁项集
	int w = 0,x = 0,y = getNdim();
	for(int i = 0; i < y; i++)
		x += num[i];
	for(int i = 1; i < y; i++)
		num[i] = num[i] + num[i-1];
	for(int i = 0; i < x; i++){
		if(i==0 || i==num[w]){
			cout << "频繁" << res[i].dim <<"-项集：\n";
			if(num[w] == i)
				w++;
		}
		for(int j = 0; j < res[i].dim; j++)
			cout << res[i].item[j] << " ";
		cout << "   frequence: " << res[i].freq << endl;
	}
	system("PAUSE");
	return 0;
}