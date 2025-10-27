class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        total = 0
        prev = 0
        for row in bank:
            current_count = row.count('1')
            if current_count > 0:
                total += prev * current_count
                prev = current_count
        
        return total