#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct GroceryItem {
    char name[50];
    float price;
    int quantity;
};
void addItem(struct GroceryItem inventory[], int *itemCount);
void displayInventory(struct GroceryItem inventory[], int itemCount);
void showTotalValue(struct GroceryItem inventory[], int itemCount);
void deleteItem(struct GroceryItem inventory[], int *itemCount);
int authenticateUser();

int main() {
    printf("\n");
    printf("\t*****************************************************\n");
    printf("\t**********                                 **********\n");
    printf("\t**********     Bismillah Grocery Shop      **********\n");
    printf("\t**********                                 **********\n");
    printf("\t*****************************************************\n");
    printf("\n");

    if (authenticateUser()) {
        struct GroceryItem inventory[100];
        int itemCount = 0;
        int choice;
        do {
            printf("\n\tMenu:\n");
            printf("\t\t1. Add Item\n");
            printf("\t\t2. Display Inventory\n");
            printf("\t\t3. Show Total Value of Purchases\n");
            printf("\t\t4. Delete Item\n");
            printf("\t\t5. Exit\n");
            printf("\n\tEnter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    addItem(inventory, &itemCount);
                    break;
                case 2:
                    displayInventory(inventory, itemCount);
                    break;
                case 3:
                    showTotalValue(inventory, itemCount);
                    break;
                case 4:
                    deleteItem(inventory, &itemCount);
                    break;
                case 5:
                    printf("\n\tExiting the program.\n");
                    break;
                default:
                    printf("\n\tInvalid choice. Please enter a valid option.\n");
            }
        } while (choice != 5);
    }
    return 0;
}
void addItem(struct GroceryItem inventory[], int *itemCount) {
    if (*itemCount < 100) {
        printf("\tEnter the name of the item: ");
        scanf("%s", inventory[*itemCount].name);
        printf("\tEnter the price of the item: ");
        scanf("%f", &inventory[*itemCount].price);
        printf("\tEnter the quantity of the item: ");
        scanf("%d", &inventory[*itemCount].quantity);
        (*itemCount)++;
        printf("\n\tItem added successfully!\n");
    } else {
        printf("\n\tInventory is full. Cannot add more items.\n");
    }
}
void displayInventory(struct GroceryItem inventory[], int itemCount) {
    if (itemCount == 0) {
        printf("\n\tInventory is empty.\n");
    } else {
        printf("\n\tInventory:\n");
        for (int i = 0; i < itemCount; i++) {
            printf("\t\t%d. %s - $%.2f - Quantity: %d\n", i + 1, inventory[i].name, inventory[i].price, inventory[i].quantity);
        }
    }
}
void showTotalValue(struct GroceryItem inventory[], int itemCount) {
    float totalValue = 0.0;
    for (int i = 0; i < itemCount; i++) {
        totalValue += inventory[i].price * inventory[i].quantity;
    }
    printf("\tTotal value of purchases in the inventory: $%.2f\n", totalValue);
}
void deleteItem(struct GroceryItem inventory[], int *itemCount) {
    if (*itemCount == 0) {
        printf("\tInventory is empty. Cannot delete an item.\n");
        return;
    }
    int index;
    printf("\t\tEnter the index of the item to delete (1 to %d): ", *itemCount);
    scanf("%d", &index);

    if (index < 1 || index > *itemCount) {
        printf("\t\tInvalid index. Please enter a valid index.\n");
        return;
    }
    printf("\tDeleted item: %s\n", inventory[index - 1].name);

    for (int i = index - 1; i < *itemCount - 1; i++) {
        strcpy(inventory[i].name, inventory[i + 1].name);
        inventory[i].price = inventory[i + 1].price;
        inventory[i].quantity = inventory[i + 1].quantity;
    }
    (*itemCount)--;
}
int authenticateUser() {
    char username[20];
    char password[20];

    printf("\tEnter username: ");
    scanf("%s", username);
    printf("\tEnter password: ");
    scanf("%s", password);
    printf("\n");

    if (strcmp(username, "asadullah_cse") == 0 && strcmp(password, "bismillah123") == 0) {
        printf("\t\tAuthentication successful!\n");
        return 1;
    } else {
        printf("\t\tAuthentication failed. Exiting the program.\n");
        return 0;
    }
}

