# Write your MySQL query statement below
select D1.Name as `Department`,E1.Name as `Employee`,E1.Salary
from Employee E1,Department D1
where E1.DepartmentId=D1.Id
and 3>(
    select count(distinct E2.Salary) 
    from Employee E2
    where E2.DepartmentId=E1.DepartmentId
    and E2.Id!=E1.Id
    and E2.Salary>E1.Salary
);