-- Last updated: 13/07/2026, 22:21:58
# Write your MySQL query statement below
SELECT 
    request_at AS Day, 
    ROUND(SUM((case when status != "completed" then 1 else 0 end)) / COUNT(*), 2) AS "Cancellation Rate"
FROM Trips
WHERE 
    request_at BETWEEN "2013-10-01" AND "2013-10-03"
    AND client_id IN (SELECT users_id FROM users where banned='No')
    AND driver_id IN (SELECT users_id FROM users where banned='No')
GROUP BY request_at;