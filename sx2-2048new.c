//ʵѵ2ֲӾ�� 1305553156
//��Ϸ2048
//��Ϸ��飨���԰ٶȣ�
//���淨����Ҳ�ǳ��ļ򵥣�һ��ʼ�����ڻ��������2��
//���ֻ��Ҫ������������һ���������ƶ����ֵ����֣�
//���е����־ͻ��򻬶��ķ���£���������Ŀհ׷���ͻ��������һ�����֣�
//��ͬ��������ײʱ����ӿ�£��Ȼ��һֱ���������ϵĵ�������ƴ�ճ�2048������־���ɹ���
//��Ϸ�Ĵ���ܼ򵥾���һ����λ��������Ϊ��������Ϸ��
//��Ҫ�������������ҵĴ���������������2�Ĵ���
//һ��ʼ�����������i,j���������ɳɹ��ĸ��ʺ�С����ܿ���
//֮�����������ɵ�λ����ָ���Ŀ�λ�����ɳɹ��ĸ��ʱ�ɰٷְ��ˣ���Ȼһ�μ���������ˣ���ֻ��һ�Ρ�
//���������Ǽ��̵ġ�������
//����getch���գ��Լ�ʵ�鷢�ְ�һ�¡�������������������Σ���һ�ν��յĶ���-32����75����72����77����80������
//��Ϸ�������˼�����
//������߷�(��������)
//ʧ������Ϸ��֮ǰ���޷�����

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <Windows.h>
#include<math.h>
int num[4][4],max1=0,eyes=0;

#define HEADER1 "          -----------------------------"
#define HEADER2 "          |------|------|------|------|"


void display(int n[][4])//��ʾ4*4
{
	int i,j;
	printf("\n\n\n\n                                           ||||||||||||||||||\n                                          ||||||||||||||||||||\n");
	printf(HEADER1);if(eyes==0){printf("�q||||�|��      �|��||||�r\n");eyes=1;}//�����۾�
	else{printf("�q||||�      �||||�r\n");eyes=0;}
	
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
		if(i==0)  printf("|�t|||o            o  |||�s\n");
		else if(i==1)  printf("|~~~~~~~~~~~~~~~~~~~~~~~\n");
		else if(i==2)  printf("|      �й��\n");
		else printf("|\n");
		if(i==0)
		{printf(HEADER2);printf("  ||�t�q--�r�A�q--�r�s||\n");}
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
			switch((int)(log10(num[i][j])/log10(2))%4)//������ɫ
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
	printf("|      ������+Q234256731\n");
	printf(HEADER1);
	printf("\n          0�ص����˵�,1����Ϸ\n");
}

void shuiji2(int n[][4])//�����������2
{
	struct MAP
	{     	
	int x;
	int y;
	} map[16];
	int i,j,k=0,l;
	for(i=0;i<4;i++)//���0������
		for(j=0;j<4;j++)
			if(n[i][j]==0)
			{
				map[k].x=i;
				map[k].y=j;
				k++;
			}
	srand( (unsigned)time( NULL ) );
	l=rand()%k;//���
	n[map[l].x][map[l].y]=2;
}

int moveleft()
{
	int i,j,k,l,flag;
	for(i=0;i<4;i++)//��λ�ƶ�
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
	for(i=0;i<4;i++)//��ͬ���
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

int win()//�ж�2048
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(num[i][j]==2048)
			{
				printf("2048��ս�ɹ�\n");
				return 1;
			}
	return 0;
}

int lose()  //�ж�ʧ��
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
	printf("��սʧ��\n");
	getch();
	return 1;
}

void Save()//������Ϸ
{
	FILE* fp;
	int i,j;
	fp=fopen("d:\\2048.txt","w");
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			fwrite(&num[i][j],sizeof(int),1,fp);
	fclose(fp);
}
int Cgame()//������Ϸ
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

int Readmax()   //��ȡ��߷�
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

void Savemax(int max)//������߷�
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


void game()  //��Ϸ����
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
			b=getch();//a=-32��75����72����77����80����
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
					printf("�Ƿ������ս����ģʽ(���ܻ���bug)(y/n):");
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
						else printf("������y/n:");
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
			printf("��ȷ�����¿�ʼ(y/n)");
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
				else printf("������y/n:");
			}
		}
	}
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(max<num[i][j])
				max=num[i][j];
	Savemax(max);
	printf("��߳ɼ�Ϊ%d\n",max1);
	printf("��ĳɼ�Ϊ%d\n",max);
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
		while(1)//���˵�
		{
			system("CLS");
			printf("             ||||||||||||||||\n");
			printf("           ||||||||||||||||||||\n");
			printf("          ||||||||||||||||||||||\n");
			printf("        �q||||����      ����||||�r\n");
			printf("        �t||| o            o |||�s\n");
			printf("          ||�t�q--�r�A�q--�r�s|| \n");
			printf("      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			printf("        ***********************\n");
			printf("        *         2048        * \n");
			printf("        *      1 ��ʼ��Ϸ     * \n");
			printf("        *      2 ������Ϸ     * \n");
			printf("        *      3 ��߳ɼ�     * \n");
			printf("        *      4 �˳���Ϸ     * \n");
			printf("        *      5 ��Ϸ˵��     *\n");
			printf("        *                     *\n");
			printf("        ***********************\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			printf("            ������ѡ��:");
			scanf("%s",sel);
			if(strlen(sel)<2&&(sel[0]>'0'&&sel[0]<'6'))
			{select=atoi(sel);break;}
			else{ printf("     ****��������!(���������)****");getch();}
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
			{	printf("        û��¼(���������)");getch();}
			else
			game();
		}
		else if(select==3)
		{
			if(Readmax()==0)
			{	printf("        û��¼(���������)");getch();}
			else
			{
				printf("        ��߷�Ϊ%d\n",max1);
				printf("        ���������");
				getch();
			}
		}
		else if(select==4)
			break;
		else if(select==5)
		{
			printf("        ʹ�ü��̵ġ�����������\n");
			printf("        ���Գ��ֲ\n");
			getch();
		}
	}
}