# Write your MySQL query statement below
select Customers.name as 'Customers' from Customers
where not Customers.id in (select customerId from Orders);