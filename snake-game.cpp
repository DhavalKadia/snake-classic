#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<winbgim.h>
#include<math.h>

void fileinit();
void player();
int filescan(char c[]);
void fileshow();
void newrecord();
void initpixels();
void init();
void autorun(int mouse);
void show();
void touch();
void Delay(int);

FILE *fp;
int sn[24][40],i,j,score=0,flag=0,del=500,step_down=50,high_score,recent_score,sign,contd=1, phase=1, radii;
int selectLevel = 0;
char name[10],level[10], charBuffer[5], currentLevel[6];

struct mouse
{
	int x;
	int y;
}vector, vector_new;

struct black_hole
{
 int x1;
 int y1;
 int x2;
 int y2;
}b;
struct first
{
int x;
int y;
}f;

struct last
{
int x;
int y;
}l;

struct target
{
int x;
int y;
}t;

struct random
{
int x;
int y;
}r;

int moveClick = 1;

int mouthAngle = 0, mouthFlag = 1;

int main()
{ 
 initwindow(1920, 1080);
 system("cls");
 fileinit();
 fileshow();
 player();
 strcpy(level,"medium");
 init();
 initpixels();

while(contd)
{
	if(phase == 1)
	{
		////////////////////////////////////////////////////////////////
		
		setcolor(CYAN);
		setfillstyle(SOLID_FILL,CYAN);
				
			getmouseclick(WM_MOUSEMOVE, vector.x, vector.y);
			radii = sqrt(pow(vector.x-950,2) + pow(vector.y-150,2));
			if(radii < 200)
			{
				circle(950, 150, 140);
			}
			else
			{
				setbkcolor(BLACK);
				cleardevice();
				circle(950, 150, 100);
			}
			
		
		floodfill(950,150,CYAN);
		
		setbkcolor(CYAN);
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,WHITE);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
		outtextxy(880, 135, "Select");
		
		if(selectLevel)
		{
		////////////////////////////////////////////////////////////////	EASY
		setcolor(GREEN);
		setfillstyle(SOLID_FILL,GREEN);
		
		
			radii = sqrt(pow(vector.x-300,2) + pow(vector.y-550,2));
			if(radii < 200)
			{
				circle(300, 550, 260);
			}
			else
			{
				circle(300, 550, 200);
			}	
		
		
		floodfill(300,550,GREEN);
		
		setbkcolor(GREEN);
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,WHITE);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 8);
		outtextxy(170, 500, "Easy");
		
		////////////////////////////////////////////////////////////////	MEDIUM
		
		setcolor(BLUE);
		setfillstyle(SOLID_FILL,BLUE);
		
			radii = sqrt(pow(vector.x-950,2) + pow(vector.y-550,2));
			if(radii < 200)
			{
				circle(950, 550, 260);
			}
			else
			{
				circle(950, 550, 200);
			}
		
		floodfill(950,550,BLUE);
		
		setbkcolor(BLUE);
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,WHITE);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 7);
		outtextxy(770, 510, "Medium");
		
		//////////////////////////////////////////////////////////////		HARD
		
		setcolor(RED);
		setfillstyle(SOLID_FILL,RED);
		
			radii = sqrt(pow(vector.x-1600,2) + pow(vector.y-550,2));
			if(radii < 200)
			{
				circle(1600, 550, 260);
			}
			else
			{
				circle(1600, 550, 200);
			}
		
		floodfill(1600,550,RED);
		
		setbkcolor(RED);
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,WHITE);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 7);
		outtextxy(1480, 510, "Hard");
			
		//////////////////////////////////////////////////////////////		CHECK LEVEL
		
		//if(ismouseclick(WM_LBUTTONDOWN))
	  	{
			getmouseclick(WM_LBUTTONDOWN, vector.x, vector.y);
			
			radii = sqrt(pow(vector.x-300,2) + pow(vector.y-550,2));
			if(radii < 200)
			{
				del=500;
				step_down=20;
				phase = 2;
				setbkcolor(BLACK);
				cleardevice();
				strcpy(currentLevel, "easy");
			}
				
			radii = sqrt(pow(vector.x-950,2) + pow(vector.y-550,2));
			if(radii < 200)
			{
				del=200;
				step_down=10;
				phase = 2;
				setbkcolor(BLACK);
				cleardevice();
				strcpy(currentLevel, "medium");
			}
				
			radii = sqrt(pow(vector.x-1600,2) + pow(vector.y-550,2));
			if(radii < 200)
			{
				del=80;
				step_down=10;
				phase = 2;
				setbkcolor(BLACK);
				cleardevice();
				strcpy(currentLevel, "hard");
			}
			
			high_score=filescan(currentLevel);				
		}
		}
		
		if(selectLevel == 0)
	  	{
			getmouseclick(WM_LBUTTONDOWN, vector.x, vector.y);
			radii = sqrt(pow(vector.x-950,2) + pow(vector.y-150,2));
			if(radii < 100)
				selectLevel = 1;
		}
		
	}
	else if(phase == 2)
	{	
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,WHITE);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
		outtextxy(1660, 80, "Player Name");	
		
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
		outtextxy(1710, 110, name);	
		
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,WHITE);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
		outtextxy(1635, 200, "Level");
		
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,WHITE);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
		outtextxy(1795, 200, "Score");
		
		setcolor(WHITE);
		circle(1680, 300, 60);
		circle(1680, 300, 61);
		circle(1680, 300, 62);
		setfillstyle(SOLID_FILL,CYAN);		
		floodfill(1680, 300,WHITE);
		
		setfillstyle(SOLID_FILL,WHITE);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
		setbkcolor(CYAN);
		outtextxy(1630, 290, currentLevel);
		setbkcolor(BLACK);		
		//////////////////////////////////////////////////////////
		setcolor(WHITE);
		circle(1835, 300, 60);
		circle(1835, 300, 61);
		circle(1835, 300, 62);
		setfillstyle(SOLID_FILL,BLUE);		
		floodfill(1835, 300,WHITE);
		
		setfillstyle(SOLID_FILL,WHITE);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
		itoa(score, charBuffer, 10);
		setbkcolor(BLUE);
		outtextxy(1825, 290, charBuffer);
		setbkcolor(BLACK);
		
	setfillstyle(SOLID_FILL,WHITE);
	circle(1757, 783, 100);
	
	setfillstyle(CLOSE_DOT_FILL, GREEN);
	sector(1757, 783, 45, 135, 100, 97);
	
	setfillstyle(CLOSE_DOT_FILL, RED);
	sector(1757, 783, 135,225, 100, 97);
	
	setfillstyle(CLOSE_DOT_FILL, YELLOW);
	sector(1757, 783, 225,315, 100, 97);
	
	setfillstyle(CLOSE_DOT_FILL, BLUE);
	sector(1757, 783, 45, 135, 100, 97);
	
	setfillstyle(CLOSE_DOT_FILL, BLUE);
	sector(1757, 783, 315, 45, 100, 97);
	  
      if(ismouseclick(WM_LBUTTONDOWN))
	  {
		getmouseclick(WM_LBUTTONDOWN, vector.x, vector.y);
		
		if(sqrt(pow(vector.x-1757,2) + pow(vector.y-783,2)) < 100)
		{
			vector.x -= 1757;	vector.y -= 783;
			vector_new.y = vector.y*cos(0.785) - vector.x*sin(0.785);
			vector_new.x = vector.y*sin(0.785) + vector.x*cos(0.785);
			
			if(vector_new.x > 0)
			{
				if(vector_new.y > 0)
				{
					moveClick = 4;
				}
				else
				{
					moveClick = 1;
				}
			}
			else
			{
				if(vector_new.y > 0)
				{
					moveClick = 3;
				}
				else
				{
					moveClick = 2;
				}
			}
		}
		show();
	  }
	  else
	  {
		//system("cls");
		autorun(moveClick);
		show();
		delay(del);
	  }	
	}
	else if(phase == 3)
	{
		setbkcolor(BLACK);
		cleardevice();
				
		setcolor(RED);
		setfillstyle(SOLID_FILL,RED);
		
			radii = sqrt(pow(vector.x-1450,2) + pow(vector.y-550,2));
			if(radii < 200)
			{
				circle(960, 550, 350);
			}
			else
			{
				circle(960, 550, 300);
			}
		
		floodfill(960,550,RED);
		
		
		setbkcolor(RED);
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,WHITE);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 30);
		itoa(recent_score, charBuffer, 10);
		outtextxy(910, 480, charBuffer);
		setbkcolor(BLACK);
		
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
		outtextxy(500, 100, "Now your Score is Highest");
		
	}
	else if(phase == 4)
	{
		setbkcolor(BLACK);
		cleardevice();
				
		getmouseclick(WM_MOUSEMOVE, vector.x, vector.y);
		
		setbkcolor(BLACK);
		cleardevice();
		
		setcolor(BLUE);
		setfillstyle(SOLID_FILL,BLUE);
		
		
			radii = sqrt(pow(vector.x-500,2) + pow(vector.y-550,2));
			if(radii < 200)
			{
				circle(500, 550, 350);
			}
			else
			{
				circle(500, 550, 300);
			}	
		
		
		floodfill(500,550,BLUE);
		
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,WHITE);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 40);
		itoa(high_score, charBuffer, 10);
		setbkcolor(BLUE);
		outtextxy(440, 470, charBuffer);
		setbkcolor(BLACK);
									
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
		outtextxy(250, 100, "Highest Score");
		
		///////////////////////////////////////////////////////////
		
		setcolor(RED);
		setfillstyle(SOLID_FILL,RED);
		
			radii = sqrt(pow(vector.x-1450,2) + pow(vector.y-550,2));
			if(radii < 200)
			{
				circle(1450, 550, 350);
			}
			else
			{
				circle(1450, 550, 300);
			}
		
		floodfill(1450,550,RED);
		
		
		setbkcolor(RED);
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,WHITE);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 40);
		itoa(recent_score, charBuffer, 10);
		outtextxy(1400, 480, charBuffer);
		setbkcolor(BLACK);
		
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
		outtextxy(1250, 100, "Your Score");
		
		//////////////////////////////////////////////////
		
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,WHITE);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 20);
		setbkcolor(BLACK);
									
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
		outtextxy(830, 30, "You lost");
		
	}
	delay(del*0.8);
}
getch();
return 1;
}

