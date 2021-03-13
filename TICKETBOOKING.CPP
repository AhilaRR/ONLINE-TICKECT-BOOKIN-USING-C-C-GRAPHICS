#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<dos.h>
#include<process.h>
#include<graphics.h>

int  ch, ch2, ch3, ch4, ch5, ch6,ch7,ch8,ch9,ch10,ch11,ch12, ch13, ch14;
 int a, b ,c, n, i, j, cvv, l, mn, dt, yr ,ticket, tic[10],row[2] ,seatcopy[13][6];
int economy=0,elite=0,premire=0, amount=0,amt=0,count=0;
char  username[30],pass[45],con, carduser[20],cardpwd[10],cardno[17],pin[9];
char ch15, tick[10], seat[13][6], seatno;
class admin       
{      public:
       int x,y,no;
       char ch[20];
       char name[30];
       char username[30];
       char password[10];
       char emailid[25];
       char cast[25];
       char movname[20];
       char rate[10];
       char direct[20];
       char genre[10];
       char lang[10];
       void add();
       void del();
}s;
class user                  
{
public:
       char name[30];
       char e[35];
       char username[10];
       char password[10];
       char mno[15];
       void userdata();
}ss1;
void logo();
void intro();
void admin_login();
void admin_menu();
void movrunning();
void user_acc();
void signup();
void signin();
void user_disp();
void faq();
void contact();
void vision();
void booking();
void timing();
void show_timing();
void seating1();
void seating2();
void ticketdisp();
void snack(int,int,int,int);
void transaction();
void trans();
void thankyou();
void main()               
{
    clrscr();
    logo();
    intro();
    getch();
}
void intro()
{
  clrscr();
  textcolor(MAGENTA);
  gotoxy(27,10);cputs(" 1) To login as Admin");
  gotoxy(27,12);cputs(" 2) To login as User");
  gotoxy(27,14);cputs(" 3) Exit");
  gotoxy(25,16);cputs("Enter your choice(1/2/3):   ");
  cin>>ch;
  switch(ch)
     {
     case 1 : admin_login();
	        break;
     case 2 : clrscr();
	        user_acc();
	        break;
     case 3 : exit(0);
	        break;
     default: intro();
     }
 }
