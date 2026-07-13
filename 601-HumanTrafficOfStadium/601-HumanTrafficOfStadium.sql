-- Last updated: 13/07/2026, 22:17:56
WITH grouped AS (
  SELECT *,
         id - ROW_NUMBER() OVER (ORDER BY id) AS grp
  FROM stadium
  WHERE people >= 100
)
SELECT id,
       visit_date,
       people
FROM (
  SELECT *,
         COUNT(*) OVER (PARTITION BY grp) AS streak_len
  FROM grouped
) t
WHERE streak_len >= 3
ORDER BY visit_date;