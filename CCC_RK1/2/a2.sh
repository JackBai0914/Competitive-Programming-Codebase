g++ -fsanitize=address -ftrapv 2.cpp

./a.out <level2_example.in >level2_example.ans
diff level2_example.ans level2_example.out
./a.out <level2_1.in >level2_1.out
./a.out <level2_2.in >level2_2.out
./a.out <level2_3.in >level2_3.out
./a.out <level2_4.in >level2_4.out
./a.out <level2_5.in >level2_5.out