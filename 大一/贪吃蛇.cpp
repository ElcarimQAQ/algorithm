#include <iostream>
#include <iomanip>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
	                                  //０　　　　　　　　　　　　　　　　　     ｃｏｏｒｄ．Ｘ 
#define WALL               "█"       //┏━━━━━━━━━━━━━━━━━━━━━━━━━━→
#define MENU_WALL          "※"       //┃
#define BLANK              "　"       //┃
#define UP                 "∧"       //┃
#define DOWN               "∨"       //┃
#define LEFT               "＜"       //┃
#define RIGHT              "＞"       //┃
#define BODY               "◆"       //┃                 控制台光标 
#define FOOD               "◎"       //┃
#define STARTWALLX         0          //┃                   坐标轴 
#define STARTWALLY         0          //┃
#define FINALWALLY         81         //┃
#define FINALWALLX         24         //┃
#define STARTMENUY         20         //┃
#define FINALMENUY         61         //┃
#define STARTMENUX         5          //┃
#define FINALMENUX         18         //┃
     							      //↓ｃｏｏｒｄ．Ｙ 
#define gotoxy(XXX,YYY);   coord.Y=XXX; coord.X=YYY; SetConsoleCursorPosition(hout,coord);  // 光标移动至 XXX行 YYY列 
#define setcolor(FC,BGC);  SetConsoleTextAttribute(hout,FC|BGC);  //改变颜色 

HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
COORD coord,head,tail,food;
char map[25][41][3],dir[25][41][3];      //[x 0..24][y 0..40][]
char game_over;                          //0=活着,1=撞了 
int  wait_time=0,length;

void InitSnakeWall();
void MakeFood();
void PrintMap();
void PrintMenu();
void PrintSelected();
void PrintOther();
void ControlMenu();
void ControlMove();
void MoveSnake();
void MoveTail(); 
void HideCursor(); 

int main(int argc, char** argv) 
{
	setcolor(7,0);
	HideCursor();
	while(1)
	{
		system("cls");
		srand((int)time(NULL));
		InitSnakeWall();
		MakeFood();
		PrintMap();
		PrintOther();
		PrintMenu();
		ControlMenu();
		PrintMap();
		game_over=0; 
		while (!game_over)
		{
			ControlMove();
			MoveSnake();
			PrintOther();
			if (game_over) 
			{
				ControlMove(); //撞死前的补救 
				MoveSnake();
				if (game_over)
				{
					cout<<'\a'; //发出声音 
					MessageBox(NULL,"傻","贪吃蛇",MB_OK); 
				}
			}
		}
	}
	return 0;
}

void HideCursor() //隐藏光标 
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
	SetConsoleCursorInfo(hout,&cursor_info);
}

