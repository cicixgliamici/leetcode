func removeElement(nums []int, val int) int {
                                       //Very similar to the previous exercise
    k := 0                             //But in this case there might not be any elements that match the one you are looking for
    for i := 0; i < len(nums); i++ {
        if nums[i] != val {            
            nums[k] = nums[i]          //Place the non-val element at index k
            k++
        }
    }
    return k                           //It does not matter what you leave beyond the returned k (hence they are underscores). 
}
