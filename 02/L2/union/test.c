#include <unistd.h>
#include <stdio.h>

int len(char *str) {
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

void smlwr(char *str) {
    int i;
    int j;
    int s;
    int l = len(str);

    i = 0;
    while (i < l) {
        s = 0;
        j = 0;
        while (j < i) {
            if (str[i] == str[j]) {
                s = 1;
            }
            j++;
        }
        if (s == 0) {
            write(1, &str[i], 1);
        }
        i++;
    }
}

int main(int argc, char *argv[]) {
    char *c1 = argv[1];
    char *str;

    smlwr(c1);
    write(1, "\n", 1);
    return 0;
}