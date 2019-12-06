~~~ mysql
-- 코드를 입력하세요
SELECT ANIMAL_ID, NAME from ANIMAL_INS where INTAKE_CONDITION LIKE 'Sick'

-- 코드를 입력하세요
SELECT ANIMAL_ID, NAME from ANIMAL_INS where INTAKE_CONDITION NOT LIKE 'Aged'

-- 코드를 입력하세요
SELECT ANIMAL_ID, NAME from ANIMAL_INS order by ANIMAL_ID

-- 코드를 입력하세요
SELECT ANIMAL_ID, NAME, DATETIME from ANIMAL_INS order by NAME, DATETIME desc

-- 코드를 입력하세요
SELECT NAME from ANIMAL_INS order by DATETIME limit 1

SELECT max(DATETIME) as 시간 from ANIMAL_INS

-- 코드를 입력하세요 
SELECT min(DATETIME) as 시간 from ANIMAL_INS

-- 코드를 입력하세요
SELECT count(*) from ANIMAL_INS

-- 코드를 입력하세요
SELECT count(distinct NAME) from ANIMAL_INS

-- 코드를 입력하세요
# SELECT ANIMAL_TYPE, count(distinct ANIMAL_TYPE) as 'count' from ANIMAL_INS
SELECT ANIMAL_TYPE, count(*) from ANIMAL_INS group by ANIMAL_TYPE

-- 코드를 입력하세요
SELECT NAME, count(*) as 'COUNT' from ANIMAL_INS group by NAME having count(NAME)>=2

-- 코드를 입력하세요
SELECT HOUR(DATETIME) as HOUR, count(*) as 'COUNT' from ANIMAL_OUTS 
group by HOUR(DATETIME) 
having HOUR between 9 and 19 
order by HOUR(DATETIME)

-- 코드를 입력하세요
# SELECT HOUR(DATETIME) as HOUR, COUNT(NVL(HOUR,0)) from ANIMAL_OUTS group by HOUR
# select * from ANIMAL_OUTS;
# select DATE_FORMAT(DATETIME, '%h') as HOUR, count(*) as COUNT from ANIMAL_OUTS group by HOUR
set @hour = -1;
select
    (@hour := @hour +1) as HOUR,
    (select count(*) from animal_outs where hour(`datetime`) = @hour) as `COUNT`
from animal_outs 
where @hour < 23

-- 코드를 입력하세요
SELECT ANIMAL_ID from ANIMAL_INS where NAME is null

-- 코드를 입력하세요
SELECT ANIMAL_ID from ANIMAL_INS where NAME is not null

-- 코드를 입력하세요
SELECT ANIMAL_TYPE, IFNULL(NAME,"No name") as NAME, SEX_UPON_INTAKE from ANIMAL_INS

-- 코드를 입력하세요
SELECT O.ANIMAL_ID, O.NAME from ANIMAL_OUTS as O 
LEFT OUTER JOIN ANIMAL_INS as I on O.ANIMAL_ID = I.ANIMAL_ID 
where I.ANIMAL_ID is null

-- 코드를 입력하세요
SELECT I.ANIMAL_ID, I.NAME from ANIMAL_INS as I 
join ANIMAL_OUTS as O on I.ANIMAL_ID = O.ANIMAL_ID 
where I.DATETIME > O.DATETIME order by I.DATETIME

-- 코드를 입력하세요
SELECT I.NAME, I.DATETIME from ANIMAL_INS as I 
LEFT OUTER JOIN ANIMAL_OUTS as O on I.ANIMAL_ID = O.ANIMAL_ID
where O.ANIMAL_ID is null ORDER BY I.DATETIME limit 3

~~~

