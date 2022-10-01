//
// Created by henry on 2022-09-28.
//
// Mobile Payment Projects(for NCC Assignment)

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
#define Q 100

class Bill{ //Bill class for control
public:
    int Current_ID;
    int Current_UserAmount;
    int locate=0;
    string M_username[Q];
    string M_password[Q];
    int M_amount[Q];

    int Main_Menu();
    int Admin_Login();
    int Register();
    int Show_AllInfo();
    int Login();
    int Login_AfterMenu();
    int Check_Balance(int balance);
    int Mobile_Topup();
    int CashIn(int CashinMoney);
    int Widthdraw(int WidthdrawMoney);
    int Transfer(int SenderID,int ReceiverID, int TransferAmount);
    int CheckReceiver(string inputName);
};


//Main Menu Functon
int Bill::Main_Menu() {
    int menu_option;

    while (true){
        cout <<endl<<"[100]Admin Login\n[1]Register\n[2]Log in\n[3]Leave From Program\n\nEnter your choice: ";
        cin >> menu_option;

        if(menu_option==1){ //start Register option
            Register();

        }else if(menu_option==2){ //start Login option

            Login();

        }else if(menu_option==3){
            cout<< "Thanks a million\n Bye Bye"<<endl;
            exit(1);

        }else if(menu_option==100){
            Current_UserAmount=M_amount[locate];
            Admin_Login();
        }else{
                cout <<endl<< "Try Again Please"<<endl;
                continue;
        }
    }//while loop end here
}


//Admin Login
int Bill::Admin_Login() {
    string Adminpass="admin221";
    string InputAdminPass;
    cout << "\t\t\tADMIN LOGIN\n\n";
    cout << "Enter Admin Password: ";
    cin >> InputAdminPass;
    if(InputAdminPass==Adminpass){
        cout <<endl<< "\t\t\tYou are Admin\t\t"<<endl<<endl;
        Show_AllInfo();
    }else{
        cout <<endl<< "Sorry! Your wrong"<<endl;
        Main_Menu();
    }
}


//Register Function Start
int Bill::Register() {
    string R_username;
    string R_password;
    string R_comfrimpassword;
    int R_money;
    cout <<endl<< "\nThis is from registration" << endl;
    cout << "Enter your username: ";
    cin >> R_username;
    cout << "Enter your password: ";
    cin >> R_password;
    cout << "Enter your password again: ";
    cin >> R_comfrimpassword;
    cout << "Enter Your Open Money: ";
    cin >> R_money;
    if (R_password==R_comfrimpassword){
        M_username[locate]=R_username;
        M_password[locate]=R_password;
        M_amount[locate]=R_money;
        cout <<endl<<"Registration Success!!"<<endl;
        locate++;
    }else{
        cout<<endl<< "sorry wrong password\nboth password must be same"<<endl;
        Main_Menu();
    }
}


// Show All Information Function Start
int Bill::Show_AllInfo() {
    cout<<"Username\t\t Password\t\t Amount"<<endl;
    for(int i=0; i<locate; i++){
        Current_UserAmount=M_amount[Current_ID];
        cout<<i+1<<"."<<M_username[i]<<"\t\t  "<<M_password[i]<<"\t\t  "<<M_amount[i]<<endl;
    }
}


//Log in Functon start here
int Bill::Login() {
    int count=0;
    int trueorFalse=0;
    string L_username;
    string L_password;
    cout << "Log In Here" << endl;
    cout << "Enter Your Name: ";
    cin >> L_username;
    cout << "Enter Password: ";
    cin >> L_password;
    for (int i = 0; i <= locate; i++) {
        if(L_username==M_username[i] && L_password == M_password[i]){
            cout <<endl<<"found"<<endl;
            Current_ID=i;
            Current_UserAmount=M_amount[i];
            Login_AfterMenu();
        }else{
            trueorFalse = 10;
        }
    } //User name FOR loop
    if(trueorFalse==10){
        cout<<endl<<"No user found"<<endl;
        cout<<"[1]Exit\n[2]Login Again\n>>";
        cin >> count;
        if(count==1){
            cout <<endl<< "Bye Bye"<<endl;
            Main_Menu();
        }else if(count==2){
            cout <<endl<< "Login Again"<<endl;
            Login();
        }
    }
} // Login main curly bracket end here



