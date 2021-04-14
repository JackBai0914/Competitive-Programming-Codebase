# g++ data.cpp -o data
g++ 4.cpp -o 4 -O2
# g++ force.cpp -o force
# ./data > 1.out
time ./4 < 1.out > 4.out
# ./force < 1.out > force.out

# diff 4.out force.out



