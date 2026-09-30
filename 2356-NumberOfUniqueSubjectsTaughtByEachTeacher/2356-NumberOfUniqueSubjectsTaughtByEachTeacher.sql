-- Last updated: 30/09/2026, 18:21:49
# Write your MySQL query statement below
SELECT 
    teacher_id,
    COUNT(DISTINCT subject_id) AS cnt
FROM 
    teacher
GROUP BY 
    teacher_id;