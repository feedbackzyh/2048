//实训2植泳辉 1305553156
//游戏2048
//游戏简介（来自百度）
//在玩法规则也非常的简单，一开始方格内会出现两个2，
//玩家只需要上下左右其中一个方向来移动出现的数字，
//所有的数字就会向滑动的方向靠拢，而滑出的空白方块就会随机出现一个数字，
//相同的数字相撞时会叠加靠拢，然后一直这样，不断的叠加最终拼凑出2048这个数字就算成功。
//游戏的代码很简单就是一个二位整形数组为基础的游戏。
//主要代码是上下左右的代码和随机生成数字2的代码
//一开始随机数是生成i,j但发现生成成功的概率很小，会很卡。
//之后改了随机生成的位置是指定的空位，生成成功的概率变成百分百了，虽然一次计算次数多了，但只用一次。
//上下左右是键盘的←↑→↓
//利用getch接收，自己实验发现按一下←（↑→↓）会接收两次，第一次接收的都是-32，（75←；72↑；77→；80↓）；
//游戏可以退了继续；
//设有最高分(最大的数字)
//失败了游戏，之前的无法继续

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <Windows.h>
#include<math.h>
int num[4][4],max1=0,eyes=0;

#define HEADER1 "          -----------------------------"
#define HEADER2 "          |------|------|------|------|"


void display(int n[][4])//显示4*4
{
	int i,j;
	printf("\n\n\n\n                                           ||||||||||||||||||\n                                          ||||||||||||||||||||\n");
	printf(HEADER1);if(eyes==0){printf("╭||||▅━      ▅━||||╮\n");eyes=1;}//会变得眼睛
	else{printf("╭||||☆━      ☆━||||╮\n");eyes=0;}
	
	for(i=0;i<3;i++)
	{
		printf("          ");
		for(j=0;j<4;j++)
		{
			if(n[i][j]==0)
				printf("|      ");
			else 
			{
				printf("|");
				switch((int)(log10(num[i][j])/log10(2))%4)
				{
					case 0:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);break;
					case 1:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_GREEN);break;
					case 2:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN);break;
					case 3:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_BLUE);break;
				}
				printf("%5d ",n[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
				
		}
		if(i==0)  printf("|╰|||o            o  |||╯\n");
		else if(i==1)  printf("|~~~~~~~~~~~~~~~~~~~~~~~\n");
		else if(i==2)  printf("|      招广告\n");
		else printf("|\n");
		if(i==0)
		{printf(HEADER2);printf("  ||╰╭--╮ˋ╭--╮╯||\n");}
		else {printf(HEADER2);printf("\n");}
	}
	printf("          ");
	for(j=0;j<4;j++)
	{
		if(n[i][j]==0)
			printf("|      ");
		else 
		{
			printf("|");
			switch((int)(log10(num[i][j])/log10(2))%4)//字体颜色
			{
				case 0:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);break;
				case 1:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_GREEN);break;
				case 2:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN);break;
				case 3:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_BLUE);break;
			}
			printf("%5d ",n[i][j]);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
	}
	printf("|      有意者+Q234256731\n");
	printf(HEADER1);
	printf("\n          0回到主菜单,1新游戏\n");
}

void shuiji2(int n[][4])//随机生成数字2
{
	struct MAP
	{     	
	int x;
	int y;
	} map[16];
	int i,j,k=0,l;
	for(i=0;i<4;i++)//检查0的坐标
		for(j=0;j<4;j++)
			if(n[i][j]==0)
			{
				map[k].x=i;
				map[k].y=j;
				k++;
			}
	srand( (unsigned)time( NULL ) );
	l=rand()%k;//随机
	n[map[l].x][map[l].y]=2;
}

int moveleft()
{
	int i,j,k,l,flag;
	for(i=0;i<4;i++)//空位移动
	{
		for(j=0;j<3;j++)
		{
			if(num[i][j]==0)
			{
				l=j;
				for(k=j;k<4;k++)
				{
					if(num[i][k]!=0)
					{
						num[i][l]=num[i][k];
						num[i][k]=0;
						flag=1;
						l++;
					}
				}
			}
		}
	}
	for(i=0;i<4;i++)//相同相加
		for(j=0;j<3;j++)
		{
			if(num[i][j]==num[i][j+1])
			{
				if(num[i][j]!=0)
					flag=1;
				num[i][j]*=2;
				for(k=j+1;k<3;k++)
					num[i][k]=num[i][k+1];
				num[i][k]=0;
			}
		}
	return flag;
}

