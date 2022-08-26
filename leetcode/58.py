class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        arr = s.split();
        if(len(arr)==0):
            return 0;
        
        return len(arr[len(arr)-1]);
        