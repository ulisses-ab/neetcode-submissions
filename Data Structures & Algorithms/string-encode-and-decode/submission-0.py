class Solution:

    def encode(self, strs: List[str]) -> str:
        out = ""
        for s in strs:
            out += str(len(s)) + '/' + s

        print(out)
        return out

    def decode(self, s: str) -> List[str]:
        out = []

        i = 0
        while i < len(s):
            j = i
            while s[j] != '/':
                j += 1

            num = int(s[i:j])
            i = j + 1 + num
            out.append(s[j+1:i])

        return out