void Delay(int s)
{
 for(int i=0;i<15*s;i++)
  for(int j=0;j<i;j++);
}


void autorun(int move)
{
 int maxn=0;

 if(move % 2 == 1)
 {
	if(move == 1)
		{
			sign=1;
		    if(f.y==(40-1))
				f.y=-1;
		}
    else
		{
			sign=-1;
			if(f.y==0)
				f.y=40;
		}
    if(sn[f.x][f.y+sign]==-3)
		{	touch(); return;	}
    else if(sn[f.x][f.y+sign]>0&&flag)
		{	touch(); return;	}
    else
		{
			if(f.x==t.x&&f.y==t.y)
			{
				score++;
				if(del>=200)
				del-=step_down;
				while(sn[r.x=rand()%24][r.y=rand()%40]==0)
					{
						if(r.x<0)	r.x*=-1;
						if(r.y<0)	r.y*=-1;
						t.x=r.x;
						t.y=r.y;
					}
				sn[t.x][t.y]=-2;

				for(i=0;i<24;i++)
					{
						for(j=0;j<40;j++)
							{
								if(sn[i][j]>0)
								sn[i][j]++;
							}
					}
				if(sn[f.x][f.y+sign]!=-4)
					{
						sn[f.x][f.y+sign]=1;
						f.y+=sign;
					}
				flag=1;

			}
			else
			{
				if(sn[f.x][f.y+sign*2]==-2)
				{
					mouthAngle = 85;
				}
				
				if(sn[f.x][f.y+sign]==-2 && mouthAngle < 35)
				{
					mouthAngle = 85;
				}
				
				if(sn[f.x][f.y+sign]==-4)
					{
						if(f.x==b.x1&&(f.y+sign)==b.y1)
							{	f.x=b.x2;	f.y=b.y2;	}
						else
							{	f.x=b.x1;	f.y=b.y1;	}
					}
				else
					{
						sn[f.x][f.y+sign]=1;
						f.y+=sign;
						sn[l.x][l.y]=0;
					}
				for(i=0;i<24;i++)
					{
						for(j=0;j<40;j++)
							{
								if(((i!=f.x)||(j!=f.y))&&(sn[i][j]!=0)&&(sn[i][j]!=-2)&&(sn[i][j]!=-3)&&(sn[i][j]!=-4))
								sn[i][j]++;
								if(sn[i][j]>maxn)
									{
										l.x=i; l.y=j;
										maxn=sn[i][j];
									}
							}
					}
			}
	}
 }

 else
 {
	if(move == 4)
		{
			sign=1;
			if(f.x==23)
				f.x=-1;
		}
	else
		{
			sign=-1;
			if(f.x==0)
				f.x=24;
		}

	if(sn[f.x+sign][f.y]==-3)
	{		
		touch(); 
		return;	
	}
	else if(sn[f.x+sign][f.y]>0&&flag)
	{		
		touch(); 
		return;	
	}
	else
	{
		if(f.x==t.x&&f.y==t.y)
		{
			score++;
			if(del>=200)
				del-=step_down;
				
			while(sn[r.x=rand()%24][r.y=rand()%40]==0)
			{
				if(r.x<0)	
					r.x*=-1;
				if(r.y<0)	
					r.y*=-1;
							
				t.x=r.x;
				t.y=r.y;
			}

					sn[t.x][t.y]=-2;
					for(i=0;i<24;i++)
						{
							for(j=0;j<40;j++)
								{
									if(sn[i][j]>0)
										sn[i][j]++;
								}
						}
					if(sn[f.x+sign][f.y]!=-4)
						{
							sn[f.x+sign][f.y]=1;
							f.x+=sign;
						}
					flag=1;
				}
			else
				{
					if(sn[f.x+sign*2][f.y]==-2)
				{
					mouthAngle = 85;
				}
				
				if(sn[f.x+sign][f.y]==-2 && mouthAngle < 35)
				{
					mouthAngle = 85;
				}
				    if(sn[f.x+sign][f.y]==-4)
						{
							if((f.x+sign)==b.x1&&f.y==b.y1)
								{	f.x=b.x2;	f.y=b.y2;	}
							else
								{	f.x=b.x1;	f.y=b.y1;	}
						}
					else
						{
							sn[f.x+sign][f.y]=1;
							f.x+=sign;
							sn[l.x][l.y]=0;
						}
					for(i=0;i<24;i++)
						{
							for(j=0;j<40;j++)
								{
									if(((i!=f.x)||(i!=f.x))&&(sn[i][j]!=0)&&(sn[i][j]!=-2)&&(sn[i][j]!=-3)&&(sn[i][j]!=-4))
									sn[i][j]++;
									if(sn[i][j]>maxn)
										{
											l.x=i; l.y=j;
											maxn=sn[i][j];
										}
								}
						}
				}
		}
  }
}

