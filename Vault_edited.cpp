#include <iostream>
#include <string>
using namespace std;

class Vault {
private:
    string name;
    double money;
    string password;
    bool isLocked;

public:
    Vault(string n, double m, string p) {
        name = n;
        money = m;
        password = p;
        isLocked = true;
    }

    void unlock(string enteredPassword) {
        if (enteredPassword == password) {
            isLocked = false;
            cout << "The vault is unlocked." << endl;
        } else {
            cout << "Wrong password." << endl;
        }
    }

    void lock() {
        isLocked = true;
        cout << "The vault is locked." << endl;
    }

    void changePassword(string oldPassword, string newPassword) {
        if (oldPassword != password) {
            cout << "Wrong old password." << endl;
        } else if (newPassword.length() <= 6) {
            cout << "New password must be longer than 6 characters." << endl;
        } else {
            password = newPassword;
            cout << "Password changed successfully." << endl;
        }
    }

    void printInfo() {
        cout << "Name = " << name << endl;
        cout << "Money = " << money << endl;
    }

    double addMoney(double amount) {
        if (isLocked) {
            cout << "You cannot add money while the vault is locked." << endl;
        } else {
            money += amount;
            cout << "Money after adding = " << money << endl;
        }

        return money;
    }

    double takeMoney(double amount) {
        if (isLocked) {
            cout << "You cannot take money while the vault is locked." << endl;
        } else if (amount > money) {
            cout << "You cannot take more money than you have." << endl;
        } else {
            money -= amount;
            cout << "Money after taking = " << money << endl;
        }

        return money;
    }

    ~Vault() {
        if (isLocked) {
            cout << "Vault closed safely." << endl;
        } else {
            cout << "Please lock the vault before closing." << endl;
        }
    }
};

int main() {
    Vault v1("Yuri", 5000, "yarayara");

    v1.unlock("yarayara");
    v1.printInfo();

    v1.addMoney(50);
    v1.takeMoney(100);

    v1.changePassword("yarayara", "yuriyuri");

    v1.lock();

    return 0;
}
