-- Last updated: 14/09/2026, 09:28:38
# Write your MySQL query statement below
SELECT 
    player_id, 
    MIN(event_date) AS "first_login" 
FROM Activity 
GROUP BY player_id;