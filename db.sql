DROP TABLE IF EXISTS speeches;

DROP TABLE IF EXISTS debates;

-- DROP TABLE IF EXISTS speechContent;

CREATE TABLE
    speeches(
        name VARCHAR(100),
        date_time DATETIME,
        debate_time DATETIME PRIMARY KEY
    );

LOAD DATA
    LOCAL INFILE './web-scrapers/transcripts-scraper/speeches.csv' INTO
TABLE
    speeches FIELDS TERMINATED BY ',' ENCLOSED BY '"' LINES TERMINATED BY '\n' IGNORE 1 LINES;

CREATE TABLE
    debates(
        titel VARCHAR(100),
        subtitle VARCHAR(200),
        datetime DATETIME PRIMARY KEY
    );

LOAD DATA
    LOCAL INFILE './web-scrapers/transcripts-scraper/debates.csv' INTO
TABLE
    debates FIELDS TERMINATED BY ',' ENCLOSED BY '"' LINES TERMINATED BY '\n' IGNORE 1 LINES;

-- CREATE TABLE

--     speechContent(

--         speechID Int,

--         type VARCHAR(10),

--         name VARCHAR(50),

--         text VARCHAR(1000),

--         speech_time DATETIME PRIMARY KEY

--     );