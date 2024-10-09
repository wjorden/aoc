#include <stdio.h>
#include <stdint.h>

/**
 * general plan:
 * Set Santa's starting point (0)
 * Read in data file (day1-input.txt)
 * Add/Sub a floor based on data
 * Count positions while traversing
 * if Santa goes to -1, stop and return position
*/
int main(void){
    int santasFloor = 0;
    int position = 0;
    FILE *data = fopen("day1-input.txt", "r");
    
    if (data == NULL){
        printf("Failed to read file!\n");
        return 1;
    } else {
        int ch;
        printf("Santa is starting at floor: %d\n", santasFloor);
        while((ch = fgetc(data)) != EOF){
            if(ch == '('){
                santasFloor++;
                position++;
            } else if (ch == ')'){
                santasFloor--;
                position++;
            } else {
                continue;
            }
            if(santasFloor == -1){
                printf("Position: %d", position);
                 break;
            }
        }
    printf("Santa ended on: %d\n", santasFloor);
    }

    return 0; // Santa made it
}
