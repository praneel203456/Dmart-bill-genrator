#include <stdio.h>

int main() {
    int id, n, i;
    char name[50], phone[15], custType;
    float price[50], total = 0, discount = 0, gst,netAmount;
    char item[50][50];
    int qty[50];
    printf("=== DMART SUPERSTORE BILL GENERATOR ===\n");
    printf("Enter Customer ID: ");
    scanf("%d", &id);
    printf("Enter Customer Name: ");
    scanf("%s", name);
    printf("Enter Customer Telephone Number: ");
    scanf("%s", phone);
    printf("Enter Customer Type (P for Premium, S for Standard): ");
    scanf(" %c", &custType);
    printf("Enter Number of Items Purchased: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nEnter Item %d Name: ",i+1);
        scanf("%s", item[i]);
        printf("Enter Quantity: ");
        scanf("%d", &qty[i]);
        printf("Enter Price per unit: ");
        scanf("%f", &price[i]);
        total += qty[i] * price[i];
    }
    if (custType == 'P') {
        discount = total * 0.10; // 10% off
        total -= discount;
    }
    gst=total*0.18;
    netAmount=total+gst;
    printf("\n----------------------------------------\n");
    printf("           DMART SUPERSTORE BILL\n");
    printf("----------------------------------------\n");
    printf("Customer ID: %d\n", id);
    printf("Customer Name: %s\n", name);
    printf("Phone Number: %s\n", phone);
    printf("Customer Type: %s\n", (custType=='P' || custType=='p') ? "Premium" : "Standard");
    printf("----------------------------------------\n");
    printf("Item\tQty\tPrice\tTotal\n");
    printf("----------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%s\t%d\t%.2f\t%.2f\n", item[i], qty[i], price[i], qty[i] * price[i]);
    }

    printf("----------------------------------------\n");
    if (discount > 0)
        printf("Premium Discount: -%.2f\n", discount);
    printf("Sub Total: %.2f\n", total);
    printf("GST (18%%): %.2f\n", gst);
    printf("Grand Total: %.2f\n", netAmount);
    printf("----------------------------------------\n");
    printf("   Thank you for shopping at DMart!\n");
     printf("             VISIT AGAIN :)       \n");
    printf("----------------------------------------\n");
    return 0;
}



