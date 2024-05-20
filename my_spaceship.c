#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

char* my_spaceship(char* param_1) {
    int x = 0;
    int y = 0;
    char initial[6]; 
    strcpy(initial, "up");
    char* formal = malloc(2 * MAX + 10);  

    for(int i = 0; param_1[i] != '\0'; i++) {
        if (param_1[i] == 'R') {
            if (strcmp(initial, "up") == 0) {
                strcpy(initial, "right");
            } else if (strcmp(initial, "right") == 0) {
                strcpy(initial, "down");
            } else if (strcmp(initial, "down") == 0) {
                strcpy(initial, "left");
            } else if (strcmp(initial, "left") == 0) {
                strcpy(initial, "up");
            }
        } else if (param_1[i] == 'L') {
           
            if (strcmp(initial, "up") == 0) {
                strcpy(initial, "left");
            } else if (strcmp(initial, "left") == 0) {
                strcpy(initial, "down");
            } else if (strcmp(initial, "down") == 0) {
                strcpy(initial, "right");
            } else if (strcmp(initial, "right") == 0) {
                strcpy(initial, "up");
            }
        } else if (param_1[i] == 'A') {
            if (strcmp(initial, "up") == 0) {
                y--;
            } else if (strcmp(initial, "down") == 0) {
                y++;
            } else if (strcmp(initial, "left") == 0) {
                x--;
            } else if (strcmp(initial, "right") == 0) {
                x++;
            }      
        }
    }

    for (int i = 0; param_1[i] != '\0'; i++) {
        if (param_1[i] != 'R' && param_1[i] != 'L' && param_1[i] != 'A') {
            free(formal);
            return NULL;   
        }
    }

    sprintf(formal, "{x: %d, y: %d, direction: '%s'}", x, y, initial); 
    return formal;
}