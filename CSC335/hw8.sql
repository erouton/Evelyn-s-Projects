--1.	[5 points] (Similar to Q1 HW 6) Find the number of students in each department. Rename the count as numbStudents. 
--		I.e., schema of the output should be (dept_name, numbStudents).

select department.dept_name, count(student) as numbStudents
from department, student
where student.dept_name = department.dept_name
group by department.dept_name;


--2.	[5 points] (Similar to Q2 HW 6) For departments that have at least three students, find department name and number of students. 
--		Rename the second attribute in the output as numbStudents. 

select department.dept_name, count(student) as numbStudents
from department, student
where student.dept_name = department.dept_name 
group by department.dept_name
having count(student) >= 3;


--3.	[10 points] Use the set membership operator to find the names of students that have taken at least three courses.  

select student.name
from student
where student.ID in (
	select takes.ID
	from takes
  	group by takes.ID
  	having count(takes.course_id) >= 3);


--4.	[10 points] Use the with clause to create a temporary relation to find the names of students that have taken at least three courses.  

with count_courses(value) as
	(select takes.ID
     from takes
     group by takes.ID
     having count(takes.course_id) >= 3)
select student.name
from student,count_courses
where student.ID = count_courses.value; 


--5.	[10 points] Use the exists construct to find the names of students that have taken at least three courses. 

select student.name
from student
where exists(select takes.ID
            from takes
            where takes.ID = student.ID
            group by takes.ID
            having count(takes.course_id) >= 3);


--6.	[10 points] Use a correlated subquery in the where clause to find the names of students that have taken at least three courses.  

select student.name
from student
where 3 <= (select count(takes.course_id)
       from takes
       where takes.ID = student.ID);


--7.	[10 points] Uses a derived relation (you may also need to use the lateral clause) to find the names of students that have taken at least 
--		three courses. 

select distinct student.name
from student join (select takes.id, count(takes.course_id) as num_course 
                   from takes
                   group by takes.ID
                   having count(takes.course_id) >= 3) count_course on count_course.ID = student.ID;



            
--8.	[10 points] Use an outer join to find names of the students in the university database who have never taken any course.

select student.name
from student natural full outer join takes
where course_id is null;


--9.	[10 points] Define the terms: view, materialized view, updatable view.
/*
view: virtual relation
materialized view: a view that stores the results of the query allowing for improved performance
updatable view: a view that allows changes to be made but must adhere to certain criteria
*/


--10.	[10 points] Write an SQL statement to create a view that gives the number of students in each department. 
--      Schema of the view should be (dept_name, num_students).
/*
create view num_students_per_department as 
    select dept_name, count(*) as num_students
    from student
    group by dept_name
*/


--11.	[5 points] What is the difference between join type and join condition.
/*
join type: determines how the tables are join together
join condition: specifies what information is output from the tables
*/


--12.	[5 points] List the three different ways one can specify a join condition.
/*
using ON: from student join takes on takes.id = student.id
using WHERE: from student, takes where takes.id = student.id
using USING: from student join takes using (id)
*/
