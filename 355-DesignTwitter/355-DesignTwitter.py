# Last updated: 13/07/2026, 22:20:45
from collections import defaultdict       
from operator import itemgetter
import heapq

class Twitter:
    def __init__(self):
        self.userTweets = defaultdict(list)
        self.followers = defaultdict(set)
        self.time = 0
        
    def postTweet(self, userId: int, tweetId: int) -> None:
        self.userTweets[userId].append([-self.time, tweetId])
        self.time += 1

    def getNewsFeed(self, userId: int) -> List[int]:
        feed = list(self.userTweets[userId])
        for follower in self.followers[userId]:
            feed.extend(self.userTweets[follower])
           
        feed.sort(key=itemgetter(0, 1))
        result = []
        for i in range(min(10, len(feed))):
            result.append(feed[i][1])
        return result
            
    def follow(self, followerId: int, followeeId: int) -> None:
        self.followers[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if (followeeId in self.followers[followerId]):
            self.followers[followerId].remove(followeeId)  


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)