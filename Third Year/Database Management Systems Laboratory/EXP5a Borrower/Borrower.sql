CREATE DATABASE EXP4a;
USE EXP4a;

CREATE TABLE borrower
(
	roll_no INT ,
	name VARCHAR(25),
	dateofissue DATE,
	name_of_book VARCHAR(25),
	status VARCHAR(20)
);

CREATE TABLE fine
(
	roll_no INT,
	date_of_return DATE,
	amt INT
);

INSERT INTO borrower VALUES (45, 'Aditya', '2024-08-01', 'HARRY POTTER', 'PENDING');
INSERT INTO borrower VALUES (46, 'mehatab', '2024-08-15', 'DARK MATTER', 'PENDING');
INSERT INTO borrower VALUES (47, 'anuj', '2024-08-24', 'SILENT HILL', 'PENDING');
INSERT INTO borrower VALUES (48, 'ramteke', '2024-08-26', 'GOD OF WAR', 'PENDING');
INSERT INTO borrower VALUES (49, 'sakshi', '2024-09-09', 'SPIDER-MAN', 'PENDING');
INSERT INTO borrower VALUES (50, 'trup􀆟', '2024-09-09', 'SILENT KILLER', 'PENDING');

DELIMITER //
CREATE PROCEDURE calculate_fine(
IN i_roll_no INT,
IN name_of_book VARCHAR(25)
)
BEGIN
	DECLARE no_of_days INT;
	DECLARE fine DECIMAL(10, 2);
	DECLARE temp INT;
	DECLARE doi DATE;
	DECLARE return_date DATE DEFAULT CURDATE();
	-- Retrieve date of issue for the specified roll number and book name
	SELECT borrower.dateofissue INTO doi
	FROM borrower
	WHERE borrower.roll_no = i_roll_no AND borrower.name_of_book = name_of_book;
	-- Calculate the number of days between the return date and date of issue
	SET no_of_days = DATEDIFF(return_date, doi);
	-- Determine fine based on the number of days overdue
	IF (no_of_days > 15 AND no_of_days <= 30) THEN
		SET fine = 5 * no_of_days;
	ELSEIF (no_of_days > 30) THEN
		SET temp = no_of_days - 30;
		SET fine = 150 + temp * 50;
	ELSE
		SET fine = 0;
	END IF;
	-- Insert the calculated fine into the fine table
	INSERT INTO fine (roll_no, date_of_return, amt) VALUES (i_roll_no, return_date, fine);
	-- Update the borrower status to 'RETURNED' for the specified roll number
	UPDATE borrower SET status = 'RETURNED' WHERE borrower.roll_no = i_roll_no AND
	borrower.name_of_book = name_of_book;
END //
DELIMITER ;

CALL calculate_fine(45, 'HARRY POTTER');
CALL calculate_fine(46, 'DARK MATTER');
CALL calculate_fine(47, 'SILENT HILL');
CALL calculate_fine(48, 'GOD OF WAR');
CALL calculate_fine(49, 'SPIDER-MAN');
CALL calculate_fine(50, 'SILENT KILLER');

select * from fine;