#include <stdio.h>


int bitAnd(int x, int y){
    return ~(~x | ~y);
}

int bitXor(int x, int y){
    return ~(~(~x & y) & ~(x & ~y));
}

int thirdBits(){
    int const firstByte = 36;
    int const secondByte = 146;
    int const thirdByte = 73;
    int const fourthByte = 36;

    int result = firstByte;
    result = result << 8;
    result += secondByte;
    result = result << 8;
    result += thirdByte;
    result = result << 8;
    result += fourthByte;

    return result;
}

int fitsBits(int x, int n) {
    int minusN = 1 + ~n;
    int move = 32 + minusN;
    return !(((x << move) >> move) ^ x);
}

int sign(int x){
    return  ((x >> 31) | (x >> 31) + 1) & ~!x;
}

int getByte(int x, int n){
    int msk = 255;
    while (n){
        msk = msk << 8;
        n += ~0;
    }

    return x & msk;
}

int logicalShift(int x, int n){
    int msk = ~((1 << 31) >> (n + ~0));
    return (x >> n) & msk;
}

int addOK(int x, int y){
    int check = ((x >> 31) + (y >> 31)) + 1;
    int sum = x + y;
    int sumDetector = ((sum >> 31) | (sum >> 31) + 1);
    int controlSum = check + (sumDetector + ~0);
    return !check | !(controlSum ^ 1) | !(controlSum) ;
}

int bang(int x){
    int movedX = (~x >> 1) & ~(1 << 31);
    int r = (movedX + 1) >> 31;


    return (3 + ~(r + 2)) & x ^ 1;
}

int conditional(int x, int y, int z){
    return (y & (!x + ~0)) | (z & ~(!x + ~0));
}

int isPower2(int x){
    return !((x & (~x + 1)) ^ x) & ~!x;
}

int main() {
    printf("bitAnd: %d\n", bitAnd(6,5));
    printf("bitXor %d\n", bitXor(4,5));
    printf("thirdBits %d\n", thirdBits());
    printf("fitsBits %d\n", fitsBits(-4, 3));
    printf("sign %d\n", sign(23));
    printf("getByte %x\n", getByte(0x12345678, 1));
    printf("logicalShift %x\n", logicalShift(0x87654321, 4));
    printf("addOK %d\n", addOK(0x7fffffff, 0x7fffffff));
    printf("bang %d\n", bang(-23));
    printf("conditional %d\n", conditional(0, 34, 5));
    printf("isPower2 %d\n", isPower2(128));

    return 0;
}