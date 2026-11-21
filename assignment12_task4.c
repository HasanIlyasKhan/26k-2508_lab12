#include <stdio.h>
#include <stdlib.h>

int main(){
  int num_category,i,max,total,max_index;
  total = 0;
  printf("Enter number of category :");
  scanf("%d",&num_category);
  int *ptr = (int*)malloc(num_category*sizeof(int));
  for(i=0; i<num_category; i++){
    printf("Enter the rating :");
    scanf("%d",&ptr[i]);
  }
  max = ptr[0];
  for(i=0; i<num_category; i++){
    total = total + ptr[i];
    if (ptr[i] > max){
      max = ptr[i];
      max_index = i;
    }
  }
  float avg;
  avg = (float)total / num_category;
  int index,up_count;
  printf("Enter the index you wanted to change :");
  scanf("%d",&index);
  printf("Enter updated count :");
  scanf("%d",&up_count);
  ptr[index] = up_count;
  for(i=0; i<num_category; i++){
    printf("Category %d : %d\n", i, ptr[i]);
  }
  printf("Avg :%0.2f\n",avg);
  printf("Max :%d\n",max);
  printf("Highest rating category index: %d\n", max_index);
  free(ptr);
}