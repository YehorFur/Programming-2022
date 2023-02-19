#include <iostream>
#include <vector>

#define ld long double

using namespace std;

class Customer {
    private:
        string name_;
        string gmail_;
        string phonenumber_;
    public:
        Customer(string name, string gmail, string phonenumber) : name_(name), gmail_(gmail), phonenumber_(phonenumber) {}

        string getName() const {
            return name_;
        }
        string getGmail() const {
            return gmail_;
        }
        string getPhonenumber() const {
            return phonenumber_;
        }
};

class BankAccount {
    private:
        Customer customer_;
        int accountId_;
        ld balance_;
    public:
        BankAccount(const Customer& customer, int accountId, ld balance) : customer_(customer), accountId_(accountId), balance_(balance) {}

        const Customer& getCustomer() const {
            return customer_;
        }
        int getAccountId() const {
            return accountId_;
        }
        const getBalance() const {
            return balance_;
        }

        void increaseBalance(ld amount) {
            balance_ += amount;
        }
        void decreaseBalance(ld amount) {
            balance_ -= amount;
        }
        void setId(int id) {
            accountId_ = id;
        }
        void showBalance() {
            cout << "Balance:" << endl;
            cout << " ($" << balance_ << ")"<< endl;
        }
};

class Base {
    private:
        vector<BankAccount> base_;
    public:
        void addCustomer(const Customer& customer, int accountId, ld balance) {
            for (auto& it : base_) {
                if (it.getCustomer().getName() == customer.getName()) {
                    it.increaseBalance(balance);
                    it.setId(accountId);
                    return;
                }
            }
            base_.emplace_back(customer, accountId, balance);
        }
        BankAccount* searchCustomer(const string& name, const string& gmail) {
            for (auto& it : base_) {
                if (it.getCustomer().getName() == name && it.getCustomer().getGmail() == gmail) {
                    return &it;
                }
            }
            return nullptr;
        }
};

int main()
{
    Base base;
    string name, gmail;
    int accountId;
    ld balance, amount;
    char choice;
    BankAccount* account;

    base.addCustomer(Customer("Oksana", "oksana@gmail.com", "+380(50)1234567"), 1001, 500.0);
    base.addCustomer(Customer("Roman", "roman@gmail.com", "+380(63)2345678"), 1002, 1000.0);
    base.addCustomer(Customer("Yuliya", "yuliya@gmail.com", "+380(67)3456789"), 1003, 750.0);
    base.addCustomer(Customer("Andriy", "andriy@gmail.com", "+380(68)4567890"), 1004, 2000.0);
    base.addCustomer(Customer("Sofiya", "sofiya@gmail.com", "+380(50)5678901"), 1005, 1500.0);
    base.addCustomer(Customer("Taras", "taras@gmail.com", "+380(63)6789012"), 1006, 3000.0);
    base.addCustomer(Customer("Anastasiya", "anastasiya@gmail.com", "+380(67)7890123"), 1007, 100.0);
    base.addCustomer(Customer("Ihor", "ihor@gmail.com", "+380(68)9012345"), 1008, 2500.0);
    base.addCustomer(Customer("Mariya", "mariya@gmail.com", "+380(50)0123456"), 1009, 5000.0);
    base.addCustomer(Customer("Mykola", "mykola@gmail.com", "+380(63)1234567"), 1010, 750.0);



    do {
        cout << "Menu:" << endl;
        cout << "1. Search for account by name and gmail" << endl;
        cout << "2. Add money to account" << endl;
        cout << "3. Withdraw money from account" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            cout << "Enter customer name: ";
            cin >> name;
            cout << "Enter customer gmail: ";
            cin >> gmail;
            account = base.searchCustomer(name, gmail);
            if (account != nullptr) {
                cout << "Account found: ID " << account->getAccountId() << ", balance $" << account->getBalance() << endl;
            } else {
                cout << "Account not found." << endl;
            }
            break;
        case '2':
            cout << "Enter customer name: ";
            cin >> name;
            cout << "Enter customer gmail: ";
            cin >> gmail;
            account = base.searchCustomer(name, gmail);
            if (account != nullptr) {
                cout << "Enter amount to add: $";
                cin >> amount;
                account->increaseBalance(amount);
                account->showBalance();
            } else {
                cout << "Account not found." << endl;
            }
            break;
        case '3':
            cout << "Enter customer name: ";
            cin >> name;
            cout << "Enter customer gmail: ";
            cin >> gmail;
            account = base.searchCustomer(name, gmail);
            if (account != nullptr) {
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                if (account->getBalance() < amount) {
                    cout << "Insufficient funds." << endl;
                } else {
                    account->decreaseBalance(amount);
                    account->showBalance();
                }
            } else {
                cout << "Account not found." << endl;
            }
            break;
        case '4':
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    } while (choice != '4');
    return 0;
}
