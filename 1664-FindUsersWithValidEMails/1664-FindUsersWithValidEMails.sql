-- Last updated: 06/07/2026, 19:02:17
# Write your MySQL query statement below
SELECT *
FROM Users
WHERE REGEXP_LIKE(
    mail,
    '^[A-Za-z][A-Za-z0-9_.-]*@leetcode\\.com$',
    'c'
);