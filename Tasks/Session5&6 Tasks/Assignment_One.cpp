#include<iostream>
using namespace std;


class BankAccount{

    protected:
        string accountNumber;
        double balance;
    public:
        BankAccount()
        {
            cout<<"bank account default constructor is called"<<endl;
        }
        BankAccount(string acc_num,double balanceinitamount)
        {
            accountNumber=acc_num;
            balance=balanceinitamount;
            cout<<"bank account paramterized constructor is called"<<endl;
        }
        void deposit(double amount)
        {
            balance += amount;
            cout<<"deposit is called"<<endl;
        }
        void withdraw(double amount)
        {
            balance -= amount;
            cout<<"withdraw is called"<<endl;
        }
        void displayinfo(void)
        {
            cout<<"Accout number: "<<accountNumber<<endl;
            cout<<"Account balance: "<<balance<<endl;
        }
        ~BankAccount()
        {
            cout<<"bank account destructor is called"<<endl;
        }

};

class SavingAccount : public BankAccount{
    private:
        double interestRate;
    public:
        SavingAccount()
        {
            cout<<"saving account default constructor is called"<<endl;
        }
        SavingAccount(string copyaccnumber,double copybalance,double interest_rate)
        {
            accountNumber=copyaccnumber;
            balance=copybalance;
            interestRate=interest_rate;
            cout<<"saving account parametrized constructor is called"<<endl;
        }
        void calculateInterest(void)
        {
            double local_value=0;
            local_value= (balance*(interestRate/100));
            balance += local_value;
            cout<<"calculate interest is called"<<endl;
        }
        void displayinfo(void)
        {
            cout<<"Accout number: "<<accountNumber<<endl;
            cout<<"Account balance: "<<balance<<endl;
            cout<<"Account Interest Rate: "<<interestRate<<endl;
        }
        ~SavingAccount()
        {
            cout<<"saving account destructor is called"<<endl;
        }
};

class CheckingAccount : public BankAccount{
    private:
        double transactionFee;
    public:
        CheckingAccount()
        {
            cout<<"default checking account constructor"<<endl;
        }
        CheckingAccount(string copy_accnumber,double copy_balance,double copyTransactionfee)
        {
            accountNumber=copy_accnumber;
            balance=copy_balance;
            transactionFee=copyTransactionfee;
            cout<<"paramteized constructor is called"<<endl;
        }
        void deductTransactionFee(void)
        {
            balance -=transactionFee;
            cout<<"deducttransactionsfee is called"<<endl;
        }
        void displayinfo(void)
        {
            cout<<"Accout number: "<<accountNumber<<endl;
            cout<<"Account balance: "<<balance<<endl;
            cout<<"Account Transaction fee: "<<transactionFee<<endl;
        }
        ~CheckingAccount()
        {
            cout<<"checking account destructor is called"<<endl;
        }
};


int main(void)
{
    BankAccount accountone("1234",5000);
    SavingAccount savingaccountone("5678",4000,30);
    CheckingAccount checkingaccountone("1122",8000,50);
    accountone.deposit(2000);
    accountone.displayinfo();
    accountone.withdraw(3000);
    accountone.displayinfo();

    savingaccountone.deposit(2000);
    savingaccountone.displayinfo();
    savingaccountone.withdraw(3000);
    savingaccountone.displayinfo();

    checkingaccountone.deposit(2000);
    checkingaccountone.displayinfo();
    checkingaccountone.withdraw(3000);
    checkingaccountone.displayinfo();
}