#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getCategory(char ch);

int main(){
    int n,i,j;
    int max = 0;
    int max_index = 0;
    printf("Enter number of participants :");
    scanf("%d",&n);
    char *pattern = (char*)malloc(100*sizeof(char));
    printf("Enter password pattern :");
    scanf("%99s",pattern);
    char **password = (char**)malloc(n*sizeof(char*));
    for(i=0; i<n; i++){
        password[i] = (char*)malloc(100*sizeof(char));
    }
    for(i=0; i<n; i++){
        int count = 0;
        printf("Enter password %d :",i+1);
        scanf("%99s",password[i]);
        int pattern_length = strlen(pattern);
        for(j=0; j<pattern_length; j++){
            if(getCategory(pattern[j]) == getCategory(password[i][j])){
                count++;
            }
        }
        int similarity = (count * 100) / pattern_length;
        printf("Password : %s\n",password[i]);
        printf("Similarity : %d%%\n\n",similarity);
        if(similarity > max){
            max = similarity;
            max_index = i;
        }
    }

    printf("Highest Similarity Password : %s\n",password[max_index]);
    printf("Similarity : %d%%\n",max);
    for(i=0; i<n; i++){
        free(password[i]);
    }
    free(password);
    free(pattern);
    return 0;
}

int getCategory(char ch){
    if(ch >= 'A' && ch <= 'Z'){
        return 1;
    }
    if(ch >= 'a' && ch <= 'z'){
        return 2;
    }
    if(ch >= '0' && ch <= '9'){
        return 3;
    }
    return 4;
}