g++ -fsanitize=address -ftrapv 4.cpp -O2

# ./a.out <level4_example.in >level4_example.ans
# diff level4_example.ans level4_example.out
# ./a.out <level4_1.in >level4_1.out
./a.out <level4_2.in >level4_2.out
# ./a.out <level4_3.in >level4_3.out
# ./a.out <level4_4.in >level4_4.out
# ./a.out <level4_5.in >level4_5.out