#include<iostream>
#include<stdlib.h>
#define MAXSIZE 100

using namespace std;


/*User enters wrong password*/
class InvalidUser
{
public:
    string msg;
    InvalidUser(string str):msg(str){}
    string show()
    {
        return msg;
    }
};

class InvalidLogin
{
public:
    string msg;
    InvalidLogin(string str):msg(str){}
    string show()
    {
        return msg;
    }

};
/* User has less amount than ticket amt*/
class InvalidPayment
{
public:
    string msg;

    InvalidPayment(string str):msg(str){}
    string show()
    {
        return msg;
    }
};



class Seat
{
public:
  string seatNo;
  Seat(string s):seatNo(s){}
   void displayseat()
{
    cout<<"-----Display Seats-----"<<endl;
    cout<<seatNo<<endl;
}
/*For RunTimePolymorphism virtual function Used*/
virtual void bookSeat()
{
//do nothing
}

virtual void bookSeat(Seat** seats_all)
    {
        string temp;
        cout<<"Enter the seat No to be booked: \n"<<endl;
        cin>>temp;
        for(int i=0;i<4;i++)
        {
            if(temp == seats_all[i]->seatNo&& temp!= "XX"){
                cout<<"Seat Booked!"<<endl;
                seats_all[i]->seatNo = "XX";
                return;
            }
        }
    }
};
/*Inheriting from base class*/
class NormalSeat:public Seat
{
public:
    NormalSeat(string s):Seat(s){}
    void displayseat()
    {
        Seat::displayseat();
        cout<<"Normal Seat"<<endl;
        cout<<"seatNo"<<seatNo<<endl;;
    }

 void bookSeat(Seat** seats_all)
    {
        string temp;
        cout<<"Enter the seat No to be booked: \n"<<endl;
        cin>>temp;
        for(int i=0;i<4;i++)
        {
            if(temp == seats_all[i]->seatNo&& temp!= "XX"){
                cout<<"Seat Booked!"<<endl;
                seats_all[i]->seatNo = "XX";
                return;
            }
        }
    }


};
/*Inheriting from base class*/

class ExecutiveSeat:public Seat
{
public:
    ExecutiveSeat(string s):Seat(s){}
    void displayseat()

    {
        Seat::displayseat();
        cout<<"Executive Seat"<<endl;
        cout<<"seatNo"<<seatNo<<endl;

    }
    void bookSeat(Seat** seats_all)
    {


        string temp;
        cout<<"Enter the seat No to be booked: \n";
        cin>>temp;
        for(int i=0;i<4;i++)
        {
            if(temp == seats_all[i]->seatNo && temp!= "XX")
            {
                cout<<"Seat Booked!"<<endl;
                seats_all[i]->seatNo = "XX";
                return;
            }
        }
    }






};

/*Inheriting from base class*/
class PremiumSeat:public Seat
{
    public:
    PremiumSeat(string s):Seat(s){}
    void displayseat()
    {
        Seat::displayseat();
        cout<<"Premium Seat"<<endl;
        cout<<"seatNo"<<seatNo<<endl;
    }


    void bookSeat(Seat** seats_all)
    {


        string temp;
        cout<<"Enter the seat No to be booked: \n";
        cin>>temp;
        for(int i=0;i<4;i++)
        {
            if(temp == seats_all[i]->seatNo && temp!= "XX")
            {
                cout<<"Seat Booked!"<<endl;
                seats_all[i]->seatNo = "XX";
                return;
            }
        }
    }



};

class Theatre
{
public:
    long long int theatreId;
    string theatreName;
    string location;
    Seat *seats;
    Theatre(long long int  a,string b,string c)
    {
        theatreId=a;
        theatreName=b;
        location=c;
    }
    /*virtual function for runtime polymorphism*/
virtual void printtheatre()
    {
        cout<<"----------Theatre Details--------"<<endl;
        cout<<"theatreId:"<<theatreId<<endl;
         cout<<"TheatreName"<<theatreName<<endl;
        cout<<"location:"<<location<<endl;
    }


virtual void place()=0;

