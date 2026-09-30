-- Last updated: 30/09/2026, 18:24:35
SELECT
    s.user_id, 
    round(avg(if(c.action="confirmed",1,0)),2) as confirmation_rate
FROM 
    Signups s LEFT JOIN Confirmations c 
ON 
    s.user_id= c.user_id 
GROUP BY
    user_id;
