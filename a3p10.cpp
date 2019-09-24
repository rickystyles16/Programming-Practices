#include<iostream>
using namespace std;
int count=0;
#define max_size 10
class APPLICANT{
	int id;
	int score;
	char name[20];
	public:
		void get_data()
		{
			id=count+1;
			cout<<"Enter the Name and Score: ";
			cin>>name;
			cin>>score;
			count++;
		}
		void print_data()
		{
			cout<<"\t\t\t DATA\n";
			cout<<"Application Id: "<<id<<"\n";
			cout<<"Name: "<<name<<"\n";
			cout<<"Score: "<<score<<"\n";
		}
};
void show_count()
{
	cout<<"No. of applicants: "<<count<<"\n";
}
int menu()
{
	 int choice;
      cout <<"\t"<<"Menu"<<"\n";
      cout << "1.ADD Applicant data"<<"\n";
      cout << "2.SHOW Applicant data"<<"\n";
      cout << "3.SHOW Number of applicants"<<"\n";     
	  cout << "4.Exit"<<"\n";
	  cin >> choice;     
	 return choice;

}
int main()
{
	class APPLICANT data[max_size];
	 int choice;
do
	{
	    choice = menu();
		switch(choice)
	    {
		case 1 : data[count].get_data(); 
		           break;
	    case 2 : int id;
				 cout<<"Enter the application id: ";
				 cin>>id;  
				 data[id-1].print_data();
	               break;
	    case 3 : show_count();
	               break;
		case 4  : printf ("System exit!\n");
	               break;
		default : printf("\nPlease try again with a valid choice\n");    
		}
	}
	while (choice != 4);
		
	
    return 0;
}

