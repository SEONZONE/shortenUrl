#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int shortUrl() {
//    int sequence = 916132907;
    char *base62 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";



    for(int sequence=916132832; sequence<916132842; sequence++) {
        char base62_encode[255] ="http://shorturl/";
        char tmp [10] = {0,};
        int i =0;
        int j= 0;
        i = sequence % 62;
        j = sequence / 62;


        char resultCheckSum = i ^ j;
        if (base62[resultCheckSum] > 62) {
            tmp[0] = base62[base62[resultCheckSum] / 62];
            tmp[1] = base62[base62[resultCheckSum] % 62];
        }

        tmp[2] = base62[resultCheckSum];
        strcat(base62_encode, tmp);
        printf("%s \n", base62_encode);
    }
    return 0;
}

int main() {
    shortUrl();
//    charToNumber();
    return 0;
}
