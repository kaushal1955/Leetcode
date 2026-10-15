# Write your MySQL query statement below
SELECT W1.id
FROM Weather w1
JOIN weather w2
ON datediff(w1.recordDate, w2.recordDate)=1
WHERE W1.temperature>W2.temperature;