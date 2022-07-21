#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int shortUrl() {
//    int sequence = 916132607;
    char *base62 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for(int num = 916132607; num < 916132617; num ++) {
        int sequence = num;
        char base62_encode[255] = "http://shorturl/";
        char checkSum[2] = {0,};
        char tmp[10] = {0,};
        int i, j, k, t = 0;
        i = sequence % 62;
        j = sequence / 62;
        checkSum[0] = base62[base62[i] / 62];
        checkSum[1] = base62[base62[i] % 62];
        do {
            k = sequence % 62;
            tmp[t] = base62[k];
            sequence /= 62;
            t++;

        } while (sequence > 0);
        strcat(base62_encode, tmp);

        printf("%s .... %d\n", base62_encode);
    }

    return 0;
}

int main() {
    shortUrl();
//    charToNumber();
    return 0;
}
