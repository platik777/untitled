#include <iostream>
using namespace std;

struct Fridge{
    int milk = 0;
    int meat = 0;
    int cheese = 0;
    int tasty_thing = 0;

    void Add() {
        int amount;
        string subject;
        cout << "Enter what u want to put in fridge: "; cin >> subject;
        if (subject == "milk" || subject == "Milk") {
            cout << "Enter litres of milk u want to input: "; cin >> amount;
            milk += amount;
        } else if (subject == "meat" || subject == "Meat") {
            cout << "Enter kilograms of meat u want to input: "; cin >> amount;
            meat += amount;
        } else if (subject == "cheese" || subject == "Cheese") {
            cout << "Enter amount of cheese slices u want to input: "; cin >> amount;
            cheese += amount;
        } else if (subject == "tasty thing" || subject == "Tasty thing"){
            cout << "Enter amount of tasty things u want to input: "; cin >> amount;
            tasty_thing += amount;
        } else {
            cout << "This product is not in Fridge" << endl;
        }
    };

    void Output() {
        int amount;
        string subject;
        cout << "Enter what u want output in fridge: "; cin >> subject;
        if (subject == "milk" || subject == "Milk") {
            cout << "Enter litres of milk u want output: " << endl; cin >> amount;
            if (milk - amount <= 0) {
                cout << "Amount of milk less than u try to output" << endl;
            } else {
                milk -= amount;
            }
        } else if (subject == "meat" || subject == "Meat") {
            cout << "Enter kilograms of meat u want output: " << endl; cin >> amount;
            if (meat - amount <= 0) {
                cout << "Amount of meat less than u try to output" << endl;
            } else {
                meat -= amount;
            }
        } else if (subject == "cheese" || subject == "Cheese") {
            cout << "Enter amount of cheese slices u want output: " << endl; cin >> amount;
            if (cheese - amount <= 0) {
                cout << "Amount of cheese less than u try to output" << endl;
            } else {
                cheese -= amount;
            }
        } else if (subject == "tasty thing" || subject == "Tasty thing"){
            cout << "Enter amount of tasty things u want output: " << endl; cin >> amount;
            if (tasty_thing - amount <= 0) {
                cout << "Amount of tasty thing less than u try to output" << endl;
            } else {
                tasty_thing -= amount;
            }
        } else {
            cout << "This product is not in Fridge" << endl;
        }
    };

    void FridgeInfo() const {
        cout << "Milk, litres: " << milk << endl;
        cout << "Meat, kilograms: " << meat << endl;
        cout << "Cheese, slices: " << cheese << endl;
        cout << "Tasty thing, amount: " << tasty_thing << endl;
    };
};
int main() {
    Fridge f1;
    Fridge f2;
    string input = " ";
    while (true) {
        cout << "Enter what u want to do with fridge: 'put' or 'output' or 'info' and write number of fridge or 'stop': " << endl; cin >> input;
        if (input == "put1") {
            f1.Add();
        } else if (input == "output1") {
            f1.Output();
        } else if (input == "info1"){
            f1.FridgeInfo();
        }else if (input == "put2") {
            f2.Add();
        }else if (input == "output2") {
            f2.Output();
        }else if (input == "info2") {
            f2.FridgeInfo();
        } else if (input == "stop") {
            break;
        } else {
            cout << "Unknown command" << endl;
        }
    }
    return 0;
}