void show()
{
 char x;
 int rotate;
 
 for(i=0;i<24;i++)
 {
  for(j=0;j<40;j++)
   {
    if(sn[i][j]>1)
		x='#';
    else if(sn[i][j]==1)
	{
		if(moveClick == 1)
		{
			rotate = 0;
			x='>';
		}
	    else if(moveClick == 3)
		{
			rotate = 180;
			x='<';
		}
		else if(moveClick == 4)
		{
			rotate = 270;
			x='v';
		}	
		else if(moveClick == 2)
		{
			rotate = 90;
			x='^';
		}	
	}
    else if(sn[i][j]==0)
		x='9';
    else if(sn[i][j]==-2)
		x='@';
    else if(sn[i][j]==-3)
		x='X';
    else if(sn[i][j]==-4)
		x='O';
    //printf("%3c",x);
    //putpixel(j,i,x%16);
    setfillstyle(SOLID_FILL,x%16);
    	
    if(sn[i][j] == 1)
    {
    	setfillstyle(CLOSE_DOT_FILL, GREEN);
    	//bar(j*40, (i+2)*40, j*40 + 20, (i+2)*40 + 40);
    	//sector(j*40 + 20, (i+1)*40 + 20, rotate + abs(85*sin(mouthAngle*3.14/180)), rotate + 360 - abs(85*sin(mouthAngle*3.14/180)), 20,20);
    	sector(j*40 + 20, (i+1)*40 + 20, rotate + mouthAngle, rotate + 360 - mouthAngle, 20,20);
    	
    	if(mouthAngle > 30)    	
    		mouthFlag = -1;
    	else if(mouthAngle < 5)
    		mouthFlag = 1;
		
    	mouthAngle += mouthFlag*5;    	
	}
	//else if(sn[i][j] > 0)
	//	circle(j*40 + 20, (i+1)*40 + 20, 20);
    else    	
   		bar(j*40, (i+1)*40, j*40 + 40, (i+1)*40 + 40);
   }
  //printf("\n");

 }
//printf("\t\t\t\t     SCORE=%d\t\t(c) of Dhaval Kadia :-)",score);

}