void admin_login()
{
clrscr();
 textcolor(CYAN);
 gotoxy(30,9); cputs("USERNAME:");
 gotoxy(41,9);cin>>username;
 gotoxy(30,10);cputs("PASSWORD:");
 gotoxy(41,10);
 char aa[20],ch3;
 int n2,v1=1;
 for(int i=0;i<20;i++)
      { ch3=getch();
	v1=ch3;
	if(v1!=13)
	{ pass[i]=ch3;
	  n2=i;
	  cout<<'\4';
	}
       if(v1==13)
	 break; }
       pass[n2+1]='\0';
       clrscr();
 cout<<"\nChecking Username and Password  Combination ";
for(int che=0;che<7;che++)
{
delay(400);   cout<<".";
}
 a=strcmp("admin",username);
 b=strcmp("password",pass);
 if(a==0&&b==0)
    {
    clrscr();
    gotoxy(30,10);cout<<"Logging in";
    for(int che=0;che<8;che++)
        {
             delay(400);cout<<".";
         }
	admin_menu();
}
    else
      {
	 clrscr();
	  gotoxy(26,13);cputs("Wrong username or password...Try again!!");
	  getch();
	  admin_login();
      }
 }
 void admin_menu()
 {
 clrscr();
  textcolor(MAGENTA);
  gotoxy(27,2);for( int i=0;i<19;i++)cout<<char(4);
  gotoxy(33,3);cputs("ADMIN");
  gotoxy(27,4);for(i=0;i<19;i++)cout<<char(4);
  gotoxy(30,8);cputs("1) Add movie");
  gotoxy(30,9);cputs("2) Delete movie");
  gotoxy(30,10);cputs("3) Go back");
  gotoxy(30,11);cputs("4) Exit");
  gotoxy(25,13);cputs("Enter your choice(1/2/3):   ");
  cin>>ch12;
  switch (ch12)
  {
      case 2:      s.del();
		  break;
      case 1:      s.add();
		  break;
      case 3:      intro();
		 break;
      case 4:    exit(0);
      default:   cout<<"Wrong Choice";
 }
 }

  void admin :: add()        
{
movrunning();
cout<<"Press any key to add movie";
getch();
char ch='y';
ofstream s1("new.txt",ios::app);
while(ch=='y')
   {
    clrscr();
    textcolor(CYAN);
    gotoxy(26,5);cputs("MOVIE NO:");
    gotoxy(40,5);cin>>s.no;
    gotoxy(26,7);cputs("MOVIE NAME:");
    gotoxy(40,7);gets(s.movname);
    gotoxy(26,9);cputs("DIRECTOR:");
    gotoxy(40,9);gets(s.direct);
    gotoxy(26,11);cputs("CAST:");
    gotoxy(40,11);gets(s.cast);
    gotoxy(26,13);cputs("GENRE:");
    gotoxy(40,13);gets(s.genre);
    gotoxy(26,15);cputs("RATING:");
    gotoxy(40,15);gets(s.rate);
    gotoxy(26,17);cputs("LANGUAGE:");
    gotoxy(40,17);gets(s.lang);
s1.write((char*)&s,sizeof(s));
clrscr();
gotoxy(20,17);cputs("Movie has been successfully added!!!");
gotoxy(20,18);cputs("Do u want to add more movies(y/n)?    ");
cin>>ch;
}
s1.close();
movrunning();
getch();
admin_menu();
}
void admin :: del()         
  {
int r;
char ch;
movrunning();
ofstream s3("d.txt",ios::out);
cout<<endl<<"Enter movie no to be deleted:  ";
cin>>r;
ifstream s4("new.txt",ios::in);
s4.seekg(0);
while(s4.read((char*)&s,sizeof(s)))
  {
     if(s.no!=r)
    s3.write((char*)&s,sizeof(s));
   }
s3.close();
s4.close();
remove("new.txt");
rename("d.txt","new.txt");
cout <<endl<<"The movies are";
clrscr();
movrunning();
getch();
admin_menu();
}
void  movrunning()        
{
clrscr();
cout<<endl<<"MOVIES RUNNING IN INOX"<<endl;
ifstream s2("new.txt",ios::in);
s2.seekg(0);
while(s2.read((char*)&s,sizeof(s)))
   {
    delay(200);
    cout<<s.no;
    cout<<char(16);
    cout<<  s.movname<<endl;
   }
s2.close();
}
void user::userdata()
{
textcolor(CYAN)	;
gotoxy(26,3);for(i=0;i<22;i++)cout<<char(4);
gotoxy(32,4);cputs("USER DETAILS");
gotoxy(26,5);for(i=0;i<22;i++)cout<<char(4);
gotoxy(23,7);cputs("NAME:");
gotoxy(44,7);gets(name);
gotoxy(23,9);cputs("USERNAME:");
gotoxy(44,9);gets(username);
gotoxy(23,11);cputs("LOGIN PASSWORD:");
 char aa[20],ch3;
 int n2,v1=1;
 for(int i=0,j=44;i<20;i++,j++)
      { ch3=getch();
	v1=ch3;
	if(v1!=13)
	{ password[i]=ch3;
	  n2=i;
	  gotoxy(j,11);cout<<'\4';
	}
       if(v1==13)
	 break;}
       password[n2+1]='\0';
gotoxy(23,13);cputs("EMAIL ID:");
gotoxy(44,13);gets(e);
gotoxy(23,15);cputs("MOBILE NUMBER:");
gotoxy(44,15);gets(mno);
}
void user_acc()
{
label1:
int d;
clrscr();
textcolor(GREEN);
gotoxy(28,3);for(i=0;i<14;i++)cout<<char(4);
gotoxy(32,4);cputs("LOGIN");
gotoxy(28,5);for(i=0;i<14;i++)cout<<char(4);
gotoxy(29,7);cputs("1.New user");
gotoxy(29,8);cputs("2.Already registered");
gotoxy(29,9);cputs("3.Exit");
gotoxy(27,12);cputs("Enter your choice(1/2/3):   ");
cin>>d;
switch(d)
{
        case 1 :   signup();
	             goto label1;
       case 2 :    signin();
	             break;
       case 3 :    exit(0);
	             break;
       default:   cout<<"WRONG CHOICE!!!";
}
}
void signup()       
{
ofstream f6("users.txt",ios::app);
clrscr();
gotoxy(26,2);
cout<<char(2)<<"WELCOME TO INOX"<<char(2);
ss1.userdata();
f6.write((char*)&ss1,sizeof(ss1));
f6.close();
}
void signin()
{
char uname[15],upass[10],ch2;
int z1,z2,r;
label2:
clrscr();
textcolor(MAGENTA);
gotoxy(31,7);cout<<"username:";
gotoxy(48,7);gets(uname);
gotoxy(31,8);cout<<"password:";
gotoxy(48,8);
 char aa[20],ch3;
      int n2,v1=1;

      for(int i=0;i<20;i++)
      { ch3=getch();
	v1=ch3;
	if(v1!=13)
	{ upass[i]=ch3;
	  n2=i;
	  cout<<'\4';
	}
       if(v1==13)
	 break;}
       upass[n2+1]='\0';
clrscr();gotoxy(26,10);
cout<<"Checking username and password combination";
for(int che=0;che<7;che++)
{
delay(400);cout<<".";
}
ifstream f7("users.txt",ios::in);
f7.seekg(0);
while(!f7.eof())
{
f7.read((char*)&ss1,sizeof(ss1));
z1=strcmp(ss1.username,uname);
z2=strcmp(ss1.password,upass);
if((z1==0)&&(z2==0))
      {
      clrscr();
      gotoxy(28,10);
      cout<<"Logging in";
      for(int che=0;che<7;che++)
{
delay(400);cout<<".";
}
	   user_disp();
	   }
}
f7.close();
 clrscr();
	   cout<<"\n\n\t\t\tUSERNAME / PASSWORD mismatching!!!\n\n";
	   cout<<"\t\t\t\t1. Try SIGNING IN once more\n";
	   cout<<"\t\t\t\t2. Go to LOGIN PAGE\n\n";
	   cout<<"Enter your CHOICE : ";
	   cin>>ch10;
	   clrscr();
		 if(ch10==1)
		    goto label2;
		 else if(ch10==2)
		    user_acc();
		    }

