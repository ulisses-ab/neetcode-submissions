class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = [0] * 2010

        for num in nums:
            freq[num + 1000] += 1

        l = []
        for i in range(2010):
            if(freq[i] > 0):
                l.append((freq[i], i))

        out = []

        l = sorted(l)[::-1]

        for i in range(k):
            out.append(l[i][1] - 1000)

        return out
