create database EXP4b;
use EXP4b;

CREATE TABLE assignment_4b
(
	radius varchar(20),
	area varchar(20)
);

DELIMITER //
CREATE PROCEDURE calculate_area()
BEGIN
    DECLARE radius_var INT;
    DECLARE area_var DECIMAL(10, 2);
    DECLARE pi DECIMAL(10, 2) DEFAULT 3.14;
    SET radius_var = 5;
    WHILE radius_var <= 9 DO
        SET area_var = pi * radius_var * radius_var;
        -- Insert calculated values into the table
        INSERT INTO assignment_4b (radius, area) VALUES (radius_var, area_var);
        -- Increment radius_var for next iteration
        SET radius_var = radius_var + 1;
    END WHILE;
END //
DELIMITER ;

CALL calculate_area();

select * from assignment_4b;