void user_disp()         
{
char ch2;
clrscr();
textcolor(YELLOW);
gotoxy(27,1);for(i=0;i<18;i++)cout<<char(4);
gotoxy(31,2);cputs("Dear User");
gotoxy(28,3);cputs(" WELCOME TO INOX");
gotoxy(27,4);for(i=0;i<18;i++)cout<<char(4);
gotoxy(30,10);cputs("3)  VISION");
gotoxy(30,8);cputs("1)  BOOK MOVIES");
gotoxy(30,9);cputs("2)  CURRENT MOVUES");
gotoxy(30,11);cputs("4)  FAQ");
gotoxy(30,12);cputs("5)  CONTACT US");
gotoxy(30,13);cputs("6)  GO BACK");
gotoxy(30,14);cputs("7)  Exit");
gotoxy(32,15);cin>>ch2;
   switch(ch2)
    {
      case '3': vision();
		getch();
		 user_disp();
		  break;
      case '1':   booking();
		  break;
      case '2':    movrunning();
		  getch();
		  user_disp();
		  break;
      case '4':     faq();
		   getch();
		   user_disp();
		    break;
      case '5':     contact();
		    getch();
		   user_disp();
		   break;
      case '6':     user_acc();
		   break;
      case '7':     exit(0);
		    break;
      default :     user_disp();
    }
}
void contact()
{
clrscr();
gotoxy(27,2);for(i=0;i<18;i++)cout<<char(4);
gotoxy(32,3);cout<<"CONTACT US";
gotoxy(27,4);for(i=0;i<18;i++)cout<<char(4);
  cout<<"\n\n\t\t\t-Our Corporate Office :";
  cout<<"\n\t\t\t #25, 5th Floor,";
  cout<<"\n\t\t\t Disha Complex, Lake View Road,";
  cout<<"\n\t\t\t adayar Main Road,";
  cout<<"\n\t\t\t Chennai - 600042";
  cout<<"\n\n\t\t\t-Phone Number:";
  cout<<"\n\t\t\t\t 044-623311";
  cout<<"\n\t\t\t\t 9368944226";
  cout<<"\n\n\t\t\t-Email id:";
  cout<<"\n\t\t\t\t inoxcinemas@gmail.com";
  getch();
  cout<<"\n\n\n\t\t Press any key to GO BACK";
 }
void vision()
{
clrscr();
gotoxy(27,2);for(i=0;i<18;i++)cout<<char(4);
gotoxy(32,3);cout<<"VISION";
gotoxy(27,4);for(i=0;i<18;i++)cout<<char(4);
gotoxy(10,7);
cout<<"\tA Superior Sensory and Social cinematic experience INOX offers";
cout<<"\n seamless service and a wealth of amenities INOX is a culmination of style,";
cout<<"\n innovation and setting like never before.";
getch();
}
void faq()
{clrscr();
gotoxy(29,2);for(i=0;i<16;i++)cout<<char(4);
gotoxy(34,3);cout<<"FAQ";
gotoxy(29,4);for(i=0;i<16;i++)cout<<char(4);
  cout<<"\n-What are the benefits of registering on our site ?";
  cout<<"\n   Registration with CINE HUT ensures that you have a hassle-free transaction   and provides you with a world-class cinema viewing.";
  cout<<"\n\n-Can I cancel the tickets that I have booked online and get a refund ?";
  cout<<"\n   No, tickets once bought cannot be cancelled, refunded or exchanged.";
  cout<<"\n\n-Can I change my seat numbers?";
  cout<<"\n   No. It is not possible to change the seat numbers of a ticket once booked.";
  cout<<"\n\n-If I am late for the film will my seat be held ?";
  cout<<"\n   Once your purchase has been confirmed, your admission is held and will not be   sold to another customer.";
  cout<<"\n\n-What is the minimum age of children to buy a ticket :";
  cout<<"\n   Children aged 3 years and above will require a separate ticket.";

  cout<<"\n\t\t\t Press any key to GO BACK";
  }
void booking()                
{
clrscr();
movrunning();
cout<<endl<<"ENTER MOVIE NO TO BOOK:  ";
cin>>ch3;
ifstream s2("new.txt",ios::in);
s2.seekg(0);
while(!s2.eof())
{
s2.read((char*)&s,sizeof(s));
if(ch3==s.no)
    {
     clrscr();
     delay(500);gotoxy(26,5);cputs("MOVIE NO:");
     gotoxy(40,5);cout<<s.no;
     delay(500);gotoxy(26,7);cputs("MOVIE NAME:");
     gotoxy(40,7);puts(s.movname);
     delay(500);gotoxy(26,9);cputs("DIRECTOR:");
     gotoxy(40,9);puts(s.direct);
     delay(500);gotoxy(26,11);cputs("CAST:");
     gotoxy(40,11);puts(s.cast);
     delay(500);gotoxy(26,13);cputs("GENRE:");
     gotoxy(40,13);puts(s.genre);
     delay(500);gotoxy(26,15);cputs("RATING:");
     gotoxy(40,15);puts(s.rate);
     delay(500);gotoxy(26,17);cputs("LANGUAGE:");
     gotoxy(40,17);puts(s.lang);
     gotoxy(26,19);cputs("1) Proceed to book");
     gotoxy(26,20);cputs("2) Go back");
     gotoxy(26,22);cputs("Enter your choice   ");
     cin>>ch7;
	     if(ch7==1)
	      timing();
	     else if(ch7==2)
	      booking();
	     else
	      booking() ;
    }
}
s2.close();
}
void timing()
{
clrscr();
void nextdate(int,int,int);
gotoxy(26,3);for(i=0;i<22;i++)cout<<char(4);
gotoxy(32,4);cputs("BOOKING DATE");
gotoxy(26,5);for(i=0;i<22;i++)cout<<char(4);
gotoxy(17,7);cout<<"ENTER TODAY DATE (dd/mm/yy)(separated by space):";
cin>>dt>>mn>>yr;
nextdate(dt,mn,yr);
}
void nextdate(int d,int m,int y)
{
 for(int i=0, w=9;i<2;i++,w++)
 {
 int k=y%4;
if(((d==31)&&(m==1||m==3||m==5||m==7||m==8||m==10))||((d==30)&&(m==4)))
 {
 d=1;
 m=m+1;
 }
 else if((d==31)&&(m==12))
 {
 d=1;
 m=1;
 y=y+1;
 }
 else if(((k==0)&&(d==29)&&(m==2))||((k!=1)&&(d==28)&&(m==2)))
 {d=1;
 m=3;
 }
 else
 {d=d+1;
 }
 gotoxy(26,w);cout<<i+1<<") "<< d<<"/"<<m<<"/"<<y;
 }
 gotoxy(20,13);cout<<"Enter your choice(1/2):  ";
 cin>>ch13;
 getch();
 show_timing();

 }
 void show_timing()
 {
 clrscr();
 gotoxy(28,5);
 gotoxy(27,3);for(i=0;i<22;i++)cout<<char(4);
gotoxy(32,4);cputs("SHOW TIMING");
gotoxy(27,5);for(i=0;i<22;i++)cout<<char(4);
gotoxy(28,8);cputs("1) MORNING SHOW - 10.00 - 12.30") ;
gotoxy(28,9);cputs("2) MATNEE       - 14.30 - 17.00");
gotoxy(28,10);cputs("3) EVENING SHOW - 18.30 - 21.00");
gotoxy(28,11);cputs("4) NIGHT SHOW   - 22.00 - 00.30");
gotoxy(24,14);cputs("Enter your choice    ");
cin>> ch14;
if(count==0)
 seating1();
 else
 seating2();
}

