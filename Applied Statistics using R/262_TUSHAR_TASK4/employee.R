# 1) Load the dataset from "employee_data.csv" into a data frame in R.

  empdata <- read.csv("C:/Users/tushar sakuja/Desktop/SEMESTER-2/APPLIED STATS WITH R/TASK_4/employee_data.csv")
  empdata
  
  
  # 2) Display the structure of the data frame, including column names and data types.
  
  str(empdata)
  
  
  # 3) Calculate and add a new column named "Years of Service" to the data frame, representing the number of years each employee has worked in the company.
  
  empdata$Years_of_Service <- as.numeric(difftime(Sys.Date(), as.Date(empdata$Joining_Date), units = "days") / 365)
  empdata
  
  
  # 4) Create a new data frame named "Senior Employees" containing records of employees who have worked for the company for 5 or more years.
  
  SeniorEmployees <- empdata[empdata$Years_of_Service >= 5,]
  SeniorEmployees
  
  
  # 5) Calculate and print the average salary of employees in each department.
  
  averageSalaries <- tapply(empdata$Salary, empdata$Department, mean)
  averageSalaries
  
  
  # 6) Determine the highest and lowest salaries in the entire dataset and identify the employees with these salaries.
  
  maxSalary <- max(empdata$Salary)
  minSalary <- min(empdata$Salary)
  
  employeeWithMaxSalary <- empdata[empdata$Salary == maxSalary, ]
  employeeWithMinSalary <- empdata[empdata$Salary == minSalary, ]
  
  maxSalary
  employeeWithMaxSalary
  minSalary
  employeeWithMinSalary
  
  
  # 7) Create a bar plot to visualize the number of employees in each department.
  
  barplot(table(empdata$Department), main = "Number of Employees in Each Department")
  
  
  # 8) Generate a scatter plot to explore the relationship between years of service and salary.
  
  plot(empdata$Years_of_Service, empdata$Salary, xlab = "Years of Service", ylab = "Salary", main = "Relationship between Years of Service and Salary")
  
  
  # 9) Save the "Senior Employees" data frame as a CSV file named "senior_employees.csv."
  
  write.csv(SeniorEmployees, "C:/Users/tushar sakuja/Desktop/SEMESTER-2/APPLIED STATS WITH R/TASK_4/senior_employee.csv", row.names = FALSE)
  

empdata

