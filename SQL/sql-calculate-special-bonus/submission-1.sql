-- Write your query below
select employee_id, 
--name,
--salary, 
case 
when employee_id % 2 = 0 or starts_with(name, 'M') then 0
else salary
end as bonus
from employees
order by employee_id;
