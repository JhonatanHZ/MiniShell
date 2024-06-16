#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

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

    if(argumentIndex == 1){
        executeCommand(argumentArray[0], NULL);
    }
    else{
        executeCommand(argumentArray[0], argumentArray);
    }
}

void readUserInput(){
    char input[200];
    pid_t child;
    while(1){
        fgets(input, sizeof(input), stdin);
        if(strcmp(input, "salir\n") != 0){
            child = fork();
            if(child == 0){
                readLine(input);
            }
            else{
                wait(NULL);
            }
        }
        else{
            return;
        }
    }
}
int main(){
   readUserInput();
}