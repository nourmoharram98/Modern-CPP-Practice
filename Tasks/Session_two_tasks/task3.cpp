#include<iostream>
#include<stdlib.h>
#include<limits>
using namespace std;

void flush_inputbuffer_wait(void)
{
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      getchar();
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
        void Deposit(int amount)
        {
            account_balance+=amount;
        }
        void Withdraw(int amount)
        {
            account_balance-=amount;
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
        void Get_account_number(void)
        {
            cout<<"the account number: "<<account_number<<endl;
            flush_inputbuffer_wait();
        }
        void Get_account_holdername(void)
        {
            cout<<"the account holder name: "<<account_holder_name<<endl;
            flush_inputbuffer_wait();

        }
        void Get_account_type(void)
        {
            cout<<"the account type: "<<account_type<<endl;
            flush_inputbuffer_wait();

        }
        int Get_account_balance(void)
        {
            cout<<"the account balance: "<<account_balance<<endl;
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
    const int number_of_bank_accounts=3;
    bankaccount bank_accounts[3];
    static int counter;
    public:
    bank()
    {
        cout<<"the bank default constructor is called"<<endl;
        
    }
    void AddAccount(void)
    {
        if(counter>=number_of_bank_accounts)
        {
            cout<<"the bank database is full press enter for new option"<<endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getchar();
        }
        else
        {
            string card_holder_name;
            string account_type;
            double account_balance=0;
            cout<<"enter the account information :"<<endl;
            bank_accounts[counter].Set_account_number(counter);
            cout<<"enter the card holder name"<<endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin,card_holder_name);            
            bank_accounts[counter].Set_accountholder_name(card_holder_name);
            cout<<"enter the account type "<<endl;
            getline(cin,account_type);            
            bank_accounts[counter].Set_account_type(account_type);
            cout<<"enter the initial account balance"<<endl;
            cin>>account_balance;
            bank_accounts[counter].Set_accountbalance(account_balance);
            bank_accounts[counter].Display_account_info();
            flush_inputbuffer_wait();
            counter++;
        }
    }
    void Deposit()
    {
        int account_number=0;
        int amount=0;
        cout<<"enter the account number"<<endl;
        cin>>account_number;
        cout<<"enter the amount needed"<<endl;
        cin>>amount;
        bank_accounts[account_number].Deposit(amount);
        cout<<"deposite successful new balance is: ";
        cout<<bank_accounts[account_number].Get_account_balance()<<endl;
        cout<<"deposite successful press enter for new option"<<endl;
        flush_inputbuffer_wait();
    }
    void Withdraw()
    {
        int account_number=0;
        int amount=0;
        cout<<"enter the account number"<<endl;
        cin>>account_number;
        cout<<"enter the amount needed"<<endl;
        cin>>amount;
        if(amount>(bank_accounts[account_number].Get_account_balance()))
        {
            cout<<"insufficient funds press enter for new option"<<endl;
            flush_inputbuffer_wait();

        }
        else
        {
            bank_accounts[account_number].Withdraw(amount);
            cout<<"withdraw successful new balance is: ";
            cout<<bank_accounts[account_number].Get_account_balance()<<endl;
            cout<<"press enter for new option"<<endl;
            flush_inputbuffer_wait();
        }
    }
    void GetTotalBalance(void)
    {
        double sum_of_balances=0;
        for(int i=0;i<counter;i++)
        {
            sum_of_balances+=bank_accounts[i].Get_account_balance();
        }
        cout<<"the total balance of bank accounts: "<<sum_of_balances<<endl;
        cout<<"press enter for new option "<<endl;
        flush_inputbuffer_wait();
    }
    void DisplayAllAccounts(void)
    {
        cout<<"Display the information of all bank accounts"<<endl;
        for(int i=0;i<counter;i++)
        {
            bank_accounts[i].Display_account_info();
        }
        flush_inputbuffer_wait();
    }
};  


int bank::counter=0;

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
                flag=0;
            break;
            default:
            cout<<"wrong option"<<endl;
            break;
        }
    }
    return 0;
}