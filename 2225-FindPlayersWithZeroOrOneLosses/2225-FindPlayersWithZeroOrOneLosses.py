# Last updated: 14/09/2026, 09:26:35
class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        winners = set()
        lostOne = set()
        lostMore = set()

        for winner,loser in matches:
            if (loser in winners):
                winners.remove(loser)
            
            if (loser in lostOne):
                lostOne.remove(loser)
                lostMore.add(loser)
            elif not(loser in lostMore):
                lostOne.add(loser)
            
            if (winner not in lostOne and winner not in lostMore):
                winners.add(winner)
        
        result = [sorted(list(winners)) , sorted(list(lostOne))]
        return result
            