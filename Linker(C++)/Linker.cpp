#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class USER // ACCOUNT CREATION CLASS
{
public:

    string city, gender,name;
    string persona;
    string mnumber;

    void input_data()
    {
        system("cls");
        cout << "NAME : ";
        fflush(stdin);
        getline(cin,name);
        fflush(stdin);
        cout << "GENDER (M/F)";
        cin >> gender;
        cout << "PLACE YOU RESIDE IN : ";
        fflush(stdin);
        getline(cin,city);
        cout << "MOBILE NUMBER : ";
        cin >> mnumber;
        cout << "BIO : ";
        fflush(stdin);
        getline(cin,persona);
    }
    void output()
    {
        cout << "NAME : " << name << endl;
        cout << "GENDER : " << gender << endl;
        cout << "CITY : " << city << endl;
        cout << "MOBILE NUMBER : " << mnumber << endl;
        cout << "BIO : "<<persona <<endl;

    }


    void output_x()
    {
        cout << "NAME : " << name_x << endl;
        cout << "GENDER : " << gender_x << endl;
        cout << "CITY : " << city_x << endl;
        cout << "BIO : "<<persona_x <<endl;

    }
    string name_x;
    string gender_x;
    string city_x;
    string mnumber_x;
    string persona_x;
    bool match_x;

    void pre_def_data(bool match ,string name, string gender, string city, string mnumber, string persona){
        name_x = name;
        gender_x = gender;
        city_x = city;
        mnumber_x = mnumber;
        persona_x = persona;
        match_x = match;
    }
};

class node
{
public:
    USER data;
    node *next;

    node(USER value)
    {
        data = value;
        next = NULL;
    }
};

node* head = NULL;

// LINKED LIST INSERTION ALGO

node *insert_tail(node *&head, USER value)
{

    node *n = new node(value);

    if (head == NULL)
    {

        head = n;
    }
    else{
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    }
    return head;
}

// DISPLAY ALGO

void display(node *head)
{

    node *temp = head;
    while (temp != NULL)
    {
        USER a;
        temp->data.output();
        cout<<endl;
        temp = temp->next;
    }
    //cout << "NULL" << endl;
}
stack<USER> s;
void showmatches();
void  match(USER a, USER b){

    if (b.match_x == 1)
    {
        cout<<"YIPPIE IT'S A MATCH  "<<endl;
        cout<<"HERE YOU GO !! RING YOUR MATCH: "<<b.mnumber_x<<endl;
    }
    else
    {
        cout<<"AWW NEVERMIND "<<endl;
        cout<<"YOU WILL FIND SOMEONE SOON "<<endl;
    }

}
void showmatches(USER a)
{
    while(!s.empty())
    {
            string cheese;
            s.top().output_x();
            cout<<"LIKED HIM/HER y/n"<<endl;
            cin>>cheese;
            if (cheese == "y")
            {
                match(a,s.top());
                cout<<endl;
            }
            else
            {
                system("cls");
            }
            cheese = "n";
            s.pop();
    }
}
//LINEAR SEARCH ALGO

void liner_search(node* head_ , USER a){
    string cheese ="n";
    int flag = 0;
    string key = a.city;
    while (head_ != NULL)
    {
        if(head_->data.city_x == key){
            s.push(head_->data);
            cout<<head_->data.name;
            flag++;
        }
        head_ = head_->next;
    }
    if (flag == 0)
    {
        cout<<"SORRY NO MATCH FOUND"<<endl;
    }
    else
    {
        showmatches(a);
    }
}

void remove_xyz(node* &head_)
{
    if (head_== NULL){
        // null
    }

    if (head_->next == NULL) {
        delete head_;
    }
    // Find the second last node
    node* second_last = head_;
    while (second_last->next->next != NULL)
        second_last = second_last->next;

    // Delete last node
    delete (second_last->next);

    // Change next of second last
    second_last->next = NULL;
    cout<<"Account Deleted";
}

// GREETING FUNCTION #2

void greeting()
{ // GREETING FUNCTION - - LET US KNOW ABOUT ACCOUNT SUCCESS
    char var_1;
    cout << "                  WELCOME TO THE LINKER FAMILY" << endl;
    cout << "            YOUR ACCOUNT HAS BEEN SUCCESSFULLY CREATED" << endl;
    cout << " " << endl;
    cout << "            ENTER F FOR HOME PAGE" << endl;
    cin >> var_1;
    if (var_1 == 'F' || var_1 == 'f')
    {
        system("cls");
    }
}
int main(){

    USER x1,x2,x3,x4,x5;
    USER a;

    int choice;
    char submit;


    // MINI DATABASE //
    x1.pre_def_data(0,"NARANG TIWARI","male","dehradun","9638481256","LOREM"); //1
    insert_tail(head,x1);
    x2.pre_def_data(1,"SONAM SHERAWAT","female","delhi","93646285835","LOREM"); //2
    insert_tail(head,x2);
    x3.pre_def_data(0,"DIVYA DUTTA","female","delhi","9653845297","LOREM"); //3
    insert_tail(head,x3);
    x4.pre_def_data(0,"OM YADAV","male","rampur","87341047664","LOREM"); //4
    insert_tail(head,x4);
    x5.pre_def_data(1,"MADHURI JHA","female","patna","9862463756","LOREM"); //5
    insert_tail(head,x5);
    // MINI DATABASE //
    cout << "            LINKER" << endl;
    cout << "     *******------*******" << endl;
    cout << " " << endl;
    cout << "          1. SIGN UP" << endl;
    cin >> choice;
    if (choice == 1){

        a.input_data();
        cout << "                    SUBMIT(Y/N)" << endl;
        cin >> submit;

        if (submit == 'Y' || submit == 'y'){
            system("cls");
            greeting();
        }
        else if (submit == 'N' || submit == 'n'){
            cout << "ACCOUNT NOT CREATED" << endl;
            cout << "SEE YOU NEXT TIME";
        }
    }
    else{
        cout << "WRONG INPUT";
    }

    //HOME PAGE
    string c = "y";
    while (c == "y")
    {
        int c1, c2;
        cout << "            HOME PAGE" << endl;
        cout << " "<< endl;
        cout << "          1. FIND FRIENDS" << endl;
        cout << "          2. SETTINGS" << endl;
        cout << " ";
        cout << "          ENTER YOUR CHOICE" << endl;
        cin >> c1;

        if (c1 == 1)
        {
            liner_search(head,a);
        }
        else if (c1 == 2)
        {
            system("cls");
            cout<<"1. VIEW PROFILE"<<endl;
            cout<<"2. UPDATE PROFILE"<<endl;
            cout<<"3. DELETE PROFILE"<<endl;
            cout<<"ENTER YOUR OPTION"<<endl;
            cin>>c2;

            if(c2 == 1)
            {
               a.output();

            }
            else if(c2 == 2)
            {
                a.input_data();

            }
            else if(c2 == 3)
            {
                remove_xyz(head);
                break;
            }
        }
        else{
        cout<<"WRONG INPUT"<<endl;
        }
    }
}