int moveup()
{
	int i,j,k,l,flag;
	for(j=0;j<4;j++)
	{
		for(i=0;i<3;i++)
		{
			if(num[i][j]==0)
			{
				l=i;
				for(k=i;k<4;k++)
				{
					if(num[k][j]!=0)
					{
						num[l][j]=num[k][j];
						num[k][j]=0;
						flag=1;
						l++;
					}
				}
			}
		}
	}
	for(j=0;j<4;j++)
		for(i=0;i<3;i++)
		{
			if(num[i][j]==num[i+1][j])
			{
				if(num[i][j]!=0)
					flag=1;
				num[i][j]*=2;
				for(k=i+1;k<3;k++)
					num[k][j]=num[k+1][j];
				num[k][j]=0;
			}
		}
	return flag;
}


int moveright()
{
	int i,j,k,l,flag;
	for(i=3;i>=0;i--)
	{
		for(j=3;j>0;j--)
		{
			if(num[i][j]==0)
			{
				l=j;
				for(k=j;k>=0;k--)
				{
					if(num[i][k]!=0)
					{
						num[i][l]=num[i][k];
						num[i][k]=0;
						flag=1;
						l--;
					}
				}
			}
		}
	}
	for(i=3;i>=0;i--)
		for(j=3;j>0;j--)
		{
			if(num[i][j]==num[i][j-1])
			{
				if(num[i][j]!=0)
					flag=1;
				num[i][j]*=2;
				for(k=j-1;k>0;k--)
					num[i][k]=num[i][k-1];
				num[i][k]=0;
			}
		}
	return flag;
}

int movedown()
{
	int i,j,k,l,flag;
	for(j=3;j>=0;j--)
	{
		for(i=3;i>0;i--)
		{
			if(num[i][j]==0)
			{
				l=i;
				for(k=i;k>=0;k--)
				{
					if(num[k][j]!=0)
					{
						num[l][j]=num[k][j];
						num[k][j]=0;
						flag=1;
						l--;
					}
				}
			}
		}
	}
	for(j=3;j>=0;j--)
		for(i=3;i>0;i--)
		{
			if(num[i][j]==num[i-1][j])
			{
				if(num[i][j]!=0)
					flag=1;
				num[i][j]*=2;
				for(k=i-1;k>0;k--)
					num[k][j]=num[k-1][j];
				num[k][j]=0;
			}
		}
	return flag;
}

int win()//判断2048
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(num[i][j]==2048)
			{
				printf("2048挑战成功\n");
				return 1;
			}
	return 0;
}

int lose()  //判断失败
{	
	FILE* fp;
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(num[i][j]==0)
				return 0;
	for(i=0;i<4;i++)
		for(j=0;j<3;j++)
			if(num[i][j]==num[i][j+1])
				return 0;
	for(j=0;j<4;j++)
		for(i=0;i<3;i++)
			if(num[i][j]==num[i+1][j])
				return 0;
	system("CLS");
	display(num);
	fp=fopen("d:\\2048.txt","w");
	fread(&num[0][0],sizeof(int),1,fp);
	fclose(fp);
	printf("挑战失败\n");
	getch();
	return 1;
}

void Save()//保存游戏
{
	FILE* fp;
	int i,j;
	fp=fopen("d:\\2048.txt","w");
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			fwrite(&num[i][j],sizeof(int),1,fp);
	fclose(fp);
}
int Cgame()//继续游戏
{
	FILE* fp;
	int i,j;
	fp=fopen("d:\\2048.txt","a+");
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(fread(&num[i][j],sizeof(int),1,fp)!=1)
			{
				fclose(fp);
				return 0;
			}
	fclose(fp);
	return 1;
}

int Readmax()   //读取最高分
{
	FILE* fp;
	fp=fopen("d:\\2048max.txt","r");
	if(fread(&max1,sizeof(int),1,fp)!=1)
	{
		
		fclose(fp);
		return 0;
	}
	fclose(fp);
	return 1;
}

