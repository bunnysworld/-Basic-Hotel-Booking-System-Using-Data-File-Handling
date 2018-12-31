#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<fstream.h>
#include<stdio.h>
#include<dos.h>
class hotel
{
  int roomno,month,date,year,roomprice;
  char name[30],roomname[30];
  char address[50];
  char phone[10];
  public:

  void main_menu();
  void add();
  void display();
  void rooms();
  void edit();
  int check(int);
  void modify(int);
  void delete_rec(int);
};

void hotel::main_menu()
{ clrscr();
  int choice;
  while(choice!=5)
  {
    clrscr();
    cout<<"";
    cout<<"\n ";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n                        1. BOOK A ROOM  ";
    cout<<"\n                        2. COUSTMARE RECORD";
    cout<<"\n                        3. ROOMS ALLOTED";
    cout<<"\n                        4. EDIT RECORD";
    cout<<"\n                        5. EXIT";
    cout<<"\n";
    cout<<"\n                       enter your choice!!!!  ";
    cin>>choice;
    switch(choice)
    {
       case 1:add();
	      break;
       case 2:display();
	      break;
       case 3:rooms();
	      break;
       case 4:edit();
	      break;
       case 5:break;
       default:
       {
	 cout<<"\n wrong choice";
	 cout<<"\n press any key to continue";
	 getch();
       }
    }
   // getch();
    }
 }

