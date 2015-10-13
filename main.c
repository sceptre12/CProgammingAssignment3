#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

//Function Declaration area
int getNumbersFromFile(char *arr[], int arrlen);
int accendingOrder(char *arr[],int size,FILE *fp);
// void changeCharArrToIntArr(char *arr[], int size);
int sumOfAllOddNumbers(char *arr[], int size,FILE *fp);
int numOfEvenValues(char *arr[], int size,FILE *fp);

int main(int argc, char *argv[]){
    char *numbers[100];
    int err = 0, arrlen = 100, count=0, maxFilled = 0;
    FILE *fp;

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
        printf("Reached\n" );
      }
    }

    printf("Max Filled %d\n",maxFilled );
    err = accendingOrder(numbers,maxFilled,fp);
    err = sumOfAllOddNumbers(numbers,maxFilled,fp);
    err = numOfEvenValues(numbers,maxFilled,fp);
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
int getNumbersFromFile(char *arr[], int arrlen){
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
        token = strtok(readStorage," ");
        int index = 0;
        while(token != NULL){
          // Personal Validators
          /*
            Okay so in C When you create an array ex: char  *test[50];
            you've actually created a pointer array of chars that point to nothing;
            in order for you to assign a string to the indexes you need to first
            allocate memory to hold that string the use strcpy to copy the string
            over. (you could do the long way but why!!);
          */
          printf("The Number from file %s\n", token);
          arr[index] = malloc(strlen(token) + 1);
          strcpy(arr[index], token);
          index = index + 1;
          token = strtok(NULL, " ");
        }
    }

    // Closes the file
    fclose(fp);
    return 0;
  }
  return -1;
}

int accendingOrder(char *arr[], int size, FILE *fp){
  int count = 0;
  int accendingindex[size];
  while(arr[count] != NULL){
    // printf("%s\n", arr[count]);
    // printf("Determines the Number\n");
    accendingindex[count] = atoi(arr[count]);
    // printf("%d\n\n", atoi(arr[count]));
    count = count + 1;
    if(arr[count] == NULL){
      printf("Reached \n" );
    }
  }
  int loop;
  for (count = 0; count < size -1 ; count = count + 1) {
    for (loop = 0; loop < size -1 ; loop = loop + 1) {
        if(accendingindex[count] < accendingindex[loop]){
          int tempInt = accendingindex[count];
          accendingindex[count]= accendingindex[loop] ;
          accendingindex[loop] = tempInt;
        }
    }
  }

  // get currentDirectory
  char path[1024];
  if(getcwd(path,sizeof(path)) != NULL){
    char filename[40];

    // Concatenates chars
    strcpy(filename, "/output.txt");
    strcat(path, filename);

    //Opens file
    fp = fopen(path,"a+");
    fprintf(fp,"%s\n", "Output in Accending Order");
    for(loop = 0; loop < size -1 ; loop = loop +1){
      fprintf(fp,"%d ", accendingindex[loop] );
    }
    fprintf(fp, "\n");
    fclose(fp);
    return 0;
  }else{
      return -1;
  }
}

int sumOfAllOddNumbers(char *arr[], int size, FILE *fp){
  int count = 0;
  int accendingindex[size];
  while(arr[count] != NULL){
    // printf("%s\n", arr[count]);
    // printf("Determines the Number\n");
    accendingindex[count] = atoi(arr[count]);
    // printf("%d\n\n", atoi(arr[count]));
    count = count + 1;
    if(arr[count] == NULL){
      printf("Reached \n" );
    }
  }
  int loop;
  for (count = 0; count < size -1 ; count = count + 1) {
    for (loop = 0; loop < size -1 ; loop = loop + 1) {
        if(accendingindex[count] < accendingindex[loop]){
          int tempInt = accendingindex[count];
          accendingindex[count]= accendingindex[loop] ;
          accendingindex[loop] = tempInt;
        }
    }
  }

  // get currentDirectory
  char path[1024];
  if(getcwd(path,sizeof(path)) != NULL){
    char filename[40];

    // Concatenates chars
    strcpy(filename, "/output.txt");
    strcat(path, filename);

    //Opens file
    fp = fopen(path,"a+");
    fprintf(fp,"%s\n", "Sum Of All Odd Values");
    int odd = 0;
    for(loop = 0; loop < size -1 ; loop = loop +1){
      if(accendingindex[loop] % 2 != 0){
        odd = odd + accendingindex[loop];
      }
    }
    fprintf(fp,"%d\n", odd);
    fclose(fp);
    return 0;
  }else{
      return -1;
  }
}

int numOfEvenValues(char *arr[], int size, FILE *fp){
  int count = 0;
  int accendingindex[size];
  while(arr[count] != NULL){
    // printf("%s\n", arr[count]);
    // printf("Determines the Number\n");
    accendingindex[count] = atoi(arr[count]);
    // printf("%d\n\n", atoi(arr[count]));
    count = count + 1;
    if(arr[count] == NULL){
      printf("Reached \n" );
    }
  }
  int loop;
  for (count = 0; count < size -1 ; count = count + 1) {
    for (loop = 0; loop < size -1 ; loop = loop + 1) {
        if(accendingindex[count] < accendingindex[loop]){
          int tempInt = accendingindex[count];
          accendingindex[count]= accendingindex[loop] ;
          accendingindex[loop] = tempInt;
        }
    }
  }

  // get currentDirectory
  char path[1024];
  if(getcwd(path,sizeof(path)) != NULL){
    char filename[40];

    // Concatenates chars
    strcpy(filename, "/output.txt");
    strcat(path, filename);

    //Opens file
    fp = fopen(path,"a+");
    fprintf(fp,"%s\n", "Number of Even Values Stored");
    int count = 0;
    for(loop = 0; loop < size  -1 ; loop = loop +1){
      if(accendingindex[loop] % 2 == 0){
        count = count + 1;
      }
    }
    fprintf(fp,"%d\n", count);
    fclose(fp);
    return 0;
  }else{
      return -1;
  }
}
