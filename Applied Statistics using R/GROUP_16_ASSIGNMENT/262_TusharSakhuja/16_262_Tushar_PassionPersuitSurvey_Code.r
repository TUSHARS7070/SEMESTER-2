# age
age <- data.frame(
  categories = c("18-20", "21-30", "31-40", "41-50"),
  values = c(76, 59, 13, 8)
)
age
# bar chart
barplot(age$values, names.arg = age$categories, 
        xlab = "AGE", ylab = "Values", 
        col = "lightblue", main = "Bar Chart")



# gender
gender <- data.frame(
  categories = c("MALE", "FEMALE"),
  values = c(84, 72)
)
gender
# bar chart
barplot(gender$values, names.arg = gender$categories, 
        xlab = "GENDER", ylab = "Values", 
        col = "lightblue", main = "Bar Chart")



# occupation
occupation <- data.frame(
  categories = c("STUDENT", "WORKING PROFESSIONAL"),
  values = c(95, 61)
)
occupation
# bar chart
barplot(occupation$values, names.arg = occupation$categories, 
        xlab = "OCCUPATION", ylab = "Values", 
        col = "lightblue", main = "Bar Chart")



# education stream
education_stream <- data.frame(
  categories = c("SCIENCE", "COMMERCE", "ARTS"),
  values = c(113, 30, 13)
)
education_stream
# bar chart
barplot(education_stream$values, names.arg = education_stream$categories, 
        xlab = "EDUCATION STREAM", ylab = "Values", 
        col = "lightblue", main = "Bar Chart")



# following passion
following_passion <- data.frame(
  categories = c("YES", "NO"),
  values = c(122, 34)
)
following_passion
# bar chart
barplot(following_passion$values, names.arg = following_passion$categories, 
        xlab = "FOLLOWING PASSION", ylab = "Values", 
        col = "lightblue", main = "Bar Chart")



# career guidance stage
career <- data.frame(
  categories = c("GRADE 10", "GRADE 12/PUC", "UNDERGRADE"),
  values = c(51, 61, 44)
)
career
# bar chart
barplot(career$values, names.arg = career$categories, 
        xlab = "CAREER GUAIDANCE STAGE", ylab = "Values", 
        col = "lightblue", main = "Bar Chart")


# INSPIRATION FOR COURSE
course <- data.frame(
  categories = c("OWN INTEREST", "HIGH DEMAND", "RECOMMENDATION"),
  values = c(97, 28, 31)
)
course
# bar chart
barplot(course$values, names.arg = course$categories, 
        xlab = "INSPIRATION FOR COURSE", ylab = "Values", 
        col = "lightblue", main = "Bar Chart")



# PREFERENCE
preference <- data.frame(
  categories = c("HIGHER SALARY", "PASSION RELATED"),
  values = c(77, 79)
)
preference
# bar chart
barplot(preference$values, names.arg = preference$categories, 
        xlab = "PREFERENCE", ylab = "Values", 
        col = "lightblue", main = "Bar Chart")



# PREFERENCE FOR STUDY OR WORK
study_work <- data.frame(
  categories = c("INDIA", "ABROAD"),
  values = c(102, 54)
)
study_work
# bar chart
barplot(study_work$values, names.arg = study_work$categories, 
        xlab = "PREFERENCE FOR STUDY OR WORK", ylab = "Values", 
        col = "lightblue", main = "Bar Chart")

