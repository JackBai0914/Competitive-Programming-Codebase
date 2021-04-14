g++ -fsanitize=address -ftrapv 1.cpp

./a.out <level1_example.in >level1_example.ans
diff level1_example.ans level1_example.out
./a.out <level1_1.in >level1_1.out
./a.out <level1_2.in >level1_2.out
./a.out <level1_3.in >level1_3.out
./a.out <level1_4.in >level1_4.out
./a.out <level1_5.in >level1_5.out