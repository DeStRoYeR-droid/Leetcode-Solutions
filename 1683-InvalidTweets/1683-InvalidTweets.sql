-- Last updated: 30/09/2026, 18:26:25
# Write your MySQL query statement below
SELECT 
    tweet_id
FROM
    Tweets
WHERE
    CHAR_LENGTH(content) > 15;