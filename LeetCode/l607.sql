select s1.name
from salesperson s1
where s1.sales_id not in(
    select o1.sales_id
    from company c1,orders o1
    where c1.com_id=o1.com_id and c1.name='RED'
);