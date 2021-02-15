//********************************************************************
///               HEADER FILE USED IN PROJECT
//********************************************************************

#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
#include<string>

using namespace std;


//****************************************************************
///                   CLASS USED IN PROJECT
//****************************************************************


class account

{
private :

    char nid[18];
    char acno[20];
    char Accname[50];
    char mobile[11];
    char type[20];
    int ibalance;
    char Bank;
    int dop;
    int with;

public :

    void menu();
    void get();
    void deposite();
    void check();
    void withdraw();
    void info();
    void file();

};


void account :: menu()
{

    int i;
    do
    {

    cout<<"\n\n\t MAIN MENU \t\n";
    cout<<"\t\tChoose your option from 1-to-6\n";
    cout<<"\t\t 1. create a New Account\n";
    cout<<"\t\t 2. Deposite Your Money\n";
    cout<<"\t\t 3. Check your Balance\n";
    cout<<"\t\t 4. withdraw Amount\n";
    cout<<"\t\t 5. your Account's All Info\n";
    cout<<"\t\t 6. Now Save Information File\n";
    cout<<"\t\t 7. Exit";
    cout <<"\n\t\t";

    cin >> i;
    switch(i)

    {

        case 1:
            get();
            break;

        case 2:
            deposite();
            break;

        case 3:
            check();
            break;

        case 4:
            withdraw();
            break;

        case 5:
            info();
            break;

        case 6:
            file();
			break;

        case 7:
			cout<<"\n\n\tThanks for using Banking Managemnt System";
			exit(0);
			break;

        default :
            cout<<"\a";
            break;
    }
        cin.ignore();
		cin.get();

	}

	while(i=7);


}


void account :: get ()

{
    int go;

    cout<<"\t\t====================================================\n\n";
    cout <<"\n\t\t Welcome to our Bank Management System Project"<< Bank << "\n";
    cout<<"\n\t\t====================================================\n\n";


    cout<<"\nEnter The NID No. :";
    cin>>nid;
    cout<<"\n";

    cout<<"\nEnter The account No. :";
    cin>>acno;
    cout<<"\n";


    cout <<"\n Enter Accname Name : ";
    cin.ignore();
	cin.getline(Accname,50);
    cout<<"\n";

    cout<<"\nEnter The Mobile No. :";
    cin>>mobile;
    cout<<"\n";


    cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) \n";
    cout<<"\t\t\n Enter your Deposite Money : ";
    cout<<"\t\t";

    cin>>ibalance;

    cout <<"\t \t \n Enter the types of Account : ";
    cin>>type;
    cout<<"\n";

    cout<<"\t\t\n Hit \'0\' for GoTo MainMenu : ";
    cout<<"\n";
    cin>>go;
    if (go  == 0)
    {
        menu();
    }
    else
        return;

}

void account :: deposite()

{
    int go;
    cout <<"\n \t \t Enter your Deposite Money : \t";
    cout<<"\t\t";
    cin>>dop;
    dop += ibalance;

    cout<<"\t\t\n Hit \'0\' for GoTo MainMenu : ";
    cout<<"\n";
    cin>>go;
    if (go  == 0)
    {
        menu();
    }

}

void account :: check()

{
    int go;
    cout << "Your current balance : "<<dop<<"\n\n";
    cout<<"\t\t\n Hit \'0\' for GoTo MainMenu : ";
    cout<<"\n";
    cin>>go;
    if (go  == 0)
    {
        menu();
    }

}

void account :: withdraw ()

{
    int go;
    cout << "How much money you wanna withdraw?\n ";
    cout <<"\n \t \t Enter your withdraw Money : \t";
    cout<<"\t\t";
    cin>>with;
    dop -= with;
    cout<<"\t\t\tAfter Withdrawing Balance : "<<dop << "\n\t";
    cout<<"\n\t\t\n Hit \'0\' for GoTo MainMenu : ";
    cout<<"\n";
    cin>>go;
    if (go  == 0)
    {
        menu();
    }

}

void account :: info()

{
    int go;
    cout << "\n\t\t Type of NID Number : "<< nid << "\n";
    cout<<"\t\t====================================================\n\n";
    cout<<"\n\t\t Type of Account Number : "<< acno << "\n";
    cout<<"\t\t====================================================\n\n";
    cout<<"\t\t Name of the Account :"<< Accname <<"\n";
    cout<<"\t\t====================================================\n\n";
    cout<<"\t\t Account of the Mobile Number :"<< mobile <<"\n";
    cout<<"\t\t====================================================\n\n";
    cout<<"\t\t Type of the Account : "<< type << "\n";
    cout<<"\t\t====================================================\n\n";
    cout<<"\t\t Ammount in Your Account : "<< dop << "\n";
    cout<<"\t\t====================================================\n\n";
    cout<<"\t\t Hit \'0\' for GoTo MainMenu : ";
    cout<<"\n";
    cin>>go;
    if (go  == 0)
    {
        menu();
    }
}

//***************************************************************
///    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************


int main()

{

    account obj;
    obj.menu();

    getch();
    return 0;

}

//***************************************************************
///    	function to Create a file
//****************************************************************


void account :: file()
{
    int go;

    char data[100],t_data[30];

   ofstream outfile;
   outfile.open("text.txt");
   cout << "Writing to the file\n" << endl;
   cout << "Enter your Account Number:";
   cin>>data;
   outfile << data << endl;
   cout << "Final Amount in your Account : ";
   cin >>t_data;
   cin.ignore();
   outfile << t_data << endl;
   outfile.close();


   ifstream infile;
   infile.open("text.txt");
   string checking;
   cout << "\nReading from the file" << endl;
    string line;
    if(infile.is_open())
    {
        while(getline(infile,checking))
               {
                   cout<<checking<<endl;
               }
    outfile.close();
    }
    else
    {
        cout<<"File not open";
    }

    cout<<"\t\t\n Hit \'0\' for GoTo MainMenu : ";
    cout<<"\n";
    cin>>go;
    if (go  == 0)
    {
        menu();
    }

}
