class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = {}

        for s in strs:
            d[''.join(sorted(s))] = d.get(''.join(sorted(s)), []) + [s]

            
        return d.values()