    //



};

/*Inheriting from baseclass*/
class SingleScreen:public Theatre
{
public:
    int ScreenNo;

    SingleScreen(long long int a,string b,string c,int e):Theatre(a,b,c)
    {
        ScreenNo=e;
    }
    void printtheatre()
    {
        Theatre::printtheatre();
        cout<<"screenNo:"<<ScreenNo<<endl;
    }

    void place()
    {
        cout<<"location"<<location<<endl;
    }
};
/*Inheriting from baseclass*/
class MultiScreen:public Theatre
{
public:
    int ScreenNo;

    MultiScreen(long long a,string b,string c,int f):Theatre(a,b,c)
    {
        ScreenNo=f;
    }

   void printtheatre()
    {
        Theatre::printtheatre();
        cout<<"screenNo:"<<ScreenNo<<endl;
    }

    void place()
    {
        cout<<"location"<<location<<endl;
    }


};


class Movies
{
public:
    int movieId;
    string movieName;
    float ticketAmt;
    Theatre *theatres;

    Movies(){}
    Movies(int r,string s,float amt)
    {
        movieId=r;
        movieName=s;
        ticketAmt=amt;
    }
    void display()
    {
        cout<<"movieid:"<<movieId<<endl;
        cout<<"movieName:"<<movieName<<endl;
        cout<<"ticketAMt:"<<ticketAmt<<endl;
    }
};


class User
{
public:
    string password;
    string userName;
    long long int mobileNo;
    float balAmt;
    bool payment_flag;
    User()
    {
        payment_flag=0;
    }

    User(string j,string m,long long int n,float p)
    {
        password=m;
        userName=j;
        mobileNo=n;
        balAmt=p;
    }

    void UserDetails(){
        cout<<"\n------------User Details------------\n";
        cout<<"UserName:"<<userName<<endl;
        cout<<"mobileNo:"<<mobileNo<<endl;
        cout<<"Balance amount :"<<balAmt<<endl;
    }
    void payAmt(float amt)
    {
        if(balAmt<300)
        {
            cout<<"AMT LESS THAN TICKET AMT"<<endl;
            cout<<"Cannot book Ticket"<<endl;
        }
        else{

        balAmt=balAmt-amt;
        cout<<"AMT:"<<amt<<endl;
        cout<<balAmt<<endl;
    }
    }
};


class Payment{
public:
    void payment(float &amt,float ticketAmt)
    {
        /* if ticketAmt greater than the balanceamt then throw error*/
        if(ticketAmt>amt)
        {
            throw InvalidPayment("Balance less than ticketAmt");
        }
        else
        {
            amt=amt-ticketAmt;
        }
    }
};



class BookMyShow
{
public:
    User **user;
    Movies **movies;
    int countUser;
    int countMovie;
    int signedInUser;
    BookMyShow();
    static BookMyShow * instance;
    int signIn()
    {
        int flag=0;
        string pass,uname;
        cout<<"Enter userName : Password\n";
        cin>>uname>>pass;
        for(int i=0;i<countUser;i++)
        {
            if(pass==user[i]->password && uname==user[i]->userName)
            {
                cout<<"Valid Password\n";
                signedInUser = i;
                return 1;
            }
        }
        if(flag==0)
            {
                /*If user has invalid password then throw error*/
            throw InvalidUser("Invalid Username or password, if new user please sign up\n");
        }
        return 0;
    }
    void signUp()
    {
        string j,n;
        float p;
        long long int ph;
        countUser++;

        cout<<"Enter the deatils of new user(Name,password,phone_number,balance)\n";
        cin>>n>>j>>ph>>p;
        user[countUser]=new User(n,j,ph,p);
        cout<<"New user created\n";
    }


