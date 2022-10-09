/**
 *  
 * The student needs to compile, test and comment the source code file.
 * 
 * Enumerate those Rules and Recommendation associated that are broken in the 
 *     previous source code file.
 * Enumerate he compilation tools and paramenters (gcc vs g++ ), -Wall ...
 * Enumerate the standard associated  -std=c99, -std=c11
 * 
 * There are several variants. You should choose at least two. You can also try clang.
 * At the end the source code  should compile without warnings to the variant 
 *     selected (you can remove/change instructions).
 * 
 * ---------------------------------------------------------------------------
 * Broken rules (explained in the document):
 * 
 * in gcc -std=c99 and -std=c11
 * 
 * returning a value in a function that is supposed to return void
 * 
 * in g++ 
 * 
 * returning a value in a function that is supposed to return void
 * ISO C++ forbids converting a string constant to 'char*'
 * 
 * 

 * 
 * 
 * ---------------------------------------------------------------------------
 * Variants choosen for fixing the code: gcc -std=c99 -Wall and g++ -Wall
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
char array1[] = "Foo" "bar";
char array2[] = { 'F', 'o', 'o', 'b', 'a', 'r', '\0' };
 
enum { BUFFER_MAX_SIZE = 1024 };


/*
* COMPILATION WARNING AND ERRORS
* ------------------------------
* using -std=c99 and -std=c11 (the compilation gives the same result)
* warning: missing terminating " character const char* s1 = R"foo(
* error: missing terminating " character const char* s1 = R"foo(
* error: 'R' undeclared here (not in a function) const char* s1 = R"foo(
* error: expected ',' or ';' before 'Hello'
* warning: missing terminating " character )foo";
* error: missing terminating " character )foo";
* 
* R IS NOT A VALID SYNTAX FOR C
*
* This does correctly compile using g++ because R is a valid syntax using C++
*
* There are not broken recomendations or rules in this code
*
*/
const char* s1 = R"foo(
Hello
World
)foo";

/* in gcc std c99 and c11 error: 's2' undeclared. Because the previous instruction is not valid */
const char* s2 = "\nHello\nWorld\n";



/*
* COMPILATION WARNING AND ERRORS
* ------------------------------
* Using -std=c99 and -std=c11 (the compilation gives the same result) warning
* warning: 'return' with a value, in function returning void return 1;
*
* Using g++ error
* 
* error: return-statement with a value, in function returning 'void' [-fpermissive] return 1;
* 
*/

void gets_example_func(void) {
  char buf[BUFFER_MAX_SIZE];
 
  if (fgets(buf, sizeof(buf), stdin) == NULL) {
        return 1;
  }
  buf[strlen(buf) - 1] = '\0';
}

/*
* BROKEN RULES AND RECOMENDATIONS
* STR30-C. Do not attempt to modify string literals
* since the argument of strrchr points to a string literal the behavior is undefined
* 
* A possible solution could be avoiding to modify a string literal and using a char array instead
*/

const char *get_dirname(const char *pathname) {
  char *slash;
  slash = strrchr(pathname, '/');
  if (slash) {
    *slash = '\0'; /*Undefined behavior*/
  }
  return pathname;
}


/*
* BROKEN RULES AND RECOMENDATIONS
* MSC24-C. Do not use deprecated or obsolescent functions
* gets is an obsolescent function and should not be used, instead fgets or gets_s should be used 
*/
void get_y_or_n(void) {  
	char response[8];

	printf("Continue? [y] n: ");  
	gets(response);

	if (response[0] == 'n') 
		exit(0);  

	return;
}

 /*
 * COMPILATION WARNING AND ERRORS
 * ------------------------------
 * Using gcc -std=c99 and -std=c11
 * 
 * error: 's2' undeclared (first use in this function); did you mean 's1'? puts (s2);
 * 
 * Using g++
 * warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings] char *ptr_char  = "new string literal";
 * 
 * Warning of unused variables flagged with -Wall in both gcc and g++
 * analitic3
 * size_array2
 * size_array1
 * 
 */
int main(int argc, char *argv[])
{
    char key[24];
    char response[8];
    char array3[16];
    char array4[16];
    char array5 []  = "01234567890123456";
    char *ptr_char  = "new string literal";
    int size_array1 = strlen("аналитик");
    int size_array2 = 100;
    
   // char analitic1[size_array1]="аналитик";
   // char analitic2[size_array2]="аналитик";

   /*
    * BROKEN RULES AND RECOMENDATIONS
    * STR11-C. Do not specify the bound of a character array initialized with a string literal
    * solution = char analitic3[]="аналитик";
    */
    char analitic3[100]="аналитик";

    puts(get_dirname(__FILE__));

    /* BROKEN RULES AND RECOMENDATIONS
    * STR31-C. Guarantee that storage for strings has sufficient space for character data and the null terminator
    * Since argv has an undefined size, the size of the array key might not be large enough to hold the string
    * A posible solution could be using strncpy_s instead of strcpy
    * 
    * 
    * MSC24-C. Do not use deprecated or obsolescent functions 
    * strcpy is an obsolescent function and should not be used, instead strcpy_s should be used
    * strcat is an obsolescent function and should not be used, instead strcat_s should be used
    */   
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
    
    /*
    * MSC24-C. Do not use deprecated or obsolescent functions 
    * strncpy is an obsolescent function and should not be used, instead strncpy_s should be used
    * 
    */  
    strncpy(array3, array5, sizeof(array3));  
    strncpy(array4, array3, strlen(array3));
    
    array5 [0] = 'M';

    /* BROKEN RULES AND RECOMENDATIONS
    * STR30-C. Do not attempt to modify string literals 
    * using a char array instead of a string literal
    */
    ptr_char [0] = 'N';
    
    array3[sizeof(array3)-1]='\0';
    
    
    return 0;
}

