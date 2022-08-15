#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

const char *base62 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

 char *encode(int sequence) {
        static char base62_encode[255] = "https://seonzone/";
        char tmp[10] = {0,};
        int i ,t= 0;
        do {
            i = sequence % 62;
            tmp[t] = base62[i];
            sequence /= 62;
            t++;
        } while (sequence > 0);
        strcat(base62_encode, tmp);
    return base62_encode;
}

int *decode(char *rsltEncode) {
     static int decode;
     for(int i=0; i<rsltEncode.length; i++) {

     }
     return decode;
 }

int main() {
    char *rsltEcode;
    rsltEcode = encode(1000);
    printf("%s \n", rsltEcode);
    decode(rsltEcode);
    return 0;
}
