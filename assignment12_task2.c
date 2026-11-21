#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char **feedback;
    char *longest;
    int n, i, total = 0;
    int longest_length = 0;
    printf("Enter number of feedback entries: ");
    scanf("%d",&n);
    feedback = (char**)malloc(n * sizeof(char*));
    for(i=0; i<n; i++){
        feedback[i] = (char*)malloc(100 * sizeof(char));
        printf("Enter feedback %d: ", i+1);
        scanf(" %[^\n]", feedback[i]);
        total = total + strlen(feedback[i]);
        if(strlen(feedback[i]) > longest_length){
            longest_length = strlen(feedback[i]);
            longest = feedback[i];
        }
    }
    printf("\nAll Feedback Entries:\n");
    for(i=0; i<n; i++){
        printf("%s\n", feedback[i]);
    }
    printf("\nTotal Characters: %d\n", total);
    printf("Longest Feedback: %s\n", longest);
    for(i=0; i<n; i++){
        free(feedback[i]);
    }
    free(feedback);
    return 0;
}