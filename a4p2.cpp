#include<iostream>
using namespace std;
class COMPLEX{
    int real,im;
public:
    COMPLEX(int r=0,int i=0){
        real=r;
        im=i;
    }
    ~COMPLEX()
    {
        
    }
    void get_data()
    {
    	cout << "Enter REAL & IMAGINARY PART :: ";
    	cin >> real;
    	cin >> im ;
	}
    
    COMPLEX operator +(COMPLEX b)
    {
        COMPLEX temp;
        temp.real=real+b.real;
        temp.im=im+b.im;
        return temp;
    }
    COMPLEX operator -(COMPLEX b)
    {
        COMPLEX temp;
        temp.real=real-b.real;
        temp.im=im-b.im;
        return temp;
    }
    void show_data()
    {
    	if (im >=0)
        cout<<real<<" + "<<im<<"i\n";
        else
        {
	        im = im *-1;
		    cout<<real<<" - "<<im<<"i\n";
	    }
	}
};

int menu ()
{
	int choice;
      cout <<"\t"<<"Menu"<<"\n";
      cout << "1.ADD "<<"\n";
      cout << "2.SUBSTRACT "<<"\n";
      cout << "3.SHOW "<<"\n";     
	  cout << "4.Exit"<<"\n";
	  cin >> choice;     
	 return choice;
}

int main()
{
    COMPLEX a,b;
    COMPLEX c;
    
    int choice;
do
	{ 
	    choice = menu();
		switch(choice)
	    {
		case 1 : a.get_data();
		         b.get_data();
				 c = a+b;
				 c.show_data(); 
		           break;
	    case 2 : a.get_data();
	             b.get_data();
	             c = a - b;
	             c.show_data();
		           break;
	    case 3 : a.get_data();
	             b.get_data(); 
		         a.show_data();
	             b.show_data();
	               break;
		case 4  : printf ("System exit!\n");
	               break;
		default : printf("\nPlease try again with a valid choice\n");    
		}
	}
	while (choice != 4);
		
	
    return 0;

    
    
    
    
    
    
}
