#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Abstract type "phone"
class Phone {
public:
    Phone(string name, string company, float price)
        : name_(name), company_(company), price_(price) {}

    virtual ~Phone() {}

    string getName() const { return name_; }
    string getCompany() const { return company_; }
    float getPrice() const { return price_; }

    virtual bool hasAnsweringMachine() const = 0;

    virtual void Input(ifstream& file) = 0;

protected:
    string name_;
    string company_;
    float price_;
};

// Derived type "mobile phone"
class MobilePhone : public Phone {
public:
    MobilePhone(string name, string company, float price, string color, int memoryVolume)
        : Phone(name, company, price), color_(color), memoryVolume_(memoryVolume) {}

    virtual bool hasAnsweringMachine() const override { return false; }

    virtual void Input(ifstream& file) override {
        file >> name_ >> company_ >> price_ >> color_ >> memoryVolume_;
    }

private:
    string color_;
    int memoryVolume_;
};

// Derived type "radio phone"
class RadioPhone : public Phone {
public:
    RadioPhone(string name, string company, float price, float radiusOfAction, bool hasAnsweringMachine)
        : Phone(name, company, price), radiusOfAction_(radiusOfAction), hasAnsweringMachine_(hasAnsweringMachine) {}

    virtual bool hasAnsweringMachine() const override { return hasAnsweringMachine_; }

    virtual void Input(ifstream& file) override {
        file >> name_ >> company_ >> price_ >> radiusOfAction_ >> hasAnsweringMachine_;
    }

private:
    float radiusOfAction_;
    bool hasAnsweringMachine_;
};

// Comparison function for sorting phones by price
bool comparePhones(const Phone* a, const Phone* b) {
    return a->getPrice() < b->getPrice();
}

int main() {
    vector<Phone*> phones;

    // Read phones from first file
    ifstream file1("company1_phones.txt");
    if (file1.is_open()) {
        int num;
        while (file1 >> num) {
            Phone* temp;
            if (num == 1) {
                temp = new MobilePhone("", "", 0.0, "", 0);
            }
            else {
                temp = new RadioPhone("", "", 0.0, 0.0, "");
            }
            temp->Input(file1);
            phones.push_back(temp);
        }
        file1.close();
    }

    // Read phones from second file
    ifstream file2("company2_phones.txt");
    if (file2.is_open()) {
        int num;
        while (file2 >> num) {
            Phone* temp;
            if (num == 1) {
                temp = new MobilePhone("", "", 0.0, "", 0);
            }
            else {
                temp = new RadioPhone("", "", 0.0, 0.0, "");
            }
            temp->Input(file2);
            phones.push_back(temp);
        }
        file2.close();
    }

    // Sort phones by price
    sort(phones.begin(), phones.end(), comparePhones);

    // Output all phones sorted by price to file
    ofstream outfile("all_phones_sorted.txt");
    if (outfile.is_open()) {
        float totalAmount = 0.0;
        for (const Phone* phone : phones) {
            outfile << phone->getName() << " " << phone->getCompany() << " " << phone->getPrice() << endl;
            totalAmount += phone->getPrice();
        }
        outfile << "Total amount: " << totalAmount << endl;
        outfile.close();
    }

    // Output radio phones with answering machine to file
    ofstream outfile2("radio_phones_with_answering_machine.txt");
    if (outfile2.is_open()) {
        for (const Phone* phone : phones) {
            if (phone->hasAnsweringMachine()) {
            outfile2 << phone->getName() << " " << phone->getCompany() << " " << phone->getPrice() << endl;
            }
        }
        outfile2.close();
    }

    // Free memory allocated for phones
    for (Phone* phone : phones) {
        delete phone;
    }

    return 0;
}
