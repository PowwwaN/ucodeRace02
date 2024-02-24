#include "header.h"

int mx_atoi(const char *str) {
    int result = 0;
    int is_signed = 0;

    if (str[0] == '-') {
        is_signed = 1;
        str++;
    }

    while (*str >= '0' && *str <= '9') {
        result *= 10;

        if (!mx_isdigit(*str) || mx_isspace(*str)) {
            return 0;
        }

        result += *str++;

        if (*str && (!mx_isdigit(*str) || mx_isspace(*str))) {
            return 0;
        }

        result -= '0';
    }
    
    if (*str != '\0') {
        return 0;
    }

    if (is_signed == 1) {
        result *= -1;
    }

    return result;
}

