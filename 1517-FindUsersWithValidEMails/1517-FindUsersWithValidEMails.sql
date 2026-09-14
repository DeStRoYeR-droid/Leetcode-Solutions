-- Last updated: 14/09/2026, 09:20:15
# Write your MySQL query statement below
SELECT *
FROM Users
WHERE REGEXP_LIKE(
    mail,
    '^[A-Za-z][A-Za-z0-9_.-]*@leetcode\\.com$',
    'c'
);