class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        if len(nums2)==0:
            return
        if len(nums1) == len(nums2):
            nums1[:] = nums2[:]
            return
        res = []
        i = 0;
        j = 0;
        while True:
            if j == len(nums2):
                res.extend(nums1[i:len(nums1)-len(nums2)])
                break
            if i == len(nums1)-len(nums2):
                res.extend(nums2[j:])
                break
            if nums1[i]==nums2[j]:
                res.append(nums1[i])
                i+=1
                continue
            if nums1[i] < nums2[j]:
                res.append(nums1[i])
                i+=1
                continue
            if nums1[i] > nums2[j]:
                res.append(nums2[j])
                j+=1
                continue
        print(res)
        nums1[:] = res[:]