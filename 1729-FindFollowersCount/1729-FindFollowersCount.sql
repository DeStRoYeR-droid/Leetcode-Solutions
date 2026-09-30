-- Last updated: 30/09/2026, 18:26:04
SELECT
    user_id,
    COUNT(follower_id) AS "followers_count"
FROM
    Followers
GROUP BY 
    user_id
ORDER BY 
    user_id;