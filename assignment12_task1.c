#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int num_category,i,total,lowest;
    total = 0;
    printf("Enter number of category :");
    scanf("%d",&num_category);
    int *arr = (int*)malloc(num_category * sizeof(int));
    for (i=0; i<num_category; i++){
        printf("Enter stock quantity :");
        scanf("%d",&arr[i]);
    }
    lowest = arr[0];
    for(i=0; i<num_category; i++){
        total = total + arr[i];
        if (arr[i] < lowest){
            lowest = arr[i];
        }
    }
    float avg = (float)total / num_category;
    printf("Total :%d",total);
    printf("Avg :%0.2f",avg);
    printf("Lowest :%d",lowest);
    int index, update;
    printf("Enter category index to update :");
    scanf("%d",&index);
    printf("Enter new stock quantity :");
    scanf("%d",&update);
    arr[index] = update;
    printf("Updated stock : %d",arr[index]);
    free(arr);
    return 0;
}