void touch()
{
 //contd=0;
 recent_score=score;
 if(recent_score>high_score)
 {
 	phase = 3;
 	newrecord();
 }	
 else
 {
 	phase = 4;
 	printf("\nYou lost!!!\n");
 }   
 //getch();
}
void init()
{
 //Delay(1000);
 system("cls");
 printf("\t\t\t\t     By\n\n\n\n\t\t\t\tDhaval Kadia\n\n\n\n\t\t\t\t   BE-II\n\n\n\n\t\t\t   Computer Sci. & Engr.\n\n\n\n\t\t\t\t    MSU");
 //Delay(2000);
 system("cls");
 printf("\t\t\t\t\t READY");
 //Delay(1500);
 system("cls");
 printf("\t\t\t\t       STEADY");
 //Delay(1500);
 system("cls");
 printf("\t\t\t\t      GO  !!!");
 //Delay(1500);
 system("cls");

}


void fileinit()
{
	fp=fopen("GAMELOG.TXT","a+");
}

void player()
{
    int l;
	printf("\n\nEnter your name=");
	scanf("%s",name);
	/*printf("\n\nSelect level :\teasy=1\t   medium=2\thard=3\n");
	printf("\nEnter choice number=");
	scanf("%d",&l);

	if(l==1)
		{
			strcpy(level,"easy");
			del=1500;
			step_down=10;
		}
	else if(l==2)
		{
			strcpy(level,"medium");
			del=1000;
			step_down=50;
		}
	else if(l==3)
		{
			strcpy(level,"hard");
			del=850;
			step_down=50;
		}
	*/

}

