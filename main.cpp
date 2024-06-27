#include <iostream>
#include <string>

using namespace std;
class Directory {
private:
    struct Record {
        string name;
        string owner;
        string phone;
        string address;
        string activity;
    };

    static const int MAX_RECORDS = 100;
    Record records[MAX_RECORDS];
    int size; 

public:
    Directory() : size(0) {}

    void addRecord(const string& name, const string& owner, const string& phone, const string& address, const string& activity) {
        if (size < MAX_RECORDS) {
            records[size].name = name;
            records[size].owner = owner;
            records[size].phone = phone;
            records[size].address = address;
            records[size].activity = activity;
            size++;
        }
        else {
            cout << "Error: Directory is full, cannot add new record.\n";
        }
    }

    void searchByName(const string& name) {
        bool found = false;
        for (int i = 0; i < size; ++i) {
            if (records[i].name == name) {
                cout << "Name: " << records[i].name << "\nOwner: " << records[i].owner << "\nPhone: " << records[i].phone << "\nAddress: " << records[i].address << "\nActivity: " << records[i].activity << "\n\n";
                found = true;
            }
        }
        if (!found) {
            cout << "No records found with that name.\n\n";
        }
    }
};

int main() {
    Directory directory;
    directory.addRecord("Company A", "John Doe", "123456789", "123 Main St, City A", "IT Services");
    directory.addRecord("Company B", "Jane Smith", "987654321", "456 Elm St, City B", "Consulting");

    cout << "Searching for 'Company A':\n";
    directory.searchByName("Company A");

    cout << "Searching for 'Company C':\n";
    directory.searchByName("Company C");

    return 0;
}
