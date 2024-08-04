#include <stdio.h>

//Defining strucuture named Product
struct Product {
    char p_name[100];
    char p_id[10];
    float p_price;
};

int main() {
    int num;
    printf("Enter the number of products: ");
    scanf("%d", &num);

    struct Product products[num];
//Insert Data
    for (int i = 0; i < num; i++) {
        printf("\nEnter details for product %d:\n", i + 1);
        printf("Product Name: ");
        scanf("%s", products[i].p_name);
        printf("Product ID: ");
        scanf("%s", products[i].p_id);
        printf("Price: ");
        scanf("%f", &products[i].p_price);
    }
//Printing data
    printf("Product Details:\n");
    for (int i = 0; i < num; i++) {
        printf("Product Name: %s, Product ID: %s, Price: %.2f\n", products[i].p_name, products[i].p_id, products[i].p_price);
    }

    float totalCost = 0;
    float maxPrice = products[0].p_price;
    float minPrice = products[0].p_price;
    int maxIndex = 0;
    int minIndex = 0;
//For max and min 
    for (int i = 1; i < num; i++) {
        totalCost += products[i].p_price;
        if (products[i].p_price > maxPrice) {
            maxPrice = products[i].p_price;
            maxIndex = i;
        }
        if (products[i].p_price < minPrice) {
            minPrice = products[i].p_price;
            minIndex = i;
        }
    }
//Calculate total cost
    totalCost += products[0].p_price;

    printf("\nMost Expensive Product: %s, Product ID: %s, Price: %.2f\n", products[maxIndex].p_name, products[maxIndex].p_id, products[maxIndex].p_price);
    printf("Least Expensive Product: %s, Product ID: %s, Price: %.2f\n", products[minIndex].p_name, products[minIndex].p_id, products[minIndex].p_price);
    printf("\nTotal Cost of All Products: %.2f\n", totalCost);

    return 0;
}