g++ -fsanitize=address -ftrapv 6.cpp

# ./a.out <level6_example.in >level6_example.ans
# diff level6_example.ans level6_example.out
# ./a.out <level6_1.in >level6_1.out
./a.out <level6_2.in >level6_2.out
# ./a.out <level6_3.in >level6_3.out
# ./a.out <level6_4.in >level6_4.out
# ./a.out <level6_5.in >level6_5.out