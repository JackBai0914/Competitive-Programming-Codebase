private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles



fun main(args: Array<String>) {
    var t = readInt()
    while (t-- >0) {
        var n = readInts();
        
    }
}

/*
  * COMPILE
    kotlinc a.kt -include-runtime -d outp.jar
    java -jar outp.jar

  * input&output
    read two integers: var (x, y) = readInts()
    
    println(list.joinToString(" "))
    println("${PAR} RANDOM_STRING")
    println(PAR)
    print d to 8 decimal places: String.format("%.8g%n", d)

  * main function:
    fun main(args: Array<String>) {
    }
   
  
  * parameters declaration:
    var x = something
  
  * for, while, if, else
    for (i in 1..n) //for (int i = 1; i <= n; i ++)
    for (i in 0 until n) //for (int i = 0; i < n; i ++)
    for (i in a) //a is a list, and i traverses all elements in a.
    for (i in n-1 downTo 0) //for (int i = n - 1; i >= 0; i --)

    while (t-- >0) // while ((t--) > 0)
    repeat(readLine()!!.toInt())

    if/else: the same as C++
    (if(x>0) '1' else '0')

  * functions declaration
    fun F (x: Int) {
    
    }
    fun quo(a: Int, b: Int): Int {
      if (a%b < b/2)
        return a/b
      return a/b+1
    }
    fun add(a: Int, b: Int) = (a + b) % md

  * IntArray, CharArray, Array //FIXED LENGTH
    var x = IntArray(n)
    var y = CharArray(n)
    x.joinToString(" ")
    y.joinToString("")
    var b = Array<Pair<Int, Int>>(n, {i -> Pair(a[i], i)})

    * multi-dimention array:
      var dp = Array(n1){Array(n2){Array(n3){Array(n4){IntArray(n5){0}}}}} //int dp[n1][n2][n3][n4][n5]

    * template:
      Array(n)
      Array(n, {0})
      Array(n, {i -> a[i]})


    
  * List (currently no evidence that it's different from Array)
    var x = readInts()
    
  * Pair and self-defined sort
    var x = Pair(1, 2)
    var b = Array<Pair<Int, Int>>(n, {i -> Pair(a[i], i)})
    b.sortWith(compareBy({it.first}, {it.second}))


  * ArrayList //addable, like vector
    ArrayList<Int>()
    //HAVE PARAMETER: size
    //some combination:
    g = Array(n, {ArrayList<Pair<Int, Int>>() })
    g[a].add(Pair(a, b)), g[b].add(Pair(a, b))
    //or
    g = Array(n, {ArrayList<Int>() })
    g[a].add(b), g[b].add(a)

    q.sortBy({x->x.second})

  * TreeSet
    var s = TreeSet <Long>()
    s.isEmpty()
    s.remove(x)
    s.add(x)
    var f = s.first()


  * Bit operations
    (a shl b) //a<<b
    (a shr b) //a>>b


  * Trivial Functions:fun
    - maxOf(a, b), minOf(a, b)
    - toInt() //2e9.toInt()
  * hashmap
    val h = HashMap<String,Int>()
    for (i in 0..n-2) {
      val w = s.substring(i,i+2)
      val c = h.getOrElse(w){0}
      h.put(w,c+1)
  }

  *BIT
    class BIT() {
      val v = LongArray(SZ)
      fun upd(_a: Int, b: Long) {
          var a = _a
          while (a < SZ) {
              v[a] += b
              a += (a and -a)
          }
      }
      fun query(_a: Int): Long {
          var a = _a
          var ans: Long = 0
          while (a > 0) {
              ans += v[a]
              a -= (a and -a)
          }
          return ans
      }
    }

*/
