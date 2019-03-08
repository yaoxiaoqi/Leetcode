class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        if rowIndex == 0:
            return [1]
        if rowIndex == 1:
            return [1, 1]
        prevline = self.getRow(rowIndex-1)
        res = [1]
        for i in range(0, len(prevline)-1):
            res.append(prevline[i] + prevline[i+1])
        res.append(1)
        return res
