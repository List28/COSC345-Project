-- ALTER DATABASE db CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;


-- DROP TABLE IF EXISTS speeches;

-- DROP TABLE IF EXISTS debates;

-- DROP TABLE IF EXISTS speechContent;

DROP TABLE IF EXISTS mp;

DROP TABLE IF EXISTS finances;

-- CREATE TABLE

--     speeches(

--         name VARCHAR(100),

--         date_time DATETIME PRIMARY KEY,

--         debate_time DATETIME

--     );

-- LOAD DATA

--     LOCAL INFILE './web-scrapers/transcripts-scraper/speeches.csv' INTO

-- TABLE

--     speeches FIELDS TERMINATED BY ',' ENCLOSED BY '"' LINES TERMINATED BY '\n' IGNORE 1 LINES;

CREATE TABLE
    mp(
        id INT,
        name VARCHAR(50) PRIMARY KEY,
        salutation VARCHAR(10) NULL,
        job_title VARCHAR(50),
        electorate VARCHAR(50),
        party VARCHAR(30),
        parliament_email VARCHAR(70)
    );

LOAD DATA
    LOCAL INFILE './web-scrapers/transcripts-scraper/mp.csv' INTO
TABLE
    mp FIELDS TERMINATED BY ',' ENCLOSED BY '"' LINES TERMINATED BY '\n' IGNORE 1 LINES;

-- CREATE TABLE

--     debates(

--         titel VARCHAR(100),

--         subtitle VARCHAR(200),

--         datetime DATETIME PRIMARY KEY

--     );

-- LOAD DATA

--     LOCAL INFILE './web-scrapers/transcripts-scraper/debates.csv' INTO

-- TABLE

--     debates FIELDS TERMINATED BY ',' ENCLOSED BY '"' LINES TERMINATED BY '\n' IGNORE 1 LINES;

-- CREATE TABLE

--     speechContent(

--         speechID Int,

--         type VARCHAR(10),

--         name VARCHAR(50),

--         text VARCHAR(1000),

--         speech_time DATETIME PRIMARY KEY

--     );

CREATE TABLE
    finances(
        mp_name VARCHAR(50) PRIMARY KEY,
        company_directorships VARCHAR(800),
        other_companies VARCHAR(1600),
        employment VARCHAR(100),
        interest_trust VARCHAR(500),
        organizations VARCHAR(800),
        property VARCHAR(800),
        retirement VARCHAR(300),
        investment_schemes VARCHAR(500),
        debts_to_you VARCHAR(400),
        debts_owed_by_you VARCHAR(300),
        overseas_travel VARCHAR(1000),
        gifts VARCHAR(1000), 
        to_remove VARCHAR(5),
        payment_activities VARCHAR(500) 
    );

ALTER TABLE
    finances CONVERT TO CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;

LOAD DATA
    LOCAL INFILE './web-scrapers/financial-scraper/output.csv' INTO
TABLE
    finances FIELDS TERMINATED BY ',' ENCLOSED BY '"' LINES TERMINATED BY '\n' IGNORE 1 LINES;