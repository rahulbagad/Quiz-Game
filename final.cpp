#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<vector>
#include<unistd.h>
using namespace std;

char nick[50];

int life=4,no;
vector<int> c;
int fifty=1,phone_a_friend=1,expert_advice=1,audience_poll=1;

void phonefriend();
void fiftyfifty(char);
void auidencepoll(char);
void expert(char);
void getinfo();
void wait(long int);
void lifeline(char );
void balance(int,int);

int main()
{
    cout<<"\n-----------------------------------------------------WELCOME TO KBC--------------------------------------------------------\n";
    getinfo();
    cout<<"\n\t\t\t\tLET'S START THE GAME\n\n";
    ifstream in;
    for(int i=0;i<4;i++)
        c.push_back(i);
    in.open("kbc.txt",fstream::binary);
    char a[500];
    while(!in.eof())
    {
            char ch,ch1,ph,ch2,ch3,ch4;
            unsigned int sval;
            time_t t;
            sval=(unsigned)time(&t);
	    
            srand(sval);
            system("clear");
            for(int i=1;i<15;i++)
            {
                int num=rand() % 3;
		int d;
		system("clear");
		for(d=0;d<num*6;d++)
		{
			in.getline(a,500);	
		}
		for(int j=0;j<=4 || (i>=15 && j<=5);j++)
                {
                    in.getline(a,500);
		    puts(a);   
		}
		in>>ph;
		cout<<"\nEnter L for lifeline: "<<endl;  
                cout<<"\nEnter option: ";
                cin>>ch;
                while(ch=='L' )
                {
                        if(life==0)
                        {
                            cout<<"No lifeline available\n";
                            cout<<"Do you want to continue?Press N to exit safely with current balance";
                            cin>>ch1;
                            if(ch1=='N')
                                balance(i,-1);
                            else
                            {
                                    cin>>ch2;    break;
                                                  
                            }                                      
                         }
                         lifeline(ph);
                         cout<<"\nWant to use Lifeline again press Y or N: ";     cin>>ch3;
                         if(ch3=='y')
                                 lifeline(ph);
                         else
                         {
                                cout<<"\nAapka ka jawab:";
                                cin>>ch4;    
			        break;
                         }                       
                  
                }      
                if(ch==ph || ch2==ph || ch4==ph)
                    balance(i,1);
                else
                {
                    balance(i,0);
	            return 0;
                }
         
		for(d=0;d<=(2-num)*6;d++)
		{
			in.getline(a,500);
		}
                          
            }
  
    }  
    return 0;
}

