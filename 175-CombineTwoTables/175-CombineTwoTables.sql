-- Last updated: 13/07/2026, 22:24:58
# Write your MySQL query statement below
SELECT 
    p.firstName, p.lastName, a.city, a.state
FROM
    Person p LEFT JOIN Address a ON a.personId = p.personId; 