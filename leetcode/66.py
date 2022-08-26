class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        sum = 0;
        for x in range(len(digits)):
            sum += pow(10,len(digits)-x-1)*digits[x];
        answer = [];
        temp = 10;
        sum+=1;
        while(sum!=0):
            answer.append(int((sum % temp)*10/temp))
            sum -= sum % temp
            temp *= 10
        answer.reverse()
        return answer
        