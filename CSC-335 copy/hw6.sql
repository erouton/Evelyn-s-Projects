-- 1. [20 points] Find the number of students in each department. 
--	   Rename the second attribute in the output as number_students. 
-- 	   This means the schema of the output is (dept_name, number_students).
select department.dept_name, count(student) as number_students
from department, student
where student.dept_name = department.dept_name
group by department.dept_name;


-- 2. [20 points] For departments that have at least three students, find department name and number of students. 
-- 	   Rename the second attribute in the output as number_students. 
-- 	   Remark: this question is similar to the previous one but the output lists only department that has at least three students.
select department.dept_name, count(student) as number_students
from department, student
where student.dept_name = department.dept_name 
group by department.dept_name
having count(student) >= 3
;


-- 3. [20 points] Find the ids of instructors who are also students using a set operation. Assume that a person is identified by her or his id. 
-- 	   So, if the same id appears in both instructor and student, then that person is both an instructor and a student. 
-- 	   Remember: set operation means union, intersect or set difference.
select instructor.ID 
from instructor
intersect
select student.ID
from student;


-- 4. [20 points] Find the ids of instructors who are also students using the set membership operator.
select instructor.ID
from instructor
where instructor.ID in (select student.ID from student);



-- 5. [20 points] Find the ids of instructors who are also students using a set comparison operator.
select instructor.ID
from instructor, student
where instructor.ID = student.ID;

