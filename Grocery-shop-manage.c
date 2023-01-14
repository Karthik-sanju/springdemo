#include <stdio.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 100
#define MAX_CUSTOMERS 100
#define MAX_GROCERIES 100

struct Transaction {
    int transaction_id;
    int grocery_id;
    int customer_id;
    char date_of_purchase[11];
    float total_payment;
};
struct Customer {
    int customer_id;
    char name[50];
    char city[50];
    char phone_number[15];
};
struct Grocery {
    int grocery_id;
    char grocery_type[50];
    float price;
};

struct Grocery Groceries[MAX_GROCERIES];
int grocery_count = 0;

struct Transaction transactions[MAX_TRANSACTIONS];
int transaction_count = 0;

 

struct Customer customers[MAX_CUSTOMERS];
int customer_count = 0;

void add_transaction() {
    if (transaction_count == MAX_TRANSACTIONS) {
        printf("Cannot add more transactions. Maximum limit reached.\n");
        return;
    }
    printf("Enter transaction id: ");
    scanf("%d", &transactions[transaction_count].transaction_id);
    printf("Enter grocery id: ");
    scanf("%d", &transactions[transaction_count].grocery_id);
    printf("Enter customer id: ");
    scanf("%d", &transactions[transaction_count].customer_id);
    printf("Enter date of purchase (dd/mm/yyyy): ");
    scanf("%s", transactions[transaction_count].date_of_purchase);
    printf("Enter total payment: ");
    scanf("%f", &transactions[transaction_count].total_payment);
    transaction_count++;
    printf("Transaction added successfully!\n");
}

void add_customer() {
    if (customer_count == MAX_CUSTOMERS) {
        printf("Cannot add more customers. Maximum limit reached.\n");
        return;
    }
    printf("Enter customer id: ");
    scanf("%d", &customers[customer_count].customer_id);
    printf("Enter name: ");
    scanf("%s", customers[customer_count].name);
    printf("Enter city: ");
    scanf("%s", customers[customer_count].city);
    printf("Enter phone number: ");
    scanf("%s", customers[customer_count].phone_number);
    customer_count++;
    printf("Customer added successfully!\n");
}

 

void view_customer(int customer_id) {
    int found = 0;
    for (int i = 0; i < customer_count; i++) {
        if (customers[i].customer_id == customer_id) {
            printf("Customer id: %d\n", customers[i].customer_id);
            printf("Name: %s\n", customers[i].name);
            printf("City: %s\n", customers[i].city);
            printf("Phone number: %s\n", customers[i].phone_number);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Customer not found.\n");
    }
}

void view_transactions() {
    if (transaction_count == 0) {
        printf("No transactions to display.\n");
        return;
    }
    printf("Transaction details:\n");
    for (int i = 0; i < transaction_count; i++) {
        printf("Transaction id: %d\n", transactions[i].transaction_id);
        printf("grocery id: %d\n", transactions[i].grocery_id);
        printf("Customer id: %d\n", transactions[i].customer_id);
        printf("Date of purchase: %s\n", transactions[i].date_of_purchase);
        printf("Total payment: %.2f\n", transactions[i].total_payment);
        printf("\n");
    }
}

 

void search_customer() {
    int customer_id;
    char name[50];
    printf("Enter customer id or name to search: ");
    scanf("%s", name);
    if (sscanf(name, "%d", &customer_id) == 1) {
        view_customer(customer_id);
    } else {
        int found = 0;
        for (int i = 0; i < customer_count; i++) {
            if (strcmp(name, customers[i].name) == 0) {
                printf("Customer id: %d\n", customers[i].customer_id);
                printf("Name: %s\n", customers[i].name);
                printf("City: %s\n", customers[i].city);
                printf("Phone number: %s\n", customers[i].phone_number);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Customer not found.\n");
        }
    }
}

 

void add_grocery() {
    if (grocery_count == MAX_GROCERIES) {
        printf("Cannot add more grocery. Maximum limit reached.\n");
        return;
    }
    printf("Enter grocery id: ");
    scanf("%d", &Groceries[grocery_count].grocery_id);
    printf("Enter grocery type: ");
    scanf("%s", Groceries[grocery_count].grocery_type);
    printf("Enter price: ");
    scanf("%f", &Groceries[grocery_count].price);
    grocery_count++;
    printf("grocery added successfully!\n");
}

 

 

void view_grocery(int id, char type[]) {
    int found = 0;
    for (int i = 0; i < grocery_count; i++) {
        if (id != -1 && Groceries[i].grocery_id != id) {
            continue;
        }
        if (strlen(type) != 0 && strcmp(Groceries[i].grocery_type, type) != 0) {
            continue;
        }
        printf("Groceriy id: %d\n", Groceries[i].grocery_id);
        printf("Grocery type: %s\n", Groceries[i].grocery_type);
        printf("Price: %.2f\n", Groceries[i].price);
        found = 1;
    }
    if (!found) {
        printf("Grocery not found.\n");
    }
}
 

void search_grocery() {
    int grocery_id;
    char grocery_type[50];
    printf("Enter Grocery id (Enter -1 to skip): ");
    scanf("%d", &grocery_id);
    printf("Enter package type (Leave empty to skip): ");
    scanf("%s", grocery_type);
    view_grocery(grocery_id, grocery_type);
}

 

void main_menu() {
    int choice;
    while (1) {
         printf("***********************************\n");
 printf("   Welcome to the Grocery Shop Management system \n");
 printf("***********************************\n");
       // printf("Grocery Shop  Management System\n");
        printf("1. Add customer\n");
        printf("2. Search customer\n");
        printf("3. Add transaction\n");
        printf("4. View transactions\n");
         printf("5. Add Grocery\n");
        printf("6. Search grocery\n");
        printf("7. Report for transactiondetails and customerdetails \n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        printf("\n\n***********************************\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_customer();
                break;
            case 2:
                search_customer();
                break;
            case 3:
                add_transaction();
                break;
            case 4:
                view_transactions();
                break;
            case 5:
               add_grocery();
                break;
            case 6:

                search_grocery();
                break;
            case 7:

                search_grocery();
                break;
            case 8:
              exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}
int main() {
    main_menu();
    return 0;
}