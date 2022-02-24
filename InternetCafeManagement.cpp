#include<bits/stdc++.h>
#include<iostream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include "windows.h"
#include<time.h>

using namespace std;


//admin Username : admin
//admin password : cafe

void coord(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

class user_entry;
class pc_entry;
class stop_watch;
class new_entry
{
    public:
    //Constructor
    new_entry()
    {
        
    }
    //function Overloading
    void printoverloading(int x)
    {
        cout<<"\nUser is registered with User ID: "<<x<<endl;
    }
    //friend function
    friend void printoverloading(double x);
    void printoverloading(char* mail)
    {
        cout<<"\nNew Password sent to the Registered Email Address:- "<<mail<<endl;
    }
    
    //Deconstructor
    ~new_entry()
    {
        
    }
};

void printoverloading(double x)
{
    cout<<"Total Amount to be paid: INR "<<x<<"/-"<<endl;
}

class user_entry:public new_entry
{
    public:
    // char user_name[20],user_password[15],user_emailid[15],user_mobile[15],user_region[15],user_plan[15];
    // user_entry()
    // {
    // }
    int user_id;
    char *user_name,*user_password,*user_emailid,*user_mobile,*user_region,*user_plan;
    user_entry()
    {
        user_name=new char[25];
        user_password=new char[15];
        user_emailid=new char[15];
        user_mobile=new char[12];
        user_region=new char[15];
        user_plan=new char[15];
    }
    void user_add();
    void user_show();
    void user_remove();
    void user_update();
    void user_display(user_entry users[],int num_users);
    int user_search(int id);
    // int user_duplicate(char mail[20]);
    // friend class new_entry;
    // System Entry
    
};

class pc_entry:public new_entry
{
    public:
    int pc_ram,pc_cost;
    char *pc_name,*pc_processor,*pc_model,*pc_date,*pc_status;
    pc_entry()
    {
        pc_name=new char[25];
        pc_processor=new char[15];
        pc_model=new char[15];
        pc_date=new char[12];
        pc_status=new char[15];      
    }
    void pc_add();
    void pc_show();
    void pc_remove();
    void pc_update();
    void pc_display(pc_entry pcs[],int num_pcs);
    void pc_free(pc_entry pcs[],int num_pcs);
    int pc_search(char model[20]);
};

class stop_watch
{
    private:
    int hrs,mins;
    int secs;
    public:
    //Encapsulation
    //Parameterized Constructors
    stop_watch(int h=0,int m=0,int s=0)
    {
        hrs=h;
        mins=m;
        secs=s;
    }

    //conversion operator
    operator double()const{
        return double(secs)*2;
    }
    void clock();
};

// float round(float value)
// {
//     float val=(int)(value*100+.5);
//     return (float)value/100;
// }

void stop_watch::clock()
{
    system("CLS");
    cout<<"\n\t\t\t\t\t"<<" -----System Booked Successfully-----";
    cout<<"\n\t\t\t\t\t"<<" Hrs: Mins: Secs";
    cout<<"\n\t\t\t\t\t"<<hrs<<" : "<<mins<<" : "<<secs;
    cout<<"\n\t\t\t\t\t"<<"Press any key to start:";
    _getch();
    while(!_kbhit())
    {
    secs++;
    Sleep(1000);
    if(secs>59)
    {
    mins++;
    secs=0;
    }
    if(mins>59)
    { 
        hrs++;
        mins=0;
    }
    system("CLS");
    cout<<"\n\t\t\t\t\t"<<" -----Your time starts now!-----";
    cout<<"\n\t\t\t\t\t"<<" Hrs: Mins: Secs";
    cout<<"\n\t\t\t\t\t"<<hrs<<" : "<<mins<<" : "<<secs;
    cout<<"\n\t\t\t\t\t"<<" Press any key to stop:";
    }
    _getch();
    cout<<"\n\t\t\t\t\t"<<" Total Time taken: ";
    cout<<"\n\t\t\t\t\t"<<hrs<<" : "<<mins<<" : "<<secs<<endl;
    cout<<"\n"<<"Press Enter to see the Charges: "<<endl;
    _getch();
    stop_watch s(hrs,mins,secs);
    double x=s;
    printoverloading(x);
    hrs=0;
    mins=0;
    secs=0;
}

void user_entry::user_show()
{
    if(user_id)
    {
    cout<<setw(20)<<"User_id     : "<<user_id<<endl;
    cout<<setw(20)<<"User_name   : "<<user_name<<endl;
    cout<<setw(20)<<"User_email  : "<<user_emailid<<endl;
    cout<<setw(20)<<"User_Mobile : "<<user_mobile<<endl;
    cout<<setw(20)<<"User_region : "<<user_region<<endl;
    cout<<setw(20)<<"User_Plan   : "<<user_plan<<endl;
    }
    else
    {
        cout<<"\nUser not Found"<<endl;
    }
}

void user_entry::user_remove()
{
    user_id = 0;
    // user_name =" ";
    // user_password =" ";
    // user_emailid =" ";
    // user_mobile =" ";
    // user_region =" ";
    // user_plan =" ";
    delete user_name;
    delete user_password;
    delete user_emailid;
    delete user_mobile;
    delete user_region;
    delete user_plan;
}



int user_entry::user_search(int id)
{
    if(id==user_id)
    return 1;
    else
    return 0;
}


void user_entry::user_update()
{
    cout<<"Choose the field you want to Update: "<<endl;
    int uc;
    cout<<"1.user_name"<<endl;
    cout<<"2.user_emailid"<<endl;
    cout<<"3.user_mobile"<<endl;
    cout<<"4.user_region"<<endl;
    cout<<"5.user_plan"<<endl;
    cout<<"6.Go Back..."<<endl;
    cin>>uc;
    switch(uc)
    {
        case 1: cout<<"Please enter the Name          : ";
                cin.ignore();
                cin.getline(user_name,20);
                break;
        case 2: cout<<"Please enter the Emailid       : ";
                cin>>user_emailid;
                break;
        case 3: cout<<"Please enter the Mobile Number : ";
                cin>>user_mobile;
                break;
        case 4: cout<<"Region (Local/Non-Local)       : ";
                cin>>user_region;
                break;
        case 5: cout<<"Please enter the plan type     : ";
                cin>>user_plan;
                break;
        case 6: break;
    }
}

void user_entry::user_add()
{
    cout<<"Please enter the Email-id again    : ";
    cin>>user_emailid;
	cout<<"Please enter the Name              : ";
    cin.ignore();
    cin.getline(user_name,20);
    cout<<"Please create the Password         : ";
    cin>>user_password;
    cout<<"Please enter the Mobile Number     : ";
    cin>>user_mobile;
    cout<<"Region (Local/Non-Local)           : ";
    cin>>user_region;
    cout<<"Please enter the plan Type         : ";
    cin>>user_plan;
}

void user_entry::user_display(user_entry users[],int num_users)
{
    int flag=1;
    cout    
            <<setw(20)
            << "Serial No"
            <<setw(20)
            << "User Id"
            <<setw(20)
            << "User Name"
            <<setw(20)
            << "User Email"
            <<setw(20)
            << "User Mobile"
            <<setw(20)
            << "User Region"
            <<setw(20)
            << "User Plan"<<endl;
    for(int j=0;j<num_users;j++)
    {
        if(users[j].user_id)
        {       
            flag=0;          
            cout 
                 <<setw(20)
                 <<j+1
                 <<setw(20)
                 <<users[j].user_id
                 <<setw(20)
                 <<users[j].user_name
                 <<setw(20)
                 <<users[j].user_emailid
                 <<setw(20)
                 <<users[j].user_mobile
                 <<setw(20)
                 <<users[j].user_region
                 <<setw(20)
                 <<users[j].user_plan<<endl;
        }
    }
    if(flag)
    {
        cout<<"No users found"<<endl;
    }
}


void pc_entry::pc_update()
{
    cout<<"Choose the field you want to Update: "<<endl;
    int uc;
    cout<<"1.System name"<<endl;
    cout<<"2.System processor"<<endl;
    cout<<"3.System ram"<<endl;
    cout<<"4.System Status"<<endl;
    cout<<"5.Go Back..."<<endl;
    cin>>uc;
    switch(uc)
    {
        case 1: cout<<"Please enter the updated Name             : ";
                cin.ignore();
                cin.getline(pc_name,20);
                break;
        case 2: cout<<"Please enter the updated System Processor : ";
                cin>>pc_processor;
                break;
        case 3: cout<<"Please enter the updated System ram       : ";
                cin>>pc_ram;
                break;
        case 4: cout<<"Please enter the updated System status    : ";
                cin>>pc_status;
                break;
        case 5: break;
    }
}

//pc_classes
void pc_entry::pc_add()
{
    cout<<"Please enter the Name: ";
    cin.ignore();
    cin.getline(pc_name,20);
    cout<<"Please enter the Model Number         : ";
    cin>>pc_model;
    cout<<"Please enter the Processor type       : ";
    cin>>pc_processor;
    cout<<"Please enter the available Ram        : ";
    cin>>pc_ram;
    cout<<"Please enter the price of the computer: ";
    cin>>pc_cost;
    cout<<"Please enter the date of purchase     : ";
    cin>>pc_date;
    cout<<"Please enter the PC Status(A/NA)      : ";
    cin>>pc_status;
}

void pc_entry::pc_remove()
{
    pc_ram=0;
    pc_cost=0;
    delete pc_name;
    delete pc_model;
    delete pc_processor;
    delete pc_date;
    delete pc_status;
}


void pc_entry::pc_display(pc_entry sys[],int num_sys)
{
    int flag=1;
    cout    
            <<setw(20)
            << "pc_name"
            <<setw(20)
            << "pc_model"
            <<setw(20)
            << "pc_processor"
            <<setw(20)
            << "pc_ram"
            <<setw(20)
            << "pc_cost"
            <<setw(20)
            << "pc_date"
            <<setw(20)
            << "pc_status"<<endl;
    for(int j=0;j<num_sys;j++)
    {
        if(sys[j].pc_ram)
        {            
            flag=0;     
            cout 
                 <<setw(20)
                 <<sys[j].pc_name
                 <<setw(20)
                 <<sys[j].pc_model
                 <<setw(20)
                 <<sys[j].pc_processor
                 <<setw(20)
                 <<sys[j].pc_ram
                 <<setw(20)
                 <<sys[j].pc_cost
                 <<setw(20)
                 <<sys[j].pc_date
                 <<setw(20)
                 <<sys[j].pc_status<<endl;
        }
    }
    if(flag)
    {
    cout<<"\n"<<setw(540)<<"------No Systems Available------"<<endl;
    }
}

void pc_entry::pc_free(pc_entry sys[],int num_sys)
{
    int flag=0;
    cout    
            <<setw(20)
            << "pc_name"
            <<setw(20)
            << "pc_model"
            <<setw(20)
            << "pc_processor"
            <<setw(20)
            << "pc_ram"
            <<setw(20)
            << "pc_status"<<endl;
    for(int j=0;j<num_sys;j++)
    {
        if(sys[j].pc_ram)
        {
        if(strcmp(sys[j].pc_status,"A")==0 || strcmp(sys[j].pc_status,"a")==0)
        {                 
            cout 
                 <<setw(20)
                 <<sys[j].pc_name
                 <<setw(20)
                 <<sys[j].pc_model
                 <<setw(20) 
                 <<sys[j].pc_processor
                 <<setw(20)
                 <<sys[j].pc_ram
                 <<setw(20)
                 <<sys[j].pc_status<<endl;
            flag=1;
        }
        }
    }
    if(!flag)
    {
        cout<<"All Systems are Booked !..."<<endl;
    }
}


void pc_entry::pc_show()
{
    if(pc_ram)
    {
    cout<<setw(20)<<"pc_name      : "<<setw(20)<<pc_name<<endl;
    cout<<setw(20)<<"pc_model     : "<<setw(20)<<pc_model<<endl;
    cout<<setw(20)<<"pc_processor : "<<setw(20)<<pc_processor<<endl;
    cout<<setw(20)<<"pc_ram       : "<<setw(20)<<pc_ram<<endl;
    cout<<setw(20)<<"pc_cost      : "<<setw(20)<<pc_cost<<endl;
    cout<<setw(20)<<"pc_date      : "<<setw(20)<<pc_date<<endl;
    cout<<setw(20)<<"pc_status    : "<<setw(20)<<pc_status<<endl;
    }
    else
    {
        cout<<"\nSystem not Found"<<endl;
    }
}

int pc_entry::pc_search(char model[20])
{
    if(strcmp(model,pc_model)==0)
    return 1;
    else
    return 0;
}


int main()
{
	system("cls");
	 coord(81,3);
    cout<<"____________________________________________________"<<endl;
     coord(80,4);
    cout<<"|                                                    |"<<endl;
     coord(80,5);
    cout<<"|   Welcome to the Internet Cafe Management System   |"<<endl;
     coord(80,6);
    cout<<"|____________________________________________________|"<<endl;
    int find=0,num_users=0,i=0,duplicate=1,flag=0,id,find_slot=0,num_sys=0,z=0,y=0,user_index=0;
    char pass[20];
    char currentpass[20];
    char newpass[20];
    int sign_flag=0;
    char name[25];
    char email[20];
    char model[20];
    // new_entry main;
    stop_watch timing;
    user_entry users[30];
    pc_entry sys[25];
    int choice1,choice2=1,choice3=1,choice4=1,choice5=1,choice6=1;
    srand(time(0));
    while(1)
    {
        // coord(31,10);
        cout <<"\n"<< setw(540);    //1920x1080 -- 1080/2 = 540
		cout<<"--------MAIN MENU--------"<<endl;
        // coord(20,11);
        cout<<"\n\t1.Admin Login"<<endl;
        // coord(20,12);
        cout<<"\t2.Customer Login"<<endl;
        // coord(20,13);
        cout<<"\t3.Cafe Management"<<endl;
        // coord(20,14);
        cout<<"\t4.Exit"<<endl;
        // coord(20,15);
        cout<<"\tPlease select your option:\n\n>>";
        cin>>choice1;
        switch(choice1)
        {
            case 1: cout <<"\n"<< setw(546)<<"-------ADMIN ACCESS INTERFACE-------"<<endl;
                    char adminusername[20],adminpass[20];
                    cout<<"\nAdmin Username : ";
                    cin>>adminusername;
                        if(strcmp(adminusername,"admin")==0)
                        {
                            cout<<"Admin Password : ";
                            cin>>adminpass;
                            if(strcmp(adminpass,"cafe")==0)
                            {
                                sign_flag=1;
                            }
                            else
                            {
                                cout<<"Password is incorrect!!"<<endl;
                                // z=1;
                            }
                        }
                    else
                            {
                                cout<<"Username is incorrect!!"<<endl;
                                // z=1;/
                            }
                    if(sign_flag){
                    while(choice2!=3)
                    {
                        cout<<"\n"<<setw(540)<<"------ADMIN PANEL------"<<endl;
                        cout<<"\n\t1.User Records"<<endl;
                        cout<<"\t2.System Records"<<endl;
                        cout<<"\t3.Go Back"<<endl;
                        cout<<"\tPlease select your option:\n\n>>";
                        cin>>choice2;
                        switch(choice2)
                        {
                            case 1: while(choice3!=6)
                                    {
                                    cout<<"\n"<<setw(540);  
                                    cout<<"-----USER RECORDS-----"<<endl;
                                    cout<<"\n\t1.Add New User"<<endl;
                                    cout<<"\t2.Show Users Data"<<endl;
                                    cout<<"\t3.Update User Data"<<endl;
                                    cout<<"\t4.Delete User Data"<<endl;
                                    cout<<"\t5.Search User Data"<<endl;
                                    cout<<"\t6.Go Back"<<endl;
                                    cout<<"\tPlease select your option:\n\n>>";
                                    cin>>choice3;
                                    switch(choice3)
                                    {
                                        case 1: cout<<"\n"<<setw(540)<<"-----Adding New User-----"<<endl;
                                                cout<<"\nPlease enter the user's email-id: ";
                                                cin>>email;
                                                for(int i=0;i<num_users;i++)
                                                {
                                                    if(strcmp(users[i].user_emailid,email)==0)
                                                    {
                                                        cout<<"User Email Already Registered... "<<endl;
                                                        duplicate=0;
                                                        break;
                                                    }
                                                }
                                                if(duplicate)
                                                {
                                                    //empty space
                                                for(i=0;i<num_users;i++)
                                                {
                                                    if(!users[i].user_id)
                                                    {
                                                        users[i].user_id=rand()%(100-1)+1;
                                                        users[i].user_add();
                                                        find=1;
                                                        users[0].printoverloading(users[i].user_id);
                                                        // cout<<"\nUser is registered with User ID: "<<users[i].user_id<<endl;
                                                    }
                                                }

                                                if(find==0)
                                                {
                                                    users[num_users].user_id=rand()%(100-1)+1;
                                                    users[num_users].user_add();
                                                    users[0].printoverloading(users[i].user_id);
                                                    // cout<<"\nUser is registered with User ID: "<<users[num_users].user_id<<endl;
                                                    num_users++;
                                                }
                                                }
                                                find=0;
                                                duplicate=1;
                                                break;
                                        case 2: cout<<"\n"<<setw(540);
                                                if(num_users){
												cout<<"-----Show Users-----"<<endl;
                                                users[0].user_display(users,num_users);
                                                }
                                                else
                                                {
                                                  cout<<"-----No Users Registered yet-----"<<endl;  
                                                }
                                                break;
                                        case 3: cout<<setw(540);
												cout<<"-----Update User Data-----"<<endl;
                                                cout<<"Please enter the user ID: ";
                                                cin>>id;
                                                for(int i=0;i<num_users;i++)
                                                {
                                                    if(users[i].user_search(id))
                                                    {
                                                        users[i].user_update();
                                                        flag=1;
                                                        cout<<"User's Data has been updated successfully!"<<endl;
                                                    }
                                                }
                                                if(!flag){
                                                cout<<"Account not found!"<<endl;
                                                }
                                                flag=0;
                                                break;
                                        case 4: cout<<"\n"<<setw(540)<<"-----Delete User-----"<<endl;
                                                cout<<"Please enter user ID: ";
                                                cin>>id;
                                                for(int i=0;i<num_users;i++)
                                                {
                                                    if(users[i].user_search(id))
                                                    {
                                                        users[i].user_remove();
                                                        cout<<"Account Deleted Successfully!"<<endl;
                                                        flag=1;
                                                    }
                                                }
                                                if(!flag)
                                                {
                                                cout<<"Account not found!"<<endl;
                                                }
                                                flag=0;
                                                break;
                                        case 5: cout<<"\n"<<setw(540)<<"-----Search User-----"<<endl;
                                                cout<<"Please enter user ID: ";
                                                cin>>id;
                                                for(int i=0;i<num_users;i++)
                                                {
                                                    if(users[i].user_search(id))
                                                    {
                                                        users[i].user_show();
                                                        flag=1;
                                                    }
                                                }
                                                if(!flag){
                                                cout<<"Account not found!"<<endl;
                                                }
                                                flag=0;
                                                break;
                                        case 6: cout<<"Returning to Admin Panel..."<<endl;
                                                break;
                                        default: cout<<"Please enter the right choice"<<endl;
                                    }
                                    }
                                    choice3=1;
                                    break;
                            case 2: 
                                    while(choice5!=6)
                                    {
                                    cout<<"\n"<<setw(540)<<"-------SYSTEM RECORDS-------"<<endl;
                                    cout<<"\n\t1.Add New Systems"<<endl;
                                    cout<<"\t2.Show All Systems"<<endl;
                                    cout<<"\t3.Update System Configurations"<<endl;
                                    cout<<"\t4.Remove System"<<endl;
                                    cout<<"\t5.Search System"<<endl;
                                    cout<<"\t6.Go Back"<<endl;
                                    cout<<"\tPlease select your option:\n\n>>";
                                    cin>>choice5;
                                    switch(choice5)
                                    {
                                        case 1: cout<<"\n\t\t\t\t\t\t\t\t\t\t-----Adding New System-----"<<endl;
                                                for(i=0;i<num_sys;i++)
                                                {
                                                    if(!sys[i].pc_model)
                                                    {
                                                        sys[i].pc_add();
                                                        find_slot=1;
                                                    }
                                                }

                                                if(find_slot==0)
                                                {
                                                    sys[num_sys].pc_add();
                                                    num_sys++;
                                                }
                                                find_slot=0;
                                                break;
                                        case 2: if(num_sys){
                                                cout<<"\n"<<setw(540)<<"------Available Systems------"<<endl;
                                                sys[0].pc_display(sys,num_sys);}
                                                break;
                                        case 3: cout<<"\n\t\t\t\t\t\t\t\t\t\t------Update Configurations------"<<endl;
                                                cout<<"Please enter System Model: "<<endl;
                                                cin>>model;
                                                for(int i=0;i<num_sys;i++)
                                                {
                                                    if(sys[i].pc_search(model))
                                                    {
                                                        sys[i].pc_update();
                                                        flag=1;
                                                    }
                                                }
                                                if(!flag)
                                                {
                                                    cout<<"System not found"<<endl;
                                                }
                                                flag=0;
                                                break;
                                        case 4: cout<<"\n\t\t\t\t\t\t\t\t\t\t------Remove System Record------"<<endl;
                                                cout<<"Please enter System Model: "<<endl;
                                                cin>>model;
                                                for(int i=0;i<num_sys;i++)
                                                {
                                                    if(sys[i].pc_search(model))
                                                    {
                                                        sys[i].pc_remove();
                                                        flag=1;
                                                    }
                                                }
                                                if(!flag)
                                                {
                                                    cout<<"System not found"<<endl;
                                                }
                                                flag=0;
                                                break;
                                        case 5: cout<<"\n\t\t\t\t\t\t\t\t\t\t------Search System------"<<endl;
                                                cout<<"Please enter System Model: "<<endl;
                                                cin>>model;
                                                for(int i=0;i<num_sys;i++)
                                                {
                                                    if(sys[i].pc_search(model))
                                                    {
                                                        sys[i].pc_show();
                                                        flag=1;
                                                    }
                                                }
                                                if(!flag)
                                                {
                                                    cout<<"System not found"<<endl;
                                                }
                                                flag=0;
                                                break;
                                        case 6: cout<<"Returning to Back Screen...."<<endl;
                                                break;
                                        default: cout<<"Please enter a valid choice"<<endl;
                                    }
                                    }
                                    choice5=1;
                                    break;
                            case 3: cout<<"Returning to Main Menu..."<<endl;
                                    break;
                            default: cout<<"Please enter a valid choice"<<endl;
                        }   
                    }
                    choice2=1;
                    sign_flag=0;
                    }
                    // else
                    // {
                    //     if(z){
                    //     cout<<"Please Check Your Admin Username!..."<<endl;
                    //     z=0;
                    //     }
                    // }
                    break;
            case 2: 
                    while(choice4!=4)
                    {
                        cout<<"\n"<<setw(540)<<"-------CUSTOMER LOGIN-------"<<endl;
                        cout<<"\n\t1.Sign In"<<endl;
                        cout<<"\t2.Forgot Password"<<endl;
                        cout<<"\t3.Create Account"<<endl;
                        cout<<"\t4.Go Back"<<endl;
                        cout<<"\tPlease select your option:\n\n>>";
                        cin>>choice4;
                        switch(choice4)
                        {
                            case 1: cout<<"\n"<<setw(540)<<"------SIGN IN------"<<endl;
                                    cout<<"UserID : ";
                                    cin>>id;
                                    for(int i=0;i<num_users;i++)
                                    {
                                        if(users[i].user_search(id))
                                        {
                                            cout<<"Password: ";
                                            cin>>pass;
                                            if(strcmp(users[i].user_password,pass)==0)
                                            {
                                                sign_flag=1;
                                                user_index=i;
                                            }
                                            else
                                            {
                                                cout<<"Incorrect Password !..."<<endl;
                                                // z=1;
                                            }
                                        }
                                        else{
                                            cout<<"User ID not Found !..."<<endl;
                                        }
                                    }
                                    if(sign_flag){
                                    cout<<"\n"<<setw(540)<<"------Thanks for Signing In------"<<endl;
                                    while(choice6!=4)
                                    {
                                        cout<<"\n\t1.System Booking"<<endl;
                                        cout<<"\t2.To see Available Systems"<<endl;
                                        cout<<"\t3.Change Password"<<endl;
                                        cout<<"\t4.Log Out"<<endl;
                                        cout<<"\tPlease select your option:\n\n>>";
                                        cin>>choice6;
                                        switch(choice6)
                                        {
                                            case 1: cout<<"\n"<<setw(540)<<"------System Booking------"<<endl;
                                                    cout<<"Enter the System Model you want to book: "<<endl;
                                                    cin>>model;
                                                    for(int i=0;i<num_sys;i++)
                                                    {
                                                        if(sys[i].pc_search(model))
                                                        {
                                                            if(strcmp(sys[i].pc_status,"A")==0){
                                                            strcpy(sys[i].pc_status,"NA");
                                                            flag=1;
                                                            cout<<"System Booked Successfully!"<<endl;
                                                            timing.clock();
                                                            }
                                                            else
                                                            {
                                                                cout<<"Systems are already Booked !..."<<endl;
                                                            }
                                                        }
                                                    }
                                                    if(!flag)
                                                    {
                                                        cout<<"System not found!"<<endl;
                                                    }
                                                    flag=0;
                                                    break;
                                            case 2: if(num_sys){
                                                    cout<<"\n"<<setw(540)<<"------Currently Available Systems------"<<endl;
                                                    sys[0].pc_free(sys,num_sys);
                                                    }
                                                    else
                                                    {
                                                    cout<<"\n"<<setw(540)<<"------Systems Unavailable------"<<endl;
                                                    }
                                                    break;
                                            case 3: cout<<"\n"<<setw(540)<<"------Password Change------"<<endl;
                                                    cout<<"Please enter current Password: ";
                                                    cin>>currentpass;
                                                    if(strcmp(currentpass,users[user_index].user_password)==0)
                                                    {
                                                        cout<<"Enter the new password: ";
                                                        cin>>newpass;
                                                        strcpy(users[user_index].user_password,newpass);
                                                        cout<<"Password Successfully changed!"<<endl;
                                                    }
                                                    else{
                                                        cout<<"Incorrect Password!"<<endl;
                                                    }
                                                    break;
                                            case 4: cout<<"\n"<<setw(540)<<"------Logging out...---"<<endl;
                                                    break;
                                            default: cout<<"Please enter a valid choice"<<endl;
                                        }
                                    }
                                    choice6=1;
                                    sign_flag=0;
                                    }
                                    // else
                                    // {
                                    //     if(!z){
                                    //     cout<<"Please Check Your User ID!"<<endl;
                                    //     z=0;
                                    //     }
                                    // }
                                    break;

                            case 2: cout<<"\n"<<setw(540)<<"------FORGET PASSWORD------"<<endl;
                                    cout<<"forget"<<endl;
                                    cout<<"UserID : ";
                                    cin>>id;
                                    for(int i=0;i<num_users;i++)
                                    {
                                        if(users[i].user_search(id))
                                        {
                                            users[0].printoverloading(users[i].user_emailid);
                                            // cout<<"New Password sent to the Registered Email Address:- "<<users[i].user_emailid<<endl;
                                            y=1;
                                        }
                                    }
                                    if(!y)
                                    {
                                        cout<<"Invalid User Id!..."<<endl;
                                        y=0;
                                    }
                                    break;
                            case 3: cout<<"\n"<<setw(540)<<"------CREATE ACCOUNT------"<<endl;
                                    cout<<"Please enter the User email-id: ";
                                    cin>>email;
                                    for(int i=0;i<num_users;i++)
                                    {
                                        if(strcmp(users[i].user_emailid,email)==0)
                                        {
                                            cout<<"User Email is already Registered.."<<endl;
                                            duplicate=0;
                                            break;
                                        }
                                    }
                                    if(duplicate)
                                    {
                                    for(i=0;i<num_users;i++)
                                    {
                                        if(!users[i].user_id)
                                        {
                                            users[i].user_id=rand()%(100-1)+1;
                                            users[i].user_add();
                                            find=1;
                                            users[0].printoverloading(users[i].user_id);
                                            // cout<<"User Registered with User ID: "<<users[i].user_id<<endl;
                                            cout<<"Thanks for creating the Account..."<<endl;
                                        }
                                    }

                                    if(find==0)
                                    {
                                        users[num_users].user_id=rand()%(100-1)+1;
                                        users[num_users].user_add();
                                        users[0].printoverloading(users[i].user_id);
                                        // cout<<"User Registered with User ID: "<<users[num_users].user_id<<endl;
                                        cout<<"Thanks for creating the Account..."<<endl;
                                        num_users++;
                                    }
                                    }
                                    find=0;
                                    duplicate=1;
                                    break;
                            case 4: cout<<"Returning to Main Menu..."<<endl;
                                    break;
                            default: cout<<"Please enter a valid choice"<<endl;
                        }
                    }
                    choice4=1;
                    break;
            case 3: 
                    while(choice5!=3)
                    {
                    cout<<setw(540)<<"-------CAFE DETAILS-------"<<endl;
                    cout<<"\n\t1.Subscription Plans"<<endl;
                    cout<<"\t2.Update User Plan"<<endl;
                    cout<<"\t3.Go Back"<<endl;
                    cout<<"\tPlease kindly select your option:\n\n>>";
                    cin>>choice5;
                    switch(choice5)
                    {
                        case 1: cout<<"\n"<<setw(540)<<"------Subscription Details------"<<endl;
                                cout<<"Charges for 5 seconds is 10 INR"<<endl;
                                cout<<"Plans:\n";
                                cout<<"1)For 1 month(M)      - 350  INR \n";
                                cout<<"2)For 3 months(3M)    - 700  INR \n";
                                cout<<"3)For 1 year(Y)       - 1200 INR \n";
                                break;
                        case 2: cout<<"\n"<<setw(540)<<"------Update User Plan------"<<endl;
                                cout<<"\nPlease enter the user's email-id: ";
                                cin>>email;
                                for(int i=0;i<num_users;i++)
                                {
                                    if(strcmp(users[i].user_emailid,email)==0)
                                    {
                                        duplicate=0;
                                        break;
                                    }
                                }
                                if(duplicate)
                                {
                                    cout<<"Email not found"<<endl;
                                }
                                else
                                {
                                    int x;
                                    cout<<"Plans:\n";
                                    cout<<"1)For 1 month(M)     - 350  INR \n";
                                    cout<<"2)For 3 months(3M)   - 700  INR \n";
                                    cout<<"3)For 1 year(Y)      - 1200 INR \n";
                                    cout<<"Enter plan number:  "<<endl;
                                    cin>>x;
                                    if(x==1)
                                    {
                                        cout<<"Digital Payment will be done for 300 INR"<<endl;
                                        strcpy(users[i].user_plan,"M");
                                    }
                                    else if(x==2)
                                    {
                                        cout<<"Digital Payment will be done for 700 INR"<<endl;
                                        strcpy(users[i].user_plan,"3M");
                                    }
                                    else
                                    {
                                        cout<<"Digital Payment will be done for 1200 INR"<<endl;
                                        strcpy(users[i].user_plan,"Y");
                                    }
                                }
                                duplicate=1;
                                break;
                        case 3: cout<<"Returning to Main Menu..."<<endl;
                                break;
                        default: cout<<"Please enter a valid choice"<<endl;
                    }
                    }
                    choice5=1;
                    break;
            case 4: cout<<"\n"<<setw(540)<<"-------Thanks for Visiting!-------"<<endl;
                    exit(0);
                    break;
            default: cout<<"Please enter a valid choice"<<endl;
        }
    }
    return 0;
}
