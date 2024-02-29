#include<iostream>
#include<stdlib.h>
#include<limits>
#include <vector>

using namespace std;

void flush_inputbuffer_wait(void)
{
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

class bankaccount
{
    int account_number;
    string account_holder_name;
    string account_type;
    double account_balance;
    public:
        bankaccount()
        {
            account_number=0;
            account_holder_name=" ";
            account_type=" ";
            account_balance=0;
            cout<<"default constructor of bankaccount created"<<endl;
        }
        void Set_account_number(int number)
        {
            account_number=number;
        }
        void Set_accountholder_name(string name)
        {
            account_holder_name=name;
        }
        void Set_accountbalance(double balance_init)
        {
            account_balance=balance_init;
        }
        void Set_account_type(string type)
        {
            account_type=type;
        }
        void Deposit(int amount)
        {
            account_balance+=amount;
        }
        void Withdraw(int amount)
        {
            account_balance-=amount;
        }
        int Get_account_number(void)
        {
            return account_number;
        }
        string Get_account_holdername(void)
        {
            return account_holder_name;

        }
        string Get_account_type(void)
        {
            return account_type;
        }
        int Get_account_balance(void)
        {
            return account_balance;
        }
        void Display_account_info(void)
        {
            cout<<"*************************************"<<endl;
            cout<<"the account number: "<<account_number<<endl;
            cout<<"the account holder name: "<<account_holder_name<<endl;
            cout<<"the account type: "<<account_type<<endl;
            cout<<"the account balance: "<<account_balance<<endl;
            cout<<"*************************************"<<endl;
        }
        ~bankaccount()
        {
            cout<<"the bankaccount destructor is called"<<endl;
        }
};

class bank
{
    vector<bankaccount> bank_database;
    public:
    bank()
    {
        cout<<"the bank default constructor is called"<<endl;
        
    }
    void AddAccount(void)
    {
        bankaccount local_bank_account;
        int account_number;
        string card_holder_name;
        string account_type;
        double account_balance=0;
        cout<<"enter the account information :"<<endl;
        cout<<"enter the account number: ";
        cin>>account_number;
        local_bank_account.Set_account_number(account_number);
        cout<<"enter the card holder name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin>>card_holder_name;
        local_bank_account.Set_accountholder_name(card_holder_name);     
        cout<<"enter the account type: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin>>account_type;
        local_bank_account.Set_account_type(account_type);
        cout<<"enter the initial account balance: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin>>account_balance;
        local_bank_account.Set_accountbalance(account_balance);
        bank_database.push_back(local_bank_account);
        cout<<"account added successfully press enter for new option"<<endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getchar();
    }
    void Deposit()
    {
        int account_number=0;
        int amount=0;
        int account_number_flag=0;
        cout<<"enter the account number"<<endl;
        cin>>account_number;
        for(auto iterator=bank_database.begin();iterator!=bank_database.end();iterator++)
        {
            if(iterator->Get_account_number()==account_number)
            {
                account_number_flag=1;
                cout<<"Welcome to the ATM Bank System Mr/Ms: "<<iterator->Get_account_holdername()<<endl;
                cout<<"enter the amount needed"<<endl;
                cin>>amount;    
                iterator->Deposit(amount);
                cout<<"deposite successful new balance is: "<<iterator->Get_account_balance()<<endl;
                cout<<"press enter for new option"<<endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getchar();
                break;
            }
        }
        if(account_number_flag==0)
        {
            cout<<"account number not found in the database press enter for new option"<<endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getchar();
        }
    }
    void Withdraw()
    {
        int account_number=0;
        int amount=0;
        int account_number_flag=0;
        cout<<"enter the account number"<<endl;
        cin>>account_number;
        for(auto iterator=bank_database.begin();iterator!=bank_database.end();iterator++)
        {
            if(iterator->Get_account_number()==account_number)
            {
                account_number_flag=1;
                cout<<"Welcome to the ATM Bank System Mr/Ms: "<<iterator->Get_account_holdername()<<endl;
                cout<<"enter the amount needed"<<endl;
                cin>>amount;
                if(iterator->Get_account_balance()<amount)
                {
                    cout<<"insufficient funds press enter for new option"<<endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getchar();
                }
                else
                {
                    iterator->Withdraw(amount);
                    cout<<"withdraw successful new balance is: "<<iterator->Get_account_balance()<<endl;
                    cout<<"Press enter for new option"<<endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getchar();
                }
                break;
            }
        }
        if(account_number_flag==0)
        {
            cout<<"account number not found in the database press enter for new option"<<endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getchar();
        }
    }
    void GetTotalBalance(void)
    {
        double sum_of_balances=0;
        for(auto iterator=bank_database.begin();iterator!=bank_database.end();iterator++)
        {
        sum_of_balances+=iterator->Get_account_balance();
        }
        cout<<"the total balance of bank accounts: "<<sum_of_balances<<endl;
        cout<<"press enter for new option "<<endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getchar();
    }
    void DisplayAllAccounts(void)
    {
        cout<<"Display the information of all bank accounts"<<endl;
        for(auto iterator=bank_database.begin();iterator!=bank_database.end();iterator++)
        {
            iterator->Display_account_info();
        }
        cout<<"Number of accounts in the system is: "<<bank_database.size()<<endl;
        cout<<"press enter for new option "<<endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getchar();
    }
    void EmptyDataBase(void)
    {
        bank_database.clear();
    }
};  

int main(void)
{
    bank b1;
    int option=0;
    int flag=1;
    while(flag)
    {
        system("CLS");
        cout<<"Menu:"<<endl;
        cout<<"1. Create an account"<<endl;
        cout<<"2. Deposite funds"<<endl;
        cout<<"3. Withdraw funds"<<endl;
        cout<<"4. Total balance"<<endl;
        cout<<"5. Display all accounts"<<endl;
        cout<<"6. Exit"<<endl;

        cout<<"enter your choice : ";
        cin>>option;
        switch(option)
        {
            case 1:
                system("CLS");
                b1.AddAccount();
            break;
            case 2:
                system("CLS");
                b1.Deposit();
            break;
            case 3:
                system("CLS");
                b1.Withdraw();
            break;
            case 4:
                    system("CLS");
                b1.GetTotalBalance();
            break;
            case 5:
                    system("CLS");
                b1.DisplayAllAccounts();
            break;
            case 6:
                system("CLS");
                cout<<"system shutdown"<<endl;
                b1.EmptyDataBase();
                flag=0;
            break;
            default:
            cout<<"wrong option"<<endl;
            break;
        }
    }
    return 0;
}