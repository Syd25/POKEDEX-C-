#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<string.h>

//*********************HEADER FILES*********************//
class pokemon
{
   int no;
   char type[20];
   char name[20];
   char evolution[20];
  public:
   void getdata();
   void displaydata();
   int retno()
   { return no;}
}s;

//********************************CLASS OVER***************//
void pokemon::getdata()
{
   cout<<"\nENTER POKEMON DATA";
   cout<<"\nENTER NAME     :";
   gets(name);
   cout<<"\nENTER NUMBER   :";
   cin>>no;
   cout<<"\nENTER TYPE     :";
   gets(type);
   cout<<"\nENTER EVOLUTION:";
   gets(evolution);
}

void pokemon::displaydata()
{
   cout<<"\nNAME      :";
   puts(name);
   cout<<"\nTYPE      :";
   puts(type);
   cout<<"\nEVOLUTION :";
   puts(evolution);
   cout<<"\nPOKEDEX NO:"<<no;
}

//*****************************GETS AND PUTS DATA***********//

void options();
void menu();
void search();
void add();
void deletedata();
void modify();
void sizeoffile();
void displayall();
void intro();

//****************************FUNCTION DECLARATION*********//

void main()
{
   clrscr();
   int gdriver=DETECT,gmode;
   initgraph(&gdriver,&gmode,"C:\\tc\\BGI");
   circle(200,200,80);
   delay(50);
   setcolor(RED);
   circle(200,200,20);
   delay(500);
   setcolor(WHITE);
   line(220,200,280,200);
   delay(200);
   line(120,200,180,200);
   delay(200);
   closegraph();
   getch();
   fstream f1("pok.dat",ios::in|ios::out|ios::binary);
   intro();
   menu();
   f1.close();
   getch();
}
//*************************MAIN FUNCTION ENDS*****************//
//***************************INTRO FUNCTION*******************//

void intro()
{
  clrscr();
  int i,j=3;
  char a,b,c,d;
  textcolor(RED+BLINK);
  for(i=0;i<50;i++)
  {
    cprintf("*");
    delay(50);
  }

  cout<<"\n#######  #####  #  #   ######  #######       #       ######";
  cout<<"\n#     #  #   #  # #    #          #         # #      #    #";
  cout<<"\n#######  #   #  ##     #          #        #   #     #    #";
  cout<<"\n##       #   #  # #    ####       #       #######    ##### ";
  cout<<"\n##       #   #  #  #   #          #      #       #   #    #";
  cout<<"\n##       #####  #   #  ######     #     #         #  ######";
  cout<<endl;
  textcolor(WHITE);
  for(i=0;i<50;i++)
  {
    cprintf("*");
    delay(50);
  }
  getch();
  clrscr();

  cprintf("ARE YOU PROFESSOR OAK");
  cout<<endl;
  cprintf("ENTER PASSWORD:");
  while(j!=0)
  {
    a=getch();
    cout<<"*";
    b=getch();
    cout<<"*";
    c=getch();
    cout<<"*";
    d=getch();
    cout<<"*";

    if((a=='p')&&(b=='o')&&(c=='a')&&(d=='k'))
    {
      cout<<"\nWELCOME TO THE POKETAB";
      getch();
      break;
    }
    else
    {
      cout<<"\nYOU ENTERED THE WRONG PASSWORD";
      cout<<"\nYOU HAVE"<<j-1<<"CHANCES LEFT";
    }
    j--;
    if(j==0)
    {
      cout<<"\nPRESS ANY KEY TO EXIT";
      getch();
      exit(0);
    }
  }
  getch();
}
//******************************OPTIONS************************//

void options()
{
 clrscr();
 cout<<"\n::::OPTIONS MENU:::::";
 cout<<"\n1.ADD DATA";
 cout<<"\n2.MODIFY DATA";
 cout<<"\n3.DELETE DATA";
 cout<<"\n4.SEARCH DATA";
 cout<<"\n5.FIND SIZE OF FILE";
 cout<<"\n6.DISPLAY ALL POKEMONS STORED";
 cout<<"\nENTER YOUR CHOICE";
 getch();
}
//*******************************MENU**************************//

