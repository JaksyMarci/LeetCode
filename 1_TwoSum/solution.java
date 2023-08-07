//Brute force, O(n^2) solution

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int currentIndex = 0;
        while (currentIndex < nums.length){
            for (int i = currentIndex + 1; i < nums.length; i++){
                if (nums[currentIndex] + nums[i] == target){
                    int[] answer = new int[]{currentIndex, i};
                    return answer;
                }
            }
            currentIndex++;
        }
        
        return null;
    }
}