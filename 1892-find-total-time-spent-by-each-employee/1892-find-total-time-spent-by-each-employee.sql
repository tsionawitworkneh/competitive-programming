# Write your MySQL query statement below
Select event_day as day,emp_id,SUM(out_time - in_time) AS total_time
from Employees
group by event_day,emp_id