# Last updated: 06/07/2026, 19:04:51
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
            