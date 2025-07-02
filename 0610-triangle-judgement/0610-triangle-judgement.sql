# Write your MySQL query statement below
SELECT *,
        CASE
            WHEN x+y > z AND x+z > y AND y+z >x THEN 'Yes'
            else 'No'
        END AS 'triangle'
From Triangle