//Login After Menu Function Start Here
int Bill::Login_AfterMenu() {
    int loginAfterrMenu_option;
    cout <<endl<<"[1]Check Balance\n[2]Mobile Top up\n[3]Cash in\n[4]Widthdraw\n[5]Transfer\n[6]Exit"<<endl;
    cout << "\nEnter your number: ";
    cin >> loginAfterrMenu_option;

    if(loginAfterrMenu_option==1){ // Check Balance option start here
        //this is chech balance option
        Check_Balance(M_amount[Current_ID]);
        Login_AfterMenu();

    }else if(loginAfterrMenu_option==2){  // Mobile Topup option start here
        //this is Mobile Top up option
        Mobile_Topup();
        Login_AfterMenu();

    }else if(loginAfterrMenu_option==3){ // Cash in option start here
        //this is cash in option
        int InputCashin;
        cout << "enter the Cash in amount: ";
        cin >> InputCashin;
        CashIn(InputCashin);
        cout << "Now! Your balance is: "<<M_amount[Current_ID];
        Login_AfterMenu();

    }else if(loginAfterrMenu_option==4){ // Widthdraw option start here
        //this is for widthdraw
        int InputWidthdraw=0;
        cout << "Enter the Widthdraw amount: ";
        cin >> InputWidthdraw;
        if(Current_UserAmount-1000 > InputWidthdraw){
            Widthdraw(InputWidthdraw);
            cout <<endl<< "You widthdrew:  "<<InputWidthdraw<<" Kyats";
            cout <<endl<< "Now! Your balance is:  "<<M_amount[Current_ID]<<" Kyats"<<endl;
        }else{
            cout<<endl<<"error";
        }
        Login_AfterMenu();

    }else if(loginAfterrMenu_option==5){ // Transfer option start here
        int TrueOrFalse=0;
        int toTranAmount;
        string toTranName;
        cout <<endl<< "Transfer Option\n";
        cout <<"Enter Reciver Name:";
        cin >> toTranName;
        int ReceiveID = CheckReceiver(toTranName);
        if(ReceiveID!=200){
            cout << "\nEnter Transfer Amount: ";
            cin >> toTranAmount;
            if(toTranAmount<M_amount[ReceiveID]){
                Transfer(Current_ID, ReceiveID, toTranAmount);
                Login_AfterMenu();
            }else{
                cout << "Balance is not enough";
            }
        }else{
            cout <<"no no";
            Login_AfterMenu();
        }

    }else if(loginAfterrMenu_option==6){ // Exit option start here
        //this is for exit
        cout << "\n\n\tExiting from user processing"<<endl;
        Main_Menu();

    }else{
        cout << "Your choice is out of Society!\n choice again";
        Login_AfterMenu();
    }
}//Login_AfterMenu Function's main curly bracket end here


// Check Balance Function start here
int Bill::Check_Balance(int balance) {

    cout <<endl<< "This is your current balance >> "<<balance<<" Kyats"<<endl;
} // Check Balance Functtion end here


// Mobile Top up Function start here
int Bill::Mobile_Topup() {
    int phoneNumber;
    int num, option;
        cout << "Enter Phone Number\n>>09";
        cin >> num;
        phoneNumber=num;
        if(num < 999999999){
            while(num >= 10){
                num = num/10;
            }
        }else{
            cout << "Do not add 09";
        }
        if(num==2 || num == 4 || num == 8){
            cout <<"09-"<<phoneNumber<<" MPT"<<endl;
        }else if(num == 9){
            cout <<"09-"<<phoneNumber<<" OOREDOO"<<endl;
        } else if(num == 7){
            cout <<"09-"<<phoneNumber<< " ATOM"<<endl;
        }
        cout << "[1]1000\n[2]3000\n[3]5000\n[4]10000\nChoose You want to topup amount:: ";
        cin >> option;
    switch (option) {
        case 1:
            M_amount[Current_ID]= M_amount[Current_ID] - 960;
            cout << "1000ks! Successfully Top up to: 09"<<phoneNumber<<endl;
            cout << "cost:: 960 Kyats";
        break;
        case 2:
            M_amount[Current_ID] = M_amount[Current_ID] - 2880;
            cout <<"3000ks! Successfully Top up to: 09"<<phoneNumber<<endl;
            cout << "cost:: 2880 Kyats";
            break;
        case 3:
            M_amount[Current_ID] = M_amount[Current_ID] - 4750;
            cout << "5000ks! Successfully Top up to: 09"<<phoneNumber<<endl;
            cout << "cost:: 4750 Kyats";
        break;
        case 4:
            M_amount[Current_ID] = M_amount[Current_ID] - 9400;
            cout << "10000ks! Successfully Top up to: 09"<<phoneNumber<<endl;
            cout << "cost:: 9400 Kyats";
        break;
    }

} //Mobile_Topup Function end here


//Cash in Function Start here
int Bill::CashIn(int CashinMoney) {
    M_amount[Current_ID] = M_amount[Current_ID] + CashinMoney;
}


//Widthdraw Function start here
int Bill::Widthdraw(int WidthdrawMoney) {
    M_amount[Current_ID] = M_amount[Current_ID] - WidthdrawMoney;
}


// Transfer Function start here
int Bill::Transfer(int SenderID, int ReceiverID, int TransferAmount) {
    M_amount[SenderID] = M_amount[SenderID] - TransferAmount;
    M_amount[ReceiverID] = M_amount[ReceiverID] + TransferAmount;
    cout <<endl<< "Balance Successfully Transferred to : "<<M_username[ReceiverID];
    cout <<endl<< "Amount ::: "<<TransferAmount<<" Kyats"<<endl;
}


// Receiver Username Check Function start here
int Bill::CheckReceiver(string inputName) {
    int tof=0;
    for(int i=0; i <= locate; i++){
        if(inputName == M_username[i]){
            return i;
        }else{
            tof=100;
        }
    }if(tof==100){
        return 200;
    }
} // Receiver Username Check Function End here


// Main Function start here
int main(){
    cout<<endl<<"\n### MOBILE BILL PAYMENT ###"<<endl;
    Bill _obj;
    _obj.Main_Menu();

    return 0;
}
//
// Program finish Successfully Here.
//