void ControlMove()
{
	if (game_over)  //延时等待 
	{
		Sleep(80);
		if (kbhit()) goto re; 
		Sleep(80);
		if (kbhit()) goto re; 
		Sleep(80);
		if (kbhit()) goto re; 
		Sleep(80);
		if (kbhit()) goto re; 
		Sleep(80);
		if (kbhit()) goto re; 
	}
	else 
		Sleep((wait_time+0.5)*40);
	if (kbhit()) 
	{
re:		switch(getch())
		{
			case 'w':
			case 'W':
				if (strcmp(map[head.X][head.Y],DOWN)&&(!strcmp(map[head.X-1][head.Y],BLANK)||(!strcmp(map[head.X-1][head.Y],FOOD))))
					strcpy(map[head.X][head.Y],UP);
				break;
	        case 's':
	        case 'S':
	        	if (strcmp(map[head.X][head.Y],UP)&&(!strcmp(map[head.X+1][head.Y],BLANK)||(!strcmp(map[head.X+1][head.Y],FOOD))))
	        		strcpy(map[head.X][head.Y],DOWN);
				break;
	    	case 'a':
	    	case 'A':
	    		if (strcmp(map[head.X][head.Y],RIGHT)&&(!strcmp(map[head.X][head.Y-1],BLANK)||(!strcmp(map[head.X][head.Y-1],FOOD))))
	    			strcpy(map[head.X][head.Y],LEFT);
				break;
	    	case 'd':
	    	case 'D':
	    		if (strcmp(map[head.X][head.Y],LEFT)&&(!strcmp(map[head.X][head.Y+1],BLANK)||(!strcmp(map[head.X][head.Y+1],FOOD))))
	    			strcpy(map[head.X][head.Y],RIGHT);
				break;
			case ' ':
				PrintMenu();
				ControlMenu();
				PrintMap();
				break;
			case 0xE0:  //方向键 
				switch(getch())
				{
					case 0x48: //↑ 
						if (strcmp(map[head.X][head.Y],DOWN)&&(!strcmp(map[head.X-1][head.Y],BLANK)||(!strcmp(map[head.X-1][head.Y],FOOD))))
							strcpy(map[head.X][head.Y],UP);	
						break;
					case 0x50: //↓ 
        				if (strcmp(map[head.X][head.Y],UP)&&(!strcmp(map[head.X+1][head.Y],BLANK)||(!strcmp(map[head.X+1][head.Y],FOOD))))
        					strcpy(map[head.X][head.Y],DOWN);
        				break;
					case 0x4b: //← 
    					if (strcmp(map[head.X][head.Y],RIGHT)&&(!strcmp(map[head.X][head.Y-1],BLANK)||(!strcmp(map[head.X][head.Y-1],FOOD))))
    						strcpy(map[head.X][head.Y],LEFT);
						break; 
					case 0x4d: //→
    					if (strcmp(map[head.X][head.Y],LEFT)&&(!strcmp(map[head.X][head.Y+1],BLANK)||(!strcmp(map[head.X][head.Y+1],FOOD))))
    						strcpy(map[head.X][head.Y],RIGHT);
						break;
				}
		}
	}	
}

void MoveSnake()
{
	game_over=0;
	gotoxy(head.X,head.Y*2);
	if (!strcmp(map[head.X][head.Y],UP))
		if (!strcmp(map[head.X-1][head.Y],BLANK)||!strcmp(map[head.X-1][head.Y],FOOD))
		{
			cout<<BODY;
			strcpy(dir[head.X][head.Y],UP);
			if (!strcmp(map[head.X][head.Y],map[food.X][food.Y]))
				MakeFood();
			else 
				MoveTail();
			strcpy(map[head.X--][head.Y],BODY);
			strcpy(map[head.X][head.Y],UP);
			gotoxy(head.X,head.Y*2);
			cout<<UP;
		}
		else game_over=1;
	else
	if (!strcmp(map[head.X][head.Y],DOWN))
		if (!strcmp(map[head.X+1][head.Y],BLANK)||!strcmp(map[head.X+1][head.Y],FOOD))
		{
			cout<<BODY;
			strcpy(dir[head.X][head.Y],DOWN);
			if (!strcmp(map[head.X][head.Y],map[food.X][food.Y]))
				MakeFood();
			else 
				MoveTail();
			strcpy(map[head.X++][head.Y],BODY);
			strcpy(map[head.X][head.Y],DOWN);
			gotoxy(head.X,head.Y*2);
			cout<<DOWN;
		}
		else game_over=1;
	else
	if (!strcmp(map[head.X][head.Y],RIGHT))
		if (!strcmp(map[head.X][head.Y+1],BLANK)||!strcmp(map[head.X][head.Y+1],FOOD))
		{
			cout<<BODY;
			strcpy(dir[head.X][head.Y],RIGHT);
			if (!strcmp(map[head.X][head.Y],map[food.X][food.Y]))
				MakeFood();
			else 
				MoveTail();
			strcpy(map[head.X][head.Y++],BODY);
			strcpy(map[head.X][head.Y],RIGHT);
			gotoxy(head.X,head.Y*2);
			cout<<RIGHT;
		}
		else game_over=1;
	else 
	if (!strcmp(map[head.X][head.Y],LEFT))
		if (!strcmp(map[head.X][head.Y-1],BLANK)||!strcmp(map[head.X][head.Y-1],FOOD))
		{
			cout<<BODY;
			strcpy(dir[head.X][head.Y],LEFT);
			if (!strcmp(map[head.X][head.Y],map[food.X][food.Y]))
				MakeFood();
			else 
				MoveTail();
			strcpy(map[head.X][head.Y--],BODY);
			strcpy(map[head.X][head.Y],LEFT);
			gotoxy(head.X,head.Y*2);
			cout<<LEFT;
		}
		else game_over=1;
	gotoxy(FINALWALLX+1,0);
}

