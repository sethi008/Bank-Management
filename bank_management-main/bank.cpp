#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;

class temp{
    int accNo;
	char name[25];
	char Fname[25];
	char Pan_number[25];
	char Contact[25];
	char email[25];
	float amount;
	int newAmount;
    fstream file,file1;

    public:
	int search;

    void createAccount(void);   // declaration of create account function
    void depositAmount(void);   // declaration of depositAmount function
    void withdrawAmount(void);  // declaration of withdrawAmount function
    void checkInfo(void);       // declaration of checkInfo function
};

int main(){

    temp obj;
    char choice;

    cout<<"\n\n\n\t\t......:::IDE Bank:::......";
	cout<<"\n\t\t:: press 1 to Login  Account :: ";
	cout<<"\n\t\t:: press 2 to Create Account ::";
	cout<<"\n\t\t:: press 0 to Exit           ::";
	cout<<"\n\t\t:: ......................... ::\n\t\t\t\t";
	cin>>choice;

    switch(choice){
        case '1':
            cout<<"Enter your account no :: ";
	        cin>>obj.search;
        while(1){

            cout<<"\n\n\n\t\t.......:::IDE Bank:::.......";
            cout<<"\n\t\t:: press 1 to Deposit  Amount  :: ";
            cout<<"\n\t\t:: press 2 to Withdraw Amount  ::";
            cout<<"\n\t\t:: press 3 to Check    Info    ::";
            cout<<"\n\t\t:: press 0 to Exit     Menu    ::";
            cout<<"\n\t\t:: ........................... ::\n\t\t\t\t";
            cin>>choice;

            switch (choice)
            {
            case '1':
                obj.depositAmount();
            break;
            case '2':
                obj.withdrawAmount();
            break;
            case '3':
                obj.checkInfo();
            break;
            case '0':
                return 0;
            break;
            default:
                cout<<"Invalid Choice...!";
            break;
            }
            system("pause");
            system("cls");
        }
        break;
        case '2':
            obj.createAccount();
        break;
        case '0':
            system("exit");
        break;
        default :
            cout<<"\n Invalid choice...! ";
        break;
    }
    return 0;
}
// Defination of create account function
void temp :: createAccount(){

    srand(time(0));
	accNo=rand()*rand()+rand()*rand();

	cout<<"Enter Your name :: ";
	cin>>name;

	cout<<"Enter Your Father name :: ";
	cin>>Fname;

	cout<<"Enter Your Pan number :: ";
	cin>>Pan_number;

	cout<<"Enter Your phone no. :: ";
	cin>>Contact;

	cout<<"Enter Your email :: ";
	cin>>email;

	cout<<"Enter Your amount :: ";
	cin>>amount;

	cout<<endl<<" This is your account number... \n"<<accNo<<endl;
	cout<<"Please save it \n\n";

	file.open("data.txt",ios::out|ios::app);
	file<<accNo<<"\t"<<name<<"\t"<<Fname<<"\t"<<Pan_number<<"\t"<<Contact<<"\t"<<email<<"\t"<<amount<<endl;
	file.close();
}
// Defination of depositAmount function
void temp :: depositAmount(){

	cout<<"Enter amount to deposit :: ";
	cin>>newAmount;

	file.open("data.txt",ios::in);
	file1.open("data1.txt",ios::out|ios::app);
	file>>accNo>>name>>Fname>>Pan_number>>Contact>>email>>amount;

	while(!file.eof()) {
		if(accNo==search){
			cout<<"\n current amount :: "<<amount;
			amount=amount + newAmount;
			cout<<"\n updated amount :: "<<amount<<endl;
			file1<<accNo<<"\t"<<name<<"\t"<<Fname<<"\t"<<Pan_number<<"\t"<<Contact<<"\t"<<email<<"\t"<<amount<<endl;
		}else{
			file1<<accNo<<"\t"<<name<<"\t"<<Fname<<"\t"<<Pan_number<<"\t"<<Contact<<"\t"<<email<<"\t"<<amount<<endl;
		}
		file>>accNo>>name>>Fname>>Pan_number>>Contact>>email>>amount;
	}

	file.close();
	file1.close();
	remove("data.txt");
	rename("data1.txt","data.txt");
}
// Defination of withdrawAmount function
void temp :: withdrawAmount(){

	cout<<"Enter amount to withdraw :: ";
	cin>>newAmount;

	file.open("data.txt",ios::in);
	file1.open("data1.txt",ios::out|ios::app);
	file>>accNo>>name>>Fname>>Pan_number>>Contact>>email>>amount;

	while(!file.eof()) {
		if(accNo==search){
			cout<<"\n current amount :: "<<amount;
			amount=amount - newAmount;
			cout<<"\n updated amount :: "<<amount<<endl;
			file1<<accNo<<"\t"<<name<<"\t"<<Fname<<"\t"<<Pan_number<<"\t"<<Contact<<"\t"<<email<<"\t"<<amount<<endl;
		}else{
			file1<<accNo<<"\t"<<name<<"\t"<<Fname<<"\t"<<Pan_number<<"\t"<<Contact<<"\t"<<email<<"\t"<<amount<<endl;
		}
		file>>accNo>>name>>Fname>>Pan_number>>Contact>>email>>amount;
	}

	file.close();
	file1.close();
	remove("data.txt");
	rename("data1.txt","data.txt");
}
// Defination of checkInfo function
void temp :: checkInfo(){


	fstream file;
	file.open("data.txt",ios::in);
	if(!file){
		cout<<"File opening error !";
	}
	file>>accNo>>name>>Fname>>Pan_number>>Contact>>email>>amount;
	while(!file.eof()){
		if(accNo==search){
            cout<<"\n---------------------------\n";
            cout<<endl<<"\t::: account Number ::: ";
            cout<<"\t   "<<accNo<<endl;
            cout<<"\t::: User Name      ::: ";
            cout<<"\t   "<<name<<"\n";
            cout<<"\t::: Father Name    ::: ";
            cout<<"\t   "<<Fname<<"\n";
            cout<<"\t::: Pan number    ::: ";
            cout<<"\t   "<<Pan_number<<"\n";
            cout<<"\t::: Phone Number   ::: ";
            cout<<"\t   "<<Contact<<"\n";
            cout<<"\t::: Email          ::: ";
            cout<<"\t   "<<email<<"\n";
            cout<<"\t::: Current amount ::: ";
            cout<<"\t   "<<amount<<endl;
            cout<<"\n---------------------------\n\n";

	    }
		file>>accNo>>name>>Fname>>Pan_number>>Contact>>email>>amount;
	}

	file.close();
}
