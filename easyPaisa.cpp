#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//Global Variables
string name;
string cnic;
string mobile;
string password;
double balance = 0.0;

//Function prototype
void CreateAccount ();
void LoginAccount ();
void Deposit ();
void Withdraw ();
void MoneyTransfer ();
void paybills ();

int main(){

    cout<<"============================================="<<endl;
    cout<<"|           Welcome TO EASYPAISA            |"<<endl;
    cout<<"============================================="<<endl;
    cout<<"|                 live easy                 |"<<endl;
    cout<<"---------------------------------------------"<<endl;

    int choice;
      while (true) {
        cout<<"1. Create Account"<<endl;
        cout<<"2. Login to your Account"<<endl;
        cout<<"3. Exit"<<endl;
        cin>>choice;

        switch (choice) {
            case 1: {
                CreateAccount();
                break;
            }
            case 2: {
                LoginAccount();
                break;
            }
            case 3: {
                cout<<"Exiting... Thank you for using Easypaisa!"<<endl;
                exit(0);
            }
            default: {
                cout<<"Invalid choice. Please try again."<<endl;
                break;
            }
        }
    }

    return 0;
}

void CreateAccount (){

    cout<<"---------------------------------------------"<<endl;
    cout<<"|      Please proceed to create an account  |"<<endl;
    cout<<"---------------------------------------------"<<endl;

    cout<<"Enter Name : ";
    cin.ignore();
    getline(cin, name);

    int attempcnic = 0;
    bool Validcnic = false;
    while ( attempcnic < 3) { 
     cout<<"Enter CNIC Number of 13 digit : ";
     cin>>cnic;

     if (cnic.length() == 13 && all_of(cnic.begin(), cnic.end(), ::isdigit)) {
            Validcnic = true;
            break;
        } else {
            cout << "CNIC is not correct. It should be 13 digits and contain only numbers. Try again." << endl;
            attempcnic++;
        }
    }

    if (!Validcnic){
        cout<<"Account creation failed. Too many invalid CNIC attempts."<<endl;
        cout<<endl;
        return;
    }

    // Mobile number validation
    int attemptMobile = 0;
    bool validMobile = false;
    while (attemptMobile < 3) {
        cout << "Enter Mobile Number: ";
        cin >> mobile;
        if (mobile.length() > 0 && all_of(mobile.begin(), mobile.end(), ::isdigit)) {
            validMobile = true;
            break;
        } else {
            cout << "Invalid mobile number. It should contain only digits. Try again." << endl;
            attemptMobile++;
        }
    }
    if (!validMobile) {
        cout << "Account creation failed. Too many invalid mobile number attempts." << endl;
        cout<<endl;
        return;
    }

    // Password creation
    int attemppass = 0;
    bool validPass = false;
    string pass1;
    while (attemppass < 3){ 
     cout<<"Create a numeric Password of 6 digits : ";
     cin>>pass1;
      if (pass1.length() == 6 && all_of(pass1.begin(), pass1.end(), ::isdigit)) {
          validPass = true;
          break;
        } else {
            cout<<"Password is not correct. It should be 6 digits and contain only numbers. Try again."<<endl;
            attemppass++;
        }    
    }
    if (!validPass) {
        cout << "Account creation failed. Too many invalid password attempts." << endl;
        cout<<endl;
        return;
        
    }

    // Confirm password logic
    string pass2;
    int confirmPassAttempts = 0;
    bool passwordsMatch = false;
    while (confirmPassAttempts < 3) {
        cout<<"Please enter the password again to confirm : ";
        cin>>pass2;
        if (pass1 == pass2) {
            passwordsMatch = true;
            break;
        } else {
            cout << "Passwords do not match. Try again." << endl;
            confirmPassAttempts++;
        }
    }
    if (!passwordsMatch) {
        cout << "Account creation failed. Too many mismatched password attempts." << endl;
        cout<<endl;
        return;
    } else {
        password = pass2;
    }

    cout<<"======================================================="<<endl;
    cout<<"|   Account Created Successfully! Now you can Login.  |"<<endl;
    cout<<"======================================================="<<endl;
    cout<<endl;

}