void MoveTail()
{
	gotoxy(tail.X,tail.Y*2);
	cout<<BLANK;
	if (!strcmp(dir[tail.X][tail.Y],UP))
	{
		strcpy(map[tail.X][tail.Y],BLANK);
		strcpy(dir[tail.X--][tail.Y],BLANK);
	}
	else 
	if (!strcmp(dir[tail.X][tail.Y],DOWN))
	{
		strcpy(dir[tail.X][tail.Y],BLANK);
		strcpy(map[tail.X++][tail.Y],BLANK);	
	}
	else
	if (!strcmp(dir[tail.X][tail.Y],LEFT))
	{
		strcpy(dir[tail.X][tail.Y],BLANK);
		strcpy(map[tail.X][tail.Y--],BLANK);	
	}
	else
	if (!strcmp(dir[tail.X][tail.Y],RIGHT))
	{
		strcpy(dir[tail.X][tail.Y],BLANK);
		strcpy(map[tail.X][tail.Y++],BLANK);	
	}
	gotoxy(FINALWALLX+1,0);
}

void PrintSelected()
{
	setcolor(12,0);
	switch(wait_time)
	{
		case 0:
			gotoxy(STARTMENUX+4,STARTMENUY+2);
			cout<<"               极速行进               ";
			setcolor(7,0);
			gotoxy(STARTMENUX+6,STARTMENUY+2);
			cout<<"               快速行进               ";
			break;
		case 1:
			gotoxy(STARTMENUX+6,STARTMENUY+2);
			cout<<"               快速行进               ";
			setcolor(7,0);
			gotoxy(STARTMENUX+4,STARTMENUY+2);
			cout<<"               极速行进               ";
			gotoxy(STARTMENUX+8,STARTMENUY+2);
			cout<<"               慢速行进               ";
			break;
		case 2:
			gotoxy(STARTMENUX+8,STARTMENUY+2);
			cout<<"               慢速行进               ";
			setcolor(7,0);
			gotoxy(STARTMENUX+6,STARTMENUY+2);
			cout<<"               快速行进               ";
			gotoxy(STARTMENUX+10,STARTMENUY+2);
			cout<<"               龟速行进               ";
			break;
		case 3:
			gotoxy(STARTMENUX+10,STARTMENUY+2);
			cout<<"               龟速行进               ";
			setcolor(7,0);
			gotoxy(STARTMENUX+8,STARTMENUY+2);
			cout<<"               慢速行进               ";
			break;	
	}
	gotoxy(FINALWALLX+1,0);
}
void ControlMenu()
{
	char c=0;
	while (c!=' ')
	{ 
		switch(c)
		{
			case 'w':
			case 'W':
			case 0x48:
				if (wait_time>0) 
				{
					wait_time--;
					PrintSelected();
				}
				break;
			case 's':
			case 'S':
			case 0x50:
				if (wait_time<3) 
				{
					wait_time++;
					PrintSelected();
				}
				break;
		}
		c=getch();
	} 
}

