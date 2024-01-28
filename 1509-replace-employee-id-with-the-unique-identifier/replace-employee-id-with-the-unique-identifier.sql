# Write your MySQL query statement below
select unique_id,name 
from Employees left JOIN EmployeeUNI 
on Employees.id = EmployeeUNI.id ;
