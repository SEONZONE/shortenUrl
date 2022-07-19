#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int numberToChar(int num) {
    char max[10];
    int i=0;
    int tmp = num;
    int tmp2 =0;

    while(tmp != 0) {
        tmp/=16;
        i ++;
    }


    while(num!=0) {
        i--;
        tmp2 = num%16;

        if(tmp2 > 10) {
            *(max+i)=65+(num%16 - 10);
        }
        else  {
            *(max+i)=num%16 + 48;
        }

        num=num/16;

    }

    printf("16진수 문자열: %s",max);
    return 0;
}

int charToNumber() {
    unsigned long num = 0;
    int i=-1;
    int tmp = 0;
    int tmp2 = 0;

    int strLength = 0;
    int base16Length = 0;
    char *base16 = "0123456789ABCDEFG";
    char str[] = "21FFG";
    int baseIndex[128] = {-1};
    int inputNum = 15;

    base16Length =strlen(base16);
    strLength =strlen(str);


    for(int i=0; i<128; i++) {
        baseIndex[i] = -1;
    }



    for(int i =0; i<base16Length; i++) {
        baseIndex[base16[i]] = i;
//         printf("baseIndex : %X \n", baseIndex[i]);
    }

    printf("baseIndex %d \n",baseIndex[1]);
    printf("ASCII %d \n",baseIndex['A']);
    printf("Number %c \n",base16[inputNum]);


    for(int i=0; i<strLength; i++) {
        printf("str ASCII %d \n",baseIndex[str[i]] );
    }


    while(1) {
        ++i;



        if(str[i] >= 'A' && str[i] <= 'F')
        {
            num = num * 16 + (str[i] - 'A' + 10);
        }
        else if(str[i] >= 'a' && str[i] <= 'f')
        {
            num = num * 16 + (str[i] - 'a' + 10);
        }
        else if(str[i] >= '0' && str[i] <= '9')
        {

            tmp = str[i] - '0';
            tmp2 = num * 16;
            num = tmp2 + tmp;


        }

        else if(str[i] == '\0') {
            printf("16진수 : %X \n",num);
            break;
        }
        else {
            printf("16진수 : %X \n",num);

        }
    }
    return numberToChar(num);
}

int shuffle() {

    int infoShuffle[10];
    int temp =0;
    srand((unsigned) time(NULL));
    for(int i=0; i<10; i++) {
        infoShuffle[i] = i;
    }
    for(int i=0; i<10; i++) {
        int random = rand()%9;
        temp = infoShuffle[i];
        infoShuffle[i] = infoShuffle[random];
        infoShuffle[random] = temp;



        printf("random number: %d \n",infoShuffle[i]);
    }



    return 0;
}

int shortUrl() {
    int sequence = 916132832;
    char *base62 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char base62_encode[255] ;
    int i =0;

    char resultChecksum =  base62[1] ^ base62[2] ^ base62[3];
    printf("result: %d \n",resultChecksum);
    i = sequence % 62;
    printf("base62: %c",base62[i]);
    return 0;
}

int main() {
    shortUrl();
//    charToNumber();
    return 0;
}
