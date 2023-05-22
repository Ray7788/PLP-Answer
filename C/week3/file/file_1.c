#include <stdio.h>
#include <stdlib.h>

void str_replace(char *target, const char *needle, const char *replacement)
{
    char buffer[1024] = { 0 };
    char *insert_point = &buffer[0];
    const char *tmp = target;
    size_t needle_len = strlen(needle);
    size_t repl_len = strlen(replacement);

    while (1) {
        const char *p = strstr(tmp, needle);

        // walked past last occurrence of needle; copy remaining part
        if (p == NULL) {
            strcpy(insert_point, tmp);
            break;
        }

        // copy part before needle
        memcpy(insert_point, tmp, p - tmp);
        insert_point += p - tmp;

        // copy replacement string
        memcpy(insert_point, replacement, repl_len);
        insert_point += repl_len;

        // adjust pointers, move on
        tmp = p + needle_len;
    }

    // write altered string back to target
    strcpy(target, buffer);
}


int main(int argc, char **argv) {
    FILE *fptr1, *fptr2;
    char filecontent[100];


    // open the file in directory: f
   fptr1 = fopen(argv[1], "r");
    // create a new file with f-processed
   fptr2 = fopen(strcat(argv[1],"-processed"), "w+");
    
    // a copy of c
    fgets(filecontent, 99, fptr1);
    // delete
    str_replace(filecontent, argv[2], "");


    fputs(filecontent,fptr2);

    // close 2 files
    fclose(fptr1);
    fclose(fptr2);
}
