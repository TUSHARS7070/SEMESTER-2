#Create a list named employee representing the details of an employee with the following components:
#EmployeeID: A unique employee identifier (as a numeric value).
#Name: The employee's full name (as a string).
#Salary: The employee's monthly salary (as a numeric value).
#Departments: A vector containing the names of the departments the employee is associated with (as strings).

employee <- list(
  EmployeeID = 101,
  Name = "TUSHAR SAKHUJA",
  Salary = 78000,
  Departments = c("IT","INFRASTRUCTURE")
)

#Display the entire content of the employee list.

employee

#Calculate and print the employee's annual salary (12 times the monthly salary).

annual_salary <- 12 * employee$Salary
annual_salary

#Update the employee's name to a different name.

employee$Name <- "ROHIT SINGH"
employee$Name

#Add a new department to the Departments vector for the employee.

employee$Departments <- c(employee$Departments, "IT")
employee$Departments

#Create a list named organization to represent an organization with the following components:
# Name: The name of the organization (as a string).
#Employees: A list containing details of at least three employees, using the structure created in Task 1.

organization <- list(
  Name = "ABC LTD.",
  Employees = list(
    list(EmployeeID = 102, Name = "SUKHWINDER SINGH", Salary = 59000, Departments = c("IT", "Finance")),
    list(EmployeeID = 103, Name = "ARYAN MUKE", Salary = 65000, Departments = c("IT", "Sales")),
    list(EmployeeID = 104, Name = "YASH JHAWAR", Salary = 62000, Departments = c("IT", "Marketing"))
  )
)

#Display the entire content of the nested list organization.
organization

#Access and print the annual salary of the second employee in the organization.

second_employee_salary <- 12 * organization$Employees[[2]]$Salary
second_employee_salary

#Access and print the name of the organization.
print(organization$Name)

#Create a new list named department_employees that groups employees by department. 
#Each department should have a list of employees associated with it.

department_employees <- list(
  HR = list(),
  Finance = list(),
  IT = list(),
  Sales = list(),
  Marketing = list()
)
for (emp in organization$Employees) {
  for (dept in emp$Departments) {
    department_employees[[dept]] <- c(department_employees[[dept]], emp$Name)
  }
}
department_employees

#Print each list created in the script to show the structure and content of the lists after performing the operations in Tasks 1-5.
str(employee)
str(organization)
str(department_employees)

# Print the 'department_employees' list
for (dept in names(department_employees)) {
  print("Employees Grouped by Department:")
  print(paste("Department:", dept))
  print(paste("Employees:", paste(department_employees[[dept]], collapse = ", ")))
}

