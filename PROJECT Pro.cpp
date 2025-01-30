#include <iostream>
#include <array>    

using namespace std;

const int SIZE = 20;  

int main() {
    array<int, SIZE> productID;
    array<string, SIZE> productName;
    array<double, SIZE> productPrice;
    array<int, SIZE> productStock;

    int totalProducts = 0;
    int choice = 0; 

    while (choice != 5) {
        cout << "!====== Supermarket Billing System ======!" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Display Products" << endl;
        cout << "3. Purchase Product" << endl;
        cout << "4. Update Stock" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {  
                if (totalProducts >= SIZE) {
                    cout << "Product limit reached. Cannot add more products." << endl;
                    break;
                }

                
                cout << "Enter product ID: ";
                cin >> productID[totalProducts];  

                
                bool duplicate = false;
                for (int i = 0; i < totalProducts; i++) {
                    if (productID[i] == productID[totalProducts]) {  
                        duplicate = true;
                        break;
                    }
                }

                
                if (duplicate) {
                    cout << "Product ID already exists. Please enter a unique ID." << endl;
                    break;  
                }

                
                cout << "Enter product name: ";
                cin >> productName[totalProducts];  

                cout << "Enter product price: ";
                cin >> productPrice[totalProducts]; 

                cout << "Enter stock quantity: ";
                cin >> productStock[totalProducts];  

                cout << "Product added successfully!" << endl << endl;

                totalProducts++;  
                break;
            }

            case 2: {  
                if (totalProducts == 0) {
                    cout << "No products available." << endl;
                    break;
                }

                cout << "Product List:" << endl;
                cout << "------------------------------------" << endl;
                for (int i = 0; i < totalProducts; i++) {
                    cout << "ID: " << productID[i] << " | Name: " << productName[i] 
                         << " | Price: $" << productPrice[i] << " | Stock: " << productStock[i] << endl;
                }
                cout << "------------------------------------" << endl << endl;
                break;
            }

            case 3: { 
                int id, quantity;
                cout << "Enter Product ID to purchase: ";
                cin >> id;  

                bool found = false;
                for (int i = 0; i < totalProducts; i++) {  
                    if (productID[i] == id) {  
                        found = true;
                        cout << "Product found: " << productName[i] << endl;
                        cout << "Enter quantity to purchase: ";
                        cin >> quantity;

                        if (quantity <= productStock[i]) {
                            productStock[i] -= quantity;
                            cout << "Purchase successful! Remaining stock: " << productStock[i] << endl << endl;
                        } else {
                            cout << "Not enough stock available!" << endl << endl;
                        }
                        break; 
                    }
                }
                if (!found) {
                    cout << "Product not found!" << endl << endl;
                }
                break;
            }

            case 4: {  
                int id, newStock;
                cout << "Enter Product ID to update stock: ";
                cin >> id; 

                bool found = false;
                for (int i = 0; i < totalProducts; i++) { 
                    if (productID[i] == id) {  
                        found = true;
                        cout << "Enter new stock quantity: ";
                        cin >> newStock;

                        productStock[i] = newStock;
                        cout << "Stock updated successfully!" << endl << endl;
                        break;  
                    }
                }
                if (!found) {
                    cout << "Product not found!" << endl << endl;
                }
                break;
            }

            case 5:
                cout << "Exiting program. Thank you!" << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
