#include <stdio.h>
#include <string.h>
#include "item.h"

#define MAX_PRODUCTS 100

int main()
{
    // get the product details
    item 
    thing[MAX_PRODUCTS];
    int i=0;
    float totalPrice=0;

    while (1)
    {

        // Taking the input from user
        printf("Enter the item name : ");
        fgets(thing[i].itemName, 50, stdin);

        printf("Enter the price : ");
        scanf("%f", &thing[i].price);

        printf("Enter the quantity : ");
        scanf("%d", &thing[i].quantity);

        // calculating the sub-total price
        thing[i].subTotal = (float)thing[i].quantity * thing[i].price;

        // calculating total price
        totalPrice+= thing[i].subTotal;

        // checking for loop continuation 
        printf("Do you want to enter details for another item (y/n)? ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N')
        {
            break;
        }

        i++;
        getchar();
    }


    // Calculate discount based on total price
    float discount, discountPrice;
    if (totalPrice > 10000) {
        discountPrice = 0.2 * totalPrice;
        discount=20;
    } else if (totalPrice >= 5001) {
        discountPrice = 0.15 * totalPrice;
        discount=15;
    } else if (totalPrice >= 2501) {
        discountPrice = 0.1 * totalPrice;
        discount=10;
    } else if (totalPrice >= 1000) {
        discountPrice = 0.05 * totalPrice;
        discount=5;
    } else {
        discountPrice = 0;
        discount=0;
    }

    // Calculate grand total
    float grandTotal = totalPrice - discountPrice;

    //printing table heading 
    printf("+-----------------------------------------------+\n");
    printf("|  Item         | Quantity | Price | Sub-total  |\n");
    printf("|---------------|----------|-------|------------|\n");

    //printing the products and it's details
    int j=0;
    while(j<=i){
         thing[j].itemName[strcspn(thing[j].itemName, "\n")] = 0;
        printf("| %-13s | %-8d | %-5.0f | %-11.0f|\n",thing[j].itemName,thing[j].quantity,thing[j].price,thing[j].subTotal);
        printf("|---------------|----------+-------|------------|\n");
        j++;
    }

    //printing total, discount and grand total
    printf("| Total %*s | %*s | %-10.0f |\n", -7," ", -16," ", totalPrice );
    printf("|---------------|----------+-------|------------|\n");
    printf("| %*s | Discount | %4.0f%% | -%-9.0f |\n", -13," ",  discount,discountPrice);
    printf("|---------------|----------+-------|------------|\n");
    printf("| Grand Total   | %*s | %-10.0f |\n", -16," ", grandTotal);
    printf("+-----------------------------------------------+\n");
    printf("\n");

    return 0;
}


