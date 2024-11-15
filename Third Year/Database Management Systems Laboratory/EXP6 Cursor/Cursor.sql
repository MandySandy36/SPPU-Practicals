create database EXP6;
use EXP6;

CREATE TABLE o_rollcall
(
	roll_no int, 
	name VARCHAR(25), 
    division VARCHAR(5)
);

CREATE TABLE n_rollcall
(
	roll_no int, 
    name VARCHAR(25), 
    division VARCHAR(5)
);

INSERT INTO o_rollcall VALUES(45,'aditya','A');
INSERT INTO o_rollcall VALUES(46,'mehatab','A');
INSERT INTO o_rollcall VALUES(47,'anuj','B');
INSERT INTO o_rollcall VALUES(48,'ramteke','A');
INSERT INTO o_rollcall VALUES(49,'sakshi','B');
INSERT INTO o_rollcall VALUES(50,'trupi','B');

DELIMITER //
CREATE PROCEDURE cursor_imp ()
BEGIN
	DECLARE done INT DEFAULT 0;
	DECLARE c_r INT;
	DECLARE c_n VARCHAR(25);
	DECLARE c_d VARCHAR(5);
	-- Declare a cursor for the select statement
	DECLARE c1 CURSOR FOR
	SELECT roll_no, name, division
	FROM o_rollcall
	GROUP BY roll_no, name, division
	HAVING COUNT(roll_no) > 1
	AND COUNT(name) > 1
	AND COUNT(division) > 1;
	-- Declare handler to exit loop when done
	DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;
	-- Open cursor
	OPEN c1;
	-- Loop through rows
	read_loop: LOOP
	FETCH c1 INTO c_r, c_n, c_d;
	IF done THEN
		LEAVE read_loop;
	END IF;
	-- Delete duplicate entry from n_rollcall
	DELETE FROM n_rollcall
	WHERE roll_no = c_r
		AND name = c_n
		AND division = c_d;
		-- Insert unique entry into n_rollcall
		INSERT INTO n_rollcall (roll_no, name, division)
		VALUES (c_r, c_n, c_d);
		-- Print values (use SELECT in MySQL since DBMS_OUTPUT is not available)
		SELECT CONCAT(c_r, ' ', c_n, ' ', c_d) AS output;
	END LOOP;
	-- Close cursor
	CLOSE c1;
END;
//

INSERT INTO o_rollcall VALUES(45,'aditya','A');
INSERT INTO o_rollcall VALUES(46,'mehatab','A');
INSERT INTO o_rollcall VALUES(47,'anuj','B');
INSERT INTO o_rollcall VALUES(48,'ramteke','A');
INSERT INTO o_rollcall VALUES(49,'sakshi','B');
INSERT INTO o_rollcall VALUES(50,'trup􀆟','B');

CALL cursor_imp ();

select * from o_rollcall;
select * from n_rollcall;