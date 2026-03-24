#include <stdint.h>
#include "keycode_mapper.h"

char map_keycode_to_char(uint8_t* keycode) {
    // Basic HID mapping for 'a'-'z'
    if (keycode[0] >= 0x04 && keycode[0] <= 0x1D) {
        return 'a' + (keycode[0] - 0x04);
    }
    return '?';
}
