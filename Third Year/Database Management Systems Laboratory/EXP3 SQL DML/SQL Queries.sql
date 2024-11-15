CREATE DATABASE EXP3;
USE EXP3;

-- 1. Create Table with Constraints
CREATE TABLE student_submissions (
    roll_no INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50) NOT NULL,
    submission_date DATE DEFAULT (CURRENT_DATE),
    marks INT CHECK (marks BETWEEN 0 AND 100)
);

INSERT INTO student_submissions (name, marks) VALUES ('Aditya', 78);
INSERT INTO student_submissions (name, marks) VALUES ('Mehatab', 85);
INSERT INTO student_submissions (name, marks) VALUES ('Anuj', 49);
INSERT INTO student_submissions (name, marks) VALUES ('Sakshi', 67);
INSERT INTO student_submissions (name, marks) VALUES ('Trupti', 91);

-- 2. Create Index
CREATE INDEX idx_roll_no ON student_submissions(roll_no);

-- 3. Create View for students with marks > 50
CREATE VIEW passing_students AS
SELECT name, roll_no, marks
FROM student_submissions
WHERE marks > 50;

-- 1. Retrieve all student records
SELECT * FROM student_submissions;

-- 2. Retrieve students who scored above 60
SELECT * FROM student_submissions WHERE marks > 60;

-- 3. Count of students who passed (marks > 50)
SELECT COUNT(*) AS passed_students FROM student_submissions WHERE marks > 50;

-- 4. Average marks of students
SELECT AVG(marks) AS average_marks FROM student_submissions;

-- 5. Retrieve students sorted by marks in descending order
SELECT * FROM student_submissions ORDER BY marks DESC;

-- 6. Retrieve students who scored between 50 and 70
SELECT * FROM student_submissions WHERE marks BETWEEN 50 AND 70;

-- 7. Retrieve student names and marks from the 'passing_students' view
SELECT name, marks FROM passing_students;

-- 8. Update a student's marks by roll_no
UPDATE student_submissions SET marks = 88 WHERE roll_no = 53;

-- 9. Delete records of students with marks below 50
DELETE FROM student_submissions WHERE marks < 50;

-- 10. Retrieve the top 3 students based on marks
SELECT * FROM student_submissions ORDER BY marks DESC LIMIT 3;
