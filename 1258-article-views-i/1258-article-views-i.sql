# Write your MySQL query statement below
Select distinct author_id as Id 
from Views
where author_id = viewer_id
order by Id;