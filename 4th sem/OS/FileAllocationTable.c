#include <stdio.h>
#include <stdbool.h>

#define MAX_FILES 10
#define MAX_BLOCKS 100

struct File {
    int file_id;
    int start_block;
    int end_block;
    bool allocated;
};

void initializeFAT(bool FAT[], int size) {
    for (int i = 0; i < size; i++) {
        FAT[i] = false;
    }
}

void displayFAT(bool FAT[], int size) {
    printf("Block\tAllocated\n");

    for (int i = 0; i < size; i++) {
        printf("%d\t%s\n", i, FAT[i] ? "Allocated" : "Free");
    }
}

int allocateFile(struct File files[], int num_files, bool FAT[], int size) {
    int start_block, end_block;
    printf("Enter the starting block number: ");
    scanf("%d", &start_block);
    printf("Enter the ending block number: ");
    scanf("%d", &end_block);

    if (start_block < 0 || end_block >= size || start_block > end_block) {
        printf("Invalid block range!\n");
        return num_files;
    }

    for (int i = start_block; i <= end_block; i++) {
        if (FAT[i]) {
            printf("Block %d is already allocated!\n", i);
            return num_files;
        }
    }

    files[num_files].file_id = num_files + 1;
    files[num_files].start_block = start_block;
    files[num_files].end_block = end_block;
    files[num_files].allocated = true;

    for (int i = start_block; i <= end_block; i++) {
        FAT[i] = true;
    }

    printf("File allocated successfully!\n");

    return num_files + 1;
}

void deallocateFile(struct File files[], int num_files, bool FAT[]) {
    int file_id;
    printf("Enter the file ID to deallocate: ");
    scanf("%d", &file_id);

    for (int i = 0; i < num_files; i++) {
        if (files[i].file_id == file_id) {
            for (int j = files[i].start_block; j <= files[i].end_block; j++) {
                FAT[j] = false;
            }

            files[i].allocated = false;
            printf("File deallocated successfully!\n");
            return;
        }
    }

    printf("File with ID %d not found!\n", file_id);
}

void displayFiles(struct File files[], int num_files) {
    printf("File ID\tStart Block\tEnd Block\tAllocated\n");

    for (int i = 0; i < num_files; i++) {
        printf("%d\t%d\t\t%d\t\t%s\n", files[i].file_id, files[i].start_block, files[i].end_block,
               files[i].allocated ? "Allocated" : "Free");
    }
}

int main() {
    int size;
    printf("Enter the size of the file system (number of blocks): ");
    scanf("%d", &size);

    bool FAT[MAX_BLOCKS];
    initializeFAT(FAT, size);

    struct File files[MAX_FILES];
    int num_files = 0;
    int option;

    do {
        printf("\n----- File Allocation using FAT -----\n");
        printf("1. Allocate file\n");
        printf("2. Deallocate file\n");
        printf("3. Display file details\n");
        printf("4. Display FAT\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                num_files = allocateFile(files, num_files, FAT, size);
                break;
            case 2:
                deallocateFile(files, num_files, FAT);
                break;
            case 3:
                displayFiles(files, num_files);
                break;
            case 4:
                displayFAT(FAT, size);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    } while (option != 5);

    return 0;
}

