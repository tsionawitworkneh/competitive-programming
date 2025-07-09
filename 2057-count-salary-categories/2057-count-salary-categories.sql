# Write your MySQL query statement below
SELECT 'Low Salary' AS category, 
        sum(income < 20000) AS accounts_count
FROM Accounts
UNION 
SELECT 'Average Salary' AS category, 
        sum(income >= 20000 AND income <=50000) AS accounts_count
FROM Accounts
UNION 
SELECT 'High Salary' AS category, 
        sum(income > 50000) AS accounts_count
FROM Accounts
ORDER BY accounts_count DESC