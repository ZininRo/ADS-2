// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    double num_pow = 1.0;
    while (n > 0) {
        if (n % 2 == 1) {
            num_pow *= value;
        }
        value *= value;
        n /= 2;
    }
    return num_pow;
}

uint64_t fact(uint16_t n) {
    uint64_t fact_of_num = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        fact_of_num *= i;
    }
    return fact_of_num;
}

double calcItem(double x, uint16_t n) {
    uint16_t now = n;
    double num_pow = 1.0;
    while (now > 0) {
        if (now % 2 == 1) {
            num_pow *= x;
        }
        x *= x;
        now /= 2;
    }
    double result = num_pow;
    for (uint16_t i = 2; i <= n; ++i) {
        result /= i;
    }
    return result;
}

double expn(double x, uint16_t count) {
    double result = 1.0;
    for (uint16_t i = 1; i < count; ++i) {
        result += pown(x, i) / fact(i);
    }
    return result;
}

double sinn(double x, uint16_t count) {
    double result = x;
    for (uint16_t i = 1; i < count; ++i) {
        if(i % 2 == 0){
            result += calcItem(x, 2 * i + 1);
        } else{
            result += calcItem(x, 2 * i + 1) * -1;
        }
    }
    return result;
}

double cosn(double x, uint16_t count) {
    double result = 1;
    for (uint16_t i = 0; i < count; ++i){
        if(i % 2 == 0){
            result += calcItem(x, 2 * i + 2) * -1;
        } else{
            result += calcItem(x, 2 * i + 2);
        }
    }
    return result;
}
