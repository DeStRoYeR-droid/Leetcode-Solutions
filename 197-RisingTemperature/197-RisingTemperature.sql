-- Last updated: 13/07/2026, 22:24:07
SELECT today.id
FROM Weather yesterday 
CROSS JOIN Weather today

WHERE DATEDIFF(today.recordDate,yesterday.recordDate) = 1
AND today.temperature > yesterday.temperature;