#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define CHUNK_SIZE 1000  // Number of integers to process at a time

// Function prototypes
void process_chunk(FILE *input_file, FILE *temp_file);
int find_mode(const char *temp_filename);

int main() {
    const char *input_filename = "numbers.txt";   // Input file with integers
    const char *temp_filename = "temp_counts.txt"; // Temporary file for counts

    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *temp_file = fopen(temp_filename, "w+");
    if (temp_file == NULL) {
        perror("Error opening temporary file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    // Process the input file in chunks
    while (!feof(input_file)) {
        process_chunk(input_file, temp_file);
    }

    fclose(input_file);
    fclose(temp_file);

    // Find the mode from the temporary file
    int mode = find_mode(temp_filename);
    printf("The mode of the list is: %d\n", mode);

    // Remove the temporary file
    if (remove(temp_filename) != 0) {
        perror("Error deleting temporary file");
    }

    return EXIT_SUCCESS;
}

// Function to process a chunk of integers
void process_chunk(FILE *input_file, FILE *temp_file) {
    int numbers[CHUNK_SIZE];
    int num_count = 0;
    
    // Read a chunk of integers from the input file
    while (num_count < CHUNK_SIZE && fscanf(input_file, "%d", &numbers[num_count]) == 1) {
        num_count++;
    }

    // Sort and count occurrences within this chunk
    for (int i = 0; i < num_count; i++) {
        for (int j = i + 1; j < num_count; j++) {
            if (numbers[i] == numbers[j]) {
                // Mark duplicate
                numbers[j] = INT_MIN;
            }
        }
    }

    // Write counts to the temporary file
    for (int i = 0; i < num_count; i++) {
        if (numbers[i] != INT_MIN) {
            fprintf(temp_file, "%d\n", numbers[i]);
        }
    }
}

// Function to find the mode from the temporary file
int find_mode(const char *temp_filename) {
    FILE *temp_file = fopen(temp_filename, "r");
    if (temp_file == NULL) {
        perror("Error opening temporary file");
        exit(EXIT_FAILURE);
    }

    int current, mode = 0, mode_count = 0, count = 0;
    int prev = INT_MIN;

    while (fscanf(temp_file, "%d", &current) == 1) {
        if (current == prev) {
            count++;
        } else {
            if (count > mode_count) {
                mode_count = count;
                mode = prev;
            }
            prev = current;
            count = 1;
        }
    }

    if (count > mode_count) {
        mode_count = count;
        mode = prev;
    }

    fclose(temp_file);
    return mode;
}