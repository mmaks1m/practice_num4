#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main() {
    FILE *fp = fopen("example.txt", "w");
    int const fd = fileno(fp);

    if (fp == NULL) {
        perror("Ошибка при открытии файла");
        return 0;
    }

    fclose(fp);

    if (close(fd) == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        perror("perror says");
    }

    return 0;
}
