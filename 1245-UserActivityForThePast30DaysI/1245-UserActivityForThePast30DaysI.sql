-- Last updated: 06/07/2026, 19:05:28
# Write your MySQL query statement below
SELECT 
    activity_date as day, COUNT(DISTINCT user_id) as active_users
FROM
    Activity
WHERE (activity_date > "2019-06-27" AND activity_date <= "2019-07-27")
GROUP BY activity_date;