void seating1()       
{
clrscr();
for(int i = 0; i < 13; i++)
{
   for(int j = 0; j < 6; j++)
   {
	 seat[i][j] = '*';
	 seatcopy[i][j] = 0;
 }
}
seating2();
}
void seating2()
{clrscr();
gotoxy(28,1);cout<<" INOX LEISURE UNLIMITED";
gotoxy(8,2);cout<<"   ROW 1-2";gotoxy(32,2);cout<<"    ROW 3-7";gotoxy(50,2);cout<<"              ROW  8-13\n";
cout<<"\t     ELITE                 PREMIERE                     ECONOMY    \n";
cout<<"\t    Rs.500                  Rs.300                      Rs.200     \n";
gotoxy(28,5);cout<<"SEATING ARRANGEMENT "<<endl;
cout<<"\t * - Available";
cout<<" \t   X - Occupied"<<endl;
cout<<endl;
cout<<"    \t \tA\tB\tC\tD\tE\tF"<<endl;
cout<<"\tRow 1\t"<<seat[0][0]<<"\t"<<seat[0][1]<<"\t"
<<seat[0][2]<<"\t"<<seat[0][3]<<"\t"<<seat[0][4]<<"\t"
<<seat[0][5]<<endl;
cout<<"\tRow 2\t"<<seat[1][0]<<"\t"<<seat[1][1]<<"\t"
<<seat[1][2]<<"\t"<<seat[1][3]<<"\t"<<seat[1][4]<<"\t"
<<seat[1][5]<<endl;
cout<<"\tRow 3\t"<<seat[2][0]<<"\t"<<seat[2][1]<<"\t"
<<seat[2][2]<<"\t"<<seat[2][3]<<"\t"<<seat[2][4]<<"\t"
<<seat[2][5]<<endl;
cout<<"\tRow 4\t"<<seat[3][0]<<"\t"<<seat[3][1]<<"\t"
<<seat[3][2]<<"\t"<<seat[3][3]<<"\t"<<seat[3][4]<<"\t"
<<seat[3][5]<<endl;
cout<<"\tRow 5\t"<<seat[4][0]<<"\t"<<seat[4][1]<<"\t"
<<seat[4][2]<<"\t"<<seat[4][3]<<"\t"<<seat[4][4]<<"\t"
<<seat[4][5]<<endl;
cout<<"\tRow 6\t"<<seat[5][0]<<"\t"<<seat[5][1]<<"\t"
<<seat[5][2]<<"\t"<<seat[5][3]<<"\t"<<seat[5][4]<<"\t"
<<seat[5][5]<<endl;
cout<<"\tRow 7\t"<<seat[6][0]<<"\t"<<seat[6][1]<<"\t"
<<seat[6][2]<<"\t"<<seat[6][3]<<"\t"<<seat[6][4]<<"\t"
<<seat[6][5]<<endl;
cout<<"\tRow 8\t"<<seat[7][0]<<"\t"<<seat[7][1]<<"\t"
<<seat[7][2]<<"\t"<<seat[7][3]<<"\t"<<seat[7][4]<<"\t"
<<seat[7][5]<<endl;
cout<<"\tRow 9\t"<<seat[8][0]<<"\t"<<seat[8][1]<<"\t"
<<seat[8][2]<<"\t"<<seat[8][3]<<"\t"<<seat[8][4]<<"\t"
<<seat[8][5]<<endl;
cout<<"\tRow 10\t"<<seat[9][0]<<"\t"<<seat[9][1]<<"\t"
<<seat[9][2]<<"\t"<<seat[9][3]<<"\t"<<seat[9][4]<<"\t"
<<seat[9][5]<<endl;
cout<<"\tRow 11\t"<<seat[10][0]<<"\t"<<seat[10][1]<<"\t"
<<seat[10][2]<<"\t"<<seat[10][3]<<"\t"<<seat[10][4]<<"\t"
<<seat[10][5]<<endl;
cout<<"\tRow 12\t"<<seat[11][0]<<"\t"<<seat[11][1]<<"\t"
<<seat[11][2]<<"\t"<<seat[11][3]<<"\t"<<seat[11][4]<<"\t"
<<seat[11][5]<<endl;
cout<<"\tRow 13\t"<<seat[12][0]<<"\t"<<seat[12][1]<<"\t"
<<seat[12][2]<<"\t"<<seat[12][3]<<"\t"<<seat[12][4]<<"\t"
<<seat[12][5]<<endl;
lb2:
cout<<endl;
cputs("How many tickets you want to book?:   ");
cin>>l;
for(j=0;j<l;j++)
{
cputs("Enter Ticket type(1/2/3):   ");
cin>>ticket;
cputs("Desired Row: ");
cin>>row[0];
cputs("Desired seat (A,B,C,D,E or F): ");
cin>>seatno;
switch(seatno)
	{
		case 'A':
		case 'a': 	row[0] = row[0] - 1;
		                        row[1] = 1;
		                        row[1] = row[1] - 1;
		                         break;

		

		case 'B':
		case 'b':    row[0] = row[0] - 1;
	                              row[1] = 2;
		                   row[1] = row[1] - 1;
		                   break; 
                       case 'C':
		case 'c':    row[0] = row[0] - 1;
	                             row[1] = 3;
		                 row[1] = row[1] - 1;
		                 break;
                      case 'D':
                      case 'd':    row[0] = row[0] - 1;
	                              row[1] = 4;
		                  row[1] = row[1] - 1;
		                  break;

		

		case 'E':
		case 'e':    row[0] = row[0] - 1;
	                              row[1] = 5;
		                   row[1] = row[1] - 1;
		                   break;
                       case 'F':
		case 'f':      row[0] = row[0] - 1;
		                    row[1] = 6;
		                    row[1] = row[1] - 1;
		                    break;
}
if(ticket == 1 )
	{
	if(row[0]+1 == 1 || row[0]+1 == 2)
		 {
                        if(seatcopy[row[0]][row[1]] == 0)
		{
		   seatcopy[row[0]][row[1]] = 1;
		   seat[row[0]][row[1]] = 'X';
		}
		else if(seatcopy[row[0]][row[1]] == 1)
		{       cout<<"Message: Seat "<<row[0] + 1<<seatno<<" is already occupied"<<endl;
                                   getch();
			goto lb2;
		} 
}
		else
		{
			cputs("Wrong Class");cout<<endl;
			getch();
			clrscr();
			seating2();
		}

	}
	else if(ticket ==2)
	{
		if(row[0]+1 == 3 || row[0]+1 == 4 || row[0]+1 == 5
		|| row[0]+1 == 6|| row[0]+1 == 7)
		{
		if(seatcopy[row[0]][row[1]] == 0)
		{
		   seatcopy[row[0]][row[1]] = 1;
		   seat[row[0]][row[1]] = 'X';
		}
		else if(seatcopy[row[0]][row[1]] == 1)
		{
			cout<<"Message: Seat "<<row[0] + 1<<seatno<<" is already occupied"<<endl;
			getch();
			goto lb2;
		}
		}
		else
		{
			cputs("Wrong Class");cout<<endl;
		       getch();
			clrscr();
			seating2();
		}
	}
	else if(ticket ==3)
	{
		if(row[0]+1 == 8 || row[0]+1 == 9 || row[0]+1 == 10
		 || row[0]+1 == 11|| row[0]+1 == 12|| row[0]+1 == 13)
		{
		if(seatcopy[row[0]][row[1]] == 0)
		{
		   seatcopy[row[0]][row[1]] = 1;
		   seat[row[0]][row[1]] = 'X';
		}
		else if(seatcopy[row[0]][row[1]] == 1)
		{
			cout<<"Message: Seat "<<row[0] + 1<<seatno<<" is already occupied"<<endl;
			getch();
			goto lb2;
		}
		}
			else
		{
			cputs("Wrong Class");cout<<endl;
			getch();
			clrscr();
			seating2();
		}
}
                tic[j]=row[0]+1  ;
	    tick[j]=seatno;
               row[1] = 0;
}
transaction();
}
void snack(int economy,int premire,int elite,int amount)  ///snack
{
lab:
clrscr();
textcolor(YELLOW);
gotoxy(17,3);cout<<char(2);cputs("WHY DO YOU WANT TO WAIT IN A QUEUE WHEN U CAN BUY NOW??");cout<<char(2);
gotoxy(24,5);cputs("1)Large Popcorn Tub         Rs.80");
gotoxy(24,7);cputs("2)Regular Coke        Rs.40");
gotoxy(24,9);cputs("3)French fries    Rs 50");
gotoxy(20,11);cputs("Enter the item no you want    ");
cin>>ch6;
switch(ch6)
{
case 1 : cout<<endl;cputs("          No of items:");
	 cin>>ch8;
	 cout<<"\n\nDo you want to buy more(y/n)??    ";
	 cin >>con;
	 if(con=='y')
	 {amt+=(ch8*80);
	 goto lab;
	 }
	 else if(con=='n')
	 amt+=(ch8*80);
	 else
	 amt+=(ch8*80);
	 break;
case 2:  cout<<"No of items:  ";
	 cin>>ch8;
	 cout<<"\n\nDo you want to buy more(y/n)??    ";
	 cin >>con;
	 if(con=='y')
	 {amt+=(ch8*40);
	 goto lab;
	 }
	 else if(con=='n')
	 amt+=(ch8*40);
	 else
	 amt+=(ch8*40);
	 break;
case 3:  cout<<"No of items:    ";
	 cin>>ch8;
	 cout<<"\n\nDo you want to buy more(y/n)??    ";
	 cin >>con;
	 if(con=='y')
	 {amt+=(ch8*50);
	 goto lab;
	 }
	 else if(con=='n')
	 amt+=(ch8*50);
	 else
	 amt+=(ch8*50);
	 break;

default :cputs("wrong choice");
}
clrscr();
gotoxy(9,3);
 for(int i=0;i<=59;i++)
 cout<<char(4);
 cout<<"\n\t\t\t\t INOX ";
 cout<<"\n\n\t\t\t       BOOKING DETAILS";
 cout<<"\n\n\t\t YOU HAVE CHOSEN TO WATCH:"<<s.movname;
 cout<<"\n\n\t\t  NO. OF SEATS           AMOUNT";
 cout<<"\n\n\t\t  ECONOMY   : "<<economy<<"\t\t"<<economy*200;
 cout<<"\n\t\t  PREMIRE     : "<<premire<<"\t\t"<<premire*300;
 cout<<"\n\t\t  ELITE : "<<elite<<"\t\t"<<elite*500;
 cout<<"\n\n\t\tTICKET COST: Rs."<<amount;
 cout<<"\n\t\tSNACKS COST: Rs."<<amt;
 cout<<"\n\t\t\t\t\t\t GRAND TOTAL  Rs."<<amt+amount;
 gotoxy(10,19);
 for( i=0;i<=59;i++)
 cout<<char(4);


 cout<<"\n\t\t\t1) GO BACK";
cout<<"\n\t\t\t2) PROCEED TO PAY";
 cout<<endl<<"\t\t\tEnter ur choice:    ";
 cin>>ch9;
       if(ch9==1)
	      goto lab;
	     else if(ch7==2)
                     trans();
delay(500);
trans();
 }
