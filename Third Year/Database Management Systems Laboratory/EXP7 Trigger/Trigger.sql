CREATE DATABASE EXP7;
USE EXP7;

CREATE TABLE lib_tab
(
	book_name VARCHAR(25),
	status VARCHAR(15)
);

CREATE TABLE library_audit
(
	date_modified DATE,
	book_name VARCHAR(25),
	old_status VARCHAR(15),
	new_status VARCHAR(15),
	action VARCHAR(25)
);

DELIMITER //
CREATE TRIGGER trigger_1
AFTER INSERT ON lib_tab FOR EACH ROW
BEGIN
	INSERT INTO library_audit VALUES (now(),NEW.book_name,NULL,NEW.status,'INSERT');
END;//

DELIMITER //
CREATE TRIGGER trigger_2
AFTER UPDATE ON lib_tab FOR EACH ROW
BEGIN
	INSERT INTO library_audit VALUES (now(),OLD.book_name,OLD.status,NEW.status,'UPDATE');
END;//

DELIMITER //
CREATE TRIGGER trigger_3
AFTER DELETE ON lib_tab
FOR EACH ROW
BEGIN
	INSERT INTO library_audit
	VALUES (NOW(), OLD.book_name, OLD.status, NULL, 'DELETE');
END;//

INSERT INTO lib_tab VALUES('DARK MATTER','AVAILABLE');
INSERT INTO lib_tab VALUES('SILENT HILL','UNAVAILABLE');
INSERT INTO lib_tab VALUES('GOD OF WAR','AVAILABLE');
INSERT INTO lib_tab VALUES('SPIDER-MAN','UNAVAILABLE');
INSERT INTO lib_tab VALUES('UNCHARTED','AVAILABLE');
DELETE FROM lib_tab WHERE book_name = 'SILENT HILL';
UPDATE lib_tab SET status = 'UNAVAILABLE' WHERE book_name = 'UNCHARTED';
UPDATE lib_tab SET status = 'PRE-ORDER' WHERE book_name = 'GOD OF WAR';
UPDATE lib_tab SET status = 'AVAILABLE' WHERE book_name = 'UNCHARTED';
INSERT INTO lib_tab VALUES('SPM','UNAVAILABLE');

Select * from library_audit;
Select * from lib_tab;