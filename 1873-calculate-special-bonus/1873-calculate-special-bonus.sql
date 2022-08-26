# Write your MySQL query statement below
select employee_id,
CASE 
   When employee_id%2<>0 && name not like 'M%' then salary
   Else 0
   END
as bonus from employees
order by employee_id;