// Function to input Information
void getinfo()
{
    cout<<"\nEnter Your Nick Name:";
    cin>>nick;
    cout<<"\nEnter Your Account Number:";
    cin>>no;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void phonefriend()
{
    int opt;
    phone_a_friend=0;  
    cout<<"\nAvailable Phone Numbers to call Friend are";
    cout<<"1) 8888855555\n"<<"2) 9503386612\n"<<"3) 8237669414\n"<<"4) 7350617969\n";
    cin>>opt;
    cout<<"\nCalling Your Friend..........";
    switch(opt)
    {
        case 1:
            cout<<"It's Probably answer is A";
            break;     
        case 2:
            cout<<"It's Probably answer is B";
            break;     
        case 3:
            cout<<"It's Probably answer is C";
            break;     
        case 4:
            cout<<"It's Probably answer is D";
            break;     
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void fiftyfifty(char ch)
{
  
    fifty=0;
    int n=ch-97;
    switch(n)
    {
        case 0:
            cout<<"\nIt's Probabale answer is "<<ch<<" or "<<char(ch+1);
            break;
        case 1:
            cout<<"\nIt's Probabale answer is "<<ch<<" or "<<char(ch+1);
            break;
        case 2:
            cout<<"\nIt's Probabale answer is "<<ch<<" or "<<char(ch-2);
            break;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void auidencepoll(char ch)
{
  
    audience_poll=0;
    int n;
    n=rand()%9+1;
    cout<<"The Auidence suggestions"<<endl;
    switch(ch)
    {
        case 'a':
            cout<<"A: "<<n*10<<" B: "<<(10-n)/6.0*10<<" C: "<<(10-n)/3.0*10<<" D: "<<(10-n)/2.0*10; break;  
        case 'b':
            cout<<"A: "<<(10-n)/6.0*10<<" B: "<<n*10<<" C: "<<(10-n)/2.0*10<<" D: "<<(10-n)/3.0*10; break;  

        case 'c':
            cout<<"A: "<<(10-n)/2.0*10<<" B: "<<(10-n)/6.0*10<<" C: "<<n*10<<" D: "<<(10-n)/3.0*10; break;  

        case 'd':
            cout<<"A: "<<(10-n)/2.0*10<<" B: "<<(10-n)/6.0*10<<" C: "<<(10-n)/3.0*10<<" D: "<<n*10; break;  

    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void expert(char ch)

{

    int opt;
    expert_advice=0;

    while(1)

    {
  
        cout<<"\n\nHi, You have chosen expert advice lifeline.\nChoose one expert:\n\n1.Mr.Nikhil Pathak(IIM Ahemedabad)\t2.Vighnesh Aiyer(Ph.D.MIT)\n3.Sankalp Yerawar(Harvard University)\t4.Dr.Rahul Bagad(Ph.D.Oxford University)\nOption: ";
  
        cin>>opt;
        if(opt>4||opt<1)
        {
            cout<<"\nPlease enter a valid option:\n";
            continue;
        }
        switch(opt)
        {
            case 1:  
                cout<<"\n\nHello,I am not sure but I think answer "<< ch<< " is correct.\n";  
                return;
      
            case 2:  
                cout<<"\n\nHi,this one is tricky I think answer "<< ch<< " is correct.\n";
                return;
      
            case 3:  
                cout<<"\n\nHello,I am  sure that answer "<< ch<< " is correct.\n";  
                return;
      
            case 4:  
                cout<<"\n\nHello,I am definitely sure that answer "<< ch<< " is correct.\n";
                return;
        }
      
    }


}
              
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function to Compute Lifeline
void lifeline(char ch)
{
    int ch1,opt;
    cout<<"\nApke pas "<<life<<" lifeline hai.\n";
    life-=1;

    for(int i=0;i<c.size();i++)
    {
        if(c[i]==0)
            cout<<"Fifty Fifty ";
        else
        {
            if(c[i]==1)
                cout<<"\t\tAuidence Poll ";
            else
            {
                if(c[i]==2)
                    cout<<"\t\tExpert Advice ";
                else
                    cout<<"\t\tPhone a Friend ";
            }
        }
    }

    	cout<<"\nAap konsa lifeline istemal karna chahenge ";       
	cin>>opt;
        switch(opt)
        {
            case 0:
                fiftyfifty(ch);
                c.erase(c.begin()+0);
                break;
            case 1:
                auidencepoll(ch);
                c.erase(c.begin()+1);
                break;
            case 2:
                expert(ch);
                c.erase(c.begin()+2);
                break;
            case 3:
                phonefriend();
                c.erase(c.begin()+3);
                break;
        }
  
  
}          

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void balance(int qno,int flg)
{
    long int money[]={1000,2000,5000,10000,20000,50000,100000,200000,5000000,1000000,2000000,3000000,5000000,7500000,10000000};
    if(flg==0)
    {
    	system("clear");
        cout<<"\n\nAfsos ke sath kehna pad raha hai ke apne galat jawab diya hai.\n";
        if(qno>12)
            cout<<"Amount Received: "<<money[12]<<"\n";
        else
        {
            if(qno>9)
                cout<<"Amount Received "<<money[9]<<"\n";
            else
            {
                if(qno>6)
                    cout<<"Amount Received "<<money[6]<<"\n";
                else
                    cout<<"Amount Received 0\n";
            }
        }
    }
    else
    {
        if(flg==-1)
        {
            	cout<<"You have QUIT and ";
            	cout<<"Aapko milte hai: "<<money[qno-1]<<"\n";
            	return ;
        }
        else
        {
        	system("clear");
        	cout<<"\nApaka jawab bilkul sahi hai.\nBadhai ho\n";
            	cout<<"Aapko milte hai: "<<money[qno]<<"\n";
            	cout<<"Agla Prashn Ye raha apke samne\n";
		usleep(5000000);
		
       }
    }
}