    void bookMovies(Seat**s)
    {
        cout<<"\n -----Today's shows------ : \n";
        for(int i=0;i<countMovie;i++)
        {
            movies[i]->display();
        }
        string temp;
        cout<<"Enter the movie name to be booked: \n";
        cin>>temp;
        for(int i=0;i<countMovie;i++)
        {
            if(temp == movies[i]->movieName)
            {
                user[signedInUser]->payAmt(movies[i]->ticketAmt);
                s[i]->bookSeat(s);
                cout<<"Ticket Booked!"<<endl;
                return;
            }
        }
    }
    static BookMyShow* getInstance()
    {
        if(!instance)
            instance=new BookMyShow;
        return instance;
    }
    void printDetails(){
        cout<<"\n------------Welcome to BOOKMYSHOW------------\n";
    }

};
BookMyShow * BookMyShow::instance=0;


BookMyShow::BookMyShow(){
        signedInUser = -1;
        countMovie=0;
        countUser=0;
        //FILE *fp;
        //fp=fopen("movies.txt","r");
        for(int i=0;i<countMovie;i++)
        {
            movies[i]=new Movies();
            printf("Enter the details of the movie: ");
            scanf("%d%s%f",&movies[i]->movieId,movies[i]->movieName,&movies[i]->ticketAmt);
        }
        //close(fp);
}



int main()
{
try{


    int choice;
    int num;
    bool found;
    User *u1 = new User("Prajwal","ab123",8861184425,10000);
    User *u2 = new User("Siddaraj","mn2378",9945434072,5000);
    User *u3 = new User("Rohit","xy123",8792579502,7000);
    User *u4 = new User("Micheal","cd456",9900251866,2000);
    User *u5 = new User("Manvanth","fgg",8762250110,700000);

    User* users_all[]={u1,u2,u3,u4,u5};

    BookMyShow *b1=b1->getInstance();
    BookMyShow *b2=b2->getInstance();

    Theatre* theatre_all[]={new SingleScreen(233,"PVR","Hubli",4),
                        new MultiScreen(212,"Cinepolis","Dharwad",5),
                        new SingleScreen(489,"Apsara","Hubli",1),
                        new MultiScreen(100,"Sudha","Hubi",2)};

    Seat *seats_all[]=  {new NormalSeat("A1"),
                     new PremiumSeat("J4"),
                     new ExecutiveSeat("Y10"),
                     new PremiumSeat("A3"),
                     new NormalSeat("B3")};

    Movies*movies_all[] = {
        new Movies(1200,"KGF2",233),
        new Movies(1300,"Beast",210),
        new Movies(1301,"DoctorStrange",300),
        new Movies(1401,"MindHunter",120)
    };
    cout<<"Book My Show\n"<<endl;
    b1->countUser = 5;
    b1->countMovie = 4;
    b1->movies = movies_all;
    b1->user = users_all;
    b1->signIn();
    while(1){
        cout<<"------------ MENU ------------"<<endl;
        cout<<"1. Display Users"<<endl;
        cout<<"2. Display Movies"<<endl;
        cout<<"3. Book ticket"<<endl;
        cout<<"4.DISPLAY theatres"<<endl;
        cout<<"5.Display Seats"<<endl;


        cout<<"6. Exit"<<endl;
        cout<<"Enter the choice: "<<endl;
        cin>>choice;
        switch(choice){
        case 1:
               for(int i=0;i<b1->countUser;i++)
               {
                 b1->user[i]->UserDetails();
                 cout<<endl;
               }
            break;
        case 2:
                for(int i=0;i<b1->countMovie;i++)
               {
                 b1->movies[i]->display();
                 cout<<endl;
               }
            break;
        case 3:
            b2->bookMovies(seats_all);
            break;

        case 4:
            for(int i=0;i<4;i++)
            {
                theatre_all[i]->printtheatre();

            }
            break;

        case 5:
            for(int i=0;i<5;i++)
            {
                seats_all[i]->displayseat();
            }
            break;


            exit(0);
            break;
        }

    }
}

catch(InvalidUser &iu){
        cout<<iu.show()<<endl;
}

catch(InvalidPayment &ip)
{
    cout<<ip.show()<<endl;
}

catch(InvalidLogin &il)
{
    cout<<il.show()<<endl;

}

    return 0;
}
