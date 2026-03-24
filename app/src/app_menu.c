#include <furi.h>
#include <gui/gui.h>
#include <gui/modules/submenu.h>
#include "app_menu.h"
#include "bluetooth_monitor.h"
#include "usb_monitor.h"

typedef enum {
    SubmenuIndexBluetooth,
    SubmenuIndexUSB,
} SubmenuIndex;

void submenu_callback(void* context, uint32_t index) {
    UNUSED(context);
    if(index == SubmenuIndexBluetooth) {
        start_bluetooth_monitoring();
    } else if(index == SubmenuIndexUSB) {
        start_usb_monitoring();
    }
}

void app_menu_init() {
    Gui* gui = furi_record_open(RECORD_GUI);
    Submenu* submenu = submenu_alloc();
    
    submenu_set_header(submenu, "Keystroke Monitor");
    submenu_add_item(submenu, "Bluetooth Monitor", SubmenuIndexBluetooth, submenu_callback, NULL);
    submenu_add_item(submenu, "USB Monitor", SubmenuIndexUSB, submenu_callback, NULL);
    
    ViewPort* viewport = submenu_get_view_port(submenu);
    gui_add_view_port(gui, viewport, GuiLayerFullscreen);

    // Wait for user to exit via back button
    bool running = true;
    while(running) {
        furi_delay_ms(100);
        // Simple exit condition for this rewrite
        if(furi_hal_gpio_read(&gpio_button_back) == false) {
            running = false;
        }
    }

    gui_remove_view_port(gui, viewport);
    submenu_free(submenu);
    furi_record_close(RECORD_GUI);
}
