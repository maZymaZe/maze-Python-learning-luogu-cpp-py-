import re
class Solution:
    def isNumber(self, s: str) -> bool:
        if re.match(r'^ *(\+|-)?(\d+((\.|,)\d*)?|\d*((\.|,)\d+))([eE](\+|-)?\d+)? *$',s):
            return True
        else:
            return False