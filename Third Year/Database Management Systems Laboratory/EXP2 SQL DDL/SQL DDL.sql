CREATE DATABASE EXP2;
USE EXP2;

-- Step 1: Create the initial table
CREATE TABLE student_submissions (
    roll_no INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50) NOT NULL,
    submission_date DATE DEFAULT (CURRENT_DATE),
    marks INT CHECK (marks BETWEEN 0 AND 100)
);

-- Step 2: Insert sample data
INSERT INTO student_submissions (name, marks) VALUES ('Aditya', 78);
INSERT INTO student_submissions (name, marks) VALUES ('Mehatab', 85);
INSERT INTO student_submissions (name, marks) VALUES ('Anuj', 49);
INSERT INTO student_submissions (name, marks) VALUES ('Sakshi', 67);
INSERT INTO student_submissions (name, marks) VALUES ('Trupti', 91);

-- DDL Operations
-- Step 3: Add a new column 'remarks'
ALTER TABLE student_submissions
ADD COLUMN remarks VARCHAR(100);

-- Step 4: Modify the 'name' column to allow 100 characters
ALTER TABLE student_submissions
MODIFY COLUMN name VARCHAR(100);

-- Step 5: Drop the existing check constraint on 'marks' 
ALTER TABLE student_submissions
DROP CHECK student_submissions_chk_1;

-- Step 6: Rename the 'marks' column to 'score'
ALTER TABLE student_submissions
CHANGE COLUMN marks score INT;

-- Step 7: Reapply the check constraint on 'score'
ALTER TABLE student_submissions
ADD CHECK (score BETWEEN 0 AND 100);

-- Step 8: Add a default value for 'remarks'
ALTER TABLE student_submissions
ALTER COLUMN remarks SET DEFAULT 'No remarks yet';

-- Step 9: Drop the 'remarks' column
ALTER TABLE student_submissions
DROP COLUMN remarks;

-- Step 10: Rename the table to 'submissions'
RENAME TABLE student_submissions TO submissions;

-- Step 11: Add a foreign key column 'course_id' and link it to another table
-- First, create the referenced table 'courses'
CREATE TABLE courses (
    course_id INT PRIMARY KEY,
    course_name VARCHAR(50) NOT NULL
);

ALTER TABLE submissions
ADD COLUMN course_id INT,
ADD CONSTRAINT fk_course
FOREIGN KEY (course_id) REFERENCES courses(course_id);

-- Step 12: Add a unique constraint on the 'name' column
ALTER TABLE submissions
ADD CONSTRAINT unique_name UNIQUE (name);

-- Step 13: Add an index on the 'submission_date' column
CREATE INDEX idx_submission_date
ON submissions (submission_date);

-- Step 14: Drop the primary key on 'roll_no'
ALTER TABLE submissions
MODIFY COLUMN roll_no INT, -- Remove AUTO_INCREMENT
DROP PRIMARY KEY;
