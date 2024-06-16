#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

bool inputValidation(char program[], char arguments[], int size){
    if((int) program[0] < 65 || (int) program[0] > 122){
        return 0;
    }

    return 1;
}

void executeCommand(char *command, char *argumentArray[]){

    if(execvp(command, argumentArray) == -1){
        exit(0);
    }
}

void readLine(char input[]){ 
    char *argumentArray[20];
    int argumentIndex = 0;
    char *argument = strtok(input, " \n");
    argumentArray[argumentIndex] = argument;
    argumentIndex++;

    if(argument != NULL){
        while(argument != NULL){
            argument = strtok(NULL, " \n");
            argumentArray[argumentIndex] = argument;
            argumentIndex++;
        }
    }

    if(inputValidation(argumentArray[0], argumentArray, argumentIndex)){
        pid_t child = fork();
        if(child == 0){
            if(argumentIndex == 1){
                executeCommand(argumentArray[0], NULL);
            }
            else{
                executeCommand(argumentArray[0], argumentArray);
            }
        }
        else{
            wait(NULL);
        }
    }
    else{
        printf("ERROR: Invalid command. \n");
    }
}

void readUserInput(){
    char input[200];
    while(1){
        fgets(input, sizeof(input), stdin);
        if(strcmp(input, "salir\n") != 0){
            readLine(input);
        }
        else{
            printf("Finishing...\n");
            return;
        }
    }
}
int main(){
   readUserInput();
}