void LoginAccount () { 

    string inputmobile, inputpassword;
    int attemptlogin = 0;
    bool loggedIn = false;
    while (attemptlogin < 3){
        cout<<"Enter your Mobile Number: ";
        cin>>inputmobile;

        cout<<"Enter your Password: ";
        cin>>inputpassword;
        cout<<endl;

        if (inputmobile == mobile && inputpassword == password){
            loggedIn = true;
            break;
        } else {
            cout<<"Invalid mobile or password. Try again."<<endl;
            attemptlogin++;
        }
    }
    if (loggedIn){
        cout<<"Welcome, "<<name<<". Your current balance is: "<<balance<<endl;

        int menuChoice;

        while (true) { 
        cout<<"=========="<<endl;
        cout<<"|  Menu  |"<<endl;
        cout<<"=========="<<endl;
        cout<<"1. Deposite Amount"<<endl;
        cout<<"2. Withdraw Amount"<<endl;
        cout<<"3. Money Transfer"<<endl;
        cout<<"4. Bill Payments"<<endl;
        cout<<"5. Logout"<<endl;
        cin>>menuChoice;
        cout<<endl;

         switch (menuChoice){
            case 1: {
                Deposit();
                break;
            }
            case 2: {
                Withdraw();
                break;
            }
            case 3: {
                MoneyTransfer();
                break;
            }
            case 4: {
                paybills();
                break;
            }
            case 5: {
                cout<<"Logging out... Thank you for using Easypaisa!"<<endl;
                return;
            }
            
            default: {
                cout<<"Invalid choice. Please try again."<<endl;
                break;
            }
         }
        }
        

    } else {
        cout<<"Too many failed login attempts. Please call to Helpline or try again later."<<endl;
        cout<<endl;
        return;
    }

}

void Deposit (){
    double depamount;
    cout<<"Enter your amount to deposit: ";
    cin>>depamount;
    if (depamount > 0){
        balance += depamount;
        cout<<"Amount: "<<depamount<<" deposited successfully. Now your new balance is: "<<balance<<endl;
    } else {
        cout<<"Invalid amount, please try again."<<endl;
    }
}

void Withdraw () { 
    double withdrawamount;
    cout<<"Enter the amount to withdraw: ";
    cin>>withdrawamount;

    if (withdrawamount > 0 && withdrawamount <= balance){
        balance -= withdrawamount;
        cout<<"Amount: " <<withdrawamount<<" withdrawn successfully. Your new balance is: "<<balance<<endl;
    } else if (withdrawamount > balance){
        cout<<"Insufficient balance! Your current balance is: "<<balance<<endl;
    } else {
        cout<<"Invalid amount. Please try again."<<endl;
    }
}

void MoneyTransfer (){
    string receiverMobile;
    double amount;
    int attempt = 0;
    bool validmobile = false;

    while (attempt < 3){
        cout<<"Enter receiver's mobile number: ";
        cin>>receiverMobile;
        if (receiverMobile.length() > 0 && all_of(receiverMobile.begin(), receiverMobile.end(), :: isdigit)){
            validmobile = true;
            break;
        } else {
            cout<<"Invalid mobile number. It should contain only digits. Try again."<<endl;
            attempt++;
        }
    }
    if (!validmobile){
        cout<<"Too many invalid attempts. Money transfer failed."<<endl;
        return;
    }
    
    cout<<"Enter the amount of transfer: ";
    cin>>amount;
    cout<<endl;

    if (amount > 0 && amount <= balance ){
        balance -= amount;
        cout<<"Money transfer of "<<amount<<" to "<<receiverMobile <<" successful."<<endl;
        cout<<"Your new balance is: "<<balance<<endl;
        cout<<endl;
    }
    else if (amount > balance){
        cout<<"Insufficient balance! Your current balance is: "<<balance<<endl;
    } else {
        cout<<"Invalid transfer amount. Please try again."<<endl;
    }
    
}

