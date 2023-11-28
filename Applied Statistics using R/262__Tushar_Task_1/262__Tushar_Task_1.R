#You are provided with a vector of monthly sales data for a small business. Your task is to perform various operations on this data using vector arithmetic,sorting, and reverse sorting in R.

#1.Create a vector named sales_data with the following sales figures (in thousands of dollars) for the last 12 months: [45, 60, 35, 75, 80, 62, 48, 53, 69, 72, 40, 55].
sales_data=c(45,60,35,75,80,62,48,53,69,72,40,55)
sales_data

#2.Calculate the total annual sales by summing the elements in the sales_data vector.
annualsales=sum(sales_data)
annualsales

#3.Compute the monthly average sales by dividing the total annual sales by 12 (the number of months).
avg_sales=annualsales/12
avg_sales

#4.Determine the month with the highest sales and the corresponding sales figure. Also, find the month with the lowest sales and its sales figure.
max_sales=max(sales_data)
max_sales
min_sales=min(sales_data)

#5.Increase the sales figure for the third month (March) by 10%.
march_sales_index=3 
sales_data[march_sales_index]=sales_data[march_sales_index] * 1.10
sales_data

#6.Sort the sales_data vector in ascending order and create a new vector named sorted_sales.
sorted_sales=sort(sales_data)
sorted_sales

#7.Sort the sales_data vector in descending order and create a new vector named reverse_sorted_sales.
reverse_sorted_sales=sort(sales_data,decreasing = TRUE)
reverse_sorted_sales

#8.Calculate the median sales value from the sorted_sales vector.
median_sales=median(sorted_sales)
median_sales

