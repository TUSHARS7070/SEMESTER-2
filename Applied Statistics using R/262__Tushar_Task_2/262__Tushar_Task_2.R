#1.Create two matrices, matrix_A and matrix_B
A <- matrix(c(2,4,8,9,6,4,7,5,3),nrow=3,ncol=3,byrow = TRUE)
B <- matrix(c(7,8,6,4,3,1,5,2,1),nrow=3,ncol=3,byrow = TRUE)
A
B

#2.Calculate the sum of matrix_A and matrix_B and store the result in a new matrix named matrix_sum.
matrix_sum=A+B
matrix_sum

#3.Calculate the difference between matrix_A and matrix_B and store the result in a new matrix named matrix_diff.
matrix_diff=A-B
matrix_diff

#4.Multiply matrix_A by a scalar value of 2 and store the result in a new matrix named matrix_mult.
matrix_mult=A*2
matrix_mult

#5.Calculate the product of matrix_A and matrix_B and store the result in a new matrix named matrix_product.
matrix_product=A*B
matrix_product

#6.Find the transpose of matrix_A and store the result in a new matrix named matrix_A_transpose.
matrix_A_transpose=t(A)
matrix_A_transpose

#7.Calculate the determinant of matrix_B and store it in a variable named determinant_B.
determinat_B=det(B)
determinat_B

#8.Invert matrix_B to obtain the inverse matrix and store it in a new matrix named matrix_B_inverse.
matrix_B_inverse=solve(B)
matrix_B_inverse

#9.Check if matrix_B is orthogonal (i.e., its transpose is equal to its inverse).
matrix_A_inverse=solve(A)
matrix_A_inverse
if(all(matrix_A_transpose==matrix_A_inverse))
  {
    print("Orthogonal")
}else{
  print("Not Orthogonal")
}

#10.Calculate the element-wise square root of matrix_A and store the result in a new matrix named matrix_A_sqrt.
matrix_A_sqrt=sqrt(A)
matrix_A_sqrt

#11.Calculate the mean of all the elements in matrix_B.
matrix_B_mean=mean(B)
matrix_B_mean

#12.Calculate the sum of each column in matrix_A.
matrix_colsum=colSums(A)
matrix_colsum

#13.Calculate the row means of matrix_B.
matrix_rowmeans=rowMeans(B)
matrix_rowmeans

#14.Extract the second row of matrix_A and store it in a vector named second_row_A.
second_row_A=A[2,]
second_row_A

#15.Extract the third column of matrix_B and store it in a vector named third_column_B.
third_column_B=B[,3]
third_column_B

