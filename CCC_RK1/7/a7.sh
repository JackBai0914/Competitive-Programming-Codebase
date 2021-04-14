g++ -fsanitize=address -ftrapv 7.cpp

# ./a.out <level7_example.in >level7_example.ans
# diff level7_example.ans level7_example.out
# ./a.out <level7_1.in >level7_1.out
./a.out <level7_2.in >level7_2.out
# ./a.out <level7_3.in >level7_3.out
# ./a.out <level7_4.in >level7_4.out
# ./a.out <level7_5.in >level7_5.out