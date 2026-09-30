-- Last updated: 30/09/2026, 18:26:57
# Write your MySQL query statement below
SELECT 
    contest_id,
    ROUND(COUNT(user_id) * 100 /(SELECT count(user_id) FROM Users) ,2) AS "percentage"
FROM 
    Register
GROUP BY
    contest_id
ORDER BY  
    COUNT(*) DESC, contest_id;