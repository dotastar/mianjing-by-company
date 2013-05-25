public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        HashMap<Integer, Integer> m = new HashMap<Integer, Integer>();
        int[] r = new int[2];
        for(int i = 0; i < numbers.length; i++) {
            m.put(target - numbers[i], i);
        }
        for(int i = 0; i < numbers.length; i++) {
            if(m.containsKey(numbers[i])) {
                int index1 = i+1;
                int index2 = m.get(numbers[i])+1;
                r[0] = Math.min(index1, index2);
                r[1] = Math.max(index1, index2);
                break;
            }
        }
        return r;
    }
}
