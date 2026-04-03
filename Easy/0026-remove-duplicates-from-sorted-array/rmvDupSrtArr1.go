func removeDuplicates(nums []int) int {
    if len(nums) == 0 {                      //Check empty array
        return 0
    }                                        //First element is always unique
    k := 1                                   //Concise notation for declaring variables in GO, automatically infers the type; it will be our "pointer" to the last unique number we have seen
    for i := 1; i < len(nums); i++ {
        if nums[i] != nums[k-1] {            //If the next number isn't the same as the last unique number
            nums[k] = nums[i]                //Update the position of the next unique element
            k++                              //And increment the counter of the unduplicated numbers
        }
    }
    return k                                 //It does not matter what you leave beyond the returned k (hence they are underscores). 
}
