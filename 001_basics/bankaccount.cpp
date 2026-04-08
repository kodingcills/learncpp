#include <iostream>
using namespace std;

class BankAccount{
    public:
        BankAccount(string owner, int accountNum, double initialBalance){
            SetOwner(owner);
            m_accountNum = accountNum;
            if(initialBalance < 0) { 
                m_balance = 0;
            }else{
                SetBalance(initialBalance);
            }
        }
        void SetOwner(string s) { 
            m_owner = s;
        }

        void SetBalance(double d){
            if (d < 0){
                cout << "Invalid balance";
            }else{
                m_balance = d;
            }
        }

        void Deposit(double amount){
            if(amount <= 0) return;   
            SetBalance(GetBalance() + amount);
        }
        bool Withdraw(double amount){
            if((m_balance-amount) <=0){
                return false;
            }
            m_balance -= amount;
            return true;
        }

        void Print(){
            cout << "Owner: " << m_owner << endl;
            cout << "Account Number: " << m_accountNum << endl;
            cout << "Balance: " << m_balance << endl;
        }

        string GetOwner(){
            return m_owner;
        }

        double GetBalance(){
            return m_balance;
        }

        int GetAccountNum() {return m_accountNum; }
    private:
        string m_owner;
        double m_balance;
        int m_accountNum;
};

int main() {
    BankAccount a("Tiffany", 123445, 1010);
    BankAccount b("b", 912983123, -1);
}