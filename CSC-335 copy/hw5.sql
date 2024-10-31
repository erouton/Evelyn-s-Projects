--Evelyn Routon - CSC335 Fall 2024

-- 1. Give an SQL schema definition for the following employee database:
drop table if exists company;
drop table if exists works;
drop table if exists manages;
drop table if exists employee;
 
create table employee (employee_name varchar(20) primary key , street varchar(40), city varchar(85));
create table works (employee_name varchar(20) references employee (employee_name), company_name varchar(40), salary numeric(8,2));
create table company (company_name varchar(40), city varchar(85));
create table manages (employee_name varchar(20) references employee (employee_name), manager_name varchar(20) references employee (employee_name)); 
               
-- 2. Populate the tables you created for the previous question with data (i.e, write SQL insert statements to insert data in the tables). 
--You need to insert at least three rows in each table. Be careful about the order you populate the tables with data.
insert into employee values('Evelyn' , 'Meadow Rd' , 'Townsville');
insert into employee values('Bella' , 'Peanut Dr' , 'Townsville');
insert into employee values('Braegan' , 'Lego St' , 'Villageton');
insert into employee values('Tommy' , 'Meadow Rd' , 'Townsville');
insert into employee values('Timmy' , 'Peanut Dr' , 'Townsville');
insert into employee values('Tammy' , 'Nowhere Ln' , 'Nowhereville');

insert into works values('Evelyn' , 'First Bank Corporation', '65000.00');
insert into works values('Bella' , 'Butter Manufacturer' , '54000.00');
insert into works values('Braegan' , 'First Bank Corporation' , '72000.00');
                  
insert into company values('First Bank Corporation' , 'Citytowne');
insert into company values('Butter Manufacturer' , 'Townsville');
insert into company values('Brick by Brick' , 'Villageton');

insert into manages values('Evelyn' , 'Tommy');
insert into manages values('Bella' , 'Timmy');
insert into manages values('Braegan' , 'Tammy');

-- 3. For this question, you are not allowed to use any SQL command that was not covered in module 5. 
--Answers that use SQL commands covered in modules after module 5 will be considered wrong. Write SQL queries to answer the following questions:

-- 3.1. Find the names of all employees who work for “First Bank Corporation”.
select employee.employee_name, works.company_name from employee, works where works.employee_name = employee.employee_name and works.company_name = 'First Bank Corporation';

-- 3.2. Find the company_name and city for every company. Order the output in alphabetical order by company_name.
select * from company order by company_name;

-- 3.3. Find the names of the employees who make a salary of at least $65,000. Notice: in the query the value should be specified as 65000.
select employee_name, salary 
from works
where salary >= 65000;

-- 3.4. Find all employees in the database who live in the same cities as the companies for which they work.
select employee.employee_name, employee.city
from employee, company, works
where employee.employee_name = works.employee_name and employee.city = company.city and works.company_name = company.company_name;


-- 3.5. Find all employees in the database who live in the same cities and on the same streets as do their managers.
select employee.employee_name, employee.street, employee.city,(manages.manager_name)
from employee join manages on employee.employee_name = manages.employee_name join employee manager on manages.manager_name = manager.employee_name
where employee.street = manager.street and employee.city = manager.city;