void paybills (){
    int billchoice;
    cout<<"1. Electricity Bill"<<endl;
    cout<<"2. PTCL Bill"<<endl;
    cout<<"3. Gas Bill"<<endl;
    cout<<"4. Education Billing"<<endl;
    cout<<"5. Cancel"<<endl;
    cin>>billchoice;
    cout<<endl;

    switch (billchoice) {

        case 1: {  
            double amountEle;
            long int referenceEle; 
            cout<<"Enter Electricity Bill Reference Number: ";
            cin>>referenceEle;
            cout<<"Enter the Electricity bill amount: ";
            cin>>amountEle;

            if (amountEle > 0 && amountEle <= balance){
                  balance -= amountEle;
                  cout<<"Electricity bill (Reference: "<<referenceEle<< ") of RS : "<<amountEle<<" paid successfully. Your new balance is: "<<balance<<endl;
                  break;
            } else if (amountEle > balance) {
             cout<<"Insufficient balance! Your current balance is: "<<balance<<endl;
            } else {
             cout<<"Invalid bill amount. Please try again."<<endl;
            }
            break;
        }
        case 2: {
            long int referencePtcl;
            double amountPtcl;
            cout<<"Enter PTCL Bill Reference Number: ";
            cin>>referencePtcl;
            cout<<"Enter the PTCL bill amount: ";
            cin>>amountPtcl;
            if (amountPtcl > 0 && amountPtcl <= balance){
                  balance -= amountPtcl;
                  cout<<"PTCL bill (Reference: "<<referencePtcl<< ") of RS : "<<amountPtcl<<" paid successfully. Your new balance is: "<<balance<<endl;
                  break;
            } else if (amountPtcl > balance) {
             cout<< "Insufficient balance! Your current balance is: "<<balance<<endl;
            } else {
             cout<<"Invalid bill amount. Please try again."<<endl;
            }
            break;
        }
        case 3: {
            long int referenceGas;
            double amountGas;
            cout<<"Enter Gas Bill Reference Number: ";
            cin>>referenceGas;
            cout<<"Enter the Gas bill amount: ";
            cin>>amountGas;
            if (amountGas > 0 && amountGas <= balance){
                  balance -= amountGas;
                  cout<<"Gas bill (Reference: "<<referenceGas<< ") of RS : "<<amountGas<<" paid successfully. Your new balance is: "<<balance <<endl;
                  break;
            } else if (amountGas > balance) {
             cout<<"Insufficient balance! Your current balance is: "<<balance<<endl;
            } else {
             cout<<"Invalid bill amount. Please try again."<<endl;
            }
            break;
        }

        case 4: {

            string schoolClg;
            cout<<"Enter your Institue Name: ";
            cin.ignore();
            getline(cin, schoolClg);

            long int studentid;
            cout<<"Enter your Student Id: ";
            cin>>studentid;

            cout<<"Enter your Fee: ";
             double fee;
             cin>>fee;

            if (fee > 0 && fee <= balance){
                balance -= fee;
                cout<<"Education Fee (Student ID: "<<studentid<< ") of RS : "<<fee<<" paid successfully. Your new balance is: "<<balance<<endl;;
                break;
            } else if (fee > balance) {
             cout<<"Insufficient balance! Your current balance is: " <<balance<<endl;
            } else {
             cout<<"Invalid bill amount. Please try again."<<endl;
            }
            break;
            
        }

        case 5: {
           cout << "Bill payment cancelled." << endl;
           return;
        }
        
        default: {
            cout<<"Invalid choice. Please try again."<<endl;
            break;
        }
    }

}