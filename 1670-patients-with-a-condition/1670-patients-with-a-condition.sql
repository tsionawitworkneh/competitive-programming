# Write your MySQL query statement below
select patient_id,patient_name ,conditions
from Patients
WHERE conditions REGEXP '(^| )DIAB1'
