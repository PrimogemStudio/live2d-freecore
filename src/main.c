#include <stdio.h>
#include <stdlib.h>

struct FileData {
    char* data;
    size_t size;
};
typedef struct FileData FileData;

FileData readFile(const char* path) {
    FILE* fp = fopen(path, "r");
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char* data = malloc(sizeof(char) * size);
    fread(data, size+1, 1, fp);
    fclose(fp);

    FileData fd;
    fd.data = data;
    fd.size = size;

    return fd;
}

int main() {
    const char* path = "/home/coder2/extsources/LpkUnpacker/Test/character/FileReferences_Moc_0.moc3";
    FileData data = readFile(path);
    for (int d = 0; d < data.size; d++) printf("%c\n", data.data[d]);

    return 0;
}
