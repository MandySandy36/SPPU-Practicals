CREATE DATABASE EXP4;
USE EXP4;

-- Create students table
CREATE TABLE students (
    roll_no INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50) NOT NULL,
    age INT
);

-- Create courses table
CREATE TABLE courses (
    course_id INT PRIMARY KEY AUTO_INCREMENT,
    course_name VARCHAR(50),
    roll_no INT,
    marks INT,
    FOREIGN KEY (roll_no) REFERENCES students(roll_no)
);

-- Insert sample data into students table
INSERT INTO students (name, age) VALUES 
    ('Aditya', 20), 
    ('Mehatab', 21), 
    ('Anuj', 19), 
    ('Sakshi', 22), 
    ('Trupti', 20),
    ('Raj', 23);

-- Insert sample data into courses table
INSERT INTO courses (course_name, roll_no, marks) VALUES
    ('Math', 1, 85),      -- Aditya enrolled in Math
    ('Science', 2, 90),   -- Mehatab enrolled in Science
    ('Math', 3, 70),      -- Anuj enrolled in Math
    ('Science', 4, 65),   -- Sakshi enrolled in Science
    ('Math', 5, 95),      -- Trupti enrolled in Math
    ('History', NULL, NULL),  -- Course with no students to show in Right Join
    ('Physics', NULL, NULL),  -- Course with no students
    ('Chemistry', NULL, NULL);

-- 1. Inner Join: Retrieve student names and their course names using an inner join.
SELECT students.name, courses.course_name, courses.marks
FROM students
INNER JOIN courses ON students.roll_no = courses.roll_no;

-- 2. Left Join: Retrieve all students, even those who haven't taken any courses.
SELECT students.name, courses.course_name, courses.marks
FROM students
LEFT JOIN courses ON students.roll_no = courses.roll_no;

-- 3. Right Join: Retrieve all courses, even if no students are enrolled in them.
SELECT students.name, courses.course_name, courses.marks
FROM students
RIGHT JOIN courses ON students.roll_no = courses.roll_no;

-- 4. Cross Join: Retrieve a Cartesian product of students and courses.
SELECT students.name, courses.course_name
FROM students
CROSS JOIN courses;

-- 5. Self Join: Find pairs of students with the same age.
SELECT s1.name AS student1, s2.name AS student2, s1.age
FROM students s1
JOIN students s2 ON s1.age = s2.age AND s1.roll_no != s2.roll_no;

-- 6. Subquery: Retrieve students who scored above the average marks in any course.
SELECT name
FROM students
WHERE roll_no IN (
    SELECT roll_no 
    FROM courses 
    WHERE marks > (SELECT AVG(marks) FROM courses)
);

-- 7. Correlated Subquery: Retrieve students and check if they scored above the average marks in each course they took.
SELECT s.name, c.course_name, c.marks
FROM students s
JOIN courses c ON s.roll_no = c.roll_no
WHERE c.marks > (
    SELECT AVG(marks) 
    FROM courses 
    WHERE course_name = c.course_name
);

-- 8. Create View: Create a view for students who scored above 80 in any course.
CREATE VIEW high_achievers AS
SELECT students.name, courses.course_name, courses.marks
FROM students
JOIN courses ON students.roll_no = courses.roll_no
WHERE courses.marks > 80;

-- 9. Use the View: Retrieve data from the high_achievers view.
SELECT * FROM high_achievers;

-- 10. Aggregate Function with Group By: Retrieve the average marks by course.
SELECT course_name, AVG(marks) AS avg_marks
FROM courses
GROUP BY course_name;

