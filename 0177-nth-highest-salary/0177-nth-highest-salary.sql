CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
      declare M INT;
      SET M = N - 1;
      RETURN(
      # Write your MySQL query statement below.
      
      SELECT DISTINCT Salary
      FROM Employee
      ORDER BY SALARY DESC
      LIMIT 1 Offset M

  );
END