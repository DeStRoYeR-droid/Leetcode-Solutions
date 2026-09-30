-- Last updated: 30/09/2026, 18:35:36
# Write your MySQL query statement below
SELECT
    CASE 
        WHEN id % 2 = 1 AND id + 1 IN (SELECT id from Seat) THEN id + 1
        WHEN id % 2 = 0 THEN id - 1
        ELSE id
    END AS id, 
    student
FROM 
    Seat
ORDER BY
    id;
