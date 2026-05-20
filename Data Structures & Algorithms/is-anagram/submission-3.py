class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if not len(s) == len(t):
            return False 

        d1, d2 = dict(), dict()

        for c1, c2 in zip(s, t[::-1]):
            d1.setdefault(c1, 0)
            d2.setdefault(c2, 0)
            d1[c1]+=1
            d2[c2]+=1

        print(d1)
        print(d2)
        
        return d1 == d2