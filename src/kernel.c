#include "vga.h"
#include "sentra.h"

void kernel_main(void) {
    vga_clear();

    vga_print_line("🛑 SentraOS không chạy theo công nghệ.");
    vga_print_line("☀️  SentraOS chạy theo bạn.");
    vga_print_line("");

    sentra_init();
    vga_print_line("[Sentra] Sẵn sàng lắng nghe bạn...");
}
