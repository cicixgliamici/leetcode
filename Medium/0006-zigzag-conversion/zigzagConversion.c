char* convert(char* s, int numRows) {
    // Edge case: if numRows is 1 or greater than/equal to the string length,
    // the zigzag pattern is just the string itself.
    if (numRows == 1 || numRows >= strlen(s)) {
        return s;
    }

    // Allocate memory for an array of strings to represent each row.
    // Each row will be a dynamically allocated string.
    char** rows = (char**)malloc(numRows * sizeof(char*));
    for (int i = 0; i < numRows; i++) {
        rows[i] = (char*)malloc((strlen(s) + 1) * sizeof(char)); // +1 for the null terminator
        rows[i][0] = '\0'; // Initialize each row as an empty string
    }

    // Initialize variables to track the current row and direction.
    int current_row = 0; // Start at the first row.
    int direction = 1;   // 1 for moving down, -1 for moving up.

    // Iterate through each character in the string.
    for (int i = 0; i < strlen(s); i++) {
        // Append the current character to the current row.
        strncat(rows[current_row], &s[i], 1);

        // Move to the next row based on the direction.
        current_row += direction;

        // If we reach the first or last row, reverse the direction.
        if (current_row == 0 || current_row == numRows - 1) {
            direction *= -1;
        }
    }

    // Concatenate all rows to get the final zigzag string.
    // Calculate the total length of the result string.
    int total_length = 0;
    for (int i = 0; i < numRows; i++) {
        total_length += strlen(rows[i]);
    }

    // Allocate memory for the result string.
    char* result = (char*)malloc((total_length + 1) * sizeof(char)); // +1 for the null terminator
    result[0] = '\0'; // Initialize the result as an empty string

    // Concatenate all rows into the result string.
    for (int i = 0; i < numRows; i++) {
        strcat(result, rows[i]);
        free(rows[i]); // Free the memory allocated for each row
    }
    free(rows); // Free the memory allocated for the rows array

    return result;
}


/*
 * Explanation of the C Code:
 *
 * Memory Allocation:
 * - In C, strings are represented as arrays of characters, and we need to manually allocate memory for them.
 * - We use malloc to allocate memory for the rows array and each row within it.
 * - Each row is initialized as an empty string by setting the first character to '\0'.
 *
 * Simulating the Zigzag Pattern:
 * - We use a 'current_row' variable to track the current row and a 'direction' variable to determine 
 *   whether we're moving down (1) or up (-1).
 * - For each character in the string, we append it to the current row using strncat.
 * - When we reach the first or last row, we reverse the direction by multiplying 'direction' by -1.
 *
 * Concatenating Rows:
 * - After processing all characters, we calculate the total length of the result string by summing the lengths of all rows.
 * - We allocate memory for the result string and concatenate all rows into it using strcat.
 *
 * Memory Management:
 * - In C, we must manually free any dynamically allocated memory to avoid memory leaks.
 * - We free the memory allocated for each row and the rows array itself after concatenating them into the result.
 *
 * Edge Cases:
 * - If numRows is 1 or greater than or equal to the length of the string, we return the string itself without any modification.
 *
 * Key Differences Between Python and C:
 * - Memory Management: In Python, memory management is automatic, but in C, we must manually allocate and free memory.
 * - String Manipulation: In Python, strings are immutable and easy to manipulate. In C, strings are arrays of characters, 
 *   and we use functions like strncat and strcat to manipulate them.
 * - Dynamic Arrays: In Python, lists are dynamic and easy to use. In C, we use pointers and malloc to create dynamic arrays.
 */