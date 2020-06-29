#include<iostream.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
void main()
{
   clrscr();
   cout<<"hello world";
   int gdriver=DETECT,gmode;
   initgraph(&gdriver,&gmode,"C:\\tc\\BGI");
   circle(200,200,80);
   delay(500);
   setcolor(RED);
   circle(200,200,20);
   delay(500);
   setcolor(WHITE);
   line(220,200,280,200);
   delay(200);
   line(120,200,180,200);
   delay(200);
   getch();
   closegraph();
}

//Pokeball only
