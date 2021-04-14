g++ -fsanitize=address -ftrapv 3.cpp

./a.out <level3_example.in >level3_example.ans
diff level3_example.ans level3_example.out
./a.out <level3_1.in >level3_1.out
./a.out <level3_2.in >level3_2.out
./a.out <level3_3.in >level3_3.out
./a.out <level3_4.in >level3_4.out
./a.out <level3_5.in >level3_5.out