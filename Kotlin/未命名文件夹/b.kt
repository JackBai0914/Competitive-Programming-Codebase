private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

var rec = IntArray(10000)

fun main(args: Array<String>) {
    var t = readInt()
    while (t-- >0) {
        var (n, k1, k2) = readInts()
        var s = readLn()
        var ans = 0
        for (i in 0 until n) {
          if (s[i] == '1') {
            var mx1 = k2
            if (i != 0)
              if (rec[i-1]!=0)
                mx1 -= rec[i-1]
            ans += minOf(k1, mx1)
            rec[i] = minOf(k1, mx1)
          }
          else {
            rec[i]=0;
          }
        }
      println(ans)
    }
}