int filescan(char level[])
{
	char scan_name[10];
	char scan_level[10];
	int scan_score,max=0;

	fseek(fp,0,0);
	while(feof(fp)==0)
		{
			fscanf(fp,"%s %s %d",scan_name,scan_level,&scan_score);
			if(strcmp(scan_level,level)==0)
				max=(scan_score>max)?scan_score:max;
		}

	return max;
}

void fileshow()
{
	char scan_name[10];
	char scan_level[10];
	int scan_score;//max=0;

	fseek(fp,0,0);
	printf("\n\n\t\t\tPREVIOUS SCORES");
	while(feof(fp)==0)
		{
			fscanf(fp,"%s %s %d",scan_name,scan_level,&scan_score);
			printf("\n%s\t%s\t%d",scan_name,scan_level,scan_score);
		}
}

void initpixels()
{
 srand(time(NULL));
 f.x=0; f.y=3;
 l.x=0; l.y=0;

 //vector='r';
 for(i=0;i<24;i++)
 {
  for(j=0;j<40;j++)
   {
    sn[i][j]=0;
   }
 }
 //vector=99;  		// forced fixed
 sn[f.x][f.y]=1;
 sn[l.x][l.y]=4; sn[0][1]=3; sn[0][2]=2;
 sn[4][4]=sn[5][4]=sn[6][4]=sn[7][4]=sn[8][4]=sn[9][4]=sn[10][4]=-3;
 sn[11][4]=sn[11][5]=sn[11][6]=sn[11][7]=-3;
 sn[6][10]=sn[6][11]=sn[6][12]=sn[6][13]=sn[6][14]=-3;
 sn[7][14]=sn[8][14]=sn[9][14]=sn[10][14]=-3;
 sn[4][20]=sn[5][20]=sn[6][20]=sn[7][20]=sn[8][20]=-3;
 sn[19][21]=sn[19][22]=sn[19][23]=-3;
 sn[16][23]=sn[17][23]=sn[18][23]=-3;
 sn[17][7]=sn[17][8]=sn[17][9]=sn[17][10]=-3;
 b.x1=3; b.y1=2;
 b.x2=15; b.y2=16;
 sn[b.x1][b.y1]=sn[b.x2][b.y2]=-4;
 while(sn[r.x=1+rand()%23][r.y=1+rand()%(40-1)]==0)
			{
			 if(r.x<0)	r.x*=-1;
			 if(r.y<0)	r.y*=-1;
				 t.x=r.x;
			 t.y=r.y;
			}
 sn[t.x][t.y]=-2;
 if(phase == 2)
 show();
}

void newrecord()
{
	printf("\n\t\t\tNEW RECORD!!!");
	printf("\n\nplayer:%s",name);
	printf("\nlevel:%s",level);
	printf("\nnew highscore:%d",recent_score);
	fileinit();
	fprintf(fp,"\n");
	fprintf(fp,"%s %s %d",name,level,recent_score);
	fileshow();
}
