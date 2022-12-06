import math

sum_x = 0
sum_f = 0
sum_fx = 0
mean = 0
cf = 0
N = 0
n = 0

X = [float(X) for X in input("Enter X values: ").split()]
print("Number of list is: ", X)
sum_x += sum(X)
print("sum of x = ", sum_x)

f = [float(f) for f in input("Enter f values: ").split()]
print("Number of list is: ", f)
N += sum(f)
print("N = ", N)

fX = [X[i] * f[i] for i in range(len(X))]
print("f*x = ", fX)

sum_fx += sum(fX)
print("Sum of fx =", sum_fx)

CF=[]
for i in range(0, len(f)):
    cf += f[i]
    CF.append(cf)
print("cf = ", CF)

size_of_median = (N+1)/2
print("Size of median", size_of_median)

md = min(i for i in CF if i > size_of_median)
print("md cf=", md)

md_index = CF.index(md)
print("Median = ", X[md_index])

mean = sum_fx/N
print("mean =", mean)

X_mean = []
for i in range(0, len(X)):
    x_mean = X[i] - mean
    X_mean.append(x_mean)
print("X-Mean = ",X_mean)

F_X_mean = []
for i in range(0, len(X)):
    f_x_mean = X_mean[i] * f[i]
    F_X_mean.append(f_x_mean)
print("F*X-Mean = ",F_X_mean)

sum_f_x_mean = 0
sum_f_x_mean += sum(F_X_mean)
print("sum of f*(x-mean) = ", sum_f_x_mean)

X_mean_square = []
for i in range(0, len(X_mean)):
    x_mean_square = X_mean[i]*X_mean[i]
    X_mean_square.append(x_mean_square)
print("X-mean square = ", X_mean_square)

F_X_mean_square = []
for i in range(0, len(X)):
    f_x_mean_square = X_mean_square[i] * f[i]
    F_X_mean_square.append(f_x_mean_square)
print("F*X-MeanSquare = ",F_X_mean_square)

sum_f_x_mean_square = 0
sum_f_x_mean_square += sum(F_X_mean_square)
print("sum of f*(x-mean)^2 = ", sum_f_x_mean_square)

X_mean_cube = []
for i in range(0, len(X_mean)):
    x_mean_cube = X_mean[i]*X_mean[i]*X_mean[i]
    X_mean_cube.append(x_mean_cube)
print("X-mean cube = ", X_mean_cube)

F_X_mean_cube = []
for i in range(0, len(X)):
    f_x_mean_cube = X_mean_cube[i] * f[i]
    F_X_mean_cube.append(f_x_mean_cube)
print("F*X-MeanCube = ",F_X_mean_cube)

sum_f_x_mean_cube = 0
sum_f_x_mean_cube += sum(F_X_mean_cube)
print("sum of f*(x-mean)^3 = ", sum_f_x_mean_cube)

X_mean_four = []
for i in range(0, len(X_mean)):
    x_mean_four = X_mean[i]*X_mean[i]*X_mean[i]*X_mean[i]
    X_mean_four.append(x_mean_four)
print("X-mean four = ", X_mean_four)

F_X_mean_four = []
for i in range(0, len(X)):
    f_x_mean_four = X_mean_four[i] * f[i]
    F_X_mean_four.append(f_x_mean_four)
print("F*X-MeanFour = ",F_X_mean_four)

sum_f_x_mean_four = 0
sum_f_x_mean_four += sum(F_X_mean_four)
print("sum of f*(x-mean)^4 = ", sum_f_x_mean_four)

mew1 = sum_f_x_mean/N
print("u1= ",mew1)

mew2 = sum_f_x_mean_square/N
print("u2= ",mew2)

mew3 = sum_f_x_mean_cube/N
print("u3= ",mew3)

mew4 = sum_f_x_mean_four/N
print("u4= ",mew4)


sd = math.sqrt(sum_mean_square/N)
print("SD = ", sd)

cv = (sd/mean)*100
print("CV = ", cv)
