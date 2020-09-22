#include<bits/stdc++.h>
#include<windows.h>
#include"project.h"
#include"project2.h"
#include"project3.h"

using namespace std;
//********************************************
// the function of control the enter all class
//********************************************
void control()
{
		team x1;
	audience x2;
	 clubs x3;
      system("cls");
	   cout<<"\n\n\n";
		cout<<"\n\t If you want to enter data of teams press  : 1  \n\t If you want to enter data of fans press  : 2 \n\t If you want to enter data of clubs press : 3 \n\t If you want exist feom program  press : 4 "<<endl;
		int y;
		cin>>y;
		switch (y)
		{
		case 1:
          x1.teams();
          break ;
        case 2 :
        	x2.chosing();
        case 3 :
             x3.chosing();
        break;
        case 4 :
         cout<<"\3 \3 \3 Bye \3 \3 \3\n";
         break;
        default :
	    cout<<"choose rigth number \n";
		}
}

/********************************
constractor to Initial value
*********************************/
var3::var3(){
strcpy(name,"no name");
number[0] ='0';
score[0]='0';
strcpy(trainer,"no name");
}
/********************************
destractor to destroy object
*********************************/
var3::~var3(){}

//****** static ********
int team::x=0;
//********************************
//fanction to delete data
//********************************/
void team :: delete_club(){
	fstream club ;
	fstream temp ;
	club.open("world_club.txt",ios::in);  //open the file
	temp.open("club.txt",ios::out);      //open the file
	char a[25];
	cin.ignore();
	cout<<"\n\t Enter The name to delete record : ";
	cin.getline(a,25);
	while(!club.eof())
	{
     club.getline(name,25,'*');
     club.getline(number,25,'*');
     club.getline(score,25,'*');
     club.getline(trainer,25);
     if(!strcmp(name,a)==0 )
	  {
	  temp<<name<<'*'<<number<<'*'<<score<<'*'<<trainer<<'\n';
      }
	}
	temp.close();
	club.close();
	remove ("world_club.txt");
    rename("club.txt","world_club.txt");
	temp.close();  //close the file
	club.close();   //close the file
	cout<<"\n done \n";

}
//*******************************************
//fanction to update  data
//*******************************************
void team :: update_club()
{
	fstream club ;
	fstream temp ;
	club.open("world_club.txt",ios::in);  //open the file
	temp.open("club.txt",ios::out);       //open the file
	char a[25];
	cin.ignore();
	cout<<"\n\t Enter The name or number to update record : ";
	cin.getline(a,25);
	while(!club.eof())
	{
     club.getline(name,25,'*');
     club.getline(number,25,'*');
     club.getline(score,25,'*');
	 club.getline(trainer,25);

     if(strcmp(name,a)==0||strcmp(number,a)==0)
     {
      cout <<"\n\tEnter The New Value of Record \n";
      cout<<"name : \n";
      cin.getline(name,25);
	  cout<<"number : \n";
	  cin.getline(number,25);
	  cout<<"score : \n";
	  cin.getline(score,25);
	  cout<<"trainer : \n";
	  cin.getline(trainer,25);
	  temp<<name<<'*'<<number<<'*'<<score<<'*'<<trainer<<'\n';
	 }
	  else
	  {
	  temp<<name<<'*'<<number<<'*'<<score<<'*'<<trainer<<'\n';
      }
	}
	temp.close();
	club.close();

   	remove ("world_club.txt");
    rename("club.txt","world_club.txt");
	temp.close();   //close the file
	club.close();    //close the file

	cout<<"\n done \n";

}
//********************************
//fanction to disblay data
//********************************
void team :: display_club()
{
	fstream club ;
	club.open("world_club.txt",ios::in); //open the file
     cout <<"----------------------------------------------------------------- \n";
	cout <<"|  name\t\t|\tnumber\t|\tscore\t|\ttrainer |\n";
	cout <<"----------------------------------------------------------------- \n";
    while(!club.eof())
   {
     club.getline(name,25,'*');
     club.getline(number,25,'*');
     club.getline(score,25,'*');
     club.getline(trainer,25);
    cout<<setw(10)<<name<<setw(18)<<number<<setw(15)<<score<<setw(19)<<trainer<<"  |\n";

  }
  cout <<"----------------------------------------------------------------- \n";
  cout<<"\n the count of all teams = "<<x<<endl;
  club.close();    //close the file
}
//********************************
//function to search about data
//********************************
void team::search_club(){
	fstream club ;
	club.open("world_club.txt",ios::in);    //open the file
	char a[25];
	cout<<" \n enter the name or number to search about it : \n";
	cin.ignore();
	cin.getline(a,25);
    int x=0 ;
    while(!club.eof())
   {
     club.getline(name,25,'*');
     club.getline(number,25,'*');
     club.getline(score,25,'*');
     club.getline(trainer,25);
     if(strcmp(name,a)==0||strcmp(number,a)==0)
     {
     cout<<"name : "<<name<<"\n"<<"number : "<<number<<"\n"<<"score : "<<score<<"\n"<<"trainer : "<<trainer<<"\n";
     x=1;
     break ;
     }
   }
     if(x==0)
     {
     	cout<<"not found !!! \n";
	 }
   club.close();    //close the file

}
//*********************************
//fanction to insert data
//********************************
void team :: insert_club()
{
	fstream club ;
	club.open("world_club.txt",ios::app);  //open the file
	cin.ignore();
	cout<<"name : \n";
	cin.getline(name,25);
	cout<<"number : \n";
	cin.getline(number,25);
	cout<<"score : \n";
	cin.getline(score,25);
	cout<<"trainer : \n";
	cin.getline(trainer,25);
	club<<name<<'*'<<number<<'*'<<score<<'*'<<trainer<<'\n';
	cout<<"done \n";
	x++;
    club.close();      //close the file
}
//********* const function **********
void team::print_message() const
{
	cout<<"\n\t Welcome to the data of teams \1 have fun \1";
}
//***************************************
//fanction to controll to all function
//***************************************
 team team :: teams(){
    system("cls");
    print_message();
	bool flag=true ;
	while(flag)
    {
	 cout<<"\n\n\t If you want to insert data of teams : 1 \n\t If you want to search about data of teams : 2 \n\t If you want to display all data of teams : 3 \n\t If you want to update data of  teams: 4 \n\t If you want to delete the data of teams: 5 \n\t if you want go back to the main menu : 6 \n\t if you want exist feom program  press : 7\n\n\t write your choose : \n";
	 int c;
	 cin>>c;
	if (c==7)
   {    cout<<"\3 \3 \3 Bye \3 \3 \3\n";
        break;
   }
	 switch (c)
	 {

	  case 1:
	 	insert_club();
	 	break;
	  case 2:
	  	  search_club();
	  	 break;
	  case 3 :
	  display_club();
	  break;
	  case 4 :
	  	update_club();
		  break;
	  case 5:
	  	delete_club();
	  	break;
	  case 6 :
	  	control();
	  	break;
	 default :
	    cout<<"choose rigth number \n";

	}

	cout<<"\n\tif you contnuie to use program press 'z' \n";
	char f;
	cin>>f;
	if(f!='z')
	 {
	   flag=false;
	 }
    system("cls");
   }

}
/***********************************************************************************************************
*    class 2 of the fans                                                                              *                                                                                                            *
 **********************************************************************************************************/
 /********************************
constractor to Initial value
*********************************/
var::var(){
  	strcpy(name,"no name");
  	id[0]='0';
  }
