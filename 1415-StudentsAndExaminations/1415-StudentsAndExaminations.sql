-- Last updated: 06/07/2026, 19:04:27
SELECT
    s.student_id,
    s.student_name,
    su.subject_name,
    COUNT(e.student_id) AS attended_exams
FROM Students AS s
CROSS JOIN Subjects AS su
LEFT JOIN Examinations AS e
    ON s.student_id = e.student_id
    AND su.subject_name = e.subject_name
GROUP BY s.student_id, s.student_name, su.subject_name
ORDER BY s.student_id, s.student_name, su.subject_name;