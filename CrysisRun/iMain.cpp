# include "iGraphics.h"
#define jumplim 190

bool jumpup= false;
bool jumpdown=false;
bool left=false;
bool right=false;
bool stand=true;
bool sound=true;

int pressed=0;
int t;
int r=255,g=255,b=255;
char boyF[7][15]={"char\\1.bmp","char\\2.bmp","char\\3.bmp","char\\4.bmp","char\\5.bmp","char\\6.bmp","char\\7.bmp"};
char boyB[7][15]={"charback\\1.bmp","charback\\2.bmp","charback\\3.bmp","charback\\4.bmp","charback\\5.bmp","charback\\6.bmp","charback\\7.bmp"};
char boystand [15]={"char\\1.bmp"};
char bomb[8][15]={"Bomb\\bomb1.bmp","Bomb\\bomb2.bmp","Bomb\\bomb3.bmp","Bomb\\bomb4.bmp","Bomb\\bomb5.bmp","Bomb\\bomb6.bmp","Bomb\\bomb7.bmp","Bomb\\bomb8.bmp"};
int boyX=443;
int boyY=37;
int boyindex=0;
int bombindex=0;
int bombX=1000;
int bombY=45;

void rgb()
{
	r= rand() % 255;
	g= rand() % 255;
	b= rand() % 255;

}
void bombmove()
{
	bombX-=10;
}


void bombani()
{
	bombindex++;
	if (bombindex>=8)
		bombindex=0;
}



void boyanijump()
{
	if (boyY<=jumplim && jumpup && !jumpdown)
			boyY+=5;
	else 
	{
		jumpdown = true;
		jumpup = false;

		if (boyY>=35 && !jumpup && jumpdown)
			boyY-=5;
	}
			
}

void iDraw()
{
	if (pressed == 0)
	{
		iPauseTimer(t);
		iClear();
		iShowBMP(0,0,"page\\fpage.bmp");
		iSetColor(r,g,b);
		iText(740,502,"START",GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(g,r,b);
		iText(747,410,"HELP",GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(b,g,r);
		iText(736,318,"CREDIT",GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(b,r,g);
		iText(748,228,"END",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (pressed == 1)
	{
		iResumeTimer(t);
		iClear();
		iShowBMP(0,0,"page\\gamepage.bmp");

		if (stand && !right && !left)
		{
			iShowBMP2(boyX,boyY,"char\\1.bmp",0);
		}

		
		if (right && !left && !stand)
		{
			
			iShowBMP2(boyX,boyY,boyF[boyindex],0);
		}
		
		if (left && !right && !stand)
		{
			
			iShowBMP2(boyX,boyY,boyB[boyindex],0);
		}

	//	iShowBMP2(bombX,bombY,bomb[bombindex],255);
		
	}

	if (pressed == 2)
	{
		iPauseTimer(t);
		iClear();
		iShowBMP(0,0,"page\\help.bmp");
		iSetColor(b,g,r);
		iText(90,525,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
		//iShowBMP(boyX,boyY,boy[boyindex]);
	}

	if (pressed == 3)
	{
		iPauseTimer(t);
		iClear();
		iShowBMP(0,0,"page\\credit.bmp");
		iSetColor(r,g,b);
		iText(90,525,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
		//iShowBMP(boyX,boyY,boy[boyindex]);
	}
	if (pressed == 4)
	{
		exit(0);
	}
	
}


void iMouseMove(int mx, int my)
{
	printf("X= %d\nY= %d\n",mx,my);
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (pressed == 0 && mx>635 && mx<915 && my>475 && my<545)
		{
			pressed = 1;
		}
		else if (pressed == 0 && mx>635 && mx<915 && my>385 && my<455)
		{
			pressed = 2;
		}
		else if (pressed == 0 && mx>635 && mx<915 && my>290 && my<360)
		{
			pressed = 3;
		}
		else if (pressed == 0 && mx>635 && mx<915 && my>205 && my<270)
		{
			pressed = 4;
		}
		else if (pressed == 2 && mx>33 && mx<225 && my>505 && my<560)
		{
			pressed = 0;
		}
		else if (pressed == 3 && mx>33 && mx<225 && my>505 && my<560)
		{
			pressed = 0;
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
	if(key == '\r')
	{
		pressed=1;
	}


	if (key == ' ')
	{
		jumpup = true;
		jumpdown = false;
		boyanijump();
		
	}

	if (key == 'm')
	{
		if (sound)
		{
			PlaySound(0,0,0);
			sound = false;
		}
		else if (!sound)
		{
			PlaySound("gamesound",NULL,SND_LOOP |  SND_ASYNC );	
			sound=true;
		}
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
	if (key == GLUT_KEY_RIGHT)
	{
		right=true;
		left=false;
		stand=false;

		if (boyX+130 <= 1000)
		{
			boyX+=10;
		}
		else
			boyX=boyX;
		

		boyindex++;
		if (boyindex >=7)
			boyindex=0;
	}

	if (key == GLUT_KEY_LEFT)
	{
		left=true;
		right=false;
		stand=false;

		if (boyX >=5)
			boyX-=10;
		else
			boyX=boyX;


		boyindex++;
		if (boyindex >=7)
			boyindex=0;

	}

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	//place your codes for other keys here
}


int main()
{
	iSetTimer(100,rgb);
	iSetTimer(50,bombmove);
	t=iSetTimer(2,boyanijump);
	iSetTimer(8,bombani);
	if (sound)
	{
		PlaySound("gamesound",NULL,SND_LOOP |  SND_ASYNC );
	}

	iInitialize(1000, 600, "CrysisRun");
	return 0;
}	