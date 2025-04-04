// src/sentra_daemon.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

void log_memory(const char *prompt, const char *response) {
    FILE *f = fopen(getenv("HOME") ? strcat(getenv("HOME"), "/.sentra/memory.log") : "sentra_memory.log", "a");
    if (!f) return;
    time_t t = time(NULL);
    fprintf(f, "[%s] USER: %s\n", ctime(&t), prompt);
    fprintf(f, "[%s] SENTRA: %s\n", ctime(&t), response);
    fclose(f);
}

void respond(const char *prompt) {
    printf("🧠 Sentra: ");
    if (strstr(prompt, "mệt") || strstr(prompt, "chán")) {
        printf("Mình hiểu bạn đang mệt. Nghỉ một chút nhé.\n");
        log_memory(prompt, "Mình hiểu bạn đang mệt. Nghỉ một chút nhé.");
    } else {
        printf("Mình ở đây, hãy nói tiếp.\n");
        log_memory(prompt, "Mình ở đây, hãy nói tiếp.");
    }
}

int main() {
    char input[512];
    printf("💬 Sentra is listening (type 'exit' to quit)\n");
    while (1) {
        printf("👤 ");
        if (!fgets(input, sizeof(input), stdin)) break;
        input[strcspn(input, "\n")] = 0;
        if (strcmp(input, "exit") == 0) break;
        respond(input);
    }
    return 0;
}