void Savemax(int max)//保存最高分
{
	FILE* fp;
	fp=fopen("d:\\2048max.txt","w");
	if(max>max1)
	{
		fwrite(&max,sizeof(int),1,fp);
		max1=max;
	}
	else
	{
		fwrite(&max1,sizeof(int),1,fp);
	}
	fclose(fp);
}


void game()  //游戏本体
{
	char ch,a,b;
	int max,i,j,flag1,flag2;
	flag2=1;
	max=0;
	while(1)
	{
		flag1=0;
		system("CLS");
		display(num);
		a=getch();
		if(a==-32)
		{	
			b=getch();//a=-32，75←；72↑；77→；80↓；
			switch(b)
			{
				case 75:flag1=moveleft();break;
				case 72:flag1=moveup();break;
				case 77:flag1=moveright();break;
				case 80:flag1=movedown();break;
			}
			if(flag1==1)
			{	
				shuiji2(num);
				if(win()==1&&flag2==1)
				{
					printf("是否继续挑战无限模式(可能会有bug)(y/n):");
					while(1)
					{
						ch=getchar();
						if(ch=='y'||ch=='Y')
						{
							flag2=0;
							break;
						}
						else if(ch=='n'||ch=='N')
						{
							flag2=1;
							break;
						}
						else printf("请输入y/n:");
					}
					if(flag2==1) break;
				}
				else if(lose()==1) break;
				Save();
			}
		}
		if(a=='0') return;
		if(a=='1')
		{
			printf("请确认重新开始(y/n)");
			while(1)
			{
				ch=getchar();
				if(ch=='y'||ch=='Y')
				{
					for(i=0;i<4;i++)
						for(j=0;j<4;j++)
							num[i][j]=0;
					shuiji2(num);
					shuiji2(num);
					break;
				}
				else if(ch=='n'||ch=='N')
				{
					break;
				}
				else printf("请输入y/n:");
			}
		}
	}
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(max<num[i][j])
				max=num[i][j];
	Savemax(max);
	printf("最高成绩为%d\n",max1);
	printf("你的成绩为%d\n",max);
	getch();
	getch();
}


main()
{
	char sel[20];
	int select,i,j;
	Readmax();
	while(1)
	{
		while(1)//主菜单
		{
			system("CLS");
			printf("             ||||||||||||||||\n");
			printf("           ||||||||||||||||||||\n");
			printf("          ||||||||||||||||||||||\n");
			printf("        ╭||||━━      ━━||||╮\n");
			printf("        ╰||| o            o |||╯\n");
			printf("          ||╰╭--╮ˋ╭--╮╯|| \n");
			printf("      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			printf("        ***********************\n");
			printf("        *         2048        * \n");
			printf("        *      1 开始游戏     * \n");
			printf("        *      2 继续游戏     * \n");
			printf("        *      3 最高成绩     * \n");
			printf("        *      4 退出游戏     * \n");
			printf("        *      5 游戏说明     *\n");
			printf("        *                     *\n");
			printf("        ***********************\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			printf("            请输入选择:");
			scanf("%s",sel);
			if(strlen(sel)<2&&(sel[0]>'0'&&sel[0]<'6'))
			{select=atoi(sel);break;}
			else{ printf("     ****输入有误!(任意键继续)****");getch();}
		}
		if(select==1)
		{
			for(i=0;i<4;i++)
				for(j=0;j<4;j++)
					num[i][j]=0;
			shuiji2(num);
			shuiji2(num);
			game();
		}
		else if(select==2)
		{
			if(Cgame()==0)
			{	printf("        没记录(任意键继续)");getch();}
			else
			game();
		}
		else if(select==3)
		{
			if(Readmax()==0)
			{	printf("        没记录(任意键继续)");getch();}
			else
			{
				printf("        最高分为%d\n",max1);
				printf("        任意键继续");
				getch();
			}
		}
		else if(select==4)
			break;
		else if(select==5)
		{
			printf("        使用键盘的↑↓←→操作\n");
			printf("        编程猿：植\n");
			getch();
		}
	}
}