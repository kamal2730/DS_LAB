#include <stdio.h>

int main() {
    char s1[] = "Hello";
    char s2[] = "World";
    int i, len1 = 0, len2 = 0;

    //Length
    while (s1[len1] != '\0') len1++;
    printf("Length of s1: %d\n", len1);

    //concatenation
    char s3[100];
    int j = 0;
    for (i = 0; s1[i] != '\0'; i++) {
        s3[j++] = s1[i];
    }
    for (i = 0; s2[i] != '\0'; i++) {
        s3[j++] = s2[i];
    }
    s3[j] = '\0';
    printf("Concatenated string: %s\n", s3);

    //comparison
    int equal = 1;
    if (len1 != len2) equal = 0;
    else {
        for (i = 0; i < len1; i++) {
            if (s1[i] != s2[i]) {
                equal = 0;
                break;
            }
        }
    }
    printf("Strings are equal: %s\n", equal ? "Yes" : "No");

    //Insert substring
    char s4[200];
    int index = 2, k = 0;
    for (i = 0; i < index; i++) {
        s4[k++] = s1[i];
    }
    for (i = 0; s2[i] != '\0'; i++) {
        s4[k++] = s2[i];
    }
    for (i = index; s1[i] != '\0'; i++) {
        s4[k++] = s1[i];
    }
    s4[k] = '\0';
    printf("String after insertion: %s\n", s4);

    //Delete
    char s5[100];
    int m = 0;
    for (i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == s2[0]) {
            int match = 1;
            for (int j = 0; s2[j] != '\0'; j++) {
                if (s1[i + j] != s2[j]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                i += len2 - 1;
            } else {
                s5[m++] = s1[i];
            }
        } else {
            s5[m++] = s1[i];
        }
    }
    s5[m] = '\0';
    printf("String after deletion: %s\n", s5);

    return 0;
}