/********************************
destractor to destroy object
*********************************/
var::~var(){}
//****** static ********
int audience::x=0;
 //******************************************
//fanction to display  data
//******************************************
 void audience::display(){
 		fstream people ;
	people.open("people_clup.txt",ios::in); //open the file
    cout <<"---------------------------- \n";
	cout <<"| name\t\t|\tid |\n";
	cout <<"---------------------------- \n";
    while(!people.eof())
   {
     people.getline(name,25,'*');
     people.getline(id,25);

    cout<<name<<"\t\t\t"<<id<<"  |\n";

  }
  cout <<"----------------------------------- \n";
  cout<<"\n the count of all fans = "<<x<<endl;
  people.close();    //close the file
 }
 
//*********************************
//function to sreach about data
//*********************************
void audience::search(){
	fstream people ;
	people.open("people_clup.txt",ios::in);    //open the file
	char a[25];
	cout<<" \n enter the name or id to search about it : \n";
	cin.ignore();
	cin.getline(a,25);
    int x=0 ;
    while(!people.eof())
   {
     people.getline(name,25,'*');
     people.getline(id,25);
     if(strcmp(name,a)==0||strcmp(id,a)==0)
     {
     cout<<"name : "<<name<<"\n"<<"id : "<<id<<"\n";
     x=1;
     break ;
     }
   }
     if(x==0)
     {
     	cout<<"not found !!! \n";
	 }
   people.close();

}
//*******************************************
//fanction to insert  data
//*******************************************
void audience :: insert ()
{
	fstream people ;
	people.open("people_clup.txt",ios::app);  //open the file
	cin.ignore();
	cout<<"name : \n";
	cin.getline(name,25);
	cout<<"id : \n";
	cin.getline(id,25);
	people<<name<<'*'<<id<<'\n';
	cout<<"done \n";
    people.close();
    x++;
}
//*********const function************
void audience::print_message() const
{
	  cout<<" \n\tWelcome to the data of fans \1 have fun \1";
}
//*******************************************
//fanction to controll all faunctions
//*******************************************
audience audience :: chosing(){
      system("cls");
    print_message();
		bool flag= true ;
	while(flag)
    {
	 cout<<"\n\n\t If you want to insert the data of fans: 1 \n\t If you want to search about data of fans : 2 \n\t If you want to display all data of fans : 3 \n\t if you want go back to the main menu : 4\n\t if you want exist from program : 5\n\n\t write your choose : \n";
	 int a;
	 cin>>a;
	if (a==5)
   {    cout<<"\3 \3 \3 Bye \3 \3 \3\n";
        break;
   }
	 switch (a)
	 {

	  case 1:
	 	 insert();
	 	 break;
      case 2 :
        search();
	 	break;
	  case 3 :
	  	display();
	  	break;
	  case 4 :
	    control();
	  	break;
	 default :
	    cout<<"choose rigth number \n";

	}

	cout<<"\n\tif you contnuie to use program press 'z' \n";
	char f;
	cin>>f;
	if(f!='z')
	 {
	   flag=false;
	 }
    system("cls");
   }
}
//*********************************************************************************************************************************************
// class 3 of the clubs
//*********************************************************************************************************************************************
 /********************************
constractor to Initial value
*********************************/

  var2::var2(){
  	strcpy(name_of_clubs,"no name");
  	id_of_clubs[0]='0';
  }
