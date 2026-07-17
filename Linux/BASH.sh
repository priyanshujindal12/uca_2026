#!/bin/bash
awk -F "," '{print $1 , $2}' file.csv
awk -F "," '$2 == "Engineering" ' file.csv
awk -F "," '{print $1, "gross pay: $" $3 * $4}' file.csv    
awk -F "," '{print NR, "(" NF " fields):", $0}' file.csv 
awk -F "," 'BEGIN { total = 0 } $2 == "Engineering" { total += $3 * $4 } END { print "Total Engineering Payroll: $" total }
' file.csv