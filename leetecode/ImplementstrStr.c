#include <string.h>
// O(nm) will do with KMP 0(n+m) sol   
int strStr(char * haystack, char * needle){
    if(needle[0]=='\0'){
        return 0;
    }
    const int needle_len = strlen(needle);
    int i = 0;
    while (haystack[i]!='\0')
    {
        int j = 0;
        while(needle[j]!='\0' && haystack[i+j]!='\0' && needle[j]==haystack[i+j]){
            j++;
        }
        if(j==needle_len){
            return i;
        }
        i ++;

    }
    return -1;
    
    
    

}
void main(void){
    printf("%d",strStr("hllo","ll"));
}