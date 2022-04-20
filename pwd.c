#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define PATH "pw_save.txt"

char *gen_pw(void) {
    int input;
    printf("Please Enter the Lengh of the Password:(max 100) ");
    scanf("%d", &input);
    if(input > 100){
        printf("to many letters");
        exit(0);
    }
    char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789#*+!&?=()/$";
    static char string[100];

    srand(time(NULL));
    for(int x = 0; x < input; x++) {
        string[x] = letters[rand() % 66];
    }

    return string;
}

int main(int argc, char *argv[]) {

    int input;
    char buffer[100];
    if(argc == 1) {
        printf("%s\n", gen_pw());
        return 0;
    }

    if(argc == 2) {
        if(strcmp(argv[1], "-help") == 0) {
            printf("./file <parameter> <Keyword>\n\n");
            printf(" -s -> Save the Keyword\n");
            printf(" -p -> Print the Keyvalue\n");
            return 0;
        }
        if(strcmp(argv[1], "-s") == 0) {
            printf("Please Enter a Keyword to save!\n");
            printf("./file <parameter> <Keyword>\n\n");
            printf(" -s -> Save the Keyword\n");
            printf(" -p -> Print the Keyvalue\n");
            return 0;
        } else if(strcmp(argv[1], "-p") == 0) {
            printf("Please Enter a Keyword to show!\n");
            printf("./file <parameter> <Keyword>\n\n");
            printf(" -s -> Save the Keyword\n");
            printf(" -p -> Print the Keyvalue\n");
            return 0;
        }
        else {
            printf("No Parameter we could look for!\n");
            printf("./file <parameter> <Keyword>\n\n");
            printf(" -s -> Save the Keyword\n");
            printf(" -p -> Print the Keyvalue\n");
            return 0;
        }
    }
    
    if(argc == 3) {
        if(strcmp(argv[1], "-s") == 0) {
            char *pw;
            pw = gen_pw();
            FILE *file;
            if((file = fopen(PATH, "a")) == NULL) {
                printf("Error with opening the File(1)\n");
                return 0;
            }
            fprintf(file, "%s\n", argv[2]);
            fprintf(file, "%s\n", pw);
            printf("%s\n", pw);
            close(file);
        } if(strcmp(argv[1], "-p") == 0) {
            FILE *file;
            if((file = fopen(PATH, "r")) == NULL) {
                printf("Error with opening File!(2)\n");
                return 0;
            }

            char look[50];
            strcpy(look, argv[2]);
            strcat(look, "\n");
            while(fgets(buffer, sizeof(buffer), file)) {
                if(strcmp(look, buffer) == 0) {
                    fgets(buffer, sizeof(buffer), file);
                    printf("%s", buffer);
                }
            }

            close(file);
        }
    }
    return 0;
}