/**
* Fixes for the variant gcc -std=c99 -Wall
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
char array1[] = "Foo" "bar";
char array2[] = { 'F', 'o', 'o', 'b', 'a', 'r', '\0' };
 
enum { BUFFER_MAX_SIZE = 1024 };


const char* s1 = "\nHello\nWorld\n";
const char* s2 = "\nHello\nWorld\n";

int gets_example_func(void) {
  char buf[BUFFER_MAX_SIZE];
 
  if (fgets(buf, sizeof(buf), stdin) == NULL) {
        return 1;
  }
  buf[strlen(buf) - 1] = '\0';
  return 0;
}

const char *get_dirname(const char *pathname) {
  char *slash;
  slash = strrchr(pathname, '/');
  if (slash) {
    *slash = '\0'; /*Undefined behavior*/
  }
  return pathname;
}

void get_y_or_n(void) {  
	char response[8];

	printf("Continue? [y] n: ");  
	fgets(response, sizeof(response), stdin);

	if (response[0] == 'n') 
		exit(0);  

	return;
}


int main(int argc, char *argv[])
{
    char key[24];
    //char *key = malloc(sizeof(argv[1])+sizeof(argv[2]+3*sizeof(char)));
    char response[8];
    char array3[16];
    char array4[16];
    char array5 []  = "01234567890123456";
    char *ptr_char  = "new string literal";

   // char analitic1[size_array1]="аналитик";
   // char analitic2[size_array2]="аналитик";



    puts(get_dirname(__FILE__));

    strcpy(key, argv[1]);  
    strcat(key, " = ");  
    strcat(key, argv[2]);

    fgets(response,sizeof(response),stdin);
    
    get_y_or_n();

    printf ("%s",array1);
    printf ("\n");
    printf ("%s",array2);
    printf ("\n");
 
    puts (s1);
    printf ("\n");
    puts (s2);
    printf ("\n");
    
    strncpy(array3, array5, sizeof(array3));  
    strncpy(array4, array3, strlen(array3));
    
    array5 [0] = 'M';

    ptr_char [0] = 'N';
    
    array3[sizeof(array3)-1]='\0';
    
    
    return 0;
}

