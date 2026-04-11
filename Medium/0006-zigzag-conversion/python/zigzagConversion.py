class Solution:
    def convert(self, s: str, numRows: int) -> str:
        # Edge case: if numRows is 1 or greater than/equal to the string length,
        # the zigzag pattern is just the string itself.
        if numRows == 1 or numRows >= len(s):
            return s
        
        # Create a list of strings to represent each row in the zigzag pattern.
        rows = [""] * numRows
        
        # Initialize variables to track the current row and direction.
        current_row = 0  # Start at the first row.
        direction = 1    # 1 for moving down, -1 for moving up.
        
        # Iterate through each character in the string.
        for char in s:
            # Append the character to the current row.
            rows[current_row] += char
            
            # Move to the next row based on the direction.
            current_row += direction
            
            # If we reach the first or last row, reverse the direction.
            if current_row == 0 or current_row == numRows - 1:
                direction *= -1
        
        # Concatenate all rows to get the final zigzag string.
        return "".join(rows)


"""
Edge Case Handling:
- If numRows is 1, the zigzag pattern is just the string itself because there's only one row.
- If numRows is greater than or equal to the length of the string, the zigzag pattern is also the string itself 
  because there's no space for diagonal movement.

Simulating the Zigzag Pattern:
- We use a list called 'rows' to store characters for each row.
  For example, rows[0] will store characters for the first row, rows[1] for the second row, and so on.
- We use 'current_row' to track which row we're currently filling and 'direction' to determine 
  whether we're moving down (1) or up (-1).
- For each character in the string, we append it to the current row and update 'current_row' based on the direction.
- When we reach the first row (current_row == 0) or the last row (current_row == numRows - 1), 
  we reverse the direction by multiplying 'direction' by -1.

Concatenating Rows:
- After processing all characters, we concatenate the strings in the 'rows' list using "".join(rows) 
  to get the final zigzag string.
"""