CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N =N - 1;
  RETURN (
      # Write your MySQL query statement below.
        SELECT DISTINCT SALARY
        FROM EMPLOYEE
        ORDER BY 1 DESC
        LIMIT 1
        OFFSET N
  );
END