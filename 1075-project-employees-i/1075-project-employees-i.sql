# Write your MySQL query statement below
SELECT p.project_id,
    COALESCE(ROUND(AVG(e.experience_years),2),0) AS average_years 
FROM Project AS p
LEFT JOIN Employee AS e
ON p.employee_id = e.employee_id 
GROUP BY p.project_id  