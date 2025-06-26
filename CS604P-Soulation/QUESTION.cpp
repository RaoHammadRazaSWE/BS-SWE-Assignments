#include<stdio.h>
#include <math.h>

int main() {
    // Variable declarations
    char studentName[50];
    char studentID[20];
    int logicalAddressKB, numPages, totalMemoryKB, numFrames;
    int bitsForPage, bitsForFrame, bitsForOffset;
    int logicalAddressSize, physicalAddressSize;
    int pageSizeBytes;

    // Inputs
    printf("Enter Your Student ID: ");
    scanf("%s", studentID);

    // Clear newline from buffer before taking full line input
    getchar();

    printf("Enter Your Student Name: ");
    scanf("%[^\n]", studentName);

    printf("Enter Logical Address Space (in KB): ");
    scanf("%d", &logicalAddressKB); 

    printf("Enter number of pages: ");
    scanf("%d", &numPages);

    printf("Enter Total Memory (in KB): ");
    scanf("%d", &totalMemoryKB);

    printf("Enter Number of Frames: ");
    scanf("%d", &numFrames);

    // Calculate page size (in bytes)
    pageSizeBytes = (logicalAddressKB * 1024) / numPages;

    // Calculate bits
    bitsForPage = (int)ceil(log2(numPages));
    bitsForFrame = (int)ceil(log2(numFrames));
    bitsForOffset = (int)ceil(log2(pageSizeBytes));

    logicalAddressSize = bitsForPage + bitsForOffset;
    physicalAddressSize = bitsForFrame + bitsForOffset;

    // Output
    printf("\nCalculated Output:\n");
    printf("Student ID: %s\n", studentID);
    printf("Student Name: %s\n", studentName);
    printf("Page size: %d Bytes\n", pageSizeBytes);
    printf("Bits for Page Number (p): %d\n", bitsForPage);
    printf("Bits for Frame Number (f): %d\n", bitsForFrame);
    printf("Bits for Offset (d): %d\n", bitsForOffset);
    printf("Logical Address Size: %d bits\n", logicalAddressSize);
    printf("Physical Address Size: %d bits\n", physicalAddressSize);

    return 0;
}
