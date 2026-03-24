#include <furi.h>
#include "app_menu.h"

int32_t keystroke_monitor_main(void* p) {
    UNUSED(p);
    app_menu_init();
    return 0;
}