void menu()
{
 clrscr();
 int ch;
 options();
 cin>>ch;

 while(ch)
 {
  switch(ch)
  {
    case 1:add();
	  break;
    case 2:modify();
	  break;
    case 3:deletedata();
	  break;
    case 4:search();
	  break;
    case 5:sizeoffile();
	  break;
    case 6:displayall();
	  break;
    default:cout<<"\nWRONG CHOICE ENTER AGAIN";
    break;
  }
  clrscr();
  cout<<"\nENTER CHOICE";
  cin>>ch;
 }
 getch();
}
//****************************ADD*****************************//
void add()
{
 clrscr();
 char ch='y';
 fstream f3("pok.dat",ios::app|ios::binary);
 while(ch=='y')
 {
   s.getdata();
   f3.write((char*)&s,sizeof(s));
   cout<<"\nENTER YOUR CHOICE(DO YOU WANNA ADD MORE)";
   cin>>ch;
 }
 f3.close();
 getch();
}
//*******************************MODIFY***********************//
void modify()
{
 clrscr();
 fstream f0("pok.dat",ios::in|ios::out|ios::binary);
 int rnom;
 char mfound='n';
 f0.seekg(0);
 cout<<"\nENTER POKE NO TO BE MODIFIED";
 cin>>rnom;

 while(f0.read((char*)&s,sizeof(s)))
 {
  int loc=f0.tellg();
  f0.read((char*)&s,sizeof(s));
  if(s.retno()==rnom)
  {
    s.getdata();
    mfound='y';
    f0.seekg(loc);
    f0.write((char*)&s,sizeof(s));
    cout<<"\nUPDATED....";
  }
}
 if(mfound=='n')
 cout<<"\nNOT IN POKETAB...";
 f0.close();
 getch();
}
//*********************************DELETE**********************//

void deletedata()
{
  clrscr();
  int rnod;
  char dfound='n';
  fstream f0("pok.dat",ios::in|ios::app|ios::binary);
  fstream f3("temp.dat",ios::app|ios::binary);
  fstream out("trash.dat",ios::app|ios::binary);

  cout<<"\nENTER ROLL NO TO DELETE";
  cin>>rnod;

  while(f0.read((char*)&s,sizeof(s)))
  {
    if(s.retno()==rnod)
    {
      out.write((char*)&s,sizeof(s));
      dfound='y';
    }
    else
    {
      f3.write((char*)&s,sizeof(s));
    }
  }

  if(dfound=='n')
  {cout<<"\nTHE POKEMON IS NOT PRESENT...";}

  f0.close();
  f3.close();
  remove("pok.dat");
  rename("temp.dat","pok.dat");

  getch();
}
//********************************SEARCH************************//

void search()
{
  clrscr();
  int rno;
  char found='n';

  fstream f2("pok.dat",ios::in|ios::binary);
  cout<<"\nENTER POKENUMBER";
  cin>>rno;
  while(f2.read((char*)&s,sizeof(s)))
  {
   if(s.retno()==rno)
   {
     s.displaydata();
     found='y';
   }
  }

  if(found=='n')
  {
    cout<<"\nNO SUCH POKEMON";
  }
  f2.close();
  getch();
}
//*****************************SIZE OF TAB***********************//
void sizeoffile()
{
  clrscr();
  fstream f0("pok.dat",ios::in|ios::out|ios::binary);
  int size,begin,last;
  begin=f0.tellg();
  while(f0.read((char*)&s,sizeof(s)))
  {
   last=f0.tellg();
  }
  f0.close();
  cout<<"\nSIZE OF TAB IS:"<<last-begin;
  getch();
}
//***************************DISPLAY ALL POKEMON*******************//

void displayall()
{
 clrscr();
 fstream f2("pok.dat",ios::in|ios::binary);
 while(f2.read((char*)&s,sizeof(s)))
 {
   s.displaydata();
 }
 f2.close();
 getch();
}
//*******************************END OF PROGRAM*****************//

//search,displayall:::f2//
//sizeof,modify:::f0     //
//deletedata:::f3,f0,out //
//add:::f3               //
//*****************************************************//