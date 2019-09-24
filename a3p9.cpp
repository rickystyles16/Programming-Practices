  
#include<iostream>
using namespace std;
#define max_size 10
class STACK{
    int array[max_size];
    int pushed=0;
public:
    void push()
    {
        if(pushed==max_size)
        {
            cout<<"Error: OVERFLOW detected\n";
            return;
        }
        cout<<"Enter the data: ";
        cin>>array[pushed];
        pushed++;
    }
    void pop()
    {
        if(pushed==0)
        {
            cout<<"Error: UNDERFLOW detected\n";
            return ;
        }
        pushed--;
    }
    void show()
    {
    	for (int i =0 ; i<pushed;i++)
    	cout << array[i]<<"\n";
	}
       
};

int menu()
 {
     int choice;
      cout <<"\t"<<"Menu"<<"\n";
      cout << "1.Push"<<"\n";
      cout << "2.Pop"<<"\n";
      cout << "3.Show Elements"<<"\n";     
	  cout <<"4.Exit"<<"\n";
	  cin >> choice;     
	 return choice;
}


int main()
{
    class STACK s;
    int choice;
do
	{
	    choice = menu();
		switch(choice)
	    {
		case 1 : s.push(); 
		           break;
	    case 2 : s.pop();
	               break;
	    case 3 : s.show();
	               break;
		case 4  : printf ("System exit!\n");
	               break;
		default : printf("\nPlease try again with a valid choice\n");    
		}
	}
	while (choice != 4);
		
	
    return 0;
}

