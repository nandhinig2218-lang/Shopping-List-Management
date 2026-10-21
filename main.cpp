
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<string> shoppingList;
    int choice;
    string item;

    do {
        cout << "\n===== SHOPPING LIST MANAGEMENT =====\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Search Item\n";
        cout << "4. Display All Items\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter item to add: ";
                getline(cin, item);
                shoppingList.push_back(item);
                cout << "Item added successfully!\n";
                break;

            case 2: {
                cout << "Enter item to remove: ";
                getline(cin, item);

                auto it = find(shoppingList.begin(),
                               shoppingList.end(), item);

                if (it != shoppingList.end()) {
                    shoppingList.erase(it);
                    cout << "Item removed successfully!\n";
                } else {
                    cout << "Item not found!\n";
                }
                break;
            }

            case 3: {
                cout << "Enter item to search: ";
                getline(cin, item);

                auto it = find(shoppingList.begin(),
                               shoppingList.end(), item);

                if (it != shoppingList.end()) {
                    cout << "Item found: " << *it << '\n';
                } else {
                    cout << "Item not found!\n";
                }
                break;
            }

            case 4:
                if (shoppingList.empty()) {
                    cout << "Shopping list is empty!\n";
                } else {
                    cout << "\nYour Shopping List:\n";
                    for (int i = 0;
                         i < static_cast<int>(shoppingList.size()); i++) {
                        cout << i + 1 << ". "
                             << shoppingList[i] << '\n';
                    }
                }
                break;

            case 5:
                cout << "Exiting Shopping List. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
