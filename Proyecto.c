#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

void executeCommand(char *command, char *argumentArray[]){
    execvp(command, argumentArray);
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
    fgets(input, sizeof(input), stdin);
    
    readLine(input);
}

int main(){
   readUserInput();
}