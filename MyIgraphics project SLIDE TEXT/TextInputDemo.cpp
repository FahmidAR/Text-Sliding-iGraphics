# include "iGraphics.h"
#include<stdio.h>

char str[100], str2[100];
int len,len2,move_x;
int mode;
int x=390,y=100;
int r=137,g=80,b=80;
int x1=30;
int i;

void text()
  {
   if(r>255&&g>255&&b>255)
   {
       r=0;
       g=0;
       b=0;
       r=r*2+10;
       g=g+30;
       b=b&3+30;
   }
   else{
        r=r+10;
        g=g+10;
        b=b+10;
       }
    if(x<=0)
    {
        x=400;
        x=x-10;
    }
    else x=x-10;
  }

void iDrawSeg(int s1,int s2,int s3,int s4,int s5,int s6,int s7)
      {
       if(s1==1) iFilledRectangle(x+x1*i,y,3,20);
       if(s2==1) iFilledRectangle(x+x1*i,y+25,3,20);
       if(s3==1) iFilledRectangle(x+3+x1*i,y+21,20,3);
       if(s4==1) iFilledRectangle(x+3+x1*i,y+46,20,3);
       if(s5==1) iFilledRectangle(x+3+x1*i,y-1,20,3);
       if(s6==1) iFilledRectangle(x+22+x1*i,y,3,20);
       if(s7==1) iFilledRectangle(x+22+x1*i,y+25,3,20);

      }
void drawTextBox()
{
	iSetColor(150, 150, 150);
	iRectangle(50, 250, 250, 30);
}

/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here
	iClear();

	drawTextBox();
	if(mode == 1)
	{
		iSetColor(255, 255, 255);
		iText(55, 260, str);
    }
	iText(10, 10, "Click to activate the box, enter to finish.");


	 iSetColor(r,g,b);
	 for(i=0;i<len;i++)
        {
            if(str[i]=='0') iDrawSeg(1,1,0,1,1,1,1);
            else if(str[i]=='1') iDrawSeg(1,1,0,0,0,0,0);
            else if(str[i]=='2') iDrawSeg(1,0,1,1,1,0,1);
            else if(str[i]=='3') iDrawSeg(0,0,1,1,1,1,1);
            else if(str[i]=='4') iDrawSeg(0,1,1,0,0,1,1);
            else if(str[i]=='5') iDrawSeg(0,1,1,1,1,1,0);
            else if(str[i]=='6') iDrawSeg(1,1,1,1,1,1,0);
            else if(str[i]=='7') iDrawSeg(0,0,0,1,0,1,1);
            else if(str[i]=='8') iDrawSeg(1,1,1,1,1,1,1);
            else if(str[i]=='9') iDrawSeg(0,1,1,1,1,1,1);
            else if(str[i]=='A') iDrawSeg(1,1,1,1,0,1,1);
            else if(str[i]=='b') iDrawSeg(1,1,1,0,1,1,0);
            else if(str[i]=='C') iDrawSeg(1,1,0,1,1,0,0);
            else if(str[i]=='D') iDrawSeg(1,1,0,1,1,1,1);
            else if(str[i]=='E') iDrawSeg(1,1,1,1,1,0,0);
            else if(str[i]=='F') iDrawSeg(1,1,1,1,0,0,0);
            else iDrawSeg(0,0,0,0,0,0,0);
        }


}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if(mx >= 50 && mx <= 300 && my >= 250 && my <= 280 && mode == 0)
		{
			mode = 1;
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	int i;
	if(mode == 1)
	{
        if(key == '\r')
		{
			mode = 0;
			strcpy(str2, str);
			printf("%s\n",str2);
     		move_x=400;
			for(i=0;i<len;i++)
                str[i]=0;
                len=0;
		}
		else
		{
			if(len==0)
            {
                for(i=0;i<len2;i++)
                {
                    str2[i]=0;
                }
            }
            str[len]=key;
            len++;
		}
	}

	if(key == 'x')
	{
	   // gets(str);
	    //printf("%s",str);
		//do something with 'x'
		exit(0);
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{   int i;
	    gets(str);
	    len=strlen(str);
//	    for(i=0;i<len;i++) iDrawSeg(str[i]);
		exit(0);
	}

	//place your codes for other keys here
}
//void iShowBMP(50,50,char str[200]);
int main()
{
	//place your own initialization codes here.
	len = 0;
	mode = 0;
	str[0]= 0;
	iSetTimer(1000,text);
	iInitialize(400, 400, "TextInputDemo");
	return 0;
}
