# Write your MySQL query statement below




SELECT employee_id,
CASE WHEN name NOT LIKE 'M%' AND (employee_id % 2 != 0) THEN salary

ELSE 0
END AS bonus
FROM Employees
ORDER BY employee_id;

        