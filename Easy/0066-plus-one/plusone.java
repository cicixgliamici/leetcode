class plusone {
    public int[] plusOne(int[] digits) {
        // Start from the last digit
        int i = digits.length - 1;
        
        // Iterate through the digits from the end to the beginning
        while (i >= 0) {
            // If the current digit is less than 9, simply increment it and return the result
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            } else {
                // If the current digit is 9, set it to 0 and move to the previous digit
                digits[i] = 0;
                i--;
            }
        }
        
        // If all digits were 9, create a new array with an additional digit '1' at the beginning
        int[] newDigits = new int[digits.length + 1];
        newDigits[0] = 1;
        return newDigits;
    }
}