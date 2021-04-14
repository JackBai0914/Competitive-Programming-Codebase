g++ -fsanitize=address -ftrapv 5.cpp

# ./a.out <level5_example.in >level5_example.ans
# diff level5_example.ans level5_example.out
# ./a.out <level5_1.in >level5_1.out
./a.out <level5_2.in >level5_2.out
# ./a.out <level5_3.in >level5_3.out
# ./a.out <level5_4.in >level5_4.out
# ./a.out <level5_5.in >level5_5.out