/********************************
destractor to destroy object
*********************************/
var2::~var2(){}

 //******************************************
//fanction to display  data
//******************************************
 void clubs::display2(){
 		fstream stad ;
	stad.open("clups.txt",ios::in); //open the file
    cout <<"---------------------------- \n";
	cout <<"| name\t\t|\tid |\n";
	cout <<"---------------------------- \n";
    while(!stad.eof())
   {
     stad.getline(name_of_clubs,25,'*');
     stad.getline(id_of_clubs,25);

    cout<<name_of_clubs<<"\t\t"<<id_of_clubs<<"  |\n";

  }
  cout <<"---------------------------- \n";
  stad.close();    //close the file
 }
//*********************************
//function to sreach about data
//*********************************
void clubs::search2(){
	fstream stad ;
	stad.open("clups.txt",ios::in);    //open the file
	char a[25];
	cout<<" \n enter the name or id to search about it : \n";
	cin.ignore();
	cin.getline(a,25);
    int x=0 ;
    while(!stad.eof())
   {
     stad.getline(name_of_clubs,25,'*');
     stad.getline(id_of_clubs,25);
     if(strcmp(name_of_clubs,a)==0||strcmp(id_of_clubs,a)==0)
     {
     cout<<"name : "<<name_of_clubs<<"\n"<<"id : "<<id_of_clubs<<"\n";
     x=1;
     break ;
     }
   }
     if(x==0)
     {
     	cout<<"not found !!! \n";
	 }
   stad.close();

}
//*******************************************
//fanction to insert  data
//*******************************************
void clubs :: insert2 ()
{

	fstream stad ;
	stad.open("clups.txt",ios::app);  //open the file
	cin.ignore();
	cout<<"name : \n";
	cin.getline(name_of_clubs,25);
	cout<<"id : \n";
	cin.getline(id_of_clubs,25);
	stad<<name_of_clubs<<'*'<<id_of_clubs<<'\n';
	cout<<"done \n";
    stad.close();

}
//**********const function***********
void clubs::print_message() const
{
	 cout<<" \n\tWelcome to the data of clubs \1 have fun \1";
}
//*******************************************
//fanction to controll all faunctions
//*******************************************
clubs clubs :: chosing(){
     system("cls");
     print_message();
		bool flag= true ;
	while(flag)
    {
	 cout<<"\n\n\t If you want to insert the data of clubs: 1 \n\t If you want to search about data of clubs : 2 \n\t If you want to display all data of clubs : 3 \n\t if you want go back to the main menu : 4\n\t if you want exist feom program : 5\n\n\t write your choose : \n";
	 int a;
	 cin>>a;
	if (a==5)
   {    cout<<"\3 \3 \3 Bye \3 \3 \3\n";
        break;
   }
	 switch (a)
	 {

	  case 1:
	 	 insert2();
	 	 break;
      case 2 :
        search2();
	 	break;
	  case 3 :
	  	display2();
	  	break;
	  case 4 :
	    control();
	  	break;
	 default :
	    cout<<"choose rigth number \n";

	}

	cout<<"\n\tif you contnuie to use program press 'z' \n";
	char f;
	cin>>f;
	if(f!='z')
	 {
	   flag=false;
	 }
     system("cls");
   }
}


int main ()
{
	cout<<"\a\n\n\t";
	char ch1[]={'\4','W','e','l','c','o','m','e',' ','T','o',' ','W','o','r','l','d',' ','C','l','u','b',' ','"','2','0','1','8','"','\4'};
	cout<<"\n\t";
	for(int i=0; i<30; i++){
        Sleep(200);
		cout<<ch1[i];
	}
    cout<<" \3\3 ";
    cout<<" \n\n\t\t\t\t";
    char ch2[]={'h','a','v','e',' ','f','u','n',' ','\1','\1' };
    	for(int i=0; i<11; i++){
        Sleep(200);
		cout<<ch2[i];
	}
    system("cls");
		control();
}
