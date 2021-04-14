# g++ data.cpp -o data
g++ c.cpp -o c
g++ c2.cpp -o c2 -std=c++11

# while true; do
# ./data
./c <inp2.in >c.out
./c2 <inp2.in >c2.out
# if diff c.out c2.out
# then
# 	echo 'AC'
# else
# 	echo 'WA'
# 	exit
# fi
# done