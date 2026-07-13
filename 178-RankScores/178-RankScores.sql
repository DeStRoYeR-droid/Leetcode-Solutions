-- Last updated: 13/07/2026, 22:24:50
# Write your MySQL query statement below
SELECT
    score, DENSE_RANK() OVER (ORDER BY score DESC) as "rank"
FROM scores;