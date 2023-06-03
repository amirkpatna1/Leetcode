SELECT a.machine_id, round(avg(b.timestamp - a.timestamp),3) as processing_time from activity a join activity b on a.machine_id = b.machine_id and a.process_id = b.process_id and a.activity_type = 'start' and b.activity_type = 'end' group by a.machine_id

# SELECT s.machine_id, ROUND(AVG(e.timestamp-s.timestamp), 3) AS processing_time
# FROM Activity s JOIN Activity e ON
#     s.machine_id = e.machine_id AND s.process_id = e.process_id AND
#     s.activity_type = 'start' AND e.activity_type = 'end'
# GROUP BY s.machine_id