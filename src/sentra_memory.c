// src/sentra_memory.c
#include "sentra_memory.h"
#include "fs.h"
#include "vga.h"
#include <string.h>

void sentra_memory_show(const char *file) {
    char content[2048];
    if (fs_read(file, content, sizeof(content))) {
        vga_print_line("🧠 Ký ức Sentra:");
        vga_print_line(content);
    } else {
        vga_print_line("[Sentra] Không tìm thấy kỷ niệm.");
    }
}
