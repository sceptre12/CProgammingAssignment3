#include <stdio.h>
#include <unistd.h>
#include <string.h>

//Function Declaration area
int getNumbersFromFile(char *arr[256], int arrlen);
int accendingOrder(char *arr[11],int size);

int main(int argc, char *argv[]){
    char *numbers[256];
    int err = 0, arrlen = 256, count=0, maxFilled = 0;;

    /*
      TODO Figure out a way to reduce the size of the char *arr[256]
      I need this to be off size 11 so how do I reduce its memory
    */
    err = getNumbersFromFile(numbers, arrlen) + err;

    // Personal Validators
    while(numbers[count] != NULL){
      printf("%s\n", numbers[count]);
      count = count + 1;
      if(numbers[count] == NULL){
        maxFilled = count;
      }
    }

    printf("%d\n",maxFilled );
    err = accendingOrder()
    printf("\n");
    if(err > 0){
      return -1;
    }else{
      return 0;
    }
}

/*
  Gets Numbers from file, parses through string,
  stores each number in the passed in array indexes
*/
int getNumbersFromFile(char *arr[256], int arrlen){
  char path[256]; // Path to the current file
  int  arrSize = arrlen;
  if((getcwd(path,sizeof(path)) != NULL)){
    FILE *fp; // File initializer
    char fileName[20];

    /*
      Copies the String pointed to by src to dest
      char *strcpy(char *dest, const char *src);
    */
    strcpy(fileName, "/numbers.txt");

    /*
      Appends the String pointed to by src to the end of dest
      char *strcat(char *dest, const char *src);
    */
    strcat(path,fileName);

    /*
      Opens the filename pointed by using given mode
      *fopen(const char *filename, const char *mode)
      Modes:
        r: open for read, file must exists
        w: open/create file to write, if file exits, erases content,
        a: Appends to a file, file created if it does not exists,
        r+: opens file to update both reading and writing, file must exists,
        w+: created an empty file for both reading and writing,
        a+: Opens a file for reading and appending
        Returns File pointer
    */
    fp = fopen(path,"r");
    if(!fp){
      printf("File Not found");
      return -1;
    }
    /*
      Reads a line from the specified stream(file) and stores it in a string
      stops when n-1 chars are read, the newline char is read or the eof is
      reached.
      char *fgets(char *str, int n, FILE *stream)
    */
    char readStorage[arrSize];
    char delim[2] = " ";
    while(fgets(readStorage, arrSize, fp)){
      /*
        Pointers
        int *var // is a pointer variable declaration
        int test = 20; // actual variable declaration
        var = &test; // Stores address of test in pointer variable
        printing out (var) will print out the address stored in the pointer
        printing out (*var) will print out the value stored in the pointer address
      */
        char *token = NULL;
        /*
          Breaks string str into a series of tokens using the delim
          char *strtok(char *str, const char *delim)
        */
        // Personal Validators
        printf("The string %s\n", readStorage);
        token = strtok(readStorage,delim);
        int index = 0;
        while(token != NULL){
          // Personal Validators
          printf("The Number from file %s\n", token);
          arr[index] = token;
          index = index + 1;
          token = strtok(NULL,delim);
        }
    }

    // Closes the file
    fclose(fp);
    return 0;
  }
  return -1;
}


int accendingOrder(char *arr[11], int size){

}
