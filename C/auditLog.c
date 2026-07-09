#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define LOG_FILE "audit.log"
#define BUFFER_SIZE 1024
int main(int argc, char *argv[]) {
    if (argc < 2) {
        write(STDOUT_FILENO,
              "Usage:\n./auditlog --add \"message\"\n./auditlog --view\n",
              56);
        return 1;
    }
    if (strcmp(argv[1], "--add") == 0) {

        if (argc < 3) {
            write(STDOUT_FILENO, "Missing log message\n", 20);
            return 1;
        }

        int fd = open(LOG_FILE, O_WRONLY | O_CREAT | O_APPEND, 0644);

        if (fd < 0) {
            perror("open");
            return 1;
        }

        write(fd, argv[2], strlen(argv[2]));
        write(fd, "\n", 1);

        close(fd);
    }


    else if (strcmp(argv[1], "--view") == 0) {

        int fd = open(LOG_FILE, O_RDONLY);

        if (fd < 0) {
            write(STDOUT_FILENO, "Log file not found\n", 19);
            return 1;
        }

        char ch;
        int line = 1;
        char num[20];

        sprintf(num, "%d: ", line);
        write(STDOUT_FILENO, num, strlen(num));

        while (read(fd, &ch, 1) > 0) {

            write(STDOUT_FILENO, &ch, 1);

            if (ch == '\n') {
                line++;
                if (read(fd, &ch, 1) > 0) {
                    sprintf(num, "%d: ", line);
                    write(STDOUT_FILENO, num, strlen(num));
                    write(STDOUT_FILENO, &ch, 1);
                } else {
                    break;
                }
            }
        }

        close(fd);
    }

    else {
        write(STDOUT_FILENO, "Invalid command\n", 16);
    }

    return 0;
}