select employee_id from(
    select employee_id from Employees
    union all
    select employee_id from Salaries
)as ans
group by 1 having count(1)=1 order by 1