-- Last updated: 06/07/2026, 19:05:43
# Write your MySQL query statement below
SELECT 
    player_id, 
    MIN(event_date) AS "first_login" 
FROM Activity 
GROUP BY player_id;