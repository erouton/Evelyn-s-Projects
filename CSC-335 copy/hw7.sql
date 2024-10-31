-- 1. [15 points] Find the ids of instructors who are also students using the exists construct.

select instructor.ID
from instructor 
where exists (select student.ID from student where student.ID = instructor.ID); 


-- 2. [15 points] Find the names and ids of the students who have taken all the courses that are offered by their departments. 
--Notice, the table course contains information about courses offered by departments.

select student.name, student.ID
from student
where not exists (
  select course.course_id
  from course
  where course.dept_name = student.dept_name and not exists (
    select takes.course_id
    from takes
    where takes.course_id = course.course_id and takes.ID = student.ID) );


-- 3. [10 points] Find the names and ids of the students who have taken exactly one course in the Fall 2017 semester.

select student.name, student.ID
from student join takes on student.ID = takes.ID
where takes.semester = 'Fall' and takes.year = '2017'
group by student.ID
having count(takes.course_id) = 1;


-- 4. [15 points] Find the names and ids of the students who have taken at most one course in the Fall 2017 semester. 
--Notice, at most one means one or zero. So, the answer should include students who did not take any course during that semester.

select student.ID, student.name
from student left join (
	select takes.ID, count(*) course_count
	from takes
	where takes.semester = 'Fall' and takes.year = '2017'
	group by takes.ID
) as Count_of_courses on student.ID =  count_of_courses.ID
where Count_of_courses.course_count <= 1 OR Count_of_courses.course_count is NULL;


-- 5. [15 points] Write a query that uses a derived relation to find the student(s) who have taken at least two courses in the 
--Fall 2017 semester. Schema of the output should be (id, number_courses). Remember: derived relation means a subquery in the from clause.

select id, number_courses
from (
  select takes.ID, count(*) course_count
  from takes
  where takes.semester = 'Fall' and takes.year = '2017'
  group by takes.ID
  ) as Count_of_courses(id, number_courses)
where number_courses >= 2;


-- 6. [15 points] Write a query that uses a scalar query in the select clause to find the number of distinct courses that have 
--been taught by each instructor. Schema of the output should be (name, id, number_courses).

select distinct instructor.name, instructor.id, Course_vals.number_courses
from instructor join (
  select teaches.ID, count(*) number_courses 
  from teaches group by teaches.ID
) as Course_vals on instructor.ID=Course_vals.ID;


-- 7. [15 points] Write a query that uses the with clause or a derived relation to find the id and number of courses that 
--have been taken by student(s) who have taken the most number of courses. Schema of the output should be (id, number_courses).

 select id, number_courses
 from (
 select takes.ID, count(*)
 from takes
 group by takes.ID
 ) as Count_of_courses(id, number_courses)
 group by Count_of_courses.number_courses, Count_of_courses.id
 order by number_courses DESC limit 1;