void hotel::add()
{
   clrscr();
   char ch;
   int r,flag;

   ofstream fout("memory1.dat",ios::app);
   cout<<"\n";
   cout<<"\n                  ------------------------";
   cout<<"\n                   ENTER COUSTMARE DETAIL  ";
   cout<<"\n                  ------------------------  ";
   cout<<"\n\n ROOM NO  : ";
   cin>>r;
   flag=check(r);
   if(flag)
    cout<<"\n sorry room is already booked";
    else
   {
     roomno=r;
     cout<<"\n";
     cout<<"\nROOM IS VACANT";
     cout<<"\nPRESS 'B' TO BOOK  :  " ;
     cin>>ch;
     if(ch=='b'|ch=='B');
    {clrscr();
     cout<<"\n NAME    :  ";
     gets(name);
     cout<<"\n ADDRESS : ";
     gets(address);
     cout<<"\n PH NO.  : ";
     gets (phone);
     cout<<"\n";
     cout<<"\n---------------------------------------------";
     cout<<"\n---------------------------------------------";
     cout<<"\n       ENTER COUSTMARE CHECK IN DETAILS      ";
     cout<<"\n YEAR    : ";
     cin>>year;
     cout<<"\n MONTHS  : ";
     cin>>month;
     cout<<"\n DATE    : ";
     cin>>date;
     fout.write((char*)this,sizeof(hotel));
     cout<<"\n";
     cout<<"\n     ROOM IS BOOKED!!!";
     }
   }
   cout<<"\n press any key to continue";

   getch();
   fout.close();
}
void hotel::display()
{  clrscr();


  ifstream fin("memory1.dat",ios::in);
  int r,flag;
  cout<<"\n ENTER ROOM NO ";
  cin>>r;

  while(!fin.eof())
  {
    fin.read((char*)this,sizeof(hotel));
    if(roomno==r)
    {
       clrscr();
       cout<<"      ___________________";
       cout<<"\n      COUSTMARE DETAIL ";
       cout<<"      -------------------";
       cout<<"\n\nROOM NO  : "<<roomno;
       cout<<"\n\n NAME    : "<<name;
       cout<<"\n\nADDRESS  : "<<address;
       cout<<"\n\n PH NO.  : "<<phone;
       cout<<"\n--------------------------";
       cout<<"\n--------------------------";
       cout<<"\nCHECK IN DETAIL";
       cout<<"\n\nYEAR     : "<<year;
       cout<<"\n\nMONTH    : "<<month;
       cout<<"\n\nDATE     : "<<date;
       flag=1;
       break;
    }
  }
  if(flag==0)
   cout<<"\n SORRY ROOM NOT FOUND!!!!";
  cout<<"\n press any key to continue";
  getch();
  fin.close();
}
void hotel::rooms()
{

  clrscr();
  ifstream fin("memory1.dat",ios::in);
  cout<<"\n              _______________________";
  cout<<"\n\n              LIST OF ROOM ALLOTED ";
  cout<<"\n\n             ----------------------";
  cout<<"\n\n ROOM NO :    \tNAME :   \tCHECK IN DATE  :\n";


  while( fin.read((char*)this,sizeof(hotel)))
  {
   // fin.read((char*)this,sizeof(hotel));
    cout<<"\n\n"<<roomno<<"\t\t"<<name;
    cout<<"\t\t"<<year<<":"<<month<<":"<<date;
  }
  cout<<"\n press any key to continue";
  getch();
  fin.close();
}
void hotel::edit()
{
  clrscr();

  int choice,r;
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"\n                        ___________ ";
  cout<<"\n                         EDIT MENU  ";
  cout<<"\n                        -----------";
  cout<<"\n";
  cout<<"\n\n               1.MODIFY COUSTMARE RECORD  ";
  cout<<"\n";
  cout<<"\n\n               2.DELETE COUSTMARE RECORD  ";

  cout<<"\n enter your choice";
  cin>>choice;
   clrscr();
   cout<<"\n ENTER YOUR ROOM NO ";
   cin>>r;
   switch(choice)
   {
      case 1:modify(r);
	     break;
      case 2:delete_rec(r);
	     break;
	     default:cout<<"\n WRONG CHOICE ";
   }
   cout<<"\n press any key to continue";
   getch();
}
int hotel::check(int r)
{
  int flag=0;
  ifstream fin("memory1.dat",ios::in);
  while(!fin.eof())
  {
   fin.read((char*)this,sizeof(hotel));
   if(roomno==r)
   {
    flag=1;
    break;
   }
  }
  fin.close();
  return(flag);
}
void hotel::modify(int r)
{
  clrscr();

  long pos,flag=0;
  fstream file("memory1.dat",ios::in|ios::out|ios::binary);

  while(!file.eof())
  {
   pos=file.tellg();
   file.read((char*)this,sizeof(hotel));
   if(roomno==r)
   { cout<<"\n";
     cout<<"\n";
     cout<<"\n                    ___________________  ";
     cout<<"\n                      ENTER NEW RECORD              ";
     cout<<"\n                    -------------------";
     cout<<"\n NAME    :";
     gets(name);
     cout<<"\n ADDRESS :";
     gets(address);
     cout<<"\n PH NO   : ";
     gets(phone);

     file.seekg(pos);
     file.write((char*)this,sizeof(hotel));
     cout<<"\n record is modified";
     flag=1;
     break;
   }
  }
  if(flag==0)
   cout<<"\n room no not found";
   file.close();
}
void hotel::delete_rec(int r)
{

  int flag=0;
  char ch;
  ifstream fin("memory1.dat",ios::in);
  ofstream fout("temp.dat",ios::out);
   while(fin.read((char*)this,sizeof(hotel)))
   {
    // fin.read((char*)this,sizeof(hotel));
     if(roomno==r)
     {
      cout<<"\n NAME      : "<<name;
      cout<<"\n ADDRESS   : "<<address;
      cout<<"\n PH NO     : "<<phone;
      cout<<"\n";
      cout<<"\n PRESS 'y' TO DELETE THIS !!!! ";
      cin>>ch;
      if(ch=='n')
      fout.write((char*)this,sizeof(hotel));
       flag=1;
      }
      else
       fout.write((char*)this,sizeof(hotel));
     }
     fin.close();
     fout.close();
      if(flag==0)
       cout<<"\n room not be found";
      else
      {
	remove("memory1.dat");
	rename("temp.dat","memory1.dat");
      }
}


void main()
{clrscr();
  hotel h;



  h.main_menu();
  getch();
}



