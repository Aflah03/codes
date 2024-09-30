#!/bin/bash

# Check if the user provided a source file name
if [ $# -eq 0 ]; then
    echo "Usage: $0 <source_file_without_extension>"
    exit 1
fi

# Name of the source file (without the .java extension) provided as the first argument
SOURCE_FILE=$1

# Compile the program
javac "$SOURCE_FILE.java" 2>errors.txt

# Check if there were any compilation errors
if [ -s errors.txt ]; then
    echo "Compilation failed with the following errors:"
    cat errors.txt
else
    echo "Compilation succeeded. Running the program:"
    java "$SOURCE_FILE"
fi

# Display the errors if there were any
if [ -s errors.txt ]; then
    echo "Errors encountered during compilation:"
    cat errors.txt
    rm errors.txt
else
    # Clean up
    rm errors.txt
fi

