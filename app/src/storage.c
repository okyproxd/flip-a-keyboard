#include <furi.h>
#include <storage/storage.h>
#include "storage.h"

void save_keystroke_to_storage(char character) {
    Storage* storage = furi_record_open(RECORD_STORAGE);
    File* file = storage_file_alloc(storage);
    
    if(storage_file_open(file, EXT_PATH("keystrokes.txt"), FSAM_WRITE, FSOM_OPEN_APPEND)) {
        storage_file_write(file, &character, 1);
        storage_file_write(file, "\n", 1);
    }
    
    storage_file_close(file);
    storage_file_free(file);
    furi_record_close(RECORD_STORAGE);
}
