# Write your MySQL query statement below
select id from weather as w where temperature > (select temperature from weather where recordDate = date_sub(w.recordDate, interval 1 day));