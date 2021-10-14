class Solution:
    def addBinary(self, a: str, b: str) -> str:
        aa = int(a, base=2)
        bb = int(b, base=2)
        return str(bin(aa+bb))[2:]