void  transaction()   
{
clrscr();
for(int i=0;i<l;i++)
{
    if(tic[i]<3)
      {
	elite++;
	amount+=500;
       }
    else
      if(tic[i]>2&&tic[i]<8)
      {
	amount+=300;
	premire++;
      }
      else
      {
	amount+=200;
	economy++;
      }
}
clrscr();
 gotoxy(9,3);
 for( i=0;i<=59;i++)
 cout<<char(4);
 cout<<"\n\t\t\t\t INOX ";
 cout<<"\n\n\n\t\t\t       BOOKING DETAILS";
 cout<<"\n\n\n\t\t YOU HAVE CHOSEN TO WATCH:"<<s.movname;
 cout<<"\n\n\n\t\t  NO. OF SEATS           AMOUNT";
 cout<<"\n\n\n\t\t  ECONOMY   : "<<economy<<"\t\t"<<economy*200;
 cout<<"\n\t\t  PREMIRE    : "<<premire<<"\t\t"<<premire*300;
 cout<<"\n\t\t  ELITE: "<<elite<<"\t\t"<<elite*500;
 cout<<"\n\n\t\t\t\t\t\t GRAND TOTAL  Rs."<<amount;
 gotoxy(10,21);
 for( i=0;i<=59;i++)
 cout<<char(4);
 cout<<"\n\t\t\t1) SNACK CORNER";
cout<<"\n\t\t\t2) PROCEED TO PAY";
 cout<<endl<<"\t\t\tEnter ur choice:    ";
 cin>>ch9;
       if(ch9==1)
	      snack(economy,premire,elite,amount);
      else
       if(ch9==2)
	      trans();
}
void trans()
{clrscr();
 cout<<"\n\t\t\t   HOW WOULD YOU LIKE TO PAY ?";
cout<<"\n\n\n\t\t\t     1. Net Banking ";
 cout<<"\n\t\t\t     2. Credit Card ";
 cout<<"\n\t\t\t     3. Debit Card   ";
 cout<<"\n\n\n\t\t\t     Enter your CHOICE : ";
 cin>>ch11;
 clrscr();
 switch(ch11)
 { case 1 : cout<<"\n\n\n\t\t\t     1. ICICI Bank ";
	    cout<<"\n\t\t\t     2. SBI Bank ";
	    cout<<"\n\t\t\t     3. Canara Bank ";
	    cout<<"\n\t\t\t     4. Back";
	    cout<<"\n\n\n\t\t\t     Enter your CHOICE : ";
	    cin>>ch12;
	    if(ch12==4)
	     trans();
	    clrscr();
	    cout<<"\n\n\n\t\t\t     WELCOME TO ";
	    if(ch12==1)
	    cout<<"ICICI BANK ";
	    else if(ch12==2)
	    cout<<"SBI BANK ";
	    else if(ch12==3)
	    cout<<"Canara BANK ";
	    cout<<"\n\n\t\t\t  Enter the following DETAILS ";
	    cout<<"\n\n\n\t\t\t  USERNAME   : ";
	    gets(carduser);
	    cout<<"\n\n\t\t\t  PASSWORD   : ";
              char aa[20],ch3;
               int n2,v1=1;
              for(int i=0;i<20;i++)
             { ch3=getch();
	v1=ch3;
	if(v1!=13)
	{ cardpwd[i]=ch3;
	  n2=i;
	  cout<<'\4';
	}
       if(v1==13)
	 break;}
       cardpwd[n2+1]='\0';
	    ticketdisp();
	    break;
   case 2 : cout<<"\n\n\n\t\t\tEnter the following DETAILS ";
	    cout<<"\n\n\n\t\tCREDIT CARD NUMBER   : ";
	    cin>>cardno;
	    cout<<"\n\n\t\tNAME                 : ";
	    cin>>carduser;
               cout<<"\n\n\t\tCVV NUMBER           : ";
	    cin>>cvv;
	    cout<<"\n\n\t\tPASSWORD             : ";
              for( i=0;i<20;i++)
               { ch3=getch();
	    v1=ch3;
	    if(v1!=13)
	   { cardpwd[i]=ch3;
	    n2=i;
	  cout<<'\4';
	}
       if(v1==13)
	 break;}
       cardpwd[n2+1]='\0';
	    ticketdisp();
	    break;
   case 3 : cout<<"\n\n\n\t\t\tEnter the following DETAILS ";
	    cout<<"\n\n\n\t\t\tCARD Number             : ";
	    cin>>cardno;
	    cout<<"\n\n\t\t\tPIN Number              : ";
               for( i=0;i<20;i++)
              { ch3=getch();
	    v1=ch3;
	   if(v1!=13)
	   { pin[i]=ch3;
	    n2=i;
	  cout<<'\4';
	}
       if(v1==13)
	 break;}
       pin[n2+1]='\0';
	    ticketdisp();
	    break;
 }
}
void ticketdisp()
{
clrscr();
cout<<"\n\n\n\n\t\t\t";
int n;
double time;
cout << "Your Transaction is being processed";
for (n=0; n<7; n++ )
{
 cout << ".";
 for ( time=0; time<=4000000; time++);
}
clrscr();
cout<<"\n\n\n\n\n\n\t\tTransaction has been SUCCESSFULLY COMPLETED. ";
cout<<"\n\n\t\tRs."<<amount+amt<<" has been DEDUCTED from your account.";
cout<<"\n\n\t\t      Your ticket has been BOOKED.";
cout<<"\n\n\n\n\t\t\t\tTHANKYOU...";
getch();
clrscr();
gotoxy(27,3);for(i=0;i<22;i++)cout<<char(4);
gotoxy(32,4);cputs("TICKET DETAILS");
gotoxy(27,5);for(i=0;i<22;i++)cout<<char(4);
gotoxy(27,8);cputs("TICKET HOLDER:");
gotoxy(42,8);cout<<ss1.username;
gotoxy(27,10);cputs("MOVIE:");
gotoxy(42,10);cout<<s.movname;
gotoxy(27,12);cputs("NO OF TICKETS:");
gotoxy(42,12);cout<<l;
gotoxy(27,14);cputs("SEAT NOS:");gotoxy(42,14);
for(int k=0;k<l;k++)
{cout<<tic[k]<<tick[k];
 cout<<"\t";
 }
 gotoxy(27,16);cputs("DATE:");gotoxy(42,16);
if(ch13==1)
 {for(int i=0;i<1;i++)
 {
 int k=yr%4;
if(((dt==31)&&(mn==1||mn==3||mn==5||mn==7||mn==8||mn==10))||((dt==30)&&(mn==4)))
 {
 dt=1;
 mn=mn+1;
 }
 else if((dt==31)&&(mn==12))
 {
 dt=1;
 mn=1;
 yr=yr+1;
 }
 else if(((k==0)&&(dt==29)&&(mn==2))||((k!=1)&&(dt==28)&&(mn==2)))
 {dt=1;
 mn=3;
 }
 else
 {dt=dt+1;
 }
 cout<<mn<<"/"<<dt<<"/"<<yr;
 }}
 else
 {for(int i=0;i<2;i++)
 {
 int k=yr%4;
 if(((dt==31)&&(mn==1||mn==3||mn==5||mn==7||mn==8||mn==10))||((dt==30)&&(mn==4)))
 {
 dt=1;
 mn=mn+1;
 }
 else if((dt==31)&&(mn==12))
 {
 dt=1;
 mn=1;
 yr=yr+1;
 }
 else if(((k==0)&&(dt==29)&&(mn==2))||((k!=1)&&(dt==28)&&(mn==2)))
 {dt=1;
 mn=3;
 }
 else
 {dt=dt+1;
 }
 }
 cout<<dt<<"/"<<mn<<"/"<<yr;
 }
 gotoxy(27,18);cputs("SHOW TIMING:");
 gotoxy(42,18);
 switch(ch14)
 {
 case 1:cputs("10:00 - 12:30");
	break;
 case 2:cputs("14:30 - 17:00");
	break;
 case 3:cputs("18:30 - 21.00");
	break;
 case 4:cputs("22:00 - 00:30");
	break;
 }
 getch();
 clrscr();
 cout<<"Do you wish to book more tickets? (y/n)   ";
cin>>ch15;
if(ch15=='y')
{++count;
amt=amount=elite=premire=economy=0;
signin();
}
else
 thankyou();
}
void logo()
{
int gd=DETECT;
int gm;
initgraph(&gd,&gm,"C:\\turboC3\\BGI");
setbkcolor(0);
settextstyle(1,HORIZ_DIR,8);
for(int i=1;i<15;i++)
{
if(i==7||i==8)
continue;
else
{
setcolor(i);
outtextxy(150,10,"THEATRE ");
outtextxy(60,100,"MANAGEMENT");
delay(300);
}
}
settextstyle(8,HORIZ_DIR,4);
setcolor(1);
outtextxy(165,220,"Project done by");
settextstyle(8,HORIZ_DIR,5);
setcolor(3);
outtextxy(120,280,"AHILA.R.R");
getch();
cleardevice();
int j,k;
gotoxy(24,19);
cout<<"L O A D I N G  P R O J E C T  "<<endl;
gotoxy(28,22);
cout<<"___________";
j=28;
for( i=0;i<101;i++)
{
gotoxy(41,22);
delay(50);
cout<<i<<"% completed"<<endl;
if(i%10==0)
{
gotoxy(j,22);
j++;
cout<<char(16);
}
}
cout<<"\n\n\t\t\t\tSUCCESSFULLY LOADED" <<endl;
 setcolor(14);
settextstyle(4,HORIZ_DIR,10);
for( i=0;i<50;i++)
{
outtextxy(125,0+i,"welcome");
outtextxy(75,0+i+100,"   to");
delay(10);
cleardevice();
}
outtextxy(125,50,"welcome");
outtextxy(267,150,"to");
getch();
closegraph();
clrscr();
delay(500);
textcolor(2);
clrscr();
int x=1;
cout<<"+";
delay(100);
for(i=0;i<78;i++)
{
delay(30);
gotoxy(2+i,1);cputs("-");
if(i<20)
{
gotoxy(1,i+2);cputs("*");
}
if(i==20)
{
gotoxy(1,22);cputs("+");
}
if(i>20)
{
gotoxy(x+1,22);cputs("-");
x++;
}
}
delay(50);
gotoxy(80,1);cputs("+");
for(i=0;i<22;i++)
{
delay(30);
if(i<20)
{
gotoxy(80,2+i);cputs("*");
}
gotoxy(x+i,22);cputs("-");
if(i==19)
{
gotoxy(80,22);cputs("+") ;
}
}
delay(700);
textcolor(14);
gotoxy(2,2);
cputs("+");
for(i=0;i<76;i++)
{
cputs("-");
}
for(i=3;i<21;i++)
{
gotoxy(2,i);cputs("*");
}
gotoxy(2,21);cputs("+");
for(i=3;i<79;i++)
{
gotoxy(i,21);cputs("-");
}
cputs("+") ;
for(i=20;i>2;i--)
{
gotoxy(79,i);cputs("*");
}
gotoxy(79,2);
cputs("+");
delay(700);
textcolor(12);
gotoxy(3,3);
cputs("+");
for(i=0;i<75;i++)
{
cputs("-");
}
for(i=4;i<21;i++)
{
gotoxy(3,i);
cputs("*");
}
gotoxy(3,20);
cputs("+");
for(i=4;i<78;i++)
{
gotoxy(i,20);
cputs("-");
}
cputs("+") ;
for(i=19;i>3;i--)
{
gotoxy(78,i);cputs("*");
}
gotoxy(78,3);
cputs("+");
x=59;int y=10;
char c=char(15);
for(i=10;i<60;i++)
{
delay(50);
gotoxy(i,10);cout<<c;
gotoxy(i-1,10);cout<<" ";
}
for(i=0;i<6;i++)
{
delay(100);
textcolor(12);
gotoxy ((x-i),(y-i));cout<<c;
gotoxy ((x+i),(y+i));cout<<c;
gotoxy ((x+i),(y-i));cout<<c;
gotoxy ((x-i),(y+i));cout<<c;
}
int m=x+5,n=x-5;
for(i=0;i<40;i++)
{
delay(60);
if(i<13)
{
gotoxy(m+i,y+5);cout<<c;
gotoxy(m+i,y-5);cout <<c;
}
gotoxy((n-i),y+5);cout<<c;
gotoxy((n-i),y-5);cout<<c;
}
delay(200);
gotoxy(27,8);for(i=0;i<5;i++)cout<<c;
gotoxy(27,9);cout<<"  "<<c;
gotoxy(27,10);cout<<"  "<<c;
gotoxy(27,11);cout<<"  "<<c;
gotoxy(27,12);for(i=0;i<5;i++)cout<<c;
delay(200);
gotoxy(37,8);cout<<c<<"     "<<c;
gotoxy(37,9);cout<<c<<" "<<c;
gotoxy(37,10);cout<<c<<"  "<<c<<"  "<<c;
gotoxy(37,11);cout<<c<<"   "<<c<<" "<<c;
gotoxy(37,12);cout<<c<<"     "<<c;
delay(200);
gotoxy(46,8);cout<<"  "<<c<<" "<<c<<" "<<c;
gotoxy(46,9);cout<<"  "<<c<<"   "<<c;
gotoxy(46,10);cout<<"  "<<c<<"   "<<c;
gotoxy(46,11);cout<<"  "<<c<<"   "<<c;
gotoxy(46,12);cout<<"  " <<c<<" "<<c<<" "<<c;
delay(200);
char temp[]={"INOX::ENTERTAINMENT UNLIMITED"};
x=46;
c=char(2);
for(i=0;i<24;i++)
{
delay(100);
gotoxy(x-i,16);cout<<c<<temp<<c;
gotoxy((x-i+32),16);cout<<" ";
}
delay(40);gotoxy(31,17);cout<<"Adayar,Chennai"<<endl;
delay(40);gotoxy(4,19);cout<<"www.inoxcinemas.com";
gotoxy(65,19);cout<<"Ph:044-623311"<<endl;
getch();
}
void thankyou()
{ clrscr();
gotoxy(18,4);
cout<<"\n";
cout<<endl<<"       _/_/_/_/_/  _/                           _/";
cout<<endl<<"	   _/      _/          _/_/_/  _/_/_/   _/  _/";
cout<<endl<<"	   _/      _/ _/_/   _/    _/  _/   _/  _/_/  ";
cout<<endl<<"	   _/      _/    _/  _/    _/  _/   _/  _/  _/ ";
cout<<endl<<"	   _/      _/    _/   _/_/_/   _/   _/  _/   _/ ";
gotoxy(15,12);
cout<<endl<<"                _/   _/                   ";
cout<<endl<<"                 _/ _/  _/_/_/_/  _/    _/";
cout<<endl<<"                  _/    _/    _/  _/    _/";
cout<<endl<<"                  _/    _/    _/  _/    _/";
cout<<endl<<"                  _/    _/_/_/_/  _/_/_/_/";
getch();
exit(0);
}
