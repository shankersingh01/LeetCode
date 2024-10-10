# Write your MySQL query statement below
#name pop area of big country

Select name, population, area
from World
where area >= 3000000 or population >= 25000000;