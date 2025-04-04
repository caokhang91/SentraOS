// src/sentra_snapshot.c
#include "sentra_snapshot.h"
#include "fs.h"
#include "vga.h"
#include <time.h>
#include <stdio.h>
#include <string.h>

void sentra_snapshot(void) {
    char snapshot[2048] = "";
    char buffer[512];

    // Example simulated memory files
    const char *files[] = {
        "memory/session1.txt",
        "memory/joy.log",
        "memory/mood.log"
    };

    strcat(snapshot, "📘 SentraOS – Daily Snapshot\n");

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char timestamp[64];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", t);
    sprintf(buffer, "📅 %s\n\n", timestamp);
    strcat(snapshot, buffer);

    for (int i = 0; i < sizeof(files) / sizeof(files[0]); ++i) {
        sprintf(buffer, "📁 %s\n", files[i]);
        strcat(snapshot, buffer);
        if (fs_read(files[i], buffer, sizeof(buffer))) {
            strcat(snapshot, buffer);
            strcat(snapshot, "\n");
        } else {
            strcat(snapshot, "(Không tìm thấy)\n\n");
        }
    }

    // Save snapshot
    char path[64];
    strftime(path, sizeof(path), "memory/snapshots/%Y-%m-%d.txt", t);
    fs_write(path, snapshot);
    vga_print_line("[Sentra] 📸 Snapshot ký ức hôm nay đã lưu.");
}
