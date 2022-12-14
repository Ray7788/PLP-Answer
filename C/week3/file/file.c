#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// declare constant MAX_SIZE as 100
#define MAX_SIZE 100

// forward declaration of functions
char *read_file(char *filename);

void delete(char *string, char *word);

int main(int argc, char **argv){

    char *f;
    char *w;
    // allocate string variables for commandline arguments
    f = malloc(MAX_SIZE);
    if (!f) return -1;
    f = argv[1];

    w = malloc(MAX_SIZE);
    if (!w) return -1;
    w = argv[2];

    // file_contents stores the entire file as a single string
    char *file_contents = read_file(f);
    if (!file_contents){
        printf("Error reading file.\n");
        return -1;
    }

    // delete every occurrence of word w in file_contents
    delete(file_contents, w);

    // create new file with given filenale + "-processed" as filename
    int fd1 = open(strcat(f,"-processed"), O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
    if (!fd1){
        printf("Error with open\n");
        return -1;
    }

    // write the modified string into the new file
    if(write(fd1, file_contents, strlen(file_contents)) != strlen(file_contents)) {
        printf("issue writing\n");
        close(fd1); return -1;
    }

    // close the file after writing to it
    close(fd1);
    // free the dynamically allocated memory before exiting
    free(file_contents);
    free(f);
    free(w);

    return 0;
}

// reads the file of given filename, and returns the contents of it as a string
char *read_file(char *filename){
    // we use fopen here to use utility like fseek()
    // as we need to find how long the length of file is for malloc()
    FILE *file;
    file = fopen(filename, "r");
    if (!file) return NULL;

    // Move the file pointer to the end of the file
    fseek(file, 0, SEEK_END);

    // ftell(file) will return the current value of the position indicator,
    // which give us the number of characters in the file
    int length = ftell(file);
    char *string = malloc(length * sizeof(char));

    // move the pointer back to the start of the file to start reading characters
    fseek(file, 0, SEEK_SET);

    // read each character in file to c, and put c into the allocated array
    char c;
    int i = 0;
    while( (c = fgetc(file)) != EOF){
        string[i] = c;
        i++;
    }
    // make sure to add the termination character at the end of string
    string[i] = '\0';
    // close the file as we no longer need access to it
    fclose(file);
    // return the resulting string read from the file
    return string;
}

// removes all instances of given word from given string
void delete(char *string, char *word){
  // i is used to loop through the string
  int i = 0;

  // store the lengths of the given string and word
  int string_length = strlen(string);
  int substr_length = strlen(word);

  // loop through the string, keeping track of our current index with i
  while (i < string_length)
  {
    // if we find the given word at the current index, delete it
    // strstr returns the first occurrence of given substring in given string
    // or NULL if not found
    if (strstr(&string[i], word) == &string[i])
    {
      // calculate new length of string after removing the word from it
      string_length -= substr_length;

      // shift forward the remaining characters in the string after the substr
      // occurrence by the length of substr, effectively removing it!
      for (int j = i; j < string_length; j++)
        string[j] = string[j + substr_length];
    }
    else i++;
  }

  // put a null terminator at the end of the string
  string[i] = '\0';
}
 
// check50 -l --ansi-log olivierpierre/comp26020-problems/2022-2023/week3-c-pointers-stdlib/08-file