void PrintMenu()
{
	int i;
	setcolor(11,0);
	gotoxy(STARTMENUX,STARTMENUY);
	for (i=1;i<=20;i++) cout<<MENU_WALL;
	for (i=5;i<=17;i++)
	{
		gotoxy(i,STARTMENUY);
		cout<<MENU_WALL;
		gotoxy(i,FINALMENUY-1);
		cout<<MENU_WALL;
	}
	gotoxy(FINALMENUX,STARTMENUY);
	for (i=1;i<=21;i++) cout<<MENU_WALL;
	setcolor(7,0);
//  长度线"--------------------------------------"
	gotoxy(STARTMENUX+1,STARTMENUY+2);
	cout<<"                选  项                ";
	gotoxy(STARTMENUX+2,STARTMENUY+2);
	cout<<"  [ ＷＳ或↑↓键选择    空格键确定 ]  ";
	gotoxy(STARTMENUX+3,STARTMENUY+2);
	cout<<"--------------------------------------";
	gotoxy(STARTMENUX+4,STARTMENUY+2);
	cout<<"               极速行进               ";  //wait_time==0
	gotoxy(STARTMENUX+5,STARTMENUY+2);
	cout<<"                                      ";
	gotoxy(STARTMENUX+6,STARTMENUY+2);
	cout<<"               快速行进               ";  //wait_time==1
	gotoxy(STARTMENUX+7,STARTMENUY+2);
	cout<<"                                      ";
	gotoxy(STARTMENUX+8,STARTMENUY+2);
	cout<<"               慢速行进               ";  //wait_time==2
	gotoxy(STARTMENUX+9,STARTMENUY+2);
	cout<<"                                      ";
	gotoxy(STARTMENUX+10,STARTMENUY+2);
	cout<<"               龟速行进               ";  //wait_time==3
	gotoxy(STARTMENUX+11,STARTMENUY+2);
	cout<<"--------------------------------------";
	gotoxy(STARTMENUX+12,STARTMENUY+2);
	cout<<" 按空格键打开/关闭菜单   按空格键暂停 "; 
	PrintSelected();
}
 
void InitSnakeWall()
{
	int x,y;
	for (x=0;x<=24;x++)
		for (y=0;y<=40;y++)
		{
			strcpy(dir[x][y],BLANK);
			strcpy(map[x][y],BLANK);
		}
	for (y=0;y<=40;y++) 
	{
		strcpy(map[0][y],WALL);
		strcpy(map[24][y],WALL);
	}
	for (x=0;x<=24;x++)
	{
		strcpy(map[x][0],WALL);
		strcpy(map[x][40],WALL);
	}
	for (y=4;y<=10;y++)
	{
		strcpy(dir[4][y],RIGHT);
		strcpy(map[4][y],BODY);
	}
	strcpy(map[4][y],RIGHT);
	strcpy(dir[4][y],RIGHT);
	head.X=tail.X=4;
	head.Y=y; tail.Y=4;
	length=7;
}

void PrintMap()
{
	int i,j;
	gotoxy(0,0);
	for (i=0;i<=24;i++) 
	{
		for (j=0;j<=40;j++)
			cout<<map[i][j];
		cout<<endl;
	}
	gotoxy(food.X,food.Y*2);
	setcolor(14,0);
	cout<<FOOD;
	setcolor(7,0);
	gotoxy(FINALWALLX+1,0)
}

void MakeFood()
{
	food.X=rand()%23+1; //1--23 
	food.Y=rand()%39+1; //1--39
	while (strcmp(map[food.X][food.Y],BLANK))
	{
		food.X=rand()%23+1;
		food.Y=rand()%39+1;
	}
	strcpy(map[food.X][food.Y],FOOD);
	gotoxy(food.X,food.Y*2);
	setcolor(14,0);
	cout<<FOOD;
	setcolor(7,0);
	gotoxy(FINALWALLX+1,0)
	length++;
}

void PrintOther()
{
	time_t timep;
	time(&timep);
	setcolor(10,0);
	gotoxy(0,FINALWALLY+2);
	cout<<"当前时间：";
	gotoxy(1,FINALWALLY+2);
	cout<<ctime(&timep);
	gotoxy(3,FINALWALLY+2);
	cout<<"速度："<<160-40*wait_time<<"    ";
	gotoxy(5,FINALWALLY+2);
	cout<<"长度："<<length;
	gotoxy(7,FINALWALLY+2);
	cout<<"蛇头位置：";
	gotoxy(8,FINALWALLY+2);
	cout<<'<'<<setw(3)<<head.X<<','<<setw(3)<<head.Y<<'>'; 
	gotoxy(10,FINALWALLY+2);
	cout<<"蛇尾位置：";
	gotoxy(11,FINALWALLY+2);
	cout<<'<'<<setw(3)<<tail.X<<','<<setw(3)<<tail.Y<<'>';
	gotoxy(13,FINALWALLY+2);
	cout<<"食物位置：";
	gotoxy(14,FINALWALLY+2);
	cout<<'<'<<setw(3)<<food.X<<','<<setw(3)<<food.Y<<'>';
	gotoxy(FINALWALLX+1,0); 
	setcolor(7,0);
}

