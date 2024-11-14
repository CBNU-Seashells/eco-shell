// cleanup.c
#include "../include/cleanup.h"
#include <dirent.h>

void cleanup_temp_files() {
    const char *temp_dir = "/tmp/";
    struct dirent *entry;
    DIR *dir = opendir(temp_dir);

    if (dir == NULL) {
        perror("Failed to open /tmp/");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, "tmp")) {
            printf("Removing %s\n", entry->d_name);
            char filepath[256];
            snprintf(filepath, sizeof(filepath) - 1, "%s%s", temp_dir, entry->d_name);
            remove(filepath);
        }
    }

    closedir(dir);
    printf("Temporary files cleaned up.\n");
}
