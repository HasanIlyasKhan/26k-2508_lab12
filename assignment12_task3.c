#include <stdio.h>
#include <stdlib.h>

int containsDigit(char *str);

int main(){
    int N,i,j,index;
    printf("Enter the value of N :");
    scanf("%d",&N);
    char **arr = (char**)malloc(N*sizeof(char*));
    char **only_alpha = (char**)malloc(N*sizeof(char*));
    for(i=0; i<N; i++){
        arr[i] = (char*)malloc(100*sizeof(char));
        only_alpha[i] = (char*)malloc(100*sizeof(char));
    }
    for(i=0; i<N; i++){
        printf("Enter your username :");
        scanf("%99s",arr[i]);
    }
    index = 0;
    for(i=0; i<N; i++){
        if(containsDigit(arr[i]) == 0){
            for(j=0; arr[i][j]!='\0'; j++){
                only_alpha[index][j] = arr[i][j];
            }
            only_alpha[index][j] = '\0';
            index++;
        }
    }

    printf("Usernames without digits:\n");
    for(i=0; i<index; i++){
        printf("%s\n",only_alpha[i]);
    }
    return 0;
}

int containsDigit(char *str){
    int i;
    for(i=0; str[i]!='\0'; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            return 1;
        }
    }
    return 0;
}