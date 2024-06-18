#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

int executeCommand(char *command, char *argumentArray[]){

    return execvp(command, argumentArray);
}

int executeProgram(char *arguments[], int size){
    pid_t child = fork();
    if(child == 0){
        if(size == 1){
            return executeCommand(arguments[0], NULL);
        }
        else{
            return executeCommand(arguments[0], arguments);
        }
    }
    else{
        wait(NULL);
    }
}

void readLine(char input[], pid_t mainProcess){ 
    char *argumentArray[20];
    char *argumentsFirstProgram[20];
    char *argumentsSecondProgram[20];
    int positionOfOperator = 0;
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

    for(int i = 0; i < argumentIndex -1; i++){
        if(strcmp(argumentArray[i], "|") == 0 || strcmp(argumentArray[i], "||") == 0 || strcmp(argumentArray[i], "&&") == 0){
            positionOfOperator = i;
            argumentsFirstProgram[i] = NULL;
            break;
        }
        argumentsFirstProgram[i] = argumentArray[i];
    }

    if(positionOfOperator != 0){
        for(int i = positionOfOperator + 1, j = 0; i < argumentIndex - 1; i++, j++){
            argumentsSecondProgram[j] = argumentArray[i];
        }
    }

    int sizeOfFirstProgram = positionOfOperator;
    int sizeOfSecondProgram = argumentIndex - positionOfOperator -2;
    argumentsSecondProgram[sizeOfSecondProgram] = NULL;
    
    if(positionOfOperator == 0){
        if(executeProgram(argumentArray, argumentIndex) == -1){
            printf("ERROR: Invalid command.\n");
            exit(0);
        }
    }
    else if(strcmp(argumentArray[positionOfOperator], "|") == 0){
        //Pipe
    }
    else if(strcmp(argumentArray[positionOfOperator], "||") == 0){
        if(executeProgram(argumentsFirstProgram, sizeOfFirstProgram) == -1){
            printf("ERROR: Invalid command.\n");

            if(executeProgram(argumentsSecondProgram, sizeOfSecondProgram) == -1){
                printf("ERROR: Invalid command.\n");
                exit(0);
            }
            exit(0);
        }
    }
    else if(strcmp(argumentArray[positionOfOperator], "&&") == 0){
        int tuberia[2];
        pipe(tuberia);
        char *returnValue = malloc(sizeof(char) * 2);

        executeProgram(argumentsFirstProgram, sizeOfFirstProgram);

        if(getppid() == mainProcess){
            close(tuberia[0]);
            write(tuberia[1], "!", sizeof(char) * 2);
            close(tuberia[1]);
            printf("ERROR: Invalid command.\n");
            exit(0);
        }
        else{
            wait(NULL);
            close(tuberia[1]);
            read(tuberia[0], returnValue, sizeof(char) * 2);
            close(tuberia[0]);
        }

        if(strcmp(returnValue, "!") != 0){
            if(executeProgram(argumentsSecondProgram, sizeOfSecondProgram) == -1){
                printf("ERROR: Invalid command.\n");
                exit(0);   
            }
        }
    }
}

void readUserInput(){
    pid_t mainProcess = getpid();
    char input[200];
    while(1){
        fgets(input, sizeof(input), stdin);
        if(strcmp(input, "salir\n") != 0){
            readLine(input, mainProcess);
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