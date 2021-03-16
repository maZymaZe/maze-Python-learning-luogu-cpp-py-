# Write your MySQL query statement below
select Department.NAME as Department,Employee.NAME as Employee,Salary
from Employee,Department
where Employee.DepartmentId=Department.Id
and (Employee.DepartmentId,Salary)in(
    select DepartmentId,max(Salary)
    from Employee
    group by DepartmentId
)