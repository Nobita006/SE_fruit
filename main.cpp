#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <fstream>
#include <string>

using namespace std;

// Function to calculate the total price for a fruit
double calculateTotalPrice(double price, int quantity) {
    return price * quantity;
}

// Function to save sales list to a file
void saveSalesList(const string& filename, const vector<string>& fruits, const vector<int>& quantities, const map<string, double>& fruitPrices) {
    ofstream file(filename);
    if (file.is_open()) {
        file << setw(10) << "Fruit" << setw(10) << "Quantity" << setw(10) << "Price" << setw(10) << "Total" << endl;
        file << setfill('-') << setw(40) << "-" << setfill(' ') << endl;

        double totalPrice = 0.0;
        for (size_t i = 0; i < fruits.size(); i++) {
            string fruitName = fruits[i];
            int fruitQuantity = quantities[i];
            double fruitPrice = fruitPrices.at(fruitName);
            double totalFruitPrice = calculateTotalPrice(fruitPrice, fruitQuantity);
            totalPrice += totalFruitPrice;

            file << setw(10) << fruitName << setw(10) << fruitQuantity << setw(10) << fruitPrice << setw(10) << totalFruitPrice << endl;
        }

        file << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
        file << setw(30) << "Total Price: " << totalPrice << endl;

        file.close();
        cout << "Sales list saved to " << filename << endl;
    }
    else {
        cout << "Unable to save sales list to " << filename << endl;
    }
}

int main() {
    map<string, double> fruitPrices;
    fruitPrices["apple"] = 1.0;
    fruitPrices["banana"] = 0.5;
    fruitPrices["orange"] = 0.75;
    fruitPrices["mango"] = 1.5;
  fruitPrices["gautam"] = 2.5;

    string name;
    vector<string> fruits;
    vector<int> quantities;
    char choice = '\0';

    cout << "Welcome to the Fruit Seller Application!" << endl;
    cout << "Please enter your name: ";
    getline(cin, name);

    while (choice != '4') {
        cout << "\nMenu:\n";
        cout << "1. Add fruit to cart\n";
        cout << "2. Generate invoice\n";
        cout << "3. Save sales list\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        cin.ignore();  // Ignore the newline character left in the input stream

        switch (choice) {
            case '1': {
                string fruit;
                int quantity;
                cout << "\nEnter the fruit you want to buy: ";
                getline(cin, fruit);

                cout << "Enter the quantity: ";
                cin >> quantity;

                fruits.push_back(fruit);
                quantities.push_back(quantity);
                break;
            }

            case '2': {
                cout << "\nInvoice for " << name << ":\n";
                cout << setw(10) << "Fruit" << setw(10) << "Quantity" << setw(10) << "Price" << setw(10) << "Total" << endl;
                cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;

                double totalPrice = 0.0;
                for (size_t i = 0; i < fruits.size(); i++) {
                    string fruitName = fruits[i];
                    int fruitQuantity = quantities[i];
                    double fruitPrice = fruitPrices[fruitName];
                    double totalFruitPrice = calculateTotalPrice(fruitPrice, fruitQuantity);
                    totalPrice += totalFruitPrice;

                    cout << setw(10) << fruitName << setw(10) << fruitQuantity << setw(10) << fruitPrice << setw(10) << totalFruitPrice << endl;
                }

                cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
                cout << setw(30) << "Total Price: " << totalPrice << endl;
                break;
            }

            case '3':
                saveSalesList("sales.txt", fruits, quantities, fruitPrices);
                break;

            case '4':
                cout << "\nThank you for using the Fruit Seller Application!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
                break;
        }
    }

    return 0;
}
