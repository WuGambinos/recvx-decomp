#include "afs.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char header[4];
    int length;
    int offset;
} AFS_Entry;

void print_afs(AFS_Entry* afs)
{
    // printf("NUM_FILES: %d\n", afs->num_files);
    printf("OFFSET: %d HEX: 0x%X\n", afs->offset, afs->offset);
    printf("length: %d\n", afs->length);
}

int read_afs(char* path)
{
    printf("READING FILE: %s\n", path);

    FILE* f;
    f = fopen(path, "rb");

    if (f == NULL) {
        printf("%s could not be opened", path);
        return 1;
    }

    fseek(f, 0L, SEEK_END);
    int fsize = ftell(f);
    fseek(f, 0L, SEEK_SET);

    uint32_t* buffer = (uint32_t*) malloc(fsize);
    fread(buffer, fsize, 1, f);
    fclose(f);

    AFS_Entry afs;
    int num_files = 0;
    num_files = buffer[1];
    int offset = 0;
    int i = 2;

    while (i < (2 * (num_files + 1))) {
        AFS_Entry temp;
        temp.offset = buffer[i++];
        temp.length = buffer[i++];
        printf("NUM: %d\n", (i - 2) / 2);
        print_afs(&temp);
        printf("\n");
    }
}
