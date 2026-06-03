-- Write your query below
select student_id, exam_id, score from 
(select student_id, exam_id, score,
row_number() over (partition by student_id order by score desc, exam_id asc)
from exam_results)
where row_number = 1;
