#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  

int main() 
{     
    printf("\nPlease enter 4 Lines :\n");     
    char str[500], line[100];     
    
    
    for(int i = 0; i < 4; i++) 
    {        
        fgets(line, sizeof(line), stdin);
        strcat(str, line);
    }     
    
    int a_count = 0, e_count = 0, i_count = 0, o_count = 0, u_count = 0;     

    
    for(int j = 0; str[j] != '\0'; j++)     
    {         
        switch(str[j]) {
            case 'a':
            case 'A':
                a_count++;
                break;
            case 'e':
            case 'E':
                e_count++;
                break;
            case 'i':
            case 'I':
                i_count++;
                break;
            case 'o':
            case 'O':
                o_count++;
                break;
            case 'u':
            case 'U':
                u_count++;
                break;
            default:
                break;
        }
    }    
    
    
    printf("\nVowel Occurrences\n");     
    printf(" a %d\n", a_count);     
    printf(" e %d\n", e_count);     
    printf(" i %d\n", i_count);     
    printf(" o %d\n", o_count);     
    printf(" u %d\n", u_count);     
    
    return 0; 
}
