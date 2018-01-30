#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>

void earthmotion(int xrad, int yrad, int midx, int midy, int xe[130], int ye[130])
{
	int i,j = 0;
	for (i = 0; i < 360; i = i + 3)
	{
		xe[j] = midx - (xrad * cos((i * 3.14) / 180));
		ye[j++] = midy - (yrad * sin((i * 3.14) / 180));
	}
}
void moonmotion(int xrad, int yrad, int midx, int midy, int xm[36], int ym[36])
{
	int i,j = 0;
	for (i = 0; i < 360; i = i + 10)
	{
		xm[j] = midx - (xrad * cos((i * 12.56) / 180));
		ym[j++] = midy - (yrad * sin((i * 12.56) / 180));
	}
}
void length(int xrad, int yrad, int midx, int midy, int xl[60], int yl[60])
{
	int i,j = 0;
	for (i = 360; i > 0; i = i - 6)
	{
		xl[j] = midx - (xrad * cos((i * 3.14) / 180));
		yl[j++] = midy - (yrad * sin((i * 3.14) / 180));
	}
}

int main()
{
	int gd = DETECT, gm;
	int i = 0, j, midx, midy,c=0,e=0;
	int xe[120], ye[120],xm[36], ym[36],xl[60],yl[60];
	int pos=0,pos1=0,d=6;
	initgraph(&gd, &gm, "C:/TURBOC3/BGI");
	midx = getmaxx() / 2;
	midy = getmaxy() / 2;
	setbkcolor(RED);
	earthmotion(230, 130, midx, midy, xe, ye);
	while (!kbhit())
	{
		     setcolor(BLUE);
		     outtextxy(150,30,"  REVOLUTION AND ROTATION OF EARTH AND MOON.");
		     length(150,100,midx-30, midy, xl, yl);
			for(i=0;i<60;i+=6)
			{
				setcolor(10);
				setlinestyle(3,0,1);
				line(midx-30, midy, xl[i], yl[i]);
			}
			length(120,90, midx-30, midy, xl, yl);
			for(i=0;i<60;i+=4)
			{
				setcolor(10);
				line(midx-30, midy, xl[i], yl[i]);
			}
		setcolor(13);
		ellipse(midx, midy, 0, 360, 230, 130);
		ellipse(xe[pos], ye[pos], 0, 360, 70 ,30);
		moonmotion(70, 30, xe[pos], ye[pos], xm, ym);
		//drawing sun
		setcolor(YELLOW);
		setfillstyle(1, YELLOW);
		circle(midx-30, midy, 30);
		floodfill(midx-30, midy, YELLOW);
		//drawing earth
		setcolor(BLUE);
		setfillstyle(1, BLUE);
		circle(xe[pos], ye[pos], 15);
		floodfill(xe[pos],ye[pos],BLUE);
		setcolor(WHITE);
		arc(xe[pos],ye[pos],270+e,90+e,15);

		//drawing texture
		setcolor(GREEN);
		arc(xe[pos]-19+c,ye[pos],315+d,50-d,10);
		arc(xe[pos]-19+c,ye[pos],315+d,50-d,13);
		arc(xe[pos]-19+c,ye[pos],315+d,50-d,16);
		arc(xe[pos]+19-c,ye[pos],130+d,235-d,10);
		arc(xe[pos]+19-c,ye[pos],130+d,235-d,13);
		arc(xe[pos]+19-c,ye[pos],130+d,235-d,16);
		//dwaring moon
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,WHITE);
		pieslice(xm[pos1], ym[pos1], 0, 360, 10);
		setcolor(YELLOW);
		circle(xm[pos1],ym[pos1],10);
		//checking for one complete rotation
			if (pos <= 0)
			{
				pos = 119;
			}
			else
			{
				pos = pos - 1;
			}
			if(pos1<=0)
				pos1=35;
			else
				pos1=pos1-1;

			c=c+6;
			if(c==18)
				c=0;
			d=d+2;
			if(d==20)
				d=4;
			e=e+3;
			if(e==360)
				e=0;
		delay(250);
		cleardevice();
	}
	closegraph();
	